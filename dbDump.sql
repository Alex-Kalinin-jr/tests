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
) ENGINE=InnoDB AUTO_INCREMENT=399 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `answer`
--

LOCK TABLES `answer` WRITE;
/*!40000 ALTER TABLE `answer` DISABLE KEYS */;
INSERT INTO `answer` VALUES (289,1,'isWidgetType()',1),(290,1,'qobject_cast<QWidget *>()',0),(291,1,'inherits(\"QWidget\")',0),(292,2,' ALTER TABLE t TRUNCATE PARTITION (p0)',1),(293,2,' ALTER TABLE t PARTITION (p0)',0),(294,2,' ALTER TABLE t PARTITION p0',0),(295,2,' ALTER TABLE t TRUNCATE PARTITION p0',0),(296,3,'mysql --local-infile=1 -u root -p',1),(297,3,'mysql -u root -p',0),(298,4,'\"ctrl+x\" then \"fg\". Further access by \"jobs\".',0),(299,4,'\"ctrl+z\" then \"fg\". Further access by \"jobs\".',0),(300,4,'\"ctrl+x\" then \"bg\". Further access by \"jobs\".',0),(301,4,'\"ctrl+z\" then \"bg\". Further access by \"jobs\".',1),(302,4,'\"ctrl+z\". Further access by \"jobs\".',0),(303,4,'\"ctrl+x\". Further access by \"jobs\".',0),(304,5,'QLayout->setBackground(QColor)',0),(305,5,'QLayout->itemAtPosition(int, int)->setBackground(QColor)',0),(306,5,'QLayout is not a visual element, it\'s a container that adjust location of contained widgets.\nYou can change background of QFrame or other widgets\nyou included QLayout into.',1),(307,6,'Undefined behaviour',1),(308,6,'Implementation-defined behaviour',1),(309,6,'Unspecified behaviour',1),(310,6,'Specified behaviour',0),(311,6,'Enormous behaviour',0),(312,6,'Undetermined behaviour',0),(313,7,'i++ * ++i;',1),(314,7,'i = ++i;',1),(315,7,'i = (i, ++i, 1) + 1;',0),(316,7,'j = (++i, i++, j*i);',0),(317,7,'++i = 2;',1),(318,7,'i = (++i,i++,i);',0),(319,8,'If a function contains a loop. (for, while and do-while)',1),(320,8,'If a function contains static variables.',1),(321,8,'If a function contains conditional statements',0),(322,8,'If a function is recursive.',1),(323,8,'If a function return type is other than void, and the return statement doesn’t exist in a function body.',1),(324,8,'If a function contains a switch or goto statement.',1),(325,9,'\"extern\" shows that this is just a definition of variable.',0),(326,9,'\"extern\" shows that this is just a declaration of variable.',1),(327,9,'Program would not be compiled because var \"int c\" is not defined.',1),(328,9,'Var \"int a\" is correct and program would be executed with val \"a = 0\" if compiled.',1),(329,9,'Var \"b\" would be \"int\" due to implicit type convertion',0),(356,30,'\"typeDef\" will cause linkage error since have different values.',0),(357,30,'\"Const int\" will cause undefined behaviour because final value undetermined and depends on order of linking.',0),(358,30,'Inline function will cause linkage error because defined differently in files',0),(359,31,'Launchs preprocessor and only preprocessor.',1),(360,31,'Launchs preprocessor and then compiler.',0),(361,31,'Launchs compiler and linker ingoring preprocessor.',0),(362,31,'Launchs compiler and only compiler.',0),(363,31,'Launchs linker and only linker.',0),(364,32,'will run due to implicit conversions',0),(365,32,'will not be compiled because reference as parameter disables implicit conversions if it is not \"const\" parameter',1),(366,33,'int f(int, int = 0, char * = 0);',0),(367,33,'int g(int = 0, int = 0, char *);',1),(368,33,'int h(int = 0, int, char * = 0);',1),(369,34,' int (*first)(int, int);\nfirst = sum;',1),(370,34,'auto second{sum};',1),(371,34,'auto *third(sub);',1),(372,34,' int *first(int, int);\nfirst = sum;',0),(373,34,'typedef (*arr)(int, int);\narr fourth[]{sum, sub};',0),(374,34,'auto second{sum, sub};',0),(375,34,'typedef int (*arr)(int, int);\narr fourth[]{sum, sub};',1),(376,35,'Yes',1),(377,35,'No',0),(378,36,'true',1),(379,36,'false',0),(380,37,'y has an access to all members (including private) of class X.',1),(381,37,'Y becames an interface of class X.',1),(382,37,'Class X gains control under y and you can use function in X.y(), X->y() manner',0),(383,38,'aaa a1;',0),(384,38,'a::aaa a2;',0),(385,38,'a::bbb a3;',1),(386,39,'23',1),(387,40,'22\n  22 {\n    222\n  }\n22\n',1),(388,41,'af {\n  afd\n}',0),(389,42,'virtual X();\n',0),(390,42,'X();\nvirtual X *new_x() {return new X();}',1),(391,43,'true. we can allocate memory differently for childs.',1),(392,44,'answ_1',1),(393,45,'создать ситуацию',1),(394,45,'разрешить ситуацию',0),(395,45,'влиять на ситуацию',0),(396,45,'выйти из ситуации',0),(397,46,'select distinct category from question;',1),(398,46,'select unique category from question;',0);
/*!40000 ALTER TABLE `answer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `category`
--

DROP TABLE IF EXISTS `category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `category` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL,
  `shortName` char(2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id` (`id`),
  UNIQUE KEY `shortName` (`shortName`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `category`
--

LOCK TABLES `category` WRITE;
/*!40000 ALTER TABLE `category` DISABLE KEYS */;
INSERT INTO `category` VALUES (1,'linux','aa'),(5,'C++','ab'),(6,'sql','ac'),(7,'qt','ad'),(18,'english','en');
/*!40000 ALTER TABLE `category` ENABLE KEYS */;
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
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `link`
--

LOCK TABLES `link` WRITE;
/*!40000 ALTER TABLE `link` DISABLE KEYS */;
INSERT INTO `link` VALUES (28,3,'https://stackoverflow.com/questions/59993844/error-loading-local-data-is-disabled-this-must-be-enabled-on-both-the-client'),(29,4,'https://linuxhint.com/send-process-background-linux/'),(30,6,'https://habr.com/ru/articles/216189/'),(31,7,'https://habr.com/ru/articles/216189/'),(32,8,'https://www.geeksforgeeks.org/inline-functions-cpp/');
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
) ENGINE=InnoDB AUTO_INCREMENT=47 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `question`
--

LOCK TABLES `question` WRITE;
/*!40000 ALTER TABLE `question` DISABLE KEYS */;
INSERT INTO `question` VALUES (1,'ad','Which method is the fastest for indicating a widget???'),(2,'ac','executing the statement DELETE FROM t PARTITION (p0) is equivalent to:'),(3,'ac','When you cannot load data into table from file you use:\nSET GLOBAL local_infile=1;\nWhen you then reconnect to the server\nwhat should you write for loading success?'),(4,'aa','You launch the proccess in foreground.\nHow to send it to background in linux?'),(5,'ad','How to change the background of the QLayout?'),(6,'ab','Choose existing termins according to C++ standard:'),(7,'ab','Choose wrong expressions accordingly to §5/4 of standard:'),(8,'ab','The compiler may not perform inlining in such circumstances as:'),(9,'ab','// file1.c:\nint a;\nint b = 1;\nextern int c;\n\n// file2.c:\nextern int a;\nextern double b;\nextern int c;\n\nChoose right statements:'),(29,'aa','test question'),(30,'aa','There are 2 files:\n// file1.c:\n\ntypedef int T;\n\nconst int a = 7;\n\ninline T f(int i) { return i+a; }\n\n\n// file2.c:\\nntypedef void T;\nconst int a = 8;\ninline T f(double d) { cout<<d; }\n\nChoose right answers:'),(31,'ab','The command \"CC -E file.c\"'),(32,'aa','If function was defined as:\nvoid func(float &a)\nthen the code:\ndouble b = 2.0;func(b);'),(33,'ab','Choose incorrect declarations:'),(34,'ab','There are two defined functions:\nint sum(int a, int b) { return a + b; }\nint sub(int a, int b) { return a - b; }\nChoose syntatically correct code:'),(35,'ab','Are \"typedef int (*fcn_t)(double, char);\" and \"using fcn_t = int(*)(double, char);\" are equivalent?'),(36,'aa','If function is invoked over pointer, implicit conversions of different types to const void * \nlet us say that func was defined as \n func(const void  *arg){} \n are not perfomed.'),(37,'ab','If a function y is a friend to class X, then:'),(38,'ab','You have a code: \nclass a \n{\n\n  struct aaa\n {\n\n    int aaa1 = 7;\n \n };\n\n public:\n\n  struct bbb\n {\n\n    int aaa2 = 6;\n\n  };\n\n};\nChoose right code:'),(39,'ac','1\n  11\n    1\n  11\n1'),(40,'ac','1\n  1\n    1\n  1\n1'),(41,'aa','  123'),(42,'ab','Correct declaration of \"virtual\" constructor for class X is: '),(43,'aa','class Arena {\n  virtual void *alloc(size_t) = 0;\n  virtual void free(void *) = 0;\n};\n\nvoid operator new(size_t sz, Arena *a) {\n  return a.alloc(sz);\n}'),(44,'ac','test'),(45,'en','translate phrase:\n\"bring about a situation\"'),(46,'ac','how to get unique values from sql table');
/*!40000 ALTER TABLE `question` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-05-27 17:50:43
