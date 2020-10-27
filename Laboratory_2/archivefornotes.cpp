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

void archivefornotes::on_pushButton_clicked()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();
    QString label;
    label = itm->text();
    if(!itm->isSelected()){
       QMessageBox::about(this,"Warning","Before adding an entry to the archive, first click on the entry number and then on the button.");
    }
    else{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedIndexes();
    while (!selectedRows.empty()) {
        ui->tableWidget->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
    QFile f("Archive_Of_Notes.txt");
    QFile f1("Notes_1.txt");
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                QString s;
                Note current_note;
                int cur = 0;
                QTextStream t(&f);
                QTextStream t1(&f1);
                int row = 1;
                while(!t.atEnd())
                {
                    QString line = t.readLine();
                    if(current_note.getNum() != label.toInt()){
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
                            cur = -1;
                            row++;
                            t<<current_note.getNum()<<"\n"
                            <<current_note.getTime_input()<<"\n"
                            <<current_note.getTime_deadline()<<"\n"
                            <<current_note.getTag()<<"\n"
                            <<current_note.getTask()<<"\n\n";
                            break;
                        }
                        cur++;
                    }
                    else if (current_note.getNum() == label.toInt()){
                        QFile file_2("Notes.txt");
                         QFile f1("Notes_1.txt");
                        if(!file_2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                            return;
                        if(!f1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                            return;
                        QTextStream stream(&file_2);
                         QTextStream t1(&f1);
                        Note current_note_1;
                        switch(cur){
                        case 0:
                            current_note.setNum(line.toInt());
                            current_note_1.setNum(line.toInt());
                            break;
                        case 1:
                            current_note.setTime_input(line);
                            current_note_1.setTime_input(line);
                            break;
                        case 2:
                            current_note.setTime_deadline(line);
                            current_note_1.setTime_deadline(line);
                            break;
                        case 3:
                            current_note.setTag(line);
                            current_note_1.setTag(line);
                            break;
                        case 4:
                            current_note.setTask(line);
                            current_note_1.setTask(line);
                            break;
                        case 5:
                            cur = -1;
                            stream<<current_note.getNum()<<"\n"
                                 <<current_note.getTime_input()<<"\n"
                                <<current_note.getTime_deadline()<<"\n"
                               <<current_note.getTag()<<"\n"
                              <<current_note.getTask()<<"\n\n";
                            t1<<current_note_1.getTag()<<"\n"
                             <<current_note_1.getTime_input()<<"\n"
                            <<current_note_1.getTime_deadline()<<"\n"
                            <<current_note_1.getNum()<<"\n"
                            <<current_note_1.getTask()<<"\n\n";
                            file_2.close();
                            f1.close();
                            break;
                        }
                        cur++;

                    }
                }
                f.resize(0);
                t << s;
                f.close();

            }

    }
    load_from_file_archive();
    emit note_to_table();

}
