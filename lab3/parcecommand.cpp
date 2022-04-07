#include "parcecommand.h"

#include <QString>

ParceCommand::ParceCommand()
{

}

QPair<QChar, int> ParceCommand::getCommand(QString &commands)
{
    QPair<QChar, int> command;
    int i = 0;
    QString num;
    //int posNum = 0;
    while (commands[i] != ']') {
        if (commands[i] == 'W') {
            command.first = 'W';
            i = i + 2;
        } else if (commands[i] == 'S') {
            command.first = 'S';
            i = i + 2;
        } else if (commands[i] == 'A') {
            command.first = 'A';
            i = i + 2;
        } else if (commands[i] == 'D') {
            command.first = 'D';
            i = i + 2;
        } else if (commands[i] != '[') {
            num += commands[i];
            i++;
            continue;
        }
        i++;
    }
    command.second = num.toInt();
    if (commands.length() != i) {
        commands.remove(0, i + 3);
    } else {
        commands.remove(0, i);
    }
    return command;
}
