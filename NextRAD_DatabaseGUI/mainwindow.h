#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>
#include <QSettings>
#include <QProcess>
#include <QDirIterator>

#include <qsearchbar.h>
#include <qandorbar.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:    
    bool load_trial_data(QString querytext);

    bool load_node_data(QString querytext);

    bool load_pulse_data(QString querytext);

    bool load_target_data(QString querytext);

    bool load_weather_data(QString querytext);

    QString add_trial_data(QString filename);

    void add_node_data(QString filename, QString fk_id);

    void add_pulse_data(QString filename, QString fk_id);

    void add_target_data(QString filename, QString fk_id);

    void add_weather_data(QString filename, QString fk_id);

    void on_pushButton_loadFiles_clicked();

    void on_pushButton_loadFile_clicked();

    void slotGetButtonNumber();

    void slotDeleteRow();

    void slotIndexChange(QString text);


    void on_pushButton_search_clicked();

    void on_pushButton_newSearchRow_clicked();

    void on_pushButton_clearSearch_clicked();


    void on_tableWidget_trial_doubleClicked(const QModelIndex &index);

    void on_tableWidget_nodes_doubleClicked(const QModelIndex &index);

    void on_tableWidget_target_doubleClicked(const QModelIndex &index);

    void on_tableWidget_pulse_doubleClicked(const QModelIndex &index);

    void on_tableWidget_weather_doubleClicked(const QModelIndex &index);

    void on_tableWidget_trial_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_nodes_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_target_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_pulse_itemChanged(QTableWidgetItem *item);

    void on_tableWidget_weather_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    bool hasInit;
    bool firstSearch = false;

    QString valueChoice0, valueChoice1, valueChoice2, valueChoice3, valueChoice4;
    QString fieldChoice0, fieldChoice1, fieldChoice2, fieldChoice3, fieldChoice4;
    QString tableChoice0, tableChoice1, tableChoice2, tableChoice3, tableChoice4;
    QString equatorChoice0, equatorChoice1, equatorChoice2, equatorChoice3, equatorChoice4;
    QString andor0, andor1;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
