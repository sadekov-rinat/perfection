sudo -u postgres psql
create database mydb
grant all privileges on database mydb to rinat
/q
psql -U rinat -d mydb -h 127.0.0.1 -W
