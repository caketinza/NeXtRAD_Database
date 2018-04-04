-- MySQL dump 10.13  Distrib 5.7.21, for Linux (x86_64)
--
-- Host: localhost    Database: nextrad
-- ------------------------------------------------------
-- Server version	5.7.21-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Nodes`
--

DROP TABLE IF EXISTS `Nodes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Nodes` (
  `fk_id` int(10) unsigned NOT NULL,
  `Node0LocationLat` decimal(8,4) DEFAULT NULL,
  `Node0LocationLon` decimal(8,4) DEFAULT NULL,
  `Node0LocationHt` decimal(8,4) DEFAULT NULL,
  `Node1LocationLat` decimal(8,4) DEFAULT NULL,
  `Node1LocationLon` decimal(8,4) DEFAULT NULL,
  `Node1LocationHt` decimal(8,4) DEFAULT NULL,
  `Node2LocationLat` decimal(8,4) DEFAULT NULL,
  `Node2LocationLon` decimal(8,4) DEFAULT NULL,
  `Node2LocationHt` decimal(8,4) DEFAULT NULL,
  `DTGOfBearing` varchar(20) DEFAULT NULL,
  `BaselineBisector` int(11) DEFAULT NULL,
  `Node0Range` decimal(8,4) DEFAULT NULL,
  `Node0Bearing` decimal(8,4) DEFAULT NULL,
  `Node1Range` decimal(8,4) DEFAULT NULL,
  `Node1Bearing` decimal(8,4) DEFAULT NULL,
  `Node2Range` decimal(8,4) DEFAULT NULL,
  `Node2Bearing` decimal(8,4) DEFAULT NULL,
  KEY `fk_id` (`fk_id`),
  CONSTRAINT `Nodes_ibfk_1` FOREIGN KEY (`fk_id`) REFERENCES `Trial` (`pk_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Nodes`
--

LOCK TABLES `Nodes` WRITE;
/*!40000 ALTER TABLE `Nodes` DISABLE KEYS */;
INSERT INTO `Nodes` VALUES (1,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(1,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(7,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(7,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(7,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(7,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'\"061855Z 1217\"',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(43,-34.1891,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(45,-34.1891,18.3665,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(46,-34.1891,18.3665,52.7600,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(47,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(48,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',NULL,NULL,NULL,NULL,NULL,NULL,NULL),(49,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(50,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(50,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(52,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(53,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(54,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(55,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(55,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(55,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(58,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(59,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(59,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(7,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(59,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(59,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(64,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(64,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(66,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(66,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(66,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(71,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(71,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(71,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(71,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192),(79,-34.1891,18.3665,52.7600,-3.1891,18.3665,52.7600,-34.1891,18.3665,52.7600,'061855Z 1217',2,1.8295,46.5192,1.8295,46.5192,1.8295,46.5192);
/*!40000 ALTER TABLE `Nodes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Pulse`
--

DROP TABLE IF EXISTS `Pulse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Pulse` (
  `fk_id` int(10) unsigned NOT NULL,
  `Waveform` decimal(8,4) DEFAULT NULL,
  `NumOfPRIs` int(11) DEFAULT NULL,
  `SamplesPerPRI` int(11) DEFAULT NULL,
  `DACDelay` int(11) DEFAULT NULL,
  `ADCDelay` int(11) DEFAULT NULL,
  `PolOrder` varchar(20) DEFAULT NULL,
  `PRI` int(11) DEFAULT NULL,
  `PrePulse` int(11) DEFAULT NULL,
  `LBandWaveformFreq` int(11) DEFAULT NULL,
  `XBandWaveformFreq` int(11) DEFAULT NULL,
  KEY `fk_id` (`fk_id`),
  CONSTRAINT `Pulse_ibfk_1` FOREIGN KEY (`fk_id`) REFERENCES `Trial` (`pk_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Pulse`
--

LOCK TABLES `Pulse` WRITE;
/*!40000 ALTER TABLE `Pulse` DISABLE KEYS */;
INSERT INTO `Pulse` VALUES (1,3.0000,10000,4096,1,372,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(1,3.0000,10000,4096,1,372,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(7,0.0000,60000,4096,1,5400,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(7,5.0000,60000,4096,1,5400,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(7,5.0000,60000,4096,1,5400,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(7,5.0000,60000,4096,1,5400,'\"0,1,2,3,4,5\"',1000,30,1300,8500),(53,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(54,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(55,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(55,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(55,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(58,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(59,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(59,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(7,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(59,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(59,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(64,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(64,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(66,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(66,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(66,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(66,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(70,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(71,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(71,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(71,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(71,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500),(79,5.0000,60000,4096,1,5400,'0,1,2,3,4,5',1000,30,1300,8500);
/*!40000 ALTER TABLE `Pulse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Target`
--

DROP TABLE IF EXISTS `Target`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Target` (
  `fk_id` int(10) unsigned NOT NULL,
  `TgtLocationLat` decimal(8,4) DEFAULT NULL,
  `TgtLocationLon` decimal(8,4) DEFAULT NULL,
  `TgtLocationHt` decimal(8,4) DEFAULT NULL,
  KEY `fk_id` (`fk_id`),
  CONSTRAINT `Target_ibfk_1` FOREIGN KEY (`fk_id`) REFERENCES `Trial` (`pk_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Target`
--

LOCK TABLES `Target` WRITE;
/*!40000 ALTER TABLE `Target` DISABLE KEYS */;
INSERT INTO `Target` VALUES (1,-34.1874,18.4280,0.0235),(1,-34.1874,18.4280,0.0235),(7,-34.1874,18.4280,0.0235),(7,-34.1874,18.4280,0.0235),(7,-34.1874,18.4280,0.0235),(7,-34.1874,18.4280,0.0235),(50,-34.1874,18.4280,0.0235),(50,-34.1874,18.4280,0.0235),(52,-34.1874,18.4280,0.0235),(53,-34.1874,18.4280,0.0235),(54,-34.1874,18.4280,0.0235),(55,-34.1874,18.4280,0.0235),(55,-34.1874,18.4280,0.0235),(55,-34.1874,18.4280,0.0235),(58,-34.1874,18.4280,0.0235),(59,-34.1874,18.4280,0.0235),(59,-34.1874,18.4280,0.0235),(7,-34.1874,18.4280,0.0235),(59,-34.1874,18.4280,0.0235),(59,-34.1874,18.4280,0.0235),(64,-34.1874,18.4280,0.0235),(64,-34.1874,18.4280,0.0235),(66,-34.1874,18.4280,0.0235),(66,-34.1874,18.4280,0.0235),(66,-34.1874,18.4280,0.0235),(66,-34.1874,18.4280,0.0235),(70,-34.1874,18.4280,0.0235),(71,-34.1874,18.4280,0.0235),(71,-34.1874,18.4280,0.0235),(71,-34.1874,18.4280,0.0235),(71,-34.1874,18.4280,0.0235),(79,-34.1874,18.4280,0.0235);
/*!40000 ALTER TABLE `Target` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Trial`
--

DROP TABLE IF EXISTS `Trial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Trial` (
  `pk_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `ArchiveName` varchar(50) NOT NULL,
  `TrialDate` date DEFAULT NULL,
  `StartTime` time DEFAULT NULL,
  PRIMARY KEY (`pk_id`),
  UNIQUE KEY `ArchiveName` (`ArchiveName`)
) ENGINE=InnoDB AUTO_INCREMENT=80 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Trial`
--

LOCK TABLES `Trial` WRITE;
/*!40000 ALTER TABLE `Trial` DISABLE KEYS */;
INSERT INTO `Trial` VALUES (1,'2017-12-11_16:20:00','2017-12-11','16:20:00'),(7,'2017-12-14_16:53:18','2017-12-14','16:53:18'),(8,'2018-01-01_16:20:00','2018-01-01','16:20:00'),(9,'2018-12-14_16_59_18','2018-12-14','16:59:18'),(10,'2018-12-14_16:59:18','2018-12-14','16:59:18'),(17,'2018-01-01_16:20:01','2018-01-01','16:20:10'),(19,'2018-01-16_13:59:23','2018-01-16','13:59:23'),(27,'2017-01-16_13:59:23','2017-01-16','13:59:23'),(28,'2017-02-16_13:59:23','2017-02-16','13:59:23'),(30,'2017-02-16_13:59:24','2017-02-16','13:59:24'),(31,'2017-02-16_13:59:25','2017-02-16','13:59:25'),(32,'2017-02-16_14:59:25','2017-02-16','14:59:25'),(34,'2017-02-16_14:59:26','2017-02-16','14:59:26'),(35,'2017-02-16_14:59:27','2017-02-16','14:59:27'),(36,'2017-02-16_14:59:28','2017-02-16','14:59:28'),(37,'2017-02-16_14:59:29','2017-02-16','14:59:29'),(38,'2017-02-16_14:59:30','2017-02-16','14:59:30'),(39,'2017-02-16_14:59:31','2017-02-16','14:59:31'),(40,'2017-02-16_14:59:32','2017-02-16','14:59:32'),(42,'2017-02-16_14:59:33','2017-02-16','14:59:33'),(43,'2017-02-16_14:59:34','2017-02-16','14:59:34'),(44,'2017-02-16_14:59:35','2017-02-16','14:59:35'),(45,'2017-02-16_14:59:36','2017-02-16','14:59:36'),(46,'2017-02-16_14:59:37','2017-02-16','14:59:37'),(47,'2017-02-16_14:59:38','2017-02-16','14:59:38'),(48,'2017-02-16_14:59:39','2017-02-16','14:59:39'),(49,'2017-02-16_14:59:40','2017-02-16','14:59:40'),(50,'2017-02-16_14:59:41','2017-02-16','14:59:41'),(52,'2017-02-16_14:59:42','2017-02-16','14:59:42'),(53,'2017-02-16_14:59:43','2017-02-16','14:59:43'),(54,'2017-02-16_14:59:44','2017-02-16','14:59:44'),(55,'2017-02-16_14:59:45','2017-02-16','14:59:45'),(58,'2017-02-16_14:59:46','2017-02-16','14:59:46'),(59,'2017-02-16_14:59:47','2017-02-16','14:59:47'),(64,'2017-02-17_14:59:47','2017-02-17','14:59:47'),(66,'2017-02-18_14:59:47','2017-02-18','14:59:47'),(70,'2017-02-19_14:59:47','2017-02-19','14:59:47'),(71,'2017-02-20_14:59:47','2017-02-20','14:59:47'),(79,'2017-02-21_14:59:47','2017-02-21','14:59:47');
/*!40000 ALTER TABLE `Trial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Weather`
--

DROP TABLE IF EXISTS `Weather`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Weather` (
  `fk_id` int(10) unsigned NOT NULL,
  `DouglasSeaState` decimal(8,4) DEFAULT NULL,
  `WindSpeed` decimal(10,4) DEFAULT NULL,
  `WindDir` decimal(8,4) DEFAULT NULL,
  `WaveHeight` decimal(8,4) DEFAULT NULL,
  `WaveDir` decimal(8,4) DEFAULT NULL,
  `WavePeriod` decimal(8,4) DEFAULT NULL,
  `AirTemperature` decimal(8,4) DEFAULT NULL,
  `AirPressure` decimal(8,4) DEFAULT NULL,
  KEY `fk_id` (`fk_id`),
  CONSTRAINT `Weather_ibfk_1` FOREIGN KEY (`fk_id`) REFERENCES `Trial` (`pk_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Weather`
--

LOCK TABLES `Weather` WRITE;
/*!40000 ALTER TABLE `Weather` DISABLE KEYS */;
INSERT INTO `Weather` VALUES (1,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(1,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(7,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(7,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(7,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(7,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(54,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(55,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(55,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(55,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(58,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(59,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(59,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(7,5.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(59,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(59,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(64,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(64,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(66,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(66,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(66,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(66,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(70,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(71,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(71,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(71,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(71,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000),(79,7.0000,10000.0000,123.0000,6.0000,123.0000,7.0000,17.0000,10.7000);
/*!40000 ALTER TABLE `Weather` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-04-04 12:01:03