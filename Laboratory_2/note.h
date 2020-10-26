#ifndef NOTE_H
#define NOTE_H

#include <QDialog>
#include <QString>
#include <QDateTime>
#include <QRadioButton>
#include <QCheckBox>
class Note
{
private:
    int num;
    QString time_input;
    QString time_deadline;
    QString tag;
    QString task;

public:
    Note();
    explicit Note(const int &n,
                  const QString &Time_input,
                  const QString &Time_deadline,
                  const QString &Tag,
                  const QString &Task
                  ):
    num(n),time_input(Time_input),time_deadline(Time_deadline),tag(Tag), task(Task){}
    QString getTime_input() const;
    void setTime_input(const QString &value);
    QString getTime_deadline() const;
    void setTime_deadline(const QString &value);
    QString getTask() const;
    void setTask(const QString &value);
    int getNum() const;
    void setNum(int value);

    QString getTag() const;
    void setTag(const QString &value);
};

#endif // NOTE_H
