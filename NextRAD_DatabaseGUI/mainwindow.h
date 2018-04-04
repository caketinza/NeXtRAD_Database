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
    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private slots:
    void on_pushButton_clicked();
    
    void on_lineEdit_returnPressed();
    
    void on_comboBox_currentIndexChanged(int index);

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    bool load_trial_data();

    bool load_node_data();

    bool load_pulse_data();

    bool load_target_data();

    bool load_weather_data();

    bool add_trial_data();

    bool add_node_data();

    bool add_pulse_data();

    bool add_target_data();

    bool add_weather_data();

    void on_pushButton_6_clicked();

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_comboBox_23_currentIndexChanged(const QString &arg1);

    void on_comboBox_27_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    bool hasInit;
    int whichTable;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
