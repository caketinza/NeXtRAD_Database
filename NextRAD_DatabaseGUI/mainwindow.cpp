#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QDirIterator>
#include <QDir>
#include <QFileInfo>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    hasInit = false;
    firstSearch = false;

    ui->setupUi(this);

    setWindowTitle("NeXtRAD Database");

    QStringList args;
    args<< "-uroot" << "-pbubsy3726" << "nextrad";
    QProcess process1;
    process1.setStandardInputFile("nextrad.sql");
    process1.start("/usr/bin/mysql",args);
    process1.waitForFinished();

    QString text = QInputDialog::getText(this, tr("MySQL Password"), tr("Please enter your MySQL password:"), QLineEdit::Normal);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("nextrad");
    db.setUserName("root");
    db.setPassword(text);

    if (db.open())
    {
        load_trial_data("SELECT * FROM Trial");
        load_node_data("SELECT * FROM Nodes");
        load_target_data("SELECT * FROM Target");
        load_pulse_data("SELECT * FROM Pulse");
        load_weather_data("SELECT * FROM Weather");
    }
    else
    {
        QMessageBox::warning(this, tr("NeXtRAD Database"), tr("Failed to connect to NeXtRAD Database."));
        qDebug() << "Failed to connect to NeXtRAD Database.";
    }

    ui->tabWidget->setCurrentIndex(0);
    hasInit = true;
    on_pushButton_newSearchRow_clicked();
}

MainWindow::~MainWindow()
{
    QStringList args;
    args<< "-uroot" << "-pbubsy3726" << "nextrad";
    QProcess process;
    process.setStandardOutputFile("nextrad.sql");
    process.start("/usr/bin/mysqldump",args);
    process.waitForFinished();

    db.close();
    delete ui;
}


bool MainWindow::load_trial_data(QString querytext)
{
    ui->tableWidget_trial->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_trial->horizontalHeader();
    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                QString primaryid = query.value(0).toString();
                QString archive = query.value(1).toString();
                QString trialdate = query.value(2).toString();
                QString starttime = query.value(3).toString();
                QString trialloc = query.value(4).toString();
                QString comments = query.value(5).toString();
                QString interference = query.value(6).toString();

                ui->tableWidget_trial->setRowCount(ui->tableWidget_trial->rowCount() + 1);

                QTableWidgetItem* primaryidItem = new QTableWidgetItem(primaryid);
                QTableWidgetItem* archiveItem = new QTableWidgetItem(archive);
                QTableWidgetItem* trialdateItem = new QTableWidgetItem(trialdate);
                QTableWidgetItem* starttimeItem = new QTableWidgetItem(starttime);
                QTableWidgetItem* triallocItem = new QTableWidgetItem(trialloc);
                QTableWidgetItem* commentsItem = new QTableWidgetItem(comments);
                QTableWidgetItem* interferenceItem = new QTableWidgetItem(interference);

                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 0, primaryidItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 1, archiveItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 2, trialdateItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 3, starttimeItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 4, triallocItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 5, commentsItem);
                ui->tableWidget_trial->setItem(ui->tableWidget_trial->rowCount() - 1, 6, interferenceItem);
            }
            header->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool MainWindow::load_node_data(QString querytext)
{
    ui->tableWidget_nodes->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_nodes->horizontalHeader();

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                QString foreignid = query.value(0).toString();
                QString node0lat = QString::number(query.value(1).toDouble());
                QString node0lon = QString::number(query.value(2).toDouble());
                QString node0ht = QString::number(query.value(3).toDouble());
                QString node1lat = QString::number(query.value(4).toDouble());
                QString node1lon = QString::number(query.value(5).toDouble());
                QString node1ht = QString::number(query.value(6).toDouble());
                QString node2lat = QString::number(query.value(7).toDouble());
                QString node2lon = QString::number(query.value(8).toDouble());
                QString node2ht = QString::number(query.value(9).toDouble());
                QString DTGbearing = query.value(10).toString();
                QString node0range = QString::number(query.value(11).toDouble());
                QString node0bearing = QString::number(query.value(12).toDouble());
                QString node1range = QString::number(query.value(13).toDouble());
                QString node1bearing = QString::number(query.value(14).toDouble());
                QString node2range = QString::number(query.value(15).toDouble());
                QString node2bearing = QString::number(query.value(16).toDouble());
                QString bistatic01 = QString::number(query.value(17).toDouble());
                QString bistatic02 = QString::number(query.value(18).toDouble());
                QString bistatic12 = QString::number(query.value(19).toDouble());

                ui->tableWidget_nodes->setRowCount(ui->tableWidget_nodes->rowCount() + 1);

                QTableWidgetItem* foreignidItem = new QTableWidgetItem(foreignid);
                QTableWidgetItem* node0latItem = new QTableWidgetItem(node0lat);
                QTableWidgetItem* node0lonItem = new QTableWidgetItem(node0lon);
                QTableWidgetItem* node0htItem = new QTableWidgetItem(node0ht);
                QTableWidgetItem* node1latItem = new QTableWidgetItem(node1lat);
                QTableWidgetItem* node1lonItem = new QTableWidgetItem(node1lon);
                QTableWidgetItem* node1htItem = new QTableWidgetItem(node1ht);
                QTableWidgetItem* node2latItem = new QTableWidgetItem(node2lat);
                QTableWidgetItem* node2lonItem = new QTableWidgetItem(node2lon);
                QTableWidgetItem* node2htItem = new QTableWidgetItem(node2ht);
                QTableWidgetItem* DTGbearingItem = new QTableWidgetItem(DTGbearing);
                QTableWidgetItem* node0rangeItem = new QTableWidgetItem(node0range);
                QTableWidgetItem* node0bearingItem = new QTableWidgetItem(node0bearing);
                QTableWidgetItem* node1rangeItem = new QTableWidgetItem(node1range);
                QTableWidgetItem* node1bearingItem = new QTableWidgetItem(node1bearing);
                QTableWidgetItem* node2rangeItem = new QTableWidgetItem(node2range);
                QTableWidgetItem* node2bearingItem = new QTableWidgetItem(node2bearing);
                QTableWidgetItem* bistatic01Item = new QTableWidgetItem(bistatic01);
                QTableWidgetItem* bistatic02Item = new QTableWidgetItem(bistatic02);
                QTableWidgetItem* bistatic12Item = new QTableWidgetItem(bistatic12);

                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 0, foreignidItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 1, node0latItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 2, node0lonItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 3, node0htItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 4, node1latItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 5, node1lonItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 6, node1htItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 7, node2latItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 8, node2lonItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 9, node2htItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 10, DTGbearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 11, node0rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 12, node0bearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 13, node1rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 14, node1bearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 15, node2rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 16, node2bearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 17, bistatic01Item);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 18, bistatic02Item);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 19, bistatic12Item);
            }
            header->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool MainWindow::load_target_data(QString querytext)
{
    ui->tableWidget_target->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_target->horizontalHeader();

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                QString foreignid = query.value(0).toString();
                QString tgtloclat = QString::number(query.value(1).toDouble());
                QString tgtloclon = QString::number(query.value(2).toDouble());
                QString tgtlocht = QString::number(query.value(3).toDouble());
                QString tgttype = query.value(4).toString();
                QString tgtarea = QString::number(query.value(5).toDouble());
                QString tgtspeed = QString::number(query.value(6).toDouble());

                ui->tableWidget_target->setRowCount(ui->tableWidget_target->rowCount() + 1);

                QTableWidgetItem* foreignidItem = new QTableWidgetItem(foreignid);
                QTableWidgetItem* tgtloclatItem = new QTableWidgetItem(tgtloclat);
                QTableWidgetItem* tgtloclonItem = new QTableWidgetItem(tgtloclon);
                QTableWidgetItem* tgtlochtItem = new QTableWidgetItem(tgtlocht);
                QTableWidgetItem* tgttypeItem = new QTableWidgetItem(tgttype);
                QTableWidgetItem* tgtareaItem = new QTableWidgetItem(tgtarea);
                QTableWidgetItem* tgtspeedItem = new QTableWidgetItem(tgtspeed);

                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 0, foreignidItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 1, tgtloclatItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 2, tgtloclonItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 3, tgtlochtItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 4, tgttypeItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 5, tgtareaItem);
                ui->tableWidget_target->setItem(ui->tableWidget_target->rowCount() - 1, 6, tgtspeedItem);
            }
            header->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool MainWindow::load_pulse_data(QString querytext)
{
    ui->tableWidget_pulse->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_pulse->horizontalHeader();

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                QString foreignid = query.value(0).toString();
                QString waveform = query.value(1).toString();
                QString numPRIs = query.value(2).toString();
                QString PRIsamples = query.value(3).toString();
                QString DACdelay = query.value(4).toString();
                QString ADCdelay = query.value(5).toString();
                QString polorder = query.value(6).toString();
                QString PRI = query.value(7).toString();
                QString prepulse = query.value(8).toString();
                QString lbandfreq = query.value(9).toString();
                QString xbandfreq = query.value(10).toString();

                ui->tableWidget_pulse->setRowCount(ui->tableWidget_pulse->rowCount() + 1);

                QTableWidgetItem* foreignidItem = new QTableWidgetItem(foreignid);
                QTableWidgetItem* waveformItem = new QTableWidgetItem(waveform);
                QTableWidgetItem* numPRIsItem = new QTableWidgetItem(numPRIs);
                QTableWidgetItem* PRIsamplesItem = new QTableWidgetItem(PRIsamples);
                QTableWidgetItem* DACdelayItem = new QTableWidgetItem(DACdelay);
                QTableWidgetItem* ADCdelayItem = new QTableWidgetItem(ADCdelay);
                QTableWidgetItem* polorderItem = new QTableWidgetItem(polorder);
                QTableWidgetItem* PRIItem = new QTableWidgetItem(PRI);
                QTableWidgetItem* prepulseItem = new QTableWidgetItem(prepulse);
                QTableWidgetItem* lbandfreqItem = new QTableWidgetItem(lbandfreq);
                QTableWidgetItem* xbandfreqItem = new QTableWidgetItem(xbandfreq);

                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 0, foreignidItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 1, waveformItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 2, numPRIsItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 3, PRIsamplesItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 4, DACdelayItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 5, ADCdelayItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 6, polorderItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 7, PRIItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 8, prepulseItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 9, lbandfreqItem);
                ui->tableWidget_pulse->setItem(ui->tableWidget_pulse->rowCount() - 1, 10, xbandfreqItem);
            }
            header->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool MainWindow::load_weather_data(QString querytext)
{
    ui->tableWidget_weather->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_weather->horizontalHeader();

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                QString foreignid = query.value(0).toString();
                QString seastate = QString::number(query.value(1).toDouble());
                QString windspeed = QString::number(query.value(2).toDouble());
                QString winddir = QString::number(query.value(3).toDouble());
                QString waveht = QString::number(query.value(4).toDouble());
                QString wavedir = QString::number(query.value(5).toDouble());
                QString waveper = QString::number(query.value(6).toDouble());
                QString airtemp = QString::number(query.value(7).toDouble());
                QString airpress = QString::number(query.value(8).toDouble());

                ui->tableWidget_weather->setRowCount(ui->tableWidget_weather->rowCount() + 1);

                QTableWidgetItem* foreignidItem = new QTableWidgetItem(foreignid);
                QTableWidgetItem* seastateItem = new QTableWidgetItem(seastate);
                QTableWidgetItem* windspeedItem = new QTableWidgetItem(windspeed);
                QTableWidgetItem* winddirItem = new QTableWidgetItem(winddir);
                QTableWidgetItem* wavehtItem = new QTableWidgetItem(waveht);
                QTableWidgetItem* wavedirItem = new QTableWidgetItem(wavedir);
                QTableWidgetItem* waveperItem = new QTableWidgetItem(waveper);
                QTableWidgetItem* airtempItem = new QTableWidgetItem(airtemp);
                QTableWidgetItem* airpressItem = new QTableWidgetItem(airpress);

                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 0, foreignidItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 1, seastateItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 2, windspeedItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 3, winddirItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 4, wavehtItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 5, wavedirItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 6, waveperItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 7, airtempItem);
                ui->tableWidget_weather->setItem(ui->tableWidget_weather->rowCount() - 1, 8, airpressItem);
            }
            header->setSectionResizeMode(QHeaderView::Stretch);
        }
        else
        {
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return true;
}


void MainWindow::on_pushButton_loadFile_clicked()
{
    hasInit = false;
    //choose a file
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose File"), "/home/caitlin", tr("Header Files(*.ini)"));
    ui->lineEdit->setText(filename);

    QStringList temp  = filename.split('/');
    QString newfolderpath;
    for (int i = 0; i < temp.length() - 3; i++)
    {
        newfolderpath = newfolderpath + temp.at(i) + "/";
    }
    newfolderpath = newfolderpath + "Data_Sorted";
    QDir dir(newfolderpath);
    if (!dir.exists())
    {
        QDir().mkpath(newfolderpath);
    }

    QString fk_id = add_trial_data(filename, newfolderpath);
    add_node_data(filename, fk_id);
    add_target_data(filename, fk_id);
    add_pulse_data(filename, fk_id);
    add_weather_data(filename, fk_id);

    load_trial_data("SELECT * FROM Trial");
    load_node_data("SELECT * FROM Nodes");
    load_target_data("SELECT * FROM Target");
    load_pulse_data("SELECT * FROM Pulse");
    load_weather_data("SELECT * FROM Weather");

    ui->lineEdit->clear();
    hasInit = true;
    ui->pushButton_loadFile->clearFocus();
}

void MainWindow::on_pushButton_loadFiles_clicked()
{
    hasInit = false;
    //choose directory
    QString folderpath = QFileDialog::getExistingDirectory(0, ("Choose Folder"), "/home/caitlin");
    ui->lineEdit->setText(folderpath);

    QString newfolderpath = folderpath + "_Sorted";
    QDir dirtemp(newfolderpath);
    if (!dirtemp.exists())
    {
        QDir().mkpath(newfolderpath);
    }

    QDir dir(folderpath);

    if (!dir.exists())
    {
        qWarning("The directory does not exist");
    }

    QDirIterator qdir(dir.absolutePath(), QStringList() << "*.ini", QDir::NoSymLinks | QDir::Files, QDirIterator::Subdirectories);

    while (qdir.hasNext())
    {
        QString filename = qdir.next();

        QString fk_id = add_trial_data(filename, newfolderpath);
        add_node_data(filename, fk_id);
        add_target_data(filename, fk_id);
        add_pulse_data(filename, fk_id);
        add_weather_data(filename, fk_id);

    }

    load_trial_data("SELECT * FROM Trial");
    load_node_data("SELECT * FROM Nodes");
    load_target_data("SELECT * FROM Target");
    load_pulse_data("SELECT * FROM Pulse");
    load_weather_data("SELECT * FROM Weather");

    ui->lineEdit->clear();
    hasInit = true;
}

void MainWindow::organise_files(QString archivename, QString filename, QString newfolderpath)
{
    QString archive = newfolderpath + "/" + archivename;
    QDir archivedir(archive);
    if (!archivedir.exists())
    {
        QDir().mkpath(archive);
    }

    QStringList temp = filename.split('/');

    QString oldpath;
    for (int i = 0;  i < (temp.length() - 3); i++)
    {
        oldpath = oldpath + temp.at(i) + "/";
    }

    QString oldfolder = temp.at(temp.length() - 2);
    QString newfolder = archivename + oldfolder.right(3);

    QDir origindir(filename.left(filename.lastIndexOf('/')));
    if (origindir.exists())
    {
        QDir destdir(archive + "/" + newfolder);
        if (!destdir.exists())
        {
            QDir().mkpath(archive + "/" + newfolder);
            foreach (QString fileName, origindir.entryList(QDir::Files))
            {
                if (fileName.right(3) == "ini")
                {
                    QFile::copy(filename.left(filename.lastIndexOf('/')) + "/" + fileName, archive + "/" + fileName);
                }
                else
                {
                    QFile::copy(filename.left(filename.lastIndexOf('/')) + "/" + fileName, archive + "/" + newfolder + "/" + fileName);
                }
            }
        }
    }
}


QString MainWindow::add_trial_data(QString filename, QString newfolderpath)
{
    //load a file into the database
    QSettings settings(filename, QSettings::IniFormat);

    //load timings into Trial table
    settings.beginGroup("Timing");
    QStringList timkeys = settings.allKeys();

    QStringList timKeys, timValues;

    foreach (const QString &childKey, timkeys)
    {
        timKeys << childKey;
        timValues << settings.value(childKey).toString();
    }

    QString year = timValues.at(timKeys.indexOf("YEAR", 0));
    QString month = timValues.at(timKeys.indexOf("MONTH", 0));
    QString day = timValues.at(timKeys.indexOf("DAY", 0));
    QString hour = timValues.at(timKeys.indexOf("HOUR", 0));
    QString min = timValues.at(timKeys.indexOf("MINUTE", 0));
    QString sec = timValues.at(timKeys.indexOf("SECOND", 0));

    QString archivename = year + "_" + month + "_" + day + "_" + hour + "_" + min + "_" + sec;
    QString trialdate = year + "-" + month + "-" + day;
    QString starttime = hour + ":" + min + ":" + sec;

    settings.endGroup();

    QSqlQuery query;

    if (query.exec("INSERT INTO Trial (ArchiveName, TrialDate, StartTime, TrialLocation, Comments) VALUES ('" + archivename + "','" + trialdate + "','" + starttime + "','" + "-" + "','" +"-"+ "')"))
    {
        QMessageBox::information(this, "Update Success", "Trial data added to database.");
    }
    else
    {
        qDebug() << query.lastError().text();
        switch(QMessageBox::warning(this, "Duplicate Record", "This trial data has already been added.\nWould you like to overwrite the previous version?", "Cancel", "Yes",0,0,1))
        {
        case 0:
            break;
        case 1:
            if (query.exec("UPDATE Trial SET TrialDate = '" + trialdate + "', StartTime = '" + starttime + "' WHERE ArchiveName = '" + archivename + "';"))
            {
                QMessageBox::information(this, "Update Success", "Trial data updated.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
            break;
        }
    }

    QString fk_id;
    if (query.exec("SELECT pk_id FROM Trial WHERE ArchiveName = '" + archivename + "';"))
    {
        while (query.next())
        {
            qDebug() << query.value(0);

            fk_id = query.value(0).toString();
        }
    }
    else
    {
        qDebug() << query.lastError().text();
    }

    organise_files(archivename, filename, newfolderpath);

    return fk_id;
}

void MainWindow::add_node_data(QString filename, QString fk_id)
{
    //load a file into the database
    QSettings settings(filename, QSettings::IniFormat);

    //load geometry and bearings into Nodes table
    settings.beginGroup("GeometrySettings");
    QStringList geomkeys = settings.allKeys();
    QStringList geomKeys, geomValues;

    foreach (const QString &childKey, geomkeys)
    {
        geomKeys << childKey;
        if (settings.value(childKey).toString() ==  "")
        {
            geomValues << QString::number(NULL);
        }
        else
        {
            geomValues << settings.value(childKey).toString();
        }
    }

    QString node0lat = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_LAT", 0));
    QString node0lon = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_LON", 0));
    QString node0ht = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_HT", 0));
    QString node1lat = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_LAT", 0));
    QString node1lon = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_LON", 0));
    QString node1ht = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_HT", 0));
    QString node2lat = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_LAT", 0));
    QString node2lon = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_LON", 0));
    QString node2ht = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_HT", 0));
    settings.endGroup();

    settings.beginGroup("Bearings");
    QStringList bearkeys = settings.allKeys();
    QStringList bearKeys, bearValues;

    foreach (const QString &childKey, bearkeys)
    {
        bearKeys << childKey;
        if (settings.value(childKey).toString() ==  "")
        {
            bearValues << QString::number(NULL);
        }
        else
        {
            bearValues << settings.value(childKey).toString();
        }
    }

    QString dtg = bearValues.at(bearKeys.indexOf("DTG", 0));
    QString node0rng = bearValues.at(bearKeys.indexOf("NODE0_RANGE", 0));
    QString node0bear = bearValues.at(bearKeys.indexOf("NODE0_BEARING", 0));
    QString node1rng = bearValues.at(bearKeys.indexOf("NODE1_RANGE", 0));
    QString node1bear = bearValues.at(bearKeys.indexOf("NODE1_BEARING", 0));
    QString node2rng = bearValues.at(bearKeys.indexOf("NODE2_RANGE", 0));
    QString node2bear = bearValues.at(bearKeys.indexOf("NODE2_BEARING", 0));

    settings.endGroup();

    QString bistatic0_1, bistatic0_2, bistatic1_2;
    int temp1, temp2, temp3;

    temp1 = node1bear.toInt() - node0bear.toInt();
    temp2 = node2bear.toInt() - node0bear.toInt();
    temp3 = node2bear.toInt() - node1bear.toInt();

    if (temp1 < 0)
    {
        temp1 = temp1 + 360;
    }
    if (temp2 < 0)
    {
        temp2 = temp2 + 360;
    }
    if (temp3 < 0)
    {
        temp3 = temp3 + 360;
    }

    bistatic0_1 = QString::number(temp1);
    bistatic0_2 = QString::number(temp2);
    bistatic1_2 = QString::number(temp3);

    QSqlQuery query;
    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Nodes where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            switch(QMessageBox::warning(this, "Duplicate Record", "This node data has already been added.\nWould you like to overwrite the previous version?", "Cancel", "Yes",0,0,1))
            {
            case 0:
                break;
            case 1:
                if (query.exec("UPDATE Nodes SET Node0LocationLat = '" + node0lat + "', Node0LocationLon = '" + node0lon + "', Node0LocationHt = '" + node0ht
                               + "', Node1LocationLat = '" + node1lat + "', Node1LocationLon = '" + node1lon + "', Node1LocationHt = '" + node1ht
                               + "', Node2LocationLat = '" + node2lat + "', Node2LocationLon = '" + node2lon + "', Node2LocationHt = '" + node2ht
                               + "', DTGOfBearing = '" + dtg + "', Node0Range = '" + node0rng + "', Node0Bearing = '" + node0bear + "', Node1Range = '" + node1rng
                               + "', Node1Bearing = '" + node1bear + "', Node2Range = '" + node2rng + "', Node2Bearing = '" + node2bear + "', BistaticAngle0_1 = '"
                               + bistatic0_1 + "', BistaticAngle0_2 = '" + bistatic0_2 + "', BistaticAngle1_2 = '" + bistatic1_2 + "' WHERE fk_id = '" + fk_id + "';"))
                {
                    QMessageBox::information(this, "Update Success", "Node data updated.");
                }
                else
                {
                    qDebug() << query.lastError().text();
                }
                break;
            }
        }
        else
        {
            if (query.exec("INSERT INTO Nodes (fk_id, Node0LocationLat, Node0LocationLon, Node0LocationHt, Node1LocationLat, Node1LocationLon, Node1LocationHt, "
                           "Node2LocationLat, Node2LocationLon, Node2LocationHt, DTGOfBearing, Node0Range, Node0Bearing, Node1Range, Node1Bearing, "
                           "Node2Range, Node2Bearing, BistaticAngle0_1, BistaticAngle0_2, BistaticAngle1_2) VALUES ('" + fk_id + "','" + node0lat + "','" + node0lon
                           + "','" + node0ht + "','" + node1lat + "','" + node1lon + "','" + node1ht + "','" + node2lat + "','" + node2lon + "','" + node2ht + "','"
                           + dtg + "','" + node0rng + "','" + node0bear + "','" + node1rng + "','" + node1bear + "','" + node2rng + "','" + node2bear
                           + "','" + bistatic0_1 + "','" + bistatic0_2 + "','" + bistatic1_2 + "')"))
            {
                QMessageBox::information(this, "Update Success", "Node data added to database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::add_pulse_data(QString filename, QString fk_id)
{
    //load a file into the database
    QSettings settings(filename, QSettings::IniFormat);

    //load pulses in Pulse table
    settings.beginGroup("PulseParameters");
    QStringList pulsekeys = settings.allKeys();
    QStringList pulseKeys, pulseValues;

    foreach (const QString &childKey, pulsekeys)
    {
        pulseKeys << childKey;
        if (settings.value(childKey).toString() ==  "")
        {
            pulseValues << QString::number(NULL);
        }
        else
        {
            pulseValues << settings.value(childKey).toString();
        }
    }

    QString wave = pulseValues.at(pulseKeys.indexOf("WAVEFORM_INDEX", 0));
    QString numPRI = pulseValues.at(pulseKeys.indexOf("NUM_PRIS", 0));
    QString samples = pulseValues.at(pulseKeys.indexOf("SAMPLES_PER_PRI", 0));
    QString dacdelay = pulseValues.at(pulseKeys.indexOf("DAC_DELAY", 0));
    QString adcdelay = pulseValues.at(pulseKeys.indexOf("ADC_DELAY", 0));
    QString polorder = pulseValues.at(pulseKeys.indexOf("POL_ORDER", 0));
    QString PRI = pulseValues.at(pulseKeys.indexOf("PRI", 0));
    QString prepulse = pulseValues.at(pulseKeys.indexOf("PRE_PULSE", 0));
    QString lbandf = pulseValues.at(pulseKeys.indexOf("L_BAND_WAVEFORM_FREQ", 0));
    QString xbandf = pulseValues.at(pulseKeys.indexOf("X_BAND_WAVEFORM_FREQ", 0));

    settings.endGroup();

    QSqlQuery query;
    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Pulse where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            switch(QMessageBox::warning(this, "Duplicate Record", "This pulse data has already been added.\nWould you like to overwrite the previous version?", "Cancel", "Yes",0,0,1))
            {
            case 0:
                break;
            case 1:
                if (query.exec("UPDATE Pulse SET Waveform = '" + wave + "', NumOfPRIs = '" + numPRI + "', SamplesPerPRI = '" + samples + "', DACDelay = '" + dacdelay
                               + "', ADCDelay = '" + adcdelay + "', PolOrder = '" + polorder + "', PRI = '" + PRI + "', PrePulse = '" + prepulse + "', LBandWaveformFreq = '" + lbandf
                               + "', XBandWaveformFreq = '" + xbandf + "' WHERE fk_id = '" + fk_id + "';"))
                {
                    QMessageBox::information(this, "Update Success", "Pulse data updated.");
                }
                else
                {
                    qDebug() << query.lastError().text();
                }
                break;
            }
        }
        else
        {
            if (query.exec("INSERT INTO Pulse (fk_id, Waveform, NumOfPRIs, SamplesPerPRI, DACDelay, ADCDelay, PolOrder, PRI, PrePulse, LBandWaveformFreq, XBandWaveformFreq) "
                           "VALUES ('" + fk_id + "','" + wave + "','" + numPRI + "','" + samples + "','" + dacdelay + "','" + adcdelay + "','" + polorder + "','" +
                           PRI + "','" + prepulse + "','" + lbandf + "','" + xbandf + "');"))
            {
                QMessageBox::information(this, "Update Success", "Pulse data added to database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::add_target_data(QString filename, QString fk_id)
{
    //load a file into the database
    QSettings settings(filename, QSettings::IniFormat);

    //load target in Target table
    settings.beginGroup("TargetSettings");
    QStringList tgtkeys = settings.allKeys();
    QStringList tgtKeys, tgtValues;

    foreach (const QString &childKey, tgtkeys)
    {
        tgtKeys << childKey;
        if (settings.value(childKey).toString() ==  "")
        {
            tgtValues << QString::number(NULL);
        }
        else
        {
            tgtValues << settings.value(childKey).toString();
        }
    }

    QString tgtlat = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LAT", 0));
    QString tgtlon = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LON", 0));
    QString tgtht = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_HT", 0));

    settings.endGroup();

    QSqlQuery query;
    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Target where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            switch(QMessageBox::warning(this, "Duplicate Record", "This target data has already been added.\nWould you like to overwrite the previous version?", "Cancel", "Yes",0,0,1))
            {
            case 0:
                break;
            case 1:
                if (query.exec("UPDATE Target SET TgtLocationLat = '" + tgtlat + "', TgtLocationLon = '" + tgtlon + "', TgtLocationHt = '" + tgtht + "' WHERE fk_id = '" + fk_id + "';"))
                {
                    QMessageBox::information(this, "Update Success", "Target data updated.");
                }
                else
                {
                    qDebug() << query.lastError().text();
                }
                break;
            }
        }
        else
        {
            if (query.exec("INSERT INTO Target (fk_id, TgtLocationLat, TgtLocationLon, TgtLocationHt) VALUES ('" + fk_id + "','" + tgtlat + "','" + tgtlon + "','" + tgtht + "');"))
            {
                QMessageBox::information(this, "Update Success", "Target data added to database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::add_weather_data(QString filename, QString fk_id)
{
    //load a file into the database
    QSettings settings(filename, QSettings::IniFormat);

    //load weather in Weather table
    settings.beginGroup("Weather");
    QStringList weatherkeys = settings.allKeys();
    QStringList weatherKeys, weatherValues;

    foreach (const QString &childKey, weatherkeys)
    {
        weatherKeys << childKey;
        if (settings.value(childKey).toString() ==  "")
        {
            weatherValues << QString::number(NULL);
        }
        else
        {
            weatherValues << settings.value(childKey).toString();
        }
    }

    QString seastate = weatherValues.at(weatherKeys.indexOf("DOUGLAS_SEA_STATE", 0));
    QString windspd = weatherValues.at(weatherKeys.indexOf("WIND_SPEED", 0));
    QString winddir = weatherValues.at(weatherKeys.indexOf("WIND_DIR", 0));
    QString waveht = weatherValues.at(weatherKeys.indexOf("WAVE_HEIGHT", 0));
    QString wavedir = weatherValues.at(weatherKeys.indexOf("WAVE_DIR", 0));
    QString waveper = weatherValues.at(weatherKeys.indexOf("WAVE_PERIOD", 0));
    QString airtemp = weatherValues.at(weatherKeys.indexOf("AIR_TEMPERATURE", 0));
    QString airpress = weatherValues.at(weatherKeys.indexOf("AIR_PRESSURE", 0));

    settings.endGroup();

    QSqlQuery query;
    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Weather where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            switch(QMessageBox::warning(this, "Duplicate Record", "This weather data has already been added.\nWould you like to overwrite the previous version?", "Cancel", "Yes",0,0,1))
            {
            case 0:
                break;
            case 1:
                if (query.exec("UPDATE Weather SET DouglasSeaState = '" + seastate + "', WindSpeed = '" + windspd + "', WindDir = '" + winddir + "', WaveHeight = '" + waveht
                               + "', WaveDir = '" + wavedir + "', WavePeriod = '" + waveper + "', AirTemperature = '" + airtemp + "', AirPressure = '" + airpress
                               + "' WHERE fk_id = '" + fk_id + "';"))
                {
                    QMessageBox::information(this, "Update Success", "Weather data updated.");
                }
                else
                {
                    qDebug() << query.lastError().text();
                }
                break;
            }
        }
        else
        {
            if (query.exec("INSERT INTO Weather (fk_id, DouglasSeaState, WindSpeed, WindDir, WaveHeight, WaveDir, WavePeriod, AirTemperature, AirPressure) VALUES ('" +
                           fk_id + "','" + seastate + "','" + windspd + "','" + winddir + "','" + waveht + "','" + wavedir + "','" + waveper + "','" + airtemp + "','" + airpress + "');"))
            {
                QMessageBox::information(this, "Update Success", "Weather data added to database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}


void MainWindow::on_pushButton_newSearchRow_clicked()
{
    if (firstSearch == true) {
        QAndOrBar *andorbar = new QAndOrBar();
        ui->verticalLayout_3->addWidget(andorbar);
    }
    firstSearch = true;

    QSearchBar *searchbar = new QSearchBar();
    ui->verticalLayout_3->addWidget(searchbar);

    connect(searchbar->button, SIGNAL(clicked()), this, SLOT(slotDeleteRow()));
    connect(searchbar->combobox1, SIGNAL(currentTextChanged(QString)), this, SLOT(slotIndexChange(QString)));
}

void MainWindow::on_pushButton_search_clicked()
{
    QStringList tables, fields, equators, values, joiners;
    for (int i = 0; i < ui->verticalLayout_3->count(); i++)
    {
        if (i%2 == 0)
        {
            QSearchBar *searchbar = qobject_cast<QSearchBar*>(ui->verticalLayout_3->itemAt(i)->widget());
            tables << searchbar->combobox1->currentText();
            fields << searchbar->combobox2->currentText();
            equators << searchbar->combobox3->currentText();
            values << searchbar->lineedit->text();
        }
        else if (i%2 == 1)
        {
            QAndOrBar *andorbar = qobject_cast<QAndOrBar*>(ui->verticalLayout_3->itemAt(i)->widget());
            joiners << andorbar->combobox->currentText();
        }
    }
    joiners << "AND";
    QString querytext;
    querytext = "SELECT * FROM " + tables.at(0) + " WHERE ";

    for (int i = 0; i < tables.length(); i++)
    {
        querytext = querytext + "(" + fields.at(i) + equators.at(i) + "'" + values.at(i) + "') " + joiners.at(i);
    }

    querytext.truncate(querytext.lastIndexOf(QChar(')')) + 1);

    if (tables.at(0) == "Trial")
    {
        hasInit = false;
        load_trial_data(querytext);
        hasInit = true;
    }
    else if (tables.at(0) == "Nodes")
    {
        hasInit = false;
        load_node_data(querytext);
        hasInit = true;
    }
    else if (tables.at(0) == "Target")
    {
        hasInit = false;
        load_target_data(querytext);
        hasInit = true;
    }
    else if (tables.at(0) == "Pulse")
    {
        hasInit = false;
        load_pulse_data(querytext);
        hasInit = true;
    }
    else if (tables.at(0) == "Weather")
    {
        hasInit = false;
        load_weather_data(querytext);
        hasInit = true;
    }
}

void MainWindow::on_pushButton_clearSearch_clicked()
{
    int total = ui->verticalLayout_3->count();
    for (int i = 0; i < total; i++)
    {
        if (i%2 == 1)
        {
            QAndOrBar *andorbar = qobject_cast<QAndOrBar*>(ui->verticalLayout_3->itemAt(total - (i + 1))->widget());
            delete andorbar;
        }
        else if (i%2 == 0)
        {
            QSearchBar *searchbar = qobject_cast<QSearchBar*>(ui->verticalLayout_3->itemAt(total - (i + 1))->widget());
            delete searchbar;
        }
    }

    QSearchBar *searchbar = new QSearchBar();
    searchbar->resetID();

    QAndOrBar *andorbar = new QAndOrBar();
    andorbar->resetID();

    hasInit = false;
    load_trial_data("SELECT * FROM Trial");
    load_node_data("SELECT * FROM Nodes");
    load_target_data("SELECT * FROM Target");
    load_pulse_data("SELECT * FROM Pulse");
    load_weather_data("SELECT * FROM Weather");
    hasInit = true;
    firstSearch = false;
    on_pushButton_newSearchRow_clicked();
}

void MainWindow::slotGetButtonNumber()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    ui->lineEdit->setText(QString::number(button->getID()));
}

void MainWindow::slotDeleteRow()
{
    QDynamicButton *button = (QDynamicButton*) sender();
    int buttonNo = button->getID();
    int searchNo, andorNo;

    if (buttonNo == 1)
    {
        searchNo = 1;
        andorNo = 1;
    }
    else
    {
        searchNo = buttonNo;
        andorNo = buttonNo - 1;
    }

    int total = ui->verticalLayout_3->count();
    for (int i = 0; i < total; i++)
    {
        if (i%2 == 0)
        {
            QSearchBar *searchbar = qobject_cast<QSearchBar*>(ui->verticalLayout_3->itemAt(total - (i+1))->widget());
            if (searchbar->getID() == searchNo)
            {
                delete searchbar;
            }
        }
        else if (i%2 == 1)
        {
            QAndOrBar *andorbar = qobject_cast<QAndOrBar*>(ui->verticalLayout_3->itemAt(total - (i+1))->widget());
            if (andorbar->getID() == andorNo)
            {
                delete andorbar;
            }
        }
    }
}

void MainWindow::slotIndexChange(QString text)
{
    QDynamicComboBox *combobox = (QDynamicComboBox*) sender();
    int comboboxNo = combobox->getID();
    int rowNo;
    if (comboboxNo <= 5)
    {
        rowNo = comboboxNo/3 + 1;
    }
    else
    {
        rowNo = comboboxNo/3;
    }
    int total = ui->verticalLayout_3->count();
    for (int i = 0; i < total; i++)
    {
        if (i%2 == 0)
        {
            QSearchBar *searchbar = qobject_cast<QSearchBar*>(ui->verticalLayout_3->itemAt(i)->widget());
            if (searchbar->getID() == rowNo)
            {
                QStringList fieldlist;
                if (text == "Trial")
                {
                    fieldlist << "ArchiveName" << "TrialDate" << "StartTime" << "TrialLocation" << "Comments" << "Interference";
                }
                else if (text == "Nodes")
                {
                    fieldlist << "Node0LocationLat" << "Node0LocationLon" << "Node0LocationHt" << "Node1LocationLat" << "Node1LocationLon" << "Node1LocationHt"
                             << "Node2LocationLat" << "Node2LocationLon" << "Node2LocationHt" << "DTGOfBearing" << "Node0Range" << "Node0Bearing"
                             << "Node1Range" << "Node1Bearing" << "Node2Range" << "Node2Bearing" << "BistaticAngle0_1" << "BistaticAngle0_2" << "BistaticAngle1_2";
                }
                else if (text == "Target")
                {
                    fieldlist << "TargetLocationLat" << "TargetLocationLon" << "TargetLocationHt" << "TgtType" << "TgtAre" << "TgtSpeed";
                }
                else if (text == "Pulse")
                {
                    fieldlist << "Waveform" << "NumOfPRIs" << "SamplesPerPRI" << "DACDelay" << "ADCDelay" << "PolOrder" << "PRI" << "PrePulse" << "LBandWaveformFreq" << "XBandWaveformFreq";
                }
                else if (text == "Weather")
                {
                    fieldlist << "DouglasSeaState" << "WindSpeed" << "WindDir" << "WaveHeight" << "WaveDir" << "WavePeriod" << "AirTemperature" << "AirPressure";
                }

                searchbar->combobox2->clear();
                searchbar->combobox2->addItems(fieldlist);
            }
        }
    }
}


void MainWindow::on_tableWidget_trial_doubleClicked()
{
    ui->tableWidget_trial->resizeColumnsToContents();
}

void MainWindow::on_tableWidget_nodes_doubleClicked()
{
    ui->tableWidget_nodes->resizeColumnsToContents();
}

void MainWindow::on_tableWidget_target_doubleClicked()
{
    ui->tableWidget_target->resizeColumnsToContents();
}

void MainWindow::on_tableWidget_pulse_doubleClicked()
{
    ui->tableWidget_pulse->resizeColumnsToContents();
}

void MainWindow::on_tableWidget_weather_doubleClicked()
{
    ui->tableWidget_weather->resizeColumnsToContents();
}


void MainWindow::on_tableWidget_trial_itemChanged(QTableWidgetItem *item)
{
    if (hasInit == true) {
        QString field = ui->tableWidget_trial->horizontalHeaderItem(item->column())->text();
        QString pk_id = ui->tableWidget_trial->item(item->row(), 0)->data(0).toString();
        QString value = ui->tableWidget_trial->item(item->row(), item->column())->data(0).toString();

        switch(QMessageBox::warning(this, "Change Value", "You are about to change a value in the database.\nDo you want to continue?", "Cancel", "OK"))
        {
        case 0:
            hasInit = false;
            load_trial_data("SELECT * FROM Trial");
            hasInit = true;
            break;
        case 1:
            QSqlQuery query;
            if (query.exec("UPDATE Trial SET " + field + " = '" + value + "' WHERE pk_id = '" + pk_id + "';"))
            {
                QMessageBox::information(this, "Update Success", "Value updated in database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::on_tableWidget_nodes_itemChanged(QTableWidgetItem *item)
{
    if (hasInit == true) {
        QString field = ui->tableWidget_nodes->horizontalHeaderItem(item->column())->text();
        QString fk_id = ui->tableWidget_nodes->item(item->row(), 0)->data(0).toString();
        QString value = ui->tableWidget_nodes->item(item->row(), item->column())->data(0).toString();

        switch(QMessageBox::warning(this, "Change Value", "You are about to change a value in the database.\nDo you want to continue?", "Cancel", "OK"))
        {
        case 0:
            hasInit = false;
            load_trial_data("SELECT * FROM Nodes");
            hasInit = true;
            break;
        case 1:
            QSqlQuery query;
            if (query.exec("UPDATE Nodes SET " + field + " = '" + value + "' WHERE fk_id = '" + fk_id + "';"))
            {
                QMessageBox::information(this, "Update Success", "Value updated in database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::on_tableWidget_target_itemChanged(QTableWidgetItem *item)
{
    if (hasInit == true) {
        QString field = ui->tableWidget_target->horizontalHeaderItem(item->column())->text();
        QString fk_id = ui->tableWidget_target->item(item->row(), 0)->data(0).toString();
        QString value = ui->tableWidget_target->item(item->row(), item->column())->data(0).toString();

        switch(QMessageBox::warning(this, "Change Value", "You are about to change a value in the database.\nDo you want to continue?", "Cancel", "OK"))
        {
        case 0:
            hasInit = false;
            load_trial_data("SELECT * FROM Target");
            hasInit = true;
            break;
        case 1:
            QSqlQuery query;
            if (query.exec("UPDATE Target SET " + field + " = '" + value + "' WHERE fk_id = '" + fk_id + "';"))
            {
                QMessageBox::information(this, "Update Success", "Value updated in database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::on_tableWidget_pulse_itemChanged(QTableWidgetItem *item)
{
    if (hasInit == true) {
        QString field = ui->tableWidget_pulse->horizontalHeaderItem(item->column())->text();
        QString fk_id = ui->tableWidget_pulse->item(item->row(), 0)->data(0).toString();
        QString value = ui->tableWidget_pulse->item(item->row(), item->column())->data(0).toString();

        switch(QMessageBox::warning(this, "Change Value", "You are about to change a value in the database.\nDo you want to continue?", "Cancel", "OK"))
        {
        case 0:
            hasInit = false;
            load_trial_data("SELECT * FROM Pulse");
            hasInit = true;
            break;
        case 1:
            QSqlQuery query;
            if (query.exec("UPDATE Pulse SET " + field + " = '" + value + "' WHERE fk_id = '" + fk_id + "';"))
            {
                QMessageBox::information(this, "Update Success", "Value updated in database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}

void MainWindow::on_tableWidget_weather_itemChanged(QTableWidgetItem *item)
{
    if (hasInit == true) {
        QString field = ui->tableWidget_weather->horizontalHeaderItem(item->column())->text();
        QString fk_id = ui->tableWidget_weather->item(item->row(), 0)->data(0).toString();
        QString value = ui->tableWidget_weather->item(item->row(), item->column())->data(0).toString();

        switch(QMessageBox::warning(this, "Change Value", "You are about to change a value in the database.\nDo you want to continue?", "Cancel", "OK"))
        {
        case 0:
            hasInit = false;
            load_trial_data("SELECT * FROM Weather");
            hasInit = true;
            break;
        case 1:
            QSqlQuery query;
            if (query.exec("UPDATE Weather SET " + field + " = '" + value + "' WHERE fk_id = '" + fk_id + "';"))
            {
                QMessageBox::information(this, "Update Success", "Value updated in database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }
}
