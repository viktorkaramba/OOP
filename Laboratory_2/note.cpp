#include "note.h"
#include "ui_note.h"
#include "mainwindow.h"

QString Note::getTime_input() const
{
    return time_input;
}

void Note::setTime_input(const QString &value)
{
    time_input = value;
}




int Note::getNum() const
{
    return num;
}

void Note::setNum(int value)
{
    num = value;
}



QString Note::getTag() const
{
    return tag;
}

void Note::setTag(const QString &value)
{
    tag = value;
}

Note::Note(){
    
}




QString Note::getTime_deadline() const
{
    return time_deadline;
}

void Note::setTime_deadline(const QString &value)
{
    time_deadline = value;
}

QString Note::getTask() const
{
    return task;
}

void Note::setTask(const QString &value)
{
    task = value;
}

