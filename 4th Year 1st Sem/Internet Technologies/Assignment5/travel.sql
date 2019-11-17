-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Oct 21, 2019 at 04:35 PM
-- Server version: 5.7.24
-- PHP Version: 7.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `travel`
--

-- --------------------------------------------------------

--
-- Table structure for table `cities`
--

DROP TABLE IF EXISTS `cities`;
CREATE TABLE IF NOT EXISTS `cities` (
  `code` varchar(5) NOT NULL,
  `city` varchar(20) NOT NULL,
  PRIMARY KEY (`code`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `cities`
--

INSERT INTO `cities` (`code`, `city`) VALUES
('CCU', 'KOLKATA'),
('BOM', 'MUMBAI'),
('DEL', 'DELHI'),
('BLR', 'BANGALORE'),
('BBSR', 'BHUBANESWAR'),
('MAA', 'CHENNAI');

-- --------------------------------------------------------

--
-- Table structure for table `flights`
--

DROP TABLE IF EXISTS `flights`;
CREATE TABLE IF NOT EXISTS `flights` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `flight_num` varchar(10) NOT NULL,
  `company` varchar(20) NOT NULL,
  `src_city` varchar(5) NOT NULL,
  `dest_city` varchar(5) NOT NULL,
  `day` varchar(15) NOT NULL,
  `dept_time` time NOT NULL,
  `arr_time` time NOT NULL,
  `num_stops` int(11) NOT NULL,
  `price` int(11) NOT NULL,
  `dur_hrs` int(11) NOT NULL,
  `dur_min` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `flights`
--

INSERT INTO `flights` (`id`, `flight_num`, `company`, `src_city`, `dest_city`, `day`, `dept_time`, `arr_time`, `num_stops`, `price`, `dur_hrs`, `dur_min`) VALUES
(1, '6E-5353', 'Indigo', 'CCU', 'BBSR', 'Tuesday', '16:00:00', '16:45:00', 0, 2000, 0, 45),
(2, '6E-5353', 'Indigo', 'CCU', 'BLR', 'Tuesday', '16:00:00', '19:00:00', 1, 5000, 3, 0),
(3, '6E-5353', 'Indigo', 'BBSR', 'BLR', 'Tuesday', '17:15:00', '19:00:00', 0, 2500, 1, 45),
(4, '7W-674', 'Vistara', 'CCU', 'BLR', 'Tuesday', '11:00:00', '14:00:00', 0, 4500, 3, 0),
(5, '6E-5334', 'Indigo', 'CCU', 'MAA', 'Wednesday', '12:00:00', '17:00:00', 0, 7000, 3, 0),
(6, '1R-456', 'SpiceJet', 'CCU', 'BLR', 'Wednesday', '16:00:00', '23:15:00', 2, 10000, 7, 15);

-- --------------------------------------------------------

--
-- Table structure for table `flight_stops`
--

DROP TABLE IF EXISTS `flight_stops`;
CREATE TABLE IF NOT EXISTS `flight_stops` (
  `flight_id` int(11) NOT NULL,
  `dest_city` varchar(11) NOT NULL,
  `stop_no` varchar(11) NOT NULL,
  `duration_hrs` int(11) NOT NULL,
  `duration_min` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `flight_stops`
--

INSERT INTO `flight_stops` (`flight_id`, `dest_city`, `stop_no`, `duration_hrs`, `duration_min`) VALUES
(2, 'BBSR', '1', 0, 30),
(6, 'BBSR', '1', 0, 30),
(6, 'MAA', '2', 1, 30);

-- --------------------------------------------------------

--
-- Table structure for table `offers`
--

DROP TABLE IF EXISTS `offers`;
CREATE TABLE IF NOT EXISTS `offers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `src` varchar(10) NOT NULL,
  `dest` varchar(10) NOT NULL,
  `start_time` datetime NOT NULL,
  `end_time` datetime NOT NULL,
  `discount` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

--
-- Dumping data for table `offers`
--

INSERT INTO `offers` (`id`, `src`, `dest`, `start_time`, `end_time`, `discount`) VALUES
(2, 'CCU', 'BLR', '2019-10-20 00:31:00', '2019-10-20 17:56:00', 15),
(3, 'CCU', 'BBSR', '2019-10-20 00:00:00', '2019-10-20 16:59:00', 10),
(4, 'CCU', 'MAA', '2019-10-20 00:00:00', '2019-10-22 00:00:00', 20);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
