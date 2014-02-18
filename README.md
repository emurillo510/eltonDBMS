eltonDBMS
=========

Project eltonDBMS is an small implementation of a database management system that I wrote it. It is a command-line based application that takes in grammar that mimics the SQL syntax. Essentially it is a parser that parses an input string and verifies each token to see if it fits the grammar, if the input is a valid input eventually the data will be saved persistently in a text file. 

db.cpp - parses sql statements, tokenizes each string and, throws error-code if violates grammer
db.h - header files containing all error codes and tree data structure for holding tokenized strings
=======
