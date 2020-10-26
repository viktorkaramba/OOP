#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "note.h"
#include "archivefornotes.h"
#include <QTableWidget>
#include <QModelIndex>
#include <QPrinter>
#include <QPrintDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime time= QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(time);
    ui->tableWidget->setColumnWidth(0,20);
    ui->tableWidget->setColumnWidth(1,185);
    ui->tableWidget->setColumnWidth(2,185);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,300);
    load_from_file();
    load_from_file_tags();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_Tag_clicked()
{
    QString T = ui->Text_Tag->text();
    add_tag_to_combobox(T);
    QFile file{"Tags.txt"};
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;
    QTextStream stream_1(&file);
    stream_1<<T<<"\n";
    file.close();
    ui->Text_Tag->clear();
}
void MainWindow::add_tag_to_combobox(const QString &T)
{
    ui->comboBox->addItem(T);
    ui->listWidget->addItem(T);
}
void MainWindow::load_from_file_tags()
{
    QFile file{"Tags.txt"};
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QString tag;
    int cur = 0;
    while(!in.atEnd()){
        QString line = in.readLine();
        switch(cur){
        case 0:
            cur = -1;
            add_tag_to_combobox(line);
            break;
        }
        cur++;
    }
    file.close();
}
void MainWindow::on_pushButton_clicked()
{
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh::mm::ss");
    int rows = ui->tableWidget->rowCount();

    Note note{rows+1,
             time,
             ui->dateTimeEdit->dateTime().toString(),
             ui->comboBox->currentText(),
             ui->Text_Task->text()
            };

    add_note_to_table(note);
    QFile file{"Notes.txt"};
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;
    QTextStream stream(&file);
        stream<<note.getNum()<<"\n"
              <<note.getTime_input()<<"\n"
              <<note.getTime_deadline()<<"\n"
              <<note.getTag()<<"\n"
              <<note.getTask()<<"\n\n";
        file.close();
         QFile file_1{"Notes_1.txt"};
        if(!file_1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;
        QTextStream t(&file_1);
            t<<note.getTag()<<"\n"
                  <<note.getTime_input()<<"\n"
                  <<note.getTime_deadline()<<"\n"
                  <<note.getNum()<<"\n"
                  <<note.getTask()<<"\n\n";
            file_1.close();
            ui->Text_Task->clear();
}


void MainWindow::add_note_to_table(const Note& note)
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



void MainWindow::load_from_file()
{
    QFile file{"Notes.txt"};
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
            cur = -1;
            row ++;
            add_note_to_table(current_note);
            break;
        }
        cur++;
    }
    file.close();
}




void MainWindow::on_Show_Archive_clicked()
{
    archive = new archivefornotes(this);
    archive->show();
}

void MainWindow::on_Add_To_Archive_clicked()
{
    if(ui->label->text() == "TextLabel"){
        QMessageBox::about(this,"Warning","Before adding an entry to the archive, first click on the entry number and then on the button.");
    }
    else{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedIndexes();
    while (!selectedRows.empty()) {
        ui->tableWidget->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
    QString index = ui->label->text();
    QFile f("Notes.txt");
    QFile f1("Notes_1.txt");
    if(f.open(QIODevice::ReadWrite | QIODevice::Text))
        if(f1.open(QIODevice::ReadWrite | QIODevice::Text))
        {
    {
        QString s;
        Note current_note;
         Note current_note_1;
        int cur = 0;
        int row = 1;
        int row_1 = 1;
        QTextStream t(&f);
         QTextStream t1(&f1);
        while(!t.atEnd())
        {
            QString line = t.readLine();
            if(current_note.getNum() != index.toInt()){
                switch(cur){
                case 0:
                    current_note.setNum(row);
                    current_note_1.setNum(row);
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
                    current_note_1.setTask(line);
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
                    t1<<current_note_1.getTag()<<"\n"
                          <<current_note_1.getTime_input()<<"\n"
                          <<current_note_1.getTime_deadline()<<"\n"
                          <<current_note_1.getNum()<<"\n"
                          <<current_note_1.getTask()<<"\n\n";
                    break;
                }
                cur++;

            }
            else{
                QFile file_2{"Archive_Of_Notes.txt"};
                if(!file_2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream stream(&file_2);
                switch(cur){
                case 0:
                    current_note.setNum(row_1);
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
                    row_1++;
                    stream<<current_note.getNum()<<"\n"
                          <<current_note.getTime_input()<<"\n"
                          <<current_note.getTime_deadline()<<"\n"
                          <<current_note.getTag()<<"\n"
                          <<current_note.getTask()<<"\n\n";
                    file_2.close();
                    break;
                }
                cur++;

            }
        }
            f.resize(0);
            f1.resize(0);
            t << s;
            f.close();
            f1.close();
    }
        }
}
    load_from_file();
}


void MainWindow::on_pushButton_2_clicked()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();
    ui->label->setText(itm->text());
}



void MainWindow::on_Print_Button_clicked()
{
     QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning","To add records to a document, select all the rows you want to transfer in the table.",
                        QMessageBox::Ok| QMessageBox::Cancel);
     if(reply == QMessageBox::Cancel){
        QApplication::quitOnLastWindowClosed();
     }
     else{
     QTextEdit *note = new QTextEdit;
     QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedIndexes();
     for (int i = 0; i < selectedRows.size(); i++){
          QString s = selectedRows [i].data().toString();
         note->append(s);
     }
    QPrinter printer;
    printer.setPrinterName("Printer for notes");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Accepted) {
    note->print(&printer);
    }
     }
}



void MainWindow::on_pushButton_3_clicked()
{

    QString s = ui->listWidget->currentItem()->text();
    QFile f{"Notes_1.txt"};
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
        Note current_note;
        int cur = 0;
        //int row = 1;
         //int row_1 = 1;
        QTextStream t(&f);
        while(!t.atEnd())
        {
             int counter = 0;
            QString line = t.readLine();
            if(current_note.getTag() == s){
                counter++;
                switch(cur){
                case 0:
                    current_note.setTag(line);
                    break;
                case 1:
                    current_note.setTime_input(line);
                    break;
                case 2:
                    current_note.setTime_deadline(line);
                    break;
                case 3:
                    current_note.setNum(line.toInt());
                    break;
                case 4:
                    current_note.setTask(line);
                    break;
                case 5:
                    cur = -1;
                    //row++;
                    add_note_to_table(current_note);
                    counter = 0;
                    break;
                }
                cur++;

            }
            else{
                QFile file_2{"Trash.txt"};
                file_2.remove();
                if(!file_2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                    return;
                QTextStream stream(&file_2);
                switch(cur){
                case 0:
                    current_note.setTag(line);
                    break;
                case 1:
                    current_note.setTime_input(line);
                    break;
                case 2:
                    current_note.setTime_deadline(line);
                    break;
                case 3:
                    current_note.setNum(line.toInt());
                    break;
                case 4:
                    current_note.setTask(line);
                    break;
                case 5:
                    cur = -1;
                   // row_1++;
                    stream<<current_note.getNum()<<"\n"
                          <<current_note.getTime_input()<<"\n"
                          <<current_note.getTime_deadline()<<"\n"
                          <<current_note.getTag()<<"\n"
                          <<current_note.getTask()<<"\n\n";
                    file_2.close();
                    break;
                }
                cur++;

            }
        }
        f.close();

}
void MainWindow::on_pushButton_4_clicked()
{
    load_from_file();
}
