-- MySQL Administrator dump 1.4
--
-- ------------------------------------------------------
-- Server version	5.5.12


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


--
-- Create schema drtuxtest
--

--
-- Definition of table `box`
--

DROP TABLE IF EXISTS `ST_box`;
CREATE TABLE `ST_box` (
  `BO_Code` varchar(45) NOT NULL,
  `BO_Libelle` varchar(45) DEFAULT NULL,
  `BO_CouleurBG` varchar(45) DEFAULT NULL,
  `BO_CouleurTitre` varchar(45) DEFAULT NULL,
  `BO_Nb_Maxi_Pat` int(10) unsigned DEFAULT NULL,
  `BO_Type` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`BO_Code`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `box`
--

/*!40000 ALTER TABLE `box` DISABLE KEYS */;
INSERT INTO `ST_box` (`BO_Code`,`BO_Libelle`,`BO_CouleurBG`,`BO_CouleurTitre`,`BO_Nb_Maxi_Pat`,`BO_Type`) VALUES 
 ('S1','Box S1','#aa00ff','#ffaa00',1,'Soins'),
 ('S2','Box S2','#aa00ff','#ffaa00',3,'Soins'),
 ('A1','Salle attente','#00aaff','#EEDDAA',4,'Attente'),
 ('SR','SORTIES','#eb0000','#FFFFFF',10,'Sortie'),
 ('A2','Attente Couloir','#7ca580','#556a4c',10,'Attente'),
 ('S3','Box S3','#aa00ff','#ffaa7f',2,'Soins'),
 ('D4','Déchocage','#ff0000','#ffaa7f',1,'Soins'),
 ('R4','Suture S4','#00ff00','#ffaa00',1,'Soins'),
 ('R1','Traumato 1','#00aa00','#ffaa00',1,'Soins'),
 ('R2','Traumato 2','#00aa00','#ffaa00',1,'Soins'),
 ('R3','Suture 3','#00aa00','#ffaa00',1,'Soins'),
 ('L1','Lit 1','#aa5500','#ffaa7f',1,'Soins'),
 ('L2','Lit 2','#aa5500','#ffaa7f',1,'Soins'),
 ('L3','Lit 3','#aa5500','#ffaa7f',1,'Soins'),
 ('L4','Lit 4','#aa5500','#ffaa7f',1,'Soins'),
 ('L5','Lit 5','#aa5500','#ffaa7f',1,'Soins'),
 ('L6','Lit 6','#aa5500','#ffaa7f',1,'Soins');
/*!40000 ALTER TABLE `box` ENABLE KEYS */;

--
-- Definition of table `destinations`
--

DROP TABLE IF EXISTS `ST_destinations`;
CREATE TABLE `ST_destinations` (
  `DE_PK` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `DE_Destination` varchar(45) NOT NULL,
  `DE_TypeSortie` varchar(45) NOT NULL,
  PRIMARY KEY (`DE_PK`)
) ENGINE=MyISAM AUTO_INCREMENT=302 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `destinations`
--

/*!40000 ALTER TABLE `destinations` DISABLE KEYS */;
INSERT INTO `ST_destinations` (`DE_PK`,`DE_Destination`,`DE_TypeSortie`) VALUES 
 (1, 'Retour Domicile'          ,'Sortie'),
 (2, 'Evasion'                  ,'Sortie'),
 (3, 'Police'                   ,'Sortie'),
 (4, 'Hospi Marignane USC 0'    ,'Sortie'),
 (5, 'Hospi Marignane USC 3'    ,'Sortie'),
 (6, 'Hospi Marignane USIC'     ,'Sortie'),
 (7, 'Hospi Marignane UTHCD'    ,'Sortie'),
 (8, 'Hospi Marignane Ambu'     ,'Sortie'),
 (9 ,'Hospi Marignane 1'        ,'Sortie'),
 (10,'Hospi Marignane 2'        ,'Sortie'),
 (11,'Hospi Marignane 3'        ,'Sortie'),
 (12,'Hospi Marignane 4'        ,'Sortie'),
 (13,'Hospi Marignane 5'        ,'Sortie'),
 (14,'Hopital Nord'             ,'Sortie'),
 (21,'Hopital Martigues'        ,'Sortie'),
 (31,'Hopital Aix en Pce'       ,'Sortie'),
 (41,'Hopital Salon'            ,'Sortie'),
 (51,'Hopital Timone'           ,'Sortie'),
 (61,'Hopital St Joseph'        ,'Sortie'),
 (71,'Hopital Ste Marguerite'   ,'Sortie'),
 (231,'Clinique Nans les Pins'  ,'Sortie'),
 (101,'Clinique Vitrolles Chir' ,'Sortie'),
 (111,'Clinique Vitrolle Mater' ,'Sortie'),
 (121,'Clinique Ambroise Pare'  ,'Sortie'),
 (251,'Clinique Martigues'      ,'Sortie'),
 (291,'Décès',' ');
/*!40000 ALTER TABLE `destinations` ENABLE KEYS */;


--
-- Definition of table `encours`
--

DROP TABLE IF EXISTS `ST_encours`;
CREATE TABLE `ST_encours` (
  `EC_PK` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `EC_CodeBox` varchar(45) NOT NULL,
  `EC_NomPatient` varchar(45) NOT NULL,
  `EC_HeureEntree` datetime NOT NULL,
  `EC_Medecin` varchar(45) DEFAULT NULL,
  `EC_GUIDPatient` varchar(45) DEFAULT NULL,
  `EC_Replier` tinyint(1) DEFAULT '0',
  `EC_HeureSortie` datetime DEFAULT NULL,
  `EC_Commentaire` varchar(45) DEFAULT NULL,
  `EC_PrenomPatient` varchar(45) DEFAULT NULL,
  `EC_ProgAnnexe` varchar(200) DEFAULT NULL,
  `EC_ArgsAnnexe` varchar(400) DEFAULT NULL,
  `EC_Destination` varchar(45) DEFAULT NULL,
  `EC_Anonyme` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`EC_PK`)
) ENGINE=MyISAM AUTO_INCREMENT=686 DEFAULT CHARSET=latin1;


--
-- Definition of table `encours_taches`
--

DROP TABLE IF EXISTS `ST_encours_taches`;
CREATE TABLE `ST_encours_taches` (
  `EN_PK_encours` int(10) unsigned NOT NULL,
  `EN_Num_tache` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `EN_Code_tache` varchar(45) DEFAULT NULL,
  `EN_Comment` varchar(200) DEFAULT NULL,
  `EN_Etat_en_cours` varchar(45) DEFAULT NULL,
  `EN_HeureDebPrevue` datetime DEFAULT NULL,
  `EN_HeureFinPrevue` datetime DEFAULT NULL,
  `EN_HeureDebut` datetime DEFAULT NULL,
  `EN_HeureFin` datetime DEFAULT NULL,
  `EN_Priorite` int(10) unsigned DEFAULT NULL,
  `EN_Note_tache` varchar(5000) DEFAULT NULL,
  `EN_Code_acteur` varchar(45) DEFAULT NULL,
  `EN_PrimKey_blob` int(10) unsigned DEFAULT NULL,
  `EN_NomFicNote` varchar(200) DEFAULT NULL,
  `EN_NomProgNote` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`EN_PK_encours`,`EN_Num_tache`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Definition of table `etats`
--

DROP TABLE IF EXISTS `ST_etats`;
CREATE TABLE `ST_etats` (
  `ET_Code_etat` varchar(45) NOT NULL,
  `ET_Libelle_etat` varchar(45) DEFAULT NULL,
  `ET_Couleur_etat` varchar(45) DEFAULT NULL,
  `ET_Tache_terminee` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`ET_Code_etat`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `etats`
--

/*!40000 ALTER TABLE `etats` DISABLE KEYS */;
INSERT INTO `ST_etats` (`ET_Code_etat`,`ET_Libelle_etat`,`ET_Couleur_etat`,`ET_Tache_terminee`) VALUES 
 ('CO','Commencé','#ffaa7f',0),
 ('EN','En Cours','#ffff7f',0),
 ('FI','Terminé','#55aa7f',1),
 ('AT','Attente','#00FF00',NULL),
 ('ET','Etat','#aa557f',0),
 ('RIEN','Aucun état','#d4d09e',0),
 ('ANU','Annulé','#bcbeb8',1);
/*!40000 ALTER TABLE `etats` ENABLE KEYS */;


--
-- Definition of table `etats_taches`
--

DROP TABLE IF EXISTS `ST_etats_taches`;
CREATE TABLE `ST_etats_taches` (
  `ST_Code_tache` varchar(45) NOT NULL,
  `ST_Code_etat` varchar(45) NOT NULL,
  PRIMARY KEY (`ST_Code_tache`,`ST_Code_etat`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `etats_taches`
--

/*!40000 ALTER TABLE `etats_taches` DISABLE KEYS */;
INSERT INTO `ST_etats_taches` (`ST_Code_tache`,`ST_Code_etat`) VALUES 
 ('A1','AT'),
 ('A1','EN'),
 ('A1','FI'),
 ('A2','CO'),
 ('A2','ET'),
 ('A3','ANU'),
 ('A3','CO'),
 ('A3','FI'),
 ('A4','ANU'),
 ('A4','AT'),
 ('A4','FI'),
 ('A5','AT'),
 ('A5','EN'),
 ('A5','FI');
/*!40000 ALTER TABLE `etats_taches` ENABLE KEYS */;


--
-- Definition of table `historique`
--

DROP TABLE IF EXISTS `ST_historique`;
CREATE TABLE `ST_historique` (
  `HI_PK` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `HI_Code_box` varchar(45) DEFAULT NULL,
  `HI_Nom_patient` varchar(45) DEFAULT NULL,
  `HI_Code_resp` varchar(45) DEFAULT NULL,
  `HI_Code_tache` varchar(45) DEFAULT NULL,
  `HI_Date` datetime DEFAULT NULL,
  `HI_Libelle_tache` varchar(45) DEFAULT NULL,
  `HI_Action` varchar(45) DEFAULT NULL,
  `HI_NumEncours` varchar(45) DEFAULT NULL,
  `HI_Libelle_etat` varchar(45) DEFAULT NULL,
  `HI_PrenomPatient` varchar(45) DEFAULT NULL,
  `HI_Commentaire` varchar(45) DEFAULT NULL,
  `HI_Code_acteur` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`HI_PK`)
) ENGINE=MyISAM AUTO_INCREMENT=8765 DEFAULT CHARSET=latin1;


--
-- Definition of table `taches`
--

DROP TABLE IF EXISTS `ST_taches`;
CREATE TABLE `ST_taches` (
  `TA_Code_tache` varchar(45)  NOT NULL,
  `TA_Libelle_tache` varchar(45)  NOT NULL,
  `TA_Couleur_tache` varchar(45)  default NULL,
  `TA_Duree_maxi` int(10) unsigned default NULL,
  `TA_Couleur_alarme` varchar(45)  default NULL,
  `TA_BoutonMenu` varchar(45)  NOT NULL,
  `TA_Priorite` varchar(10)  default NULL,
  `TA_Commentaire` varchar(256)  default NULL,
  PRIMARY KEY  (`TA_Code_tache`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
--
-- Dumping data for table `taches`
--

/*!40000 ALTER TABLE `taches` DISABLE KEYS */;
INSERT INTO `ST_taches` (`TA_Code_tache`,`TA_Libelle_tache`,`TA_Couleur_tache`,`TA_Duree_maxi`,`TA_Couleur_alarme`,`TA_BoutonMenu`) VALUES 
 ('RX THO','Radio du thorax','#aaaa7f',10,'#ffaa00','M'),
 ('RX ASP D','ASP debout de face et coupôles','#aaaa7f',10,'#ffaa00','M'),
 ('RX ASP C','ASP couché','#aaaa7f',10,'#ffaa00','M'),
 ('RX OS','Radio traumato','#aaaa7f',10,'#ffaa00','M'),
 ('ECHO A','Echographie abdominale','#aaaa7f',10,'#ffaa00','M'),
 ('ECHO M','Echographie musculaire','#aaaa7f',10,'#ffaa00','M'),
 ('ECHO V','Echographie vésico prostatique','#aaaa7f',10,'#ffaa00','M'),
 ('ECHO P','Echographie parties molles','#aaaa7f',10,'#ffaa00','M'),
 ('ECHO D','Echographie parties diverses','#aaaa7f',10,'#ffaa00','M'),
 ('BIO C','Bilan cardio','#aaaa7f',10,'#ffaa00','M'),
 ('BIO CH','Bilan cardio hépatique','#aaaa7f',10,'#ffaa00','M'),
 ('BIO H','Bilan hépatique','#aaaa7f',10,'#ffaa00','M'),
 ('BIO S','Bilan standard','#aaaa7f',10,'#ffaa00','M'),
 ('BIO P','Prélèvement','#aaaa7f',10,'#ffaa00','M'),
 ('GAZO','Gazo','#aaaa7f',10,'#ffaa00','M'),
 ('BU','BU','#aaaa7f',10,'#ffaa00','M'),
 ('CBU','CBU','#aaaa7f',10,'#ffaa00','M'),
 ('ECG','ECG','#ffaa7f',0,'#aaff7f','B'),
 ('ED V','Echo doppler veineuse','#FFEE22',5,'#ff0000','B'),
 ('ED T','Echo doppler TSA','#FFEE22',5,'#ff0000','B'),
 ('ED A','Echo doppler artérielle','#FFEE22',5,'#ff0000','B'),
 ('IRM','IRM','#FFEE22',5,'#ff0000','B'),
 ('CS C','Consultation cardio','#FFEE22',5,'#ff0000','B'),
 ('CS V','Consultation viscérale','#FFEE22',5,'#ff0000','B'),
 ('CS G','Consultation gastro','#FFEE22',5,'#ff0000','B'),
 ('CS O','Consultation ORL','#FFEE22',5,'#ff0000','B'),
 ('CS P','Consultation pneumo','#FFEE22',5,'#ff0000','B'),
 ('CS A','Consultation anesthésie','#FFEE22',5,'#ff0000','B'),
 ('CS D','Consultation autre','#FFEE22',5,'#ff0000','B'),
 ('SCAN A','Scanner abdominal','#FFEE22',5,'#ff0000','B'),
 ('SCAN C','Scanner cérébral','#EEFFDD',30,'#55007f','B'),
 ('SCAN U','Uro scanner','#ab93b9',30,'#c54923','B'),
 ('SCAN RC','Scanner rachis cervical','#ab93b9',30,'#c54923','B'),
 ('SCAN RD','Scanner rachis dorsal','#ab93b9',30,'#c54923','B'),
 ('SCAN RL','Scanner rachis lombaire','#ab93b9',30,'#c54923','B'),
 ('SCAN D','Scanner','#ab93b9',30,'#c54923','B'),
 ('SCAN T','Scanner thoracique','#818181',10,'#aaff7f','M');
/*!40000 ALTER TABLE `taches` ENABLE KEYS */;


--