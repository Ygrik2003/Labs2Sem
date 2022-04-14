#include "lab4disign.h"
#include "ui_lab4disign.h"

#include <qlist.h>

lab4Disign::lab4Disign(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lab4Disign)
{
    ui->setupUi(this);
    //ui->MatrixGrid->;
}

lab4Disign::~lab4Disign()
{
    delete ui;
}

void lab4Disign::on_saveButton_clicked()
{

}


void lab4Disign::on_openButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString());
    std::fstream fileTemp(path.toStdString());
    int i = 0;
    std::string row;
    while (!file.eof()) {
        getline(file, row);
        rows.push_back(row);
        i++;
    }
    int tempInt;
    int counter;
    std::stringstream ss;
    mat.resize(rows.size());
    for (size_t i = 0; i < rows.size(); i++) {
        ss.clear();
        ss << rows[i];
        counter = 0;
        while (ss.peek() != -1) {
            ss >> tempInt;
            qDebug() << tempInt;
            ui->MatrixGrid->addWidget(new QLabel(QString::number(tempInt)), i, counter);
            counter++;
            mat[i].push_back(tempInt);
        }
    }
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
    if (mat[0].size() == mat.size())
        ui->infoLabel->setText(QString("Size: %1x%2\nDeterminant: %3").arg(QString::number(mat.size()), QString::number(mat.size()), QString::number(det(mat))));
    else
        ui->infoLabel->setText(QString("Size: %1x%2\nDeterminant: Can't calculate").arg(QString::number(mat.size()), QString::number(mat[0].size())));
}


void lab4Disign::on_saveAsButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "", QDir::homePath(), tr("Text files (*.txt)"));
    std::fstream file(path.toStdString());

    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            file << mat[i][j] << " ";
        }
        file << std::endl;
    }

}

