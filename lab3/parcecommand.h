#ifndef PARCECOMMAND_H
#define PARCECOMMAND_H

#include <QChar>
#include <QPair>



class ParceCommand
{
public:
    ParceCommand();
    QPair<QChar, int> getCommand(QString &);
};

#endif // PARCECOMMAND_H
