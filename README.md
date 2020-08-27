


sudo mysql -u root -p

password: 

mysql --help

scroll the terminal: ctrl+shift + arrow up/down

mysql -h host -u user -p
Enter Password: ******* 

mysql -u user -p 

mysql 

QUIT

SHOW DATABASES;
CREATE DATABASE database_name;   // CREATE DATABASE test;

USE database_name;  // USE test;

SHOW tables;


CREATE TABLE potluck (id INT NOT NULL PRIMARY KEY AUTO_INCREMENT, 
name VARCHAR(20),
food VARCHAR(30),
confirmed CHAR(1), 
signup_date DATE);

SHOW TABLES;

DESCRIBE potluck;


INSERT INTO `potluck` (`id`,`name`,`food`,`confirmed`,`signup_date`) VALUES (NULL, "John", "Casserole","Y", '2012-04-11');


1INSERT INTO `potluck` (`id`,`name`,`food`,`confirmed`,`signup_date`) VALUES (NULL, "Sandy", "Key Lime Tarts","N", '2012-04-14');
INSERT INTO `potluck` (`id`,`name`,`food`,`confirmed`,`signup_date`) VALUES (NULL, "Tom", "BBQ","Y", '2012-04-18');
INSERT INTO `potluck` (`id`,`name`,`food`,`confirmed`,`signup_date`) VALUES (NULL, "Tina", "Salad","Y", '2012-04-10'); 



UPDATE `potluck` 
SET 
`confirmed` = 'Y' 
WHERE `potluck`.`name` ='Sandy';



ALTER TABLE potluck ADD email VARCHAR(40);

ALTER TABLE potluck ADD email VARCHAR(40) AFTER name; 

ALTER TABLE potluck DROP email;

DELETE from [table name] where [column name]=[field text];

DELETE from potluck  where name='Sandy';



https://www.digitalocean.com/community/tutorials/a-basic-mysql-tutorial




https://github.com/duaraghav8/MySQL-CPP-Integration/blob/master/basic_connection.cpp


https://github.com/bskari/mysql-cpp





