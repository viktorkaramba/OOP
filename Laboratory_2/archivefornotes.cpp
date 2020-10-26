#include "archivefornotes.h"
#include "ui_archivefornotes.h"

archivefornotes::archivefornotes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::archivefornotes)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,35);
    ui->tableWidget->setColumnWidth(1,170);
    ui->tableWidget->setColumnWidth(2,195);
    ui->tableWidget->setColumnWidth(3,115);
    ui->tableWidget->setColumnWidth(4,350);
    load_from_file_archive();
}

archivefornotes::~archivefornotes()
{
    delete ui;
}

void archivefornotes::load_from_file_archive()
{
    QFile file{"Archive_Of_Notes.txt"};
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    QTextStream in(&file);
    int cur = 0;
    int row = 1;
    Note current_note;
    while(!in.atEnd()){
        QString line = in.readLine();
        switch(cur){
        case 0:
            current_note.setNum(row);
            break;

        case 1:
            current_note.setTime_input(line);
            break;

        case 2:
            current_note.setTime_deadline(line);
            break;

        case 3:
            current_note.setTag(line);
            break;
        case 4:
            current_note.setTask(line);
            break;

        case 5:
            cur =-1;
            row++;
            add_note_to_table(current_note);
            break;
        }
        cur++;
    }
    file.close();
}

void archivefornotes::add_note_to_table(const Note &note)
{
    int rows = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(rows+1);
    QTableWidgetItem* item = new QTableWidgetItem(QString::number(note.getNum()));
    ui->tableWidget->setItem(rows,0,item);
    item = new QTableWidgetItem(note.getTime_input());
    ui->tableWidget->setItem(rows,1,item);
    item = new QTableWidgetItem(note.getTime_deadline());
    ui->tableWidget->setItem(rows,2,item);
    item = new QTableWidgetItem(note.getTag());
    ui->tableWidget->setItem(rows,3,item);
    item = new QTableWidgetItem(note.getTask());
    ui->tableWidget->setItem(rows,4,item);

}
