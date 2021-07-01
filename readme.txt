#-------------------------------------------------
install rapidxml
sudo apt install librapidxml-dev -y

====================================
psql -U rinat -d test -h 127.0.0.1 -W
\i /home/rinat/work_dir/perfect/solution.sql






SELECT datname FROM pg_database; - list of all database
\l - list database
\c testdb - connect to db

CREATE TABLE accounts (
	user_id serial PRIMARY KEY,
	username VARCHAR ( 50 ) UNIQUE NOT NULL,
	password VARCHAR ( 50 ) NOT NULL,
	email VARCHAR ( 255 ) UNIQUE NOT NULL,
	created_on TIMESTAMP NOT NULL,
        last_login TIMESTAMP 
);

\dt - list of table
\dt+


==============initial===============
sudo -u postgres psql
postgres=# create database mydb;
postgres=# create user rinat with encrypted password '05203';
postgres=# grant all privileges on database mydb to rinat;

====================================
psql -U rinat -d test -h 127.0.0.1 -W
