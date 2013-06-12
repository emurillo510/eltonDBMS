set echo=on
rem TEST1.BAT - test driver for CS157B/CS167B project
rem Clean up
del dbfile.bin *.tab *.bak?
rem ==========================================================================================
rem #01 Test setup - create table + insert data
db "create table class ( student char(10), gender char(1), exams int, quiz int, total int )"
rem ------------------------------------------------------------------------------------------
rem #02 Insert 15 rows of data
db "insert into class values ('siu', 'M', 480, 80, 560)"
db "insert into class values ('Frank', 'M', 600, 100, 700)"
db "insert into class values ('Jordon', 'M', 450, 75, 525)"
db "insert into class values ('Jeff', 'M', 455, 60, 515)"
db "insert into class values ('Ying', 'F', 540, 85, 625)"
db "insert into class values ('David', 'M', 550, 83, 633)"
db "insert into class values ('euna', 'F', 460, 75, 535)"
db "insert into class values ('Victor', 'M', 475, 60, 535)"
db "insert into class values ('Bad1', 'F', 200, NULL, 220)"
db "insert into class values ('Linawati', 'F', 490, 86, 576)"
db "insert into class values ('Bad2', 'F', 210, NULL, 225)"
db "insert into class values ('Stephen', 'M', 520, 76, 596)"
db "insert into class values ('Parichart', 'F', 450, 76, 526)"
db "insert into class values ('Bad3', 'M', NULL, 15, 205)"
db "insert into class values ('Quoc', 'M', 500, 85, 585)"
rem ------------------------------------------------------------------------------------------
rem #dir
dir
rem ------------------------------------------------------------------------------------------
rem #type class.bat
type class.dat
rem ------------------------------------------------------------------------------------------
rem #03 & #04 Simple select * & verify headings & verify NULL display with -
db "select * from class"
rem ------------------------------------------------------------------------------------------
rem ==========================================================================================
rem Error Testing Section
rem Setup the table
db "create table test (col1 char(10), col2 int, col3 int not null)"
rem ------------------------------------------------------------------------------------------
db "insert into test values ( 'one', 1, 11 )"
db "insert into test values ( 'two', 2, 22 )"
rem ------------------------------------------------------------------------------------------
db "select * from test"
rem ------------------------------------------------------------------------------------------
rem #05 "syntax errors in various INSERT statement combinations"
db "insert into test ( 'not_null', 1, '11' )"
db "insert into test values ( 'not_null', 1 )"
rem ------------------------------------------------------------------------------------------
rem #06 "data type mismatch"
db "insert into test values ( 'not_null', 1, 'string' )"
rem ------------------------------------------------------------------------------------------
rem #07 NOT NULL on inserts
db "insert into test values ( 'not_null', 1, NULL )"
