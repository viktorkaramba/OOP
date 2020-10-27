#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
#include "note.h"
#include "archivefornotes.h"
#include <QTableWidget>
#include <QModelIndex>
#include <QTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Add_Tag_clicked();

    void on_pushButton_clicked();

    void on_Show_Archive_clicked();

    void on_Add_To_Archive_clicked();



    void on_Print_Button_clicked();

    void slot();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    archivefornotes *archive;
    void add_note_to_table(const Note &note);
    void add_tag_to_combobox(const QString &Tag);
    void load_from_file();
    void load_from_file_tags();

};
#endif // MAINWINDOW_H
