#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QDirIterator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    hasInit = false;
    whichTable = 0;

    ui->setupUi(this);

    setWindowTitle("NeXtRAD Database");

    QStringList args;
    args<< "-uroot" << "-pbubsy3726" << "nextrad" << "<" << "/home/caitlin/Documents/MSc/NeXtRAD_Database/nextrad.sql";
    QProcess process1;
    process1.setStandardOutputFile("nextrad.sql");
    process1.start("/usr/bin/mysql",args);
    process1.waitForFinished();

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("nextrad");
    db.setUserName("root");
    db.setPassword("bubsy3726");

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
        qDebug() << "Failed to connect to NeXtRAD Database.";
    }
}

MainWindow::~MainWindow()
{
    QStringList args;
    args<< "-uroot" << "-pbubsy3726" << "nextrad";
    QProcess process;
    process.setStandardOutputFile("nextrad.sql");
    process.start("/usr/bin/mysqldump",args);
    process.waitForFinished();
    QFile::copy("/home/caitlin/build-NextRAD_DatabaseGUI-Desktop-Debug/nextrad.sql", "/home/caitlin/Documents/MSc/NeXtRAD_Database/nextrad.sql");

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
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4) << query.value(5) << query.value(6);

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
    //still need to add bistatic angles when added to mysql
    ui->tableWidget_nodes->setRowCount(0);
    QHeaderView* header =  ui->tableWidget_nodes->horizontalHeader();

    if (db.open())
    {
        QSqlQuery query;
        if (query.exec(querytext))
        {
            while (query.next())
            {
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4) << query.value(5) << query.value(6)
                         << query.value(7) << query.value(8) << query.value(9) << query.value(10) << query.value(11) << query.value(12) << query.value(13)
                         << query.value(14) << query.value(15) << query.value(16) << query.value(17);

                QString foreignid = query.value(0).toString();
                QString node0lat = query.value(1).toString();
                QString node0lon = query.value(2).toString();
                QString node0ht = query.value(3).toString();
                QString node1lat = query.value(4).toString();
                QString node1lon = query.value(5).toString();
                QString node1ht = query.value(6).toString();
                QString node2lat = query.value(7).toString();
                QString node2lon = query.value(8).toString();
                QString node2ht = query.value(9).toString();
                QString DTGbearing = query.value(10).toString();
                QString basebisect = query.value(11).toString();
                QString node0range = query.value(12).toString();
                QString node0bearing = query.value(13).toString();
                QString node1range = query.value(14).toString();
                QString node1bearing = query.value(15).toString();
                QString node2range = query.value(16).toString();
                QString node2bearing = query.value(17).toString();

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
                QTableWidgetItem* basebisectItem = new QTableWidgetItem(basebisect);
                QTableWidgetItem* node0rangeItem = new QTableWidgetItem(node0range);
                QTableWidgetItem* node0bearingItem = new QTableWidgetItem(node0bearing);
                QTableWidgetItem* node1rangeItem = new QTableWidgetItem(node1range);
                QTableWidgetItem* node1bearingItem = new QTableWidgetItem(node1bearing);
                QTableWidgetItem* node2rangeItem = new QTableWidgetItem(node2range);
                QTableWidgetItem* node2bearingItem = new QTableWidgetItem(node2bearing);

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
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 11, basebisectItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 12, node0rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 13, node0bearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 14, node1rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 15, node1bearingItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 16, node2rangeItem);
                ui->tableWidget_nodes->setItem(ui->tableWidget_nodes->rowCount() - 1, 17, node2bearingItem);
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
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4) << query.value(5) << query.value(6);

                QString foreignid = query.value(0).toString();
                QString tgtloclat = query.value(1).toString();
                QString tgtloclon = query.value(2).toString();
                QString tgtlocht = query.value(3).toString();
                QString tgttype = query.value(4).toString();
                QString tgtarea = query.value(5).toString();
                QString tgtspeed = query.value(6).toString();

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
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4) << query.value(5)
                         << query.value(6) << query.value(7) << query.value(8) << query.value(9) << query.value(10);

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
                qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(4)
                         << query.value(5) << query.value(6) << query.value(7) << query.value(8);

                QString foreignid = query.value(0).toString();
                QString seastate = query.value(1).toString();
                QString windspeed = query.value(2).toString();
                QString winddir = query.value(3).toString();
                QString waveht = query.value(4).toString();
                QString wavedir = query.value(5).toString();
                QString waveper = query.value(6).toString();
                QString airtemp = query.value(7).toString();
                QString airpress = query.value(8).toString();

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
    //choose a file
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose File"), "/home/caitlin", tr("Header Files(*.ini);;Text Files (*.txt)"));
    ui->lineEdit->setText(filename);



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

    QString archivename = year + "-" + month + "-" + day + "_" + hour + ":" + min + ":" + sec;
    QString trialdate = year + "-" + month + "-" + day;
    QString starttime = hour + ":" + min + ":" + sec;

    settings.endGroup();

    QSqlQuery query;
    if (query.exec("INSERT INTO Trial (ArchiveName, TrialDate, StartTime) VALUES ('" + archivename + "','" + trialdate + "','" + starttime + "')"))
    {
        QMessageBox::information(this, "Update Success", "Trial data added to database.");
    }
    else
    {
        qDebug() << query.lastError().text();
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


    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Nodes where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            QMessageBox::warning(this, "Duplicate Data", "Node data previously added to database.");
        }
        else
        {
            //load geometry and bearings into Nodes table
            settings.beginGroup("GeometrySettings");
            QStringList geomkeys = settings.allKeys();
            QStringList geomKeys, geomValues;

            foreach (const QString &childKey, geomkeys)
            {
                geomKeys << childKey;
                geomValues << settings.value(childKey).toString();
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
                bearValues << settings.value(childKey).toString();
            }

            QString dtg = bearValues.at(bearKeys.indexOf("DTG", 0));
            QString basebi = bearValues.at(bearKeys.indexOf("BASELINE_BISECTOR", 0));
            QString node0rng = bearValues.at(bearKeys.indexOf("NODE0_RANGE", 0));
            QString node0bear = bearValues.at(bearKeys.indexOf("NODE0_BEARING", 0));
            QString node1rng = bearValues.at(bearKeys.indexOf("NODE1_RANGE", 0));
            QString node1bear = bearValues.at(bearKeys.indexOf("NODE1_BEARING", 0));
            QString node2rng = bearValues.at(bearKeys.indexOf("NODE2_RANGE", 0));
            QString node2bear = bearValues.at(bearKeys.indexOf("NODE2_BEARING", 0));

            settings.endGroup();

            if (query.exec("INSERT INTO Nodes (fk_id, Node0LocationLat, Node0LocationLon, Node0LocationHt, Node1LocationLat, Node1LocationLon, Node1LocationHt, "
                           "Node2LocationLat, Node2LocationLon, Node2LocationHt, DTGOfBearing, BaselineBisector, Node0Range, Node0Bearing, Node1Range, Node1Bearing, "
                           "Node2Range, Node2Bearing) VALUES ('" + fk_id + "','" + node0lat + "','" + node0lon + "','" + node0ht + "','" + node1lat + "','" +
                           node1lon + "','" + node1ht + "','" + node2lat + "','" + node2lon + "','" + node2ht + "','" + dtg + "','" + basebi + "','" +
                           node0rng + "','" + node0bear + "','" + node1rng + "','" + node1bear + "','" + node2rng + "','" + node2bear + "')"))
            {
                QMessageBox::information(this, "Update Success", "Node data added to database.");
            }
            else
            {
                qDebug() << query.lastError().text();
            }
        }
    }


    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Target where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            QMessageBox::warning(this, "Duplicate Data", "Target data previously added to database.");
        }
        else
        {
            //load target in Target table
            settings.beginGroup("TargetSettings");
            QStringList tgtkeys = settings.allKeys();
            QStringList tgtKeys, tgtValues;

            foreach (const QString &childKey, tgtkeys)
            {
                tgtKeys << childKey;
                tgtValues << settings.value(childKey).toString();
            }

            QString tgtlat = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LAT", 0));
            QString tgtlon = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LON", 0));
            QString tgtht = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_HT", 0));


            settings.endGroup();

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


    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Pulse where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            QMessageBox::warning(this, "Duplicate Data", "Pulse data previously added to database.");
        }
        else
        {
            //load pulses in Pulse table
            settings.beginGroup("PulseParameters");
            QStringList pulsekeys = settings.allKeys();
            QStringList pulseKeys, pulseValues;

            foreach (const QString &childKey, pulsekeys)
            {
                pulseKeys << childKey;
                pulseValues << settings.value(childKey).toString();
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


    //previously been loaded check
    if (query.exec("SELECT fk_id FROM Weather where fk_id = '" + fk_id + "'"))
    {
        query.next();
        if (query.value(0).toString() == fk_id)
        {
            QMessageBox::warning(this, "Duplicate Data", "Weather data previously added to database.");
        }
        else
        {
            //load weather in Weather table
            settings.beginGroup("Weather");
            QStringList weatherkeys = settings.allKeys();
            QStringList weatherKeys, weatherValues;

            foreach (const QString &childKey, weatherkeys)
            {
                weatherKeys << childKey;
                weatherValues << settings.value(childKey).toString();
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

    ui->lineEdit->clear();

}

void MainWindow::on_pushButton_loadFiles_clicked()
{
    //choose directory
    QStringList help;
    QDirIterator it("/home/caitlin/Downloads/Data", QStringList() << "*.ini", QDir::NoFilter, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        help << it.next();

        QString filename = it.next();
        //ui->label_testing->setText(filename+" =   " + ui->label_testing->text());

//        QSettings settings(filename, QSettings::IniFormat);

//        settings.beginGroup("Timing");
//        QStringList timkeys = settings.allKeys();

//        QStringList timKeys, timValues;

//        foreach (const QString &childKey, timkeys)
//        {
//            timKeys << childKey;
//            timValues << settings.value(childKey).toString();
//        }

//        QString year = timValues.at(timKeys.indexOf("YEAR", 0));
//        QString month = timValues.at(timKeys.indexOf("MONTH", 0));
//        QString day = timValues.at(timKeys.indexOf("DAY", 0));
//        QString hour = timValues.at(timKeys.indexOf("HOUR", 0));
//        QString min = timValues.at(timKeys.indexOf("MINUTE", 0));
//        QString sec = timValues.at(timKeys.indexOf("SECOND", 0));

//        QString archivename = year + "-" + month + "-" + day + "_" + hour + ":" + min + ":" + sec;
//        QString trialdate = year + "-" + month + "-" + day;
//        QString starttime = hour + ":" + min + ":" + sec;

//        settings.endGroup();

//        QSqlQuery query;
//        if (query.exec("INSERT INTO Trial (ArchiveName, TrialDate, StartTime) VALUES ('" + archivename + "','" + trialdate + "','" + starttime + "')"))
//        {
//            QMessageBox::information(this, "Update Success", "Trial data added to database.");
//        }
//        else
//        {
//            qDebug() << query.lastError().text();
//        }


    }


//    //choose a file
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose File"), "/home/caitlin", tr("Header Files(*.ini);;Text Files (*.txt)"));
//    ui->lineEdit->setText(fileName);

//    //load a file into the database
//    QSettings settings(fileName, QSettings::IniFormat);


//    //load timings into Trial table
//    settings.beginGroup("Timing");
//    QStringList timkeys = settings.allKeys();

//    QStringList timKeys, timValues;

//    foreach (const QString &childKey, timkeys)
//    {
//        timKeys << childKey;
//        timValues << settings.value(childKey).toString();
//    }

//    QString year = timValues.at(timKeys.indexOf("YEAR", 0));
//    QString month = timValues.at(timKeys.indexOf("MONTH", 0));
//    QString day = timValues.at(timKeys.indexOf("DAY", 0));
//    QString hour = timValues.at(timKeys.indexOf("HOUR", 0));
//    QString min = timValues.at(timKeys.indexOf("MINUTE", 0));
//    QString sec = timValues.at(timKeys.indexOf("SECOND", 0));

//    QString archivename = year + "-" + month + "-" + day + "_" + hour + ":" + min + ":" + sec;
//    QString trialdate = year + "-" + month + "-" + day;
//    QString starttime = hour + ":" + min + ":" + sec;

//    settings.endGroup();

//    QSqlQuery query;
//    if (query.exec("INSERT INTO Trial (ArchiveName, TrialDate, StartTime) VALUES ('" + archivename + "','" + trialdate + "','" + starttime + "')"))
//    {
//        QMessageBox::information(this, "Update Success", "Trial data added to database.");
//    }
//    else
//    {
//        qDebug() << query.lastError().text();
//    }


//    QString fk_id;
//    if (query.exec("SELECT pk_id FROM Trial WHERE ArchiveName = '" + archivename + "';"))
//    {
//        while (query.next())
//        {
//            qDebug() << query.value(0);

//            fk_id = query.value(0).toString();
//        }
//    }
//    else
//    {
//        qDebug() << query.lastError().text();
//    }

//    //previously been loaded check
//    if (query.exec("SELECT fk_id FROM Nodes where fk_id = '" + fk_id + "'"))
//    {
//        query.next();
//        if (query.value(0).toString() == fk_id)
//        {
//            ui->label_testing->setText("duplicate");
//            QMessageBox::warning(this, "Duplicate Data", "Node data previously added to database.");
//        }
//        else
//        {
//            ui->label_testing->setText("not duplicate");
//            //load geometry and bearings into Nodes table
//            settings.beginGroup("GeometrySettings");
//            QStringList geomkeys = settings.allKeys();
//            QStringList geomKeys, geomValues;

//            foreach (const QString &childKey, geomkeys)
//            {
//                geomKeys << childKey;
//                geomValues << settings.value(childKey).toString();
//            }

//            QString node0lat = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_LAT", 0));
//            QString node0lon = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_LON", 0));
//            QString node0ht = geomValues.at(geomKeys.indexOf("NODE0_LOCATION_HT", 0));
//            QString node1lat = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_LAT", 0));
//            QString node1lon = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_LON", 0));
//            QString node1ht = geomValues.at(geomKeys.indexOf("NODE1_LOCATION_HT", 0));
//            QString node2lat = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_LAT", 0));
//            QString node2lon = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_LON", 0));
//            QString node2ht = geomValues.at(geomKeys.indexOf("NODE2_LOCATION_HT", 0));
//            settings.endGroup();

//            settings.beginGroup("Bearings");
//            QStringList bearkeys = settings.allKeys();
//            QStringList bearKeys, bearValues;

//            foreach (const QString &childKey, bearkeys)
//            {
//                bearKeys << childKey;
//                bearValues << settings.value(childKey).toString();
//            }

//            QString dtg = bearValues.at(bearKeys.indexOf("DTG", 0));
//            QString basebi = bearValues.at(bearKeys.indexOf("BASELINE_BISECTOR", 0));
//            QString node0rng = bearValues.at(bearKeys.indexOf("NODE0_RANGE", 0));
//            QString node0bear = bearValues.at(bearKeys.indexOf("NODE0_BEARING", 0));
//            QString node1rng = bearValues.at(bearKeys.indexOf("NODE1_RANGE", 0));
//            QString node1bear = bearValues.at(bearKeys.indexOf("NODE1_BEARING", 0));
//            QString node2rng = bearValues.at(bearKeys.indexOf("NODE2_RANGE", 0));
//            QString node2bear = bearValues.at(bearKeys.indexOf("NODE2_BEARING", 0));

//            settings.endGroup();

//            if (query.exec("INSERT INTO Nodes (fk_id, Node0LocationLat, Node0LocationLon, Node0LocationHt, Node1LocationLat, Node1LocationLon, Node1LocationHt, "
//                           "Node2LocationLat, Node2LocationLon, Node2LocationHt, DTGOfBearing, BaselineBisector, Node0Range, Node0Bearing, Node1Range, Node1Bearing, "
//                           "Node2Range, Node2Bearing) VALUES ('" + fk_id + "','" + node0lat + "','" + node0lon + "','" + node0ht + "','" + node1lat + "','" +
//                           node1lon + "','" + node1ht + "','" + node2lat + "','" + node2lon + "','" + node2ht + "','" + dtg + "','" + basebi + "','" +
//                           node0rng + "','" + node0bear + "','" + node1rng + "','" + node1bear + "','" + node2rng + "','" + node2bear + "')"))
//            {
//                QMessageBox::information(this, "Update Success", "Node data added to database.");
//            }
//            else
//            {
//                qDebug() << query.lastError().text();
//            }
//        }
//    }


//    //previously been loaded check
//    if (query.exec("SELECT fk_id FROM Target where fk_id = '" + fk_id + "'"))
//    {
//        query.next();
//        if (query.value(0).toString() == fk_id)
//        {
//            ui->label_testing->setText("duplicate");
//            QMessageBox::warning(this, "Duplicate Data", "Target data previously added to database.");
//        }
//        else
//        {
//            ui->label_testing->setText("not duplicate");

//            //load target in Target table
//            settings.beginGroup("TargetSettings");
//            QStringList tgtkeys = settings.allKeys();
//            QStringList tgtKeys, tgtValues;

//            foreach (const QString &childKey, tgtkeys)
//            {
//                tgtKeys << childKey;
//                tgtValues << settings.value(childKey).toString();
//            }

//            QString tgtlat = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LAT", 0));
//            QString tgtlon = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_LON", 0));
//            QString tgtht = tgtValues.at(tgtKeys.indexOf("TGT_LOCATION_HT", 0));

//            settings.endGroup();

//            if (query.exec("INSERT INTO Target (fk_id, TgtLocationLat, TgtLocationLon, TgtLocationHt) VALUES ('" + fk_id + "','" + tgtlat + "','" + tgtlon + "','" + tgtht + "');"))
//            {
//                QMessageBox::information(this, "Update Success", "Target data added to database.");
//            }
//            else
//            {
//                qDebug() << query.lastError().text();
//            }
//        }
//    }


//    //previously been loaded check
//    if (query.exec("SELECT fk_id FROM Pulse where fk_id = '" + fk_id + "'"))
//    {
//        query.next();
//        if (query.value(0).toString() == fk_id)
//        {
//            ui->label_testing->setText("duplicate");
//            QMessageBox::warning(this, "Duplicate Data", "Pulse data previously added to database.");
//        }
//        else
//        {
//            ui->label_testing->setText("not duplicate");

//            //load pulses in Pulse table
//            settings.beginGroup("PulseParameters");
//            QStringList pulsekeys = settings.allKeys();
//            QStringList pulseKeys, pulseValues;

//            foreach (const QString &childKey, pulsekeys)
//            {
//                pulseKeys << childKey;
//                pulseValues << settings.value(childKey).toString();
//            }

//            QString wave = pulseValues.at(pulseKeys.indexOf("WAVEFORM_INDEX", 0));
//            QString numPRI = pulseValues.at(pulseKeys.indexOf("NUM_PRIS", 0));
//            QString samples = pulseValues.at(pulseKeys.indexOf("SAMPLES_PER_PRI", 0));
//            QString dacdelay = pulseValues.at(pulseKeys.indexOf("DAC_DELAY", 0));
//            QString adcdelay = pulseValues.at(pulseKeys.indexOf("ADC_DELAY", 0));
//            QString polorder = pulseValues.at(pulseKeys.indexOf("POL_ORDER", 0));
//            QString PRI = pulseValues.at(pulseKeys.indexOf("PRI", 0));
//            QString prepulse = pulseValues.at(pulseKeys.indexOf("PRE_PULSE", 0));
//            QString lbandf = pulseValues.at(pulseKeys.indexOf("L_BAND_WAVEFORM_FREQ", 0));
//            QString xbandf = pulseValues.at(pulseKeys.indexOf("X_BAND_WAVEFORM_FREQ", 0));

//            settings.endGroup();

//            if (query.exec("INSERT INTO Pulse (fk_id, Waveform, NumOfPRIs, SamplesPerPRI, DACDelay, ADCDelay, PolOrder, PRI, PrePulse, LBandWaveformFreq, XBandWaveformFreq) "
//                           "VALUES ('" + fk_id + "','" + wave + "','" + numPRI + "','" + samples + "','" + dacdelay + "','" + adcdelay + "','" + polorder + "','" +
//                           PRI + "','" + prepulse + "','" + lbandf + "','" + xbandf + "');"))
//            {
//                QMessageBox::information(this, "Update Success", "Pulse data added to database.");
//            }
//            else
//            {
//                qDebug() << query.lastError().text();
//            }
//        }
//    }


//    //previously been loaded check
//    if (query.exec("SELECT fk_id FROM Weather where fk_id = '" + fk_id + "'"))
//    {
//        query.next();
//        if (query.value(0).toString() == fk_id)
//        {
//            ui->label_testing->setText("duplicate");
//            QMessageBox::warning(this, "Duplicate Data", "Weather data previously added to database.");
//        }
//        else
//        {
//            ui->label_testing->setText("not duplicate");
//            //load weather in Weather table
//            settings.beginGroup("Weather");
//            QStringList weatherkeys = settings.allKeys();
//            QStringList weatherKeys, weatherValues;

//            foreach (const QString &childKey, weatherkeys)
//            {
//                weatherKeys << childKey;
//                weatherValues << settings.value(childKey).toString();
//            }

//            QString seastate = weatherValues.at(weatherKeys.indexOf("DOUGLAS_SEA_STATE", 0));
//            QString windspd = weatherValues.at(weatherKeys.indexOf("WIND_SPEED", 0));
//            QString winddir = weatherValues.at(weatherKeys.indexOf("WIND_DIR", 0));
//            QString waveht = weatherValues.at(weatherKeys.indexOf("WAVE_HEIGHT", 0));
//            QString wavedir = weatherValues.at(weatherKeys.indexOf("WAVE_DIR", 0));
//            QString waveper = weatherValues.at(weatherKeys.indexOf("WAVE_PERIOD", 0));
//            QString airtemp = weatherValues.at(weatherKeys.indexOf("AIR_TEMPERATURE", 0));
//            QString airpress = weatherValues.at(weatherKeys.indexOf("AIR_PRESSURE", 0));

//            settings.endGroup();

//            if (query.exec("INSERT INTO Weather (fk_id, DouglasSeaState, WindSpeed, WindDir, WaveHeight, WaveDir, WavePeriod, AirTemperature, AirPressure) VALUES ('" +
//                           fk_id + "','" + seastate + "','" + windspd + "','" + winddir + "','" + waveht + "','" + wavedir + "','" + waveper + "','" + airtemp + "','" + airpress + "');"))
//            {
//                QMessageBox::information(this, "Update Success", "Weather data added to database.");
//            }
//            else
//            {
//                qDebug() << query.lastError().text();
//            }
//            ui->comboBox->setCurrentIndex(ui->comboBox->findText("Weather"));
//        }
//    }

//    ui->lineEdit->clear();

}




void MainWindow::on_comboBox_5_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Trial")
    {
        QStringList triallist;
        triallist << "ArchiveName" << "TrialDate" << "StartTime";
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(triallist);
    }
    else if (arg1 == "Nodes")
    {
        QStringList nodelist;
        nodelist << "Node0LocationLat" << "Node0LocationLon" << "Node0LocationHt" << "Node1LocationLat" << "Node1LocationLon" << "Node1LocationHt"
                 << "Node2LocationLat" << "Node2LocationLon" << "Node2LocationHt" << "DTGOfBearing" << "BaselineBisector" << "Node0Range" << "Node0Bearing"
                 << "Node1Range" << "Node1Bearing" << "Node2Range" << "Node2Bearing";
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(nodelist);
    }
    else if (arg1 == "Target")
    {
        QStringList targetlist;
        targetlist << "TgtLocationLat" << "TgtLocationLon" << "TgLocationHt";
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(targetlist);
    }
    else if (arg1 == "Pulse")
    {
        QStringList pulselist;
        pulselist << "Waveform" << "NumOfPRIs" << "SamplesPerPRI" << "DACDelay" << "ADCDelay" << "PolOrder" << "PRI" << "PrePulse" << "LBandWaveformFreq" << "XBandWaveformFreq";
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(pulselist);
    }
    else if (arg1 == "Weather")
    {
        QStringList weatherlist;
        weatherlist << "DouglasSeaState" << "WindSpeed" << "WindDir" << "WaveHeight" << "WaveDir" << "WavePeriod" << "AirTemperature" << "AirPressure";
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(weatherlist);
    }
}

void MainWindow::on_comboBox_23_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Trial")
    {
        QStringList triallist;
        triallist << "ArchiveName" << "TrialDate" << "StartTime";
        ui->comboBox_24->clear();
        ui->comboBox_24->addItems(triallist);
    }
    else if (arg1 == "Nodes")
    {
        QStringList nodelist;
        nodelist << "Node0LocationLat" << "Node0LocationLon" << "Node0LocationHt" << "Node1LocationLat" << "Node1LocationLon" << "Node1LocationHt"
                 << "Node2LocationLat" << "Node2LocationLon" << "Node2LocationHt" << "DTGOfBearing" << "BaselineBisector" << "Node0Range" << "Node0Bearing"
                 << "Node1Range" << "Node1Bearing" << "Node2Range" << "Node2Bearing";
        ui->comboBox_24->clear();
        ui->comboBox_24->addItems(nodelist);
    }
    else if (arg1 == "Target")
    {
        QStringList targetlist;
        targetlist << "TargetLocationLat" << "TargetLocationLon" << "TargetLocationHt";
        ui->comboBox_24->clear();
        ui->comboBox_24->addItems(targetlist);
    }
    else if (arg1 == "Pulse")
    {
        QStringList pulselist;
        pulselist << "Waveform" << "NumOfPRIs" << "SamplesPerPRI" << "DACDelay" << "ADCDelay" << "PolOrder" << "PRI" << "PrePulse" << "LBandWaveformFreq" << "XBandWaveformFreq";
        ui->comboBox_24->clear();
        ui->comboBox_24->addItems(pulselist);
    }
    else if (arg1 == "Weather")
    {
        QStringList weatherlist;
        weatherlist << "DouglasSeaState" << "WindSpeed" << "WindDir" << "WaveHeight" << "WaveDir" << "WavePeriod" << "AirTemperature" << "AirPressure";
        ui->comboBox_24->clear();
        ui->comboBox_24->addItems(weatherlist);
    }
}

void MainWindow::on_comboBox_27_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Trial")
    {
        QStringList triallist;
        triallist << "ArchiveName" << "TrialDate" << "StartTime";
        ui->comboBox_28->clear();
        ui->comboBox_28->addItems(triallist);
    }
    else if (arg1 == "Nodes")
    {
        QStringList nodelist;
        nodelist << "Node0LocationLat" << "Node0LocationLon" << "Node0LocationHt" << "Node1LocationLat" << "Node1LocationLon" << "Node1LocationHt"
                 << "Node2LocationLat" << "Node2LocationLon" << "Node2LocationHt" << "DTGOfBearing" << "BaselineBisector" << "Node0Range" << "Node0Bearing"
                 << "Node1Range" << "Node1Bearing" << "Node2Range" << "Node2Bearing";
        ui->comboBox_28->clear();
        ui->comboBox_28->addItems(nodelist);
    }
    else if (arg1 == "Target")
    {
        QStringList targetlist;
        targetlist << "TargetLocationLat" << "TargetLocationLon" << "TargetLocationHt";
        ui->comboBox_28->clear();
        ui->comboBox_28->addItems(targetlist);
    }
    else if (arg1 == "Pulse")
    {
        QStringList pulselist;
        pulselist << "Waveform" << "NumOfPRIs" << "SamplesPerPRI" << "DACDelay" << "ADCDelay" << "PolOrder" << "PRI" << "PrePulse" << "LBandWaveformFreq" << "XBandWaveformFreq";
        ui->comboBox_28->clear();
        ui->comboBox_28->addItems(pulselist);
    }
    else if (arg1 == "Weather")
    {
        QStringList weatherlist;
        weatherlist << "DouglasSeaState" << "WindSpeed" << "WindDir" << "WaveHeight" << "WaveDir" << "WavePeriod" << "AirTemperature" << "AirPressure";
        ui->comboBox_28->clear();
        ui->comboBox_28->addItems(weatherlist);
    }
}



void MainWindow::on_pushButton_newSearchRow_clicked()
{
    QCheckBox* check1 = new QCheckBox();
    QComboBox* box1 = new QComboBox();
    QStringList valueChoicefieldChoice;
    valueChoicefieldChoice << "Choose a table" << "Trial" << "Nodes" << "Target" << "Pulse" << "Weather";
    box1->addItems(valueChoicefieldChoice);
    QComboBox* box2 = new QComboBox();
    box2->addItem("Choose a field");
    QComboBox* box3 = new QComboBox();
    QStringList equators;
    equators << "=" << "<>" << ">" << "<" << ">=" << "<=";
    box3->addItems(equators);
    QLineEdit* line1 = new QLineEdit();
    QPushButton* button1 = new QPushButton("Delete");


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(check1);
    layout->addWidget(box1);
    layout->addWidget(box2);
    layout->addWidget(box3);
    layout->addWidget(line1);
    layout->addWidget(button1);
    ui->verticalLayout_2->addLayout(layout, 0);
}

void MainWindow::on_pushButton_search_clicked()
{
    QString querytext;

    if (ui->checkBox->isChecked())
    {
        tableChoice0 = ui->comboBox_5->currentText();
        fieldChoice0 = ui->comboBox_3->currentText();
        valueChoice0 = ui->lineEdit_10->text();
        equatorChoice0 = ui->comboBox_2->currentText();
    }

    if (ui->checkBox_2->isChecked())
    {
        andor0 = ui->comboBox_31->currentText();

        tableChoice1 = ui->comboBox_23->currentText();
        fieldChoice1 = ui->comboBox_24->currentText();
        valueChoice1 = ui->lineEdit_20->text();
        equatorChoice1 = ui->comboBox_29->currentText();
    }

    if (ui->checkBox_3->isChecked())
    {
        andor1 = ui->comboBox_32->currentText();

        tableChoice2 = ui->comboBox_27->currentText();
        fieldChoice2 = ui->comboBox_28->currentText();
        valueChoice2 = ui->lineEdit_22->text();
        equatorChoice2 = ui->comboBox_30->currentText();
    }

    if (ui->checkBox->isChecked())
    {
        if (ui->checkBox_2->isChecked())
        {
            if (ui->checkBox_3->isChecked())
            {
                querytext = "SELECT * FROM " + tableChoice0 + " WHERE (" + fieldChoice0 + equatorChoice0 + "'" + valueChoice0 + "')"
                        + andor0 + "(" + fieldChoice1 + equatorChoice1 + "'" + valueChoice1 + "')" + andor1 + "(" + fieldChoice2 + equatorChoice2 + "'" + valueChoice2 + "');";
            }
            else
            {
                querytext = "SELECT * FROM " + tableChoice0 + " WHERE (" + fieldChoice0 + equatorChoice0 + "'" + valueChoice0 + "')" + andor0 + "(" + fieldChoice1 + equatorChoice1 + "'" + valueChoice1 + "');";
            }
        }
        else
        {
            querytext = "SELECT * FROM " + tableChoice0 + " WHERE (" + fieldChoice0 + equatorChoice0 + "'" + valueChoice0 + "');";
        }
    }

    if (tableChoice0 == "Trial")
    {
        load_trial_data(querytext);
    }
    else if (tableChoice0 == "Nodes")
    {
        load_node_data(querytext);
    }
    else if (tableChoice0 == "Target")
    {
        load_target_data(querytext);
    }
    else if (tableChoice0 == "Pulse")
    {
        load_pulse_data(querytext);
    }
    else if (tableChoice0 == "Weather")
    {
        load_weather_data(querytext);
    }
}


