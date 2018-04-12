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



    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_comboBox_23_currentIndexChanged(const QString &arg1);

    void on_comboBox_27_currentIndexChanged(const QString &arg1);

    void on_pushButton_search_clicked();

    void on_pushButton_loadFiles_clicked();

    void on_pushButton_loadFile_clicked();

    void on_pushButton_newSearchRow_clicked();

private:
    Ui::MainWindow *ui;
    bool hasInit;
    int whichTable;
    QString valueChoice0, valueChoice1, valueChoice2, valueChoice3, valueChoice4;
    QString fieldChoice0, fieldChoice1, fieldChoice2, fieldChoice3, fieldChoice4;
    QString tableChoice0, tableChoice1, tableChoice2, tableChoice3, tableChoice4;
    QString equatorChoice0, equatorChoice1, equatorChoice2, equatorChoice3, equatorChoice4;
    QString andor0, andor1;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
