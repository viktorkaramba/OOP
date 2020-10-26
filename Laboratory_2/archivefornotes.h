#ifndef ARCHIVEFORNOTES_H
#define ARCHIVEFORNOTES_H

#include <QDialog>
#include <QFile>
#include "note.h"
#include <QTextStream>
namespace Ui {
class archivefornotes;
}

class archivefornotes : public QDialog
{
    Q_OBJECT

public:
    explicit archivefornotes(QWidget *parent = nullptr);
    ~archivefornotes();

private:
    Ui::archivefornotes *ui;
     void load_from_file_archive();
     void add_note_to_table(const Note &note);
};

#endif // ARCHIVEFORNOTES_H
