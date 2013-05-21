set echo=on
rem
rem TEST1.BAT - test driver for CS157B/CS167B project
rem
rem Clean up
del dbfile.bin *.tab *.bak?
rem
rem #1 Test setup - create table + insert data
rem
db "create table class ( student char(10), gender char(1), exams int, quiz int, total int )"
rem
rem #2 Insert 15 rows of data
rem
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
rem
rem #3 & #4 Simple select * & verify headings & verify NULL display with -
rem
db "select * from class"
rem
rem #5 Single row delete
rem
db "delete from class where student = 'Bad3'"
db "select * from class"
rem
rem #6 Delete when 0 row matched
rem
db "delete from class where student = 'Nobody'"
db "select * from class"
rem
rem #7 Multi-row delete, bad1 and bad2 should be deleted
rem
db "delete from class where total < 250"
db "select * from class"
rem
rem #8 Single row update
rem
db "update class set exams = 600 where student = 'David'"
db "select * from class"
rem
rem #9 Update with no row matched
rem
db "update class set exams = 999 where student = 'Nobody'"
rem
rem #10 Multi-row updates,  Jordan & Jeff are now 'F'
rem
db "update class set gender = 'F' where total < 526
db "select * from class"
rem
rem #11 Single column select without WHERE clause
rem
db "select student from class
rem
rem #12 Multi-column select without WHERE clause
rem
db "select total, student from class
rem
rem #13 Select with WHERE clause with a single condition
rem
db "select * from class where total > 600"
rem
rem #14 Select with where clause and AND keyword
rem
db "select * from class where total > 570 and gender = 'M'"
rem
rem #15 Select with where clause and OR keyword
rem
db "select * from class where total > 570 or gender = 'F'"
db "select * from class where total > 600"
rem
rem #16 Select with ORDER BY clause
rem
db "select student from class order by student"
db "select * from class order by total desc"
rem
rem #17 Select with WHERE and ORDER BY clauses
rem
db "select * from class where total > 570 order by total"
rem
rem #18 Select SUM()
rem
db "select SUM(quiz) from class"
rem
rem #19 Select SUM() with where clause
rem
db "select SUM(total) from class where total > 600"
rem
rem #20 Select AVG()
rem
db "select AVG(quiz) from class"
rem
rem #21 Select AVG() with where clause
rem
db "select AVG(total) from class where total > 600"
rem
rem #22 Select COUNT()
rem
db "select COUNT(*) from class"
rem
rem #23 Select COUNT() with where clause
rem
db "select COUNT(total) from class where total > 600"
rem
rem #24 Test SUM(), AVG() when there are NULLs.
rem
db "select * from class"
db "update class set exams = NULL where student = 'David'" 
db "update class set quiz = NULL where student = 'Stephen'" 
db "select avg(exams) from class"
db "select sum(quiz) from class"
rem
rem #25 Test COUNT(*), COUNT(Quiz_Total) when there are NULLs.
rem
db "select COUNT(*) from class"
db "select COUNT(exams) from class"
rem
rem Error Testing Section
rem
rem Setup the table
db "create table test (col1 char(10), col2 int, col3 int not null)"
db "insert into test values ( 'one', 1, 11 )"
db "insert into test values ( 'two', 2, 22 )"
db "select * from test"
rem
rem #26 "syntax errors in various INSERT statement combinations"
rem
db "insert into test ( 'not_null', 1, '11' )"
db "insert into test values ( 'not_null', 1 )"
rem
rem #27 "syntax errors in various UPDATE statement combinations"
rem
db "update test set col5 = NULL where col2 = 1"
db "update test5 set col3 = NULL where col2 = 1"
rem
rem #28 "syntax errors in various SELECT statement combinations"
rem
db "select col1, * from test"
db "select count(*) from test order by col2"
db "select col1, count(col2) from test"
db "select col5 from test"
rem
rem #29 "data type mismatch"
rem
db "insert into test values ( 'not_null', 1, 'string' )"
rem
rem #30 NOT NULL on inserts
rem
db "insert into test values ( 'not_null', 1, NULL )"
rem 
rem #31 NOT NULL updates
rem
db "update test set col3 = NULL where col2 = 1"
rem
rem #32 Catch “data type mismatch” errors on WHERE clauses of update, delete, select.
rem
db "update test set col3 = 'Frank' where col2 = 2"
db "delete from test where col2 = 'two'"
db "select * from test where col1 > 200"
rem
rem #33. “invalid data value” errors.
rem
db "update test set col1 = 'stringlargerthan10' where col2 = 2"
rem
rem #34. "invalid relational operator" & "invalid aggregate function parameter" errors
rem
db "select * from test where col2 not = 100"
db "select AVG(col1) from test"
rem
rem End of test1.bat

