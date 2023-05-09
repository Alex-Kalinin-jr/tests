-- MySQL dump 10.13  Distrib 8.0.33, for Linux (x86_64)
--
-- Host: localhost    Database: questions
-- ------------------------------------------------------
-- Server version	8.0.33

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `answer`
--

DROP TABLE IF EXISTS `answer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `answer` (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `question_id` int NOT NULL,
  `text` varchar(256) NOT NULL,
  `is_it_right_answer` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `pn_user_index` (`question_id`),
  CONSTRAINT `answer_ibfk_1` FOREIGN KEY (`question_id`) REFERENCES `question` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=100 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `answer`
--

LOCK TABLES `answer` WRITE;
/*!40000 ALTER TABLE `answer` DISABLE KEYS */;
INSERT INTO `answer` VALUES (69,1,'isWidgetType()',1),(70,1,'qobject_cast<QWidget *>()',0),(71,1,'inherits(\"QWidget\")',0),(72,2,' ALTER TABLE t TRUNCATE PARTITION (p0)',1),(73,2,' ALTER TABLE t PARTITION (p0)',0),(74,2,' ALTER TABLE t PARTITION p0',0),(75,2,' ALTER TABLE t TRUNCATE PARTITION p0',0),(76,3,'mysql --local-infile=1 -u root -p',1),(77,3,'mysql -u root -p',0),(78,4,'\"ctrl+x\" then \"fg\". Further access by \"jobs\".',0),(79,4,'\"ctrl+z\" then \"fg\". Further access by \"jobs\".',0),(80,4,'\"ctrl+x\" then \"bg\". Further access by \"jobs\".',0),(81,4,'\"ctrl+z\" then \"bg\". Further access by \"jobs\".',1),(82,4,'\"ctrl+z\". Further access by \"jobs\".',0),(83,4,'\"ctrl+x\". Further access by \"jobs\".',0),(84,5,'QLayout->setBackground(QColor)',0),(85,5,'QLayout->itemAtPosition(int, int)->setBackground(QColor)',0),(86,5,'QLayout is not a visual element, it\'s a container that adjust location of contained widgets.\nYou can change background of QFrame or other widgets\nyou included QLayout into.',1);
/*!40000 ALTER TABLE `answer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `link`
--

DROP TABLE IF EXISTS `link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `link` (
  `id` bigint NOT NULL AUTO_INCREMENT,
  `question_id` int NOT NULL,
  `text` varchar(256) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `pk_user_index` (`question_id`),
  CONSTRAINT `link_ibfk_1` FOREIGN KEY (`question_id`) REFERENCES `question` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `link`
--

LOCK TABLES `link` WRITE;
/*!40000 ALTER TABLE `link` DISABLE KEYS */;
INSERT INTO `link` VALUES (4,3,'https://stackoverflow.com/questions/59993844/error-loading-local-data-is-disabled-this-must-be-enabled-on-both-the-client'),(5,4,'https://linuxhint.com/send-process-background-linux/');
/*!40000 ALTER TABLE `link` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `question`
--

DROP TABLE IF EXISTS `question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `question` (
  `id` int NOT NULL AUTO_INCREMENT,
  `category` char(2) NOT NULL,
  `text` varchar(256) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `question`
--

LOCK TABLES `question` WRITE;
/*!40000 ALTER TABLE `question` DISABLE KEYS */;
INSERT INTO `question` VALUES (1,'ad','Which method is the fastest for indicating a widget???'),(2,'ac','executing the statement DELETE FROM t PARTITION (p0) is equivalent to:'),(3,'ac','When you cannot load data into table from file you use:\nSET GLOBAL local_infile=1;\nWhen you then reconnect to the server\nwhat should you write for loading success?'),(4,'aa','You launch the proccess in foreground.\nHow to send it to background in linux?'),(5,'ad','How to change the background of the QLayout?');
/*!40000 ALTER TABLE `question` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'questions'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-09 15:02:12
