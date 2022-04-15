#include "lab4disign.h"
#include "ui_lab4disign.h"

#include <QFont>
#include <qlist.h>
#include <qtextedit.h>

lab4Disign::lab4Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab4Disign)
{
    ui->setupUi(this);
    mat.resize(1);
    mat[0].push_back(1);
    QTextEdit *tempEdit;

    tempEdit = new QTextEdit(QString::number(0));
    tempEdit->setAlignment(Qt::AlignCenter);
    tempEdit->setFont(QFont("Time New Roman", 15));
    ui->MatrixGrid->addWidget(tempEdit, 0, 0);

}

lab4Disign::~lab4Disign()
{
    delete ui;
}

void lab4Disign::on_saveButton_clicked()
{
    QTextEdit *temp;
    std::fstream file(path.toStdString(), std::ios::out | std::ios::trunc);
    //qDebug() << rowsC << columnsC;
    file.flush();
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < columnsC; j++) {
            temp = (QTextEdit*)(ui->MatrixGrid->itemAtPosition(i, j)->widget());
            file << temp->toPlainText().toStdString();
            if (j != columnsC - 1)
                 file << " ";
        }
        if (i != rowsC - 1)
            file << std::endl;
    }
    file.close();
}


void lab4Disign::on_openButton_clicked()
{
    for (int i = 0; i < rowsC; i++)
        for (int j = 0; j < columnsC; j++) {
            delete ui->MatrixGrid->itemAtPosition(i, j)->widget();
        }
    mat.resize(0);
    rows.resize(0);
    path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString());
    int i = 0;
    std::string row;
    while (!file.eof()) {
        getline(file, row);
        rows.push_back(row);
        i++;
    }
    int tempInt;
    int counter = 0;
    std::stringstream ss;
    mat.resize(rows.size());
    QTextEdit *tempEdit;
    for (size_t i = 0; i < rows.size(); i++) {
        ss.clear();
        ss << rows[i];
        counter = 0;
        mat[i].resize(0);
        while (ss.peek() != -1) {
            ss >> tempInt;
            tempEdit = new QTextEdit(QString::number(tempInt));
            tempEdit->setAlignment(Qt::AlignCenter);
            tempEdit->setFont(QFont("Time New Roman", 15));
            ui->MatrixGrid->addWidget(tempEdit, i, counter);
            ui->MatrixGrid->itemAt(i * rows.size() + counter)->widget();
            counter++;
            mat[i].push_back(tempInt);
        }
    }
    rowsC = rows.size();
    columnsC = counter;
}

int det(std::vector<std::vector<int>> m) {

    if (m.size() == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    int sum = 0;
    std::vector<std::vector<int>> a;
  a.resize(m.size() - 1);
    for (size_t i = 0; i < m.size(); i++) {
        a.clear();
        a.resize(m.size() - 1);
        for (size_t j = 1; j < m.size(); j++)
            for (size_t k = 0; k < m.size(); k++)
              if (i != k)
                  a[j - 1].push_back(m[j][k]);
        sum += m[0][i] * det(a) * pow(-1, i);
    }
    return sum;
}

void lab4Disign::on_calcButton_clicked()
{
    QTextEdit *temp;
    mat.resize(rowsC);
    for (int i = 0; i < rowsC; i++) {
        mat[i].resize(columnsC);
        for (int j = 0; j < columnsC; j++) {
            temp = (QTextEdit*)(ui->MatrixGrid->itemAtPosition(i, j)->widget());
            mat[i][j] = temp->toPlainText().toInt();
        }
    if (mat[0].size() == mat.size())
        ui->infoLabel->setText(QString("Determinant: %1").arg(QString::number(det(mat))));
    else
        ui->infoLabel->setText(QString("Determinant: Can't calculate"));
    }
}


void lab4Disign::on_saveAsButton_clicked()
{
    QTextEdit *temp;
    path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString(), std::ios::out | std::ios::trunc);
    //qDebug() << rowsC << columnsC;
    file.flush();
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < columnsC; j++) {
            temp = (QTextEdit*)(ui->MatrixGrid->itemAtPosition(i, j)->widget());
            file << temp->toPlainText().toStdString();
            if (j != columnsC - 1)
                 file << " ";
        }
        if (i != rowsC - 1)
            file << std::endl;
    }
    file.close();
}

void lab4Disign::on_setSizeButton_clicked()
{
    rowsC = ui->RowsLine->text().toInt();
    columnsC = ui->ColumnsLine->text().toInt();

    QTextEdit *tempEdit;

    for (size_t i = 0; i < mat.size(); i++)
        for (size_t j = 0; j < mat[0].size(); j++) {
            delete ui->MatrixGrid->itemAtPosition(i, j)->widget();
        }
    mat.resize(rowsC);
    for (int i = 0; i < rowsC; i++) {
        mat[i].resize(columnsC);
        for (int j = 0; j < columnsC; j++) {
            tempEdit = new QTextEdit(QString::number(0));
            tempEdit->setAlignment(Qt::AlignCenter);
            tempEdit->setFont(QFont("Time New Roman", 15));
            ui->MatrixGrid->addWidget(tempEdit, i, j);
        }
    }
}

