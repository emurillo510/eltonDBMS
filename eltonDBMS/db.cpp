/************************************************************
	Project#1:	CLP & DDL
	author: Elton Murillo
	date: 4/5/2012
	school: San Jose State University
 ************************************************************/

#include "db.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>

int main(int argc, char** argv)

{
	int rc = 0;
	token_list *tok_list=NULL, *tok_ptr=NULL, *tmp_tok_ptr=NULL;


	/* His test cases */

	//argv[1] = "create table class2 ( student char(10), gender char(1), exams int, quiz int, total int )";
	//argv[1] = "create table class2 ( student char(10) not null , gender char(1) not null, exams int not null, quiz int not null, total int not null)";
	
	/* Delete cases */
	//argv[1]  = "delete from class2 where student = 'Elton'";
	//argv[1]  = "delete from class2 where student > 'Elton'";
	//argv[1]  = "delete from class2 where exams = null";

	/* Update cases */
	//argv[1] = "update class2 set quiz = 13337 where exams < 500";
	//argv[1] = "update class2 set student = 'Kobe' where student = 'Elton'";
	//argv[1] = "update class2 set gender = 'F' where total < 526";
	//argv[1] = "update class2 set exams = 13337 where student = NULL";
	//argv[1] = "update class2 set student = 'Elton' where student = NULL";

	/* Select cases */

	//argv[1] = "select * from class2";
	//argv[1] = "select * from class2 fsafsa";
	//argv[1] = "select * from class2 where student > 'Frank'";
	//argv[1] = "select * from class2 where exams > 500";
	//argv[1] = "select * from class2 where student = 'Elton'";
	//argv[1] = "select * from class2 where exams is null";
	//argv[1] = "select * from class2 where exams is not null";

	//argv[1] = "select * from class2 where student = 'Elton' and exams = 1";
	//argv[1] = "select * from class2 where student = 'Elton' and exams = 1";
	//argv[1] = "select * from class2 where student = 'Bad3' and exams = NULL";
	//argv[1] = "select * from class2 where exams =  NULL and student = null";
	//argv[1] = "select * from class2 where exams =  NULL and student > 'a'";
	//argv[1] = "select * from class2 where exams =  NULL and exams > NULL";
	//argv[1] = "select * from class2 where student <  NULL and exams = null";
	//argv[1] = "select * from class2 where student <  NULL and exams is null";
	//argv[1] = "select * from class2 where student is null"; //not working
	//argv[1] = "select * from class2 where student is null"; //not working
  	//argv[1] = "select * from class2 where student < 'G' and student > 'A'";
	//argv[1] = "select * from class2 where student = 'Elton' and exams is not null";
	//argv[1] = "select * from class2";
	//argv[1] = "select * from class2 where student = 'Elton' and exams is not null";
	//argv[1] = "select * from class2 where student = null or student = 1000";
  	//argv[1] = "select * from class2 where student = 'Elton' or exams is null";
	//argv[1] = "select * from class2 where student = 'Elton'";
	//argv[1] = "select * from class2 where exams = 600 and student is null"; //not working
	//argv[1] = "select * from class2 where exams < 700 and student > 'A'";


	//argv[1] = "select * from class2 where student = 'Elton' order by student desc";
	//argv[1] = "select * from class2 where student = 'Elton' and exams is null order by student desc";
    //argv[1] = "select * from class2 where student is null and exams is null order by student desc";
	//argv[1] = "select * from class2 order by student";
	//argv[1] = "select * from class2 order by student desc";

	//argv[1] = "select SUM(student) from class2";
	//argv[1] = "select SUM(quiz) from class2";

	//argv[1] = "insert into class2 values ('siu', 'M', 480, 80, 560)";
	//argv[1] = "insert into class2 values ('Frank', 'M', 600, 100, 700)";
	//argv[1] = "insert into class2 values ('Jordon', 'M', 450, 75, 525)";
	//argv[1] = "insert into class2 values ('Jeff', 'M', 455, 60, 515)";
	//argv[1] = "insert into class2 values ('Ying', 'F', 540, 85, 625)";
	//argv[1] = "insert into class2 values ('David', 'M', 550, 83, 633)";
	//argv[1] = "insert into class2 values ('euna', 'F', 460, 75, 535)";
	//argv[1] = "insert into class2 values ('Victor', 'M', 475, 60, 535)";
	//argv[1] = "insert into class2 values ('Bad1', 'F', 200, NULL, 220)";
	//argv[1] = "insert into class2 values ('Linawati', 'F', 490, 86, 576)"; //error here
	//argv[1] = "insert into class2 values ('Bad2', 'F', 210, NULL, 225)";
	//argv[1] = "insert into class2 values ('Stephen', 'M', 520, 76, 596)";
	//argv[1] = "insert into class2 values ('Parichart', 'F', 450, 76, 526)";
	//argv[1] = "insert into class2 values ('Bad3', 'M', NULL, 15, 205)";
	//argv[1] = "insert into class2 values ('Quoc', 'M', 500, 85, 585)";
	//argv[1] = "insert into class2 values (NULL,NULL,NULL,NULL,NULL)";
	//argv[1] = "insert into class2 values ('Elton', 'M', 1000, 1000, 1000)";

	//argv[1] = "insert into class values ('siu', 'M', 480, 80, 560)";
	//argv[1] = "insert into class values ('Frank', 'M', 600, 100, 700)";
	//argv[1] = "insert into class values ('Jordon', 'M', 450, 75, 525)";
	//argv[1] = "insert into class values ('Jeff', 'M', 455, 60, 515)";
	//argv[1] = "insert into class values ('Ying', 'F', 540, 85, 625)";
	//argv[1] = "insert into class values ('David', 'M', 550, 83, 633)";
	//argv[1] = "insert into class values ('euna', 'F', 460, 75, 535)";
	//argv[1] = "insert into class values ('Victor', 'M', 475, 60, 535)";
	//argv[1] = "insert into class values ('Bad1', 'F', 200, NULL, 220)";
	//argv[1] = "insert into class values ('Linawati', 'F', 490, 86, 576)"; //error here
	//argv[1] = "insert into class values ('Bad2', 'F', 210, NULL, 225)";
	//argv[1] = "insert into class values ('Stephen', 'M', 520, 76, 596)";
	//argv[1] = "insert into class values ('Parichart', 'F', 450, 76, 526)";
	//argv[1] = "insert into class values ('Bad3', 'M', NULL, 15, 205)";
	//argv[1] = "insert into class2 values ('john doe', 'M', 122, 50, 1000)";

	

	
	//argv[1] = "select * from class";
	
	//argv[1] = "delete from class where student = 'Nobody'";
	//argv[1] = "select * from class";

	//argv[1] = "delete from class where total < 250";
	//argv[1] = "select * from class";

	//argv[1] = "update class set exams = 600 where student = 'David'";
	//argv[1] = "select * from class";

	//argv[1] = "update class set exams = 999 where student = 'Nobody'";

	//argv[1] = "update class set gender = 'F' where total < 526";
	//argv[1] = "select * from class";

	//argv[1] = "select student from class;
	
	//argv[1] = "select total, student from class;

	//argv[1] = "select * from class where total > 600";

	//argv[1] = "select * from class where total > 570 and gender = 'M'";

	//argv[1] = "select * from class where total > 570 or gender = 'F'";
	//argv[1] = "select * from class where total > 600";

	//argv[1] = "select student from class order by student";
	//argv[1] = "select * from class order by total desc";

	//argv[1] = "select * from class where total > 570 order by total";

	//argv[1] = "select SUM(quiz) from class";

	//argv[1] = "select SUM(total) from class where total > 600";

	//argv[1] = "select AVG(quiz) from class";

	//argv[1] = "select AVG(total) from class where total > 600"

	//argv[1] = "select COUNT(*) from class";

	//argv[1] = "select COUNT(total) from class where total > 600";

	//argv[1] = "select * from class";

	//argv[1] = "update class set exams = NULL where student = 'David'" ;
	//argv[1] = "update class set quiz = NULL where student = 'Stephen'";	
	//argv[1] = "select avg(exams) from class";
	//argv[1] = "select sum(quiz) from class";

	//argv[1] = "select COUNT(*) from class";
	//argv[1] = "select COUNT(exams) from class";

	//argv[1] = "create table test (col1 char(10), col2 int, col3 int not null)";
	//argv[1] = "insert into test values ( 'one', 1, 11 )";
	//argv[1] = "insert into test values ( 'two', 2, 22 )";
	//argv[1] = "select * from test";

	//argv[1] = "insert into test ( 'not_null', 1, '11' )";
	//argv[1] = "insert into test values ( 'not_null', 1 )";

	//argv[1] = "update test set col5 = NULL where col2 = 1";
	//argv[1] = "update test5 set col3 = NULL where col2 = 1";

	//argv[1] = "select col1, * from test";
	//argv[1] = "select count(*) from test order by col2";
	//argv[1] = "select col1, count(col2) from test";
	//argv[1] = "select col5 from test";

	//argv[1] = "insert into test values ( 'not_null', 1, 'string' )";

	//argv[1] = "insert into test values ( 'not_null', 1, NULL )";

	//argv[1] = "update test set col3 = NULL where col2 = 1";

	//argv[1] = "update test set col3 = 'Frank' where col2 = 2";
	//argv[1] = "delete from test where col2 = 'two'";
	//argv[1] = "select * from test where col1 > 200";
	
	//argv[1] = "update test set col1 = 'stringlargerthan10' where col2 = 2";
	
	//argv[1] = "select * from test where col2 not = 100";
	//argv[1] = "select AVG(col1) from test";

	/* END OF HIS CASES */

	//argv[1] = "insert into elton3 values(2 ,3)"; 
 	//if ((argc != 2) || (strlen(argv[1]) == 0))
 	//{
  	//	printf("Usage: db \"command statement\"");
 	//	return 1;
 	//}

	rc = initialize_tpd_list();
	if (rc)
	{
	printf("\nError in initialize_tpd_list().\nrc = %d\n", rc);
    }
	else
	{
    rc = get_token(argv[1], &tok_list);

		/* Test code */
		tok_ptr = tok_list;
		while (tok_ptr != NULL)
		{
			printf("%16s \t%d \t %d\n",tok_ptr->tok_string, tok_ptr->tok_class,
				      tok_ptr->tok_value);
			tok_ptr = tok_ptr->next;
		}
    
		if (!rc)
		{
			rc = do_semantic(tok_list);
		}

		if (rc)
		{
			tok_ptr = tok_list;
			while (tok_ptr != NULL)
			{
				if ((tok_ptr->tok_class == error) ||
					  (tok_ptr->tok_value == INVALID))
				{
					printf("\nError in the string: %s\n", tok_ptr->tok_string);
					printf("rc=%d\n", rc);
					break;
				}
				tok_ptr = tok_ptr->next;
			}
		}

    /* Whether the token list is valid or not, we need to free the memory */
		tok_ptr = tok_list;
		while (tok_ptr != NULL)
		{
      tmp_tok_ptr = tok_ptr->next;
      free(tok_ptr);
      tok_ptr=tmp_tok_ptr;
		}
	}

	return rc;
}

/************************************************************* 
	This is a lexical analyzer for simple SQL statements
 *************************************************************/
int get_token(char* command, token_list** tok_list)
{
	int rc=0,i,j;
	char *start, *cur, temp_string[MAX_TOK_LEN];
	bool done = false;
	
	start = cur = command;
	while (!done)
	{
		bool found_keyword = false;

		/* This is the TOP Level for each token */
	  memset ((void*)temp_string, '\0', MAX_TOK_LEN);
		i = 0;

		/* Get rid of all the leading blanks */
		while (*cur == ' ')
			cur++;

		if (cur && isalpha(*cur))
		{
			// find valid identifier
			int t_class;
			do 
			{
				temp_string[i++] = *cur++;
			}
			while ((isalnum(*cur)) || (*cur == '_'));

			if (!(strchr(STRING_BREAK, *cur)))
			{
				/* If the next char following the keyword or identifier
				   is not a blank, (, ), or a comma, then append this
					 character to temp_string, and flag this as an error */
				temp_string[i++] = *cur++;
				add_to_list(tok_list, temp_string, error, INVALID);
				rc = INVALID;
				done = true;
			}
			else
			{

				// We have an identifier with at least 1 character
				// Now check if this ident is a keyword
				for (j = 0, found_keyword = false; j < TOTAL_KEYWORDS_PLUS_TYPE_NAMES; j++)
				{
					if ((stricmp(keyword_table[j], temp_string) == 0))
					{
						found_keyword = true;
						break;
					}
				}

				if (found_keyword)
				{
				  if (KEYWORD_OFFSET+j < K_CREATE)
						t_class = type_name;
					else if (KEYWORD_OFFSET+j >= F_SUM)
					   t_class = function_name;
				    else
					   t_class = keyword;
					 
					add_to_list(tok_list, temp_string, t_class, KEYWORD_OFFSET+j);
				}
				else
				{
					if (strlen(temp_string) <= MAX_IDENT_LEN)
					  add_to_list(tok_list, temp_string, identifier, IDENT);
					else
					{
						add_to_list(tok_list, temp_string, error, INVALID);
						rc = INVALID;
						done = true;
					}
				}

				if (!*cur)
				{
					add_to_list(tok_list, "", terminator, EOC);
					done = true;
				}
			}
		}
		else if (isdigit(*cur))
		{
			// find valid number
			do 
			{
				temp_string[i++] = *cur++;
			}
			while (isdigit(*cur));

			if (!(strchr(NUMBER_BREAK, *cur)))
			{
				/* If the next char following the keyword or identifier
				   is not a blank or a ), then append this
					 character to temp_string, and flag this as an error */
				temp_string[i++] = *cur++;
				add_to_list(tok_list, temp_string, error, INVALID);
				rc = INVALID;
				done = true;
			}
			else
			{
				add_to_list(tok_list, temp_string, constant, INT_LITERAL);

				if (!*cur)
				{
					add_to_list(tok_list, "", terminator, EOC);
					done = true;
				}
			}
		}
		else if ((*cur == '(') || (*cur == ')') || (*cur == ',') || (*cur == '*')
		         || (*cur == '=') || (*cur == '<') || (*cur == '>'))
		{
			/* Catch all the symbols here. Note: no look ahead here. */
			int t_value;
			switch (*cur)
			{
				case '(' : t_value = S_LEFT_PAREN; break;
				case ')' : t_value = S_RIGHT_PAREN; break;
				case ',' : t_value = S_COMMA; break;
				case '*' : t_value = S_STAR; break;
				case '=' : t_value = S_EQUAL; break;
				case '<' : t_value = S_LESS; break;
				case '>' : t_value = S_GREATER; break;
			}

			temp_string[i++] = *cur++;

			add_to_list(tok_list, temp_string, symbol, t_value);

			if (!*cur)
			{
				add_to_list(tok_list, "", terminator, EOC);
				done = true;
			}
		}
    else if (*cur == '\'')
    {
      /* Find STRING_LITERRAL */
			int t_class;
      cur++;
			do 
			{
				temp_string[i++] = *cur++;
			}
			while ((*cur) && (*cur != '\''));

      temp_string[i] = '\0';

	  //add string break here. ------------------------------------

			if (!*cur)
			{
				/* If we reach the end of line */
				add_to_list(tok_list, temp_string, error, INVALID);
				rc = INVALID;
				done = true;
			}
      else /* must be a ' */
      {
        add_to_list(tok_list, temp_string, constant, STRING_LITERAL);
        cur++;
				if (!*cur)
				{
					add_to_list(tok_list, "", terminator, EOC);
					done = true;
        }
      }
    }
		else
		{
			if (!*cur)
			{
				add_to_list(tok_list, "", terminator, EOC);
				done = true;
			}
			else
			{
				/* not a ident, number, or valid symbol */
				temp_string[i++] = *cur++;
				add_to_list(tok_list, temp_string, error, INVALID);
				rc = INVALID;
				done = true;
			}
		}
	}
			
  return rc;
}

void add_to_list(token_list **tok_list, char *tmp, int t_class, int t_value)
{
	token_list *cur = *tok_list;
	token_list *ptr = NULL;

	// printf("%16s \t%d \t %d\n",tmp, t_class, t_value);

	ptr = (token_list*)calloc(1, sizeof(token_list));
	strcpy(ptr->tok_string, tmp);
	ptr->tok_class = t_class;
	ptr->tok_value = t_value;
	ptr->next = NULL;

  if (cur == NULL)
		*tok_list = ptr;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;

		cur->next = ptr;
	}
	return;
}

int do_semantic(token_list *tok_list)
{
	int rc = 0, cur_cmd = INVALID_STATEMENT;
	bool unique = false;
    token_list *cur = tok_list;

	if ((cur->tok_value == K_CREATE) &&
			((cur->next != NULL) && (cur->next->tok_value == K_TABLE)))
	{
		printf("CREATE TABLE statement\n");
		cur_cmd = CREATE_TABLE;
		cur = cur->next->next;
	}
	else if ((cur->tok_value == K_DROP) &&
					((cur->next != NULL) && (cur->next->tok_value == K_TABLE)))
	{
		printf("DROP TABLE statement\n");
		cur_cmd = DROP_TABLE;
		cur = cur->next->next;
	}
	else if ((cur->tok_value == K_LIST) &&
					((cur->next != NULL) && (cur->next->tok_value == K_TABLE)))
	{
		printf("LIST TABLE statement\n");
		cur_cmd = LIST_TABLE;
		cur = cur->next->next;
	}
	else if ((cur->tok_value == K_LIST) &&
					((cur->next != NULL) && (cur->next->tok_value == K_SCHEMA)))
	{
		printf("LIST SCHEMA statement\n");
		cur_cmd = LIST_SCHEMA;
		cur = cur->next->next;
	}
	else if ((cur->tok_value == K_INSERT) &&
					((cur->next != NULL) && (cur->next->tok_value == K_INTO)))
	{
		printf("INSERT statement\n");
		cur_cmd = INSERT;
		cur = cur->next->next;


	} else if ((cur->tok_value == K_DELETE) &&
					((cur->next != NULL) && (cur->next->tok_value == K_FROM)))
	{ 
		printf("DELETE statement\n");
		cur_cmd = DELETE;
		cur = cur->next->next;


	}
	else if (cur->tok_value == K_UPDATE)
	{ 
		printf("UPDATE statement\n");
		cur_cmd = UPDATE;
		cur = cur->next;


	}else if (cur->tok_value == K_SELECT)
	{ 
		printf("SELECT statement\n");
		cur_cmd = SELECT;
		cur = cur->next;


	} else 
    {
		printf("Invalid statement\n");
		rc = cur_cmd;
	}

	if (cur_cmd != INVALID_STATEMENT)
	{
		switch(cur_cmd)
		{
			case CREATE_TABLE:
						rc = sem_create_table(cur);
						break;
			case DROP_TABLE:
						rc = sem_drop_table(cur);
						break;
			case LIST_TABLE:
						rc = sem_list_tables();
						break;
			case LIST_SCHEMA:
						rc = sem_list_schema(cur);
						break;
			case INSERT:
						rc = sem_insert(cur);
						break;
			case DELETE: 
						rc = sem_delete(cur);
						break;
			case UPDATE: 
						rc = sem_update(cur);
						break;
			case SELECT:

						rc = sem_select(cur);
						break;
			default:
					; /* no action */
		}
	}
	
	return rc;
}

/* 
This method creates the table and processes input create statement by advancing the token and handling all possible errors
*/
int sem_create_table(token_list *t_list)
{
	int rc = 0; //return code
	token_list *cur; //pointer to curent token
	tpd_entry tab_entry; //column name
	tpd_entry *new_entry = NULL; //column pointer 
	bool column_done = false; //the last right paren for creating table statement
	int cur_id = 0; //first column
	cd_entry	col_entry[MAX_NUM_COL];  // column struct 
	FILE *fhandle = NULL; //file declaration used for table info
	char *tablename = NULL;//table name


	memset(&tab_entry, '\0', sizeof(tpd_entry)); //puts empty string inside memory of table_entry
	cur = t_list; //assigns cursor to the token list

	//checks if token is a string other then keyword, identifier, type_name
	if ((cur->tok_class != keyword) &&
		  (cur->tok_class != identifier) &&
			(cur->tok_class != type_name))
	{
		// Error
		rc = INVALID_TABLE_NAME;
		cur->tok_value = INVALID;
	}
	else
	{
		/*calls a getter for table packed descriptor to find the target string and sees if it is duplicate.*/
		if ((new_entry = get_tpd_from_list(cur->tok_string)) != NULL)
		{
			rc = DUPLICATE_TABLE_NAME;
			cur->tok_value = INVALID;
			printf("ERROR - The Table Name already exists."); //print error "ERROR - The Table Name already exists."
		}
		else
		{

			strcpy(tab_entry.table_name, cur->tok_string); //sets the table name to the token string
			cur = cur->next; //moves the token to the next token

			if (cur->tok_value != S_LEFT_PAREN) //checks if the token is a "(".
			{
				//Error the next string is anything other then a "(" throw error
				rc = INVALID_TABLE_DEFINITION;
				cur->tok_value = INVALID;
			}
			else
			{
				/*
				puts empty string inside memory.
				allocates max num of columns * size of entry.
				*/
				memset(&col_entry, '\0', (MAX_NUM_COL * sizeof(cd_entry)));

				/* Now build a set of column entries */
				cur = cur->next;
				do
				{
					if ((cur->tok_class != keyword) &&
							(cur->tok_class != identifier) &&
							(cur->tok_class != type_name))
					{
						// Error: INVALID_COLUMN_NAME, THEN SETS RC TO INVALID
						rc = INVALID_COLUMN_NAME;
						cur->tok_value = INVALID;
					}
					else
					{
						//process the statement
						int i;
						for(i = 0; i < cur_id; i++)
						{
              /* make column name case sensitive */
							//checks to see if the token string is in the column entries
							if (strcmp(col_entry[i].col_name, cur->tok_string)==0)
							{
								/*Error: the column exists in the list
								sets the token valid to invalid
								*/
								rc = DUPLICATE_COLUMN_NAME;
								cur->tok_value = INVALID;
								printf("ERROR - The Column Name is already used.");
								break;
							}
						}

						if (!rc) //first column = cur_id = 0 , successful creation of the column
						{
							/*sets the token string to the column name.
							assigns the column id using the cur_id variable.
							default value is not null
							*/
						
							strcpy(col_entry[cur_id].col_name, cur->tok_string);
							col_entry[cur_id].col_id = cur_id;
							col_entry[cur_id].not_null = false;    /* set default */

							cur = cur->next; //advances the next token

							//if the current token is anything other than a type then it is invalid
							if (cur->tok_class != type_name)
							{
								/* Error:token is not a valid type.
								set the current token valid to invalid.
								*/
								rc = INVALID_TYPE_NAME;
								cur->tok_value = INVALID;
							}
							else
							{
                /* Set the column type here, int or char */ // at this point we are checking type
								col_entry[cur_id].col_type = cur->tok_value; //stores type into column id
								cur = cur->next; //advances the token
		
								if (col_entry[cur_id].col_type == T_INT) //error checking if it is an int
		
								{
									/*
									if the token is anything other than a c "," "NOT", or ")"
									*/
									if ((cur->tok_value != S_COMMA) &&
										  (cur->tok_value != K_NOT) &&
										  (cur->tok_value != S_RIGHT_PAREN))
									{
										/*
										sets the return code to an INVALID COLUMN DEFINITION.
										sets the token value to invalid
										*/
										rc = INVALID_COLUMN_DEFINITION;
										cur->tok_value = INVALID;
									}
								  else //filling information about column length for integer case.
									{
										col_entry[cur_id].col_len = sizeof(int); //sets the column length to size of int
										
										/*
										 error handling checking if the column anything other than "NOT NULL"	 
										*/
										if ((cur->tok_value == K_NOT) &&
											  (cur->next->tok_value != K_NULL))  
										{
											/* 
											 sets rc to INVALID_COLUMN_DEFINITION
											 sets current token to INVALID
										    */
											rc = INVALID_COLUMN_DEFINITION;
											cur->tok_value = INVALID;
										}	
										else if ((cur->tok_value == K_NOT) &&
											    (cur->next->tok_value == K_NULL)) //checks if the token is a "NOT NULL"
										{					
											col_entry[cur_id].not_null = true; //set column to NOT NULL
											cur = cur->next->next; //advances token
										}
	
										if (!rc)
										{
											/* I must have either a comma or right paren */
											if ((cur->tok_value != S_RIGHT_PAREN) &&
												  (cur->tok_value != S_COMMA))
											{
												
												rc = INVALID_COLUMN_DEFINITION;//the return code is set to INVALID_COLUMN_DEFINITION
												cur->tok_value = INVALID;//sets the current token to INVALID
											}
											else
											{         //if the token valid is a ")"
												if (cur->tok_value == S_RIGHT_PAREN)
												{
 													column_done = true; //column done flag is set to true. (meaning we are done processing everything
												}
												cur = cur->next; //advances cursor
											}
										}
									}
								}   // end of S_INT processing
								else
								{
									// It must be char()
									if (cur->tok_value != S_LEFT_PAREN)
									{
										rc = INVALID_COLUMN_DEFINITION; //return code is set to INVALID_COLUMN_DEFINITION
										cur->tok_value = INVALID; //the current token is set to INVALID
									}
									else
									{
										/* Enter char(n) processing */
										cur = cur->next; // points at ( n ) 
		
										if (cur->tok_value != INT_LITERAL)
										{
											rc = INVALID_COLUMN_LENGTH; //the return code is set to INVALID_COLUMN_LENGTH
											cur->tok_value = INVALID; //the current token value is set to INVALID
										}
										else
										{
											/* Got a valid integer - convert */
											col_entry[cur_id].col_len = atoi(cur->tok_string); //converts string to int type.
											cur = cur->next; // advances pointer
											
											if (cur->tok_value != S_RIGHT_PAREN) //right paren or else invalid
											{
												rc = INVALID_COLUMN_DEFINITION; //the return code is set to INVALID_COLUMN_DEFINITION
												cur->tok_value = INVALID; //sets return code to INVALID
											}
											else
											{
												cur = cur->next; //advances token
						
												//error handling.  checks if next token is anything other then a "," "NOT" or ")" in the create statement
												if ((cur->tok_value != S_COMMA) &&
														(cur->tok_value != K_NOT) &&
														(cur->tok_value != S_RIGHT_PAREN))
												{
													rc = INVALID_COLUMN_DEFINITION; //sets the return code to INVALID_COLUMN_DEFINITION.
													cur->tok_value = INVALID; //sets the current token value to INVALID
												}
												else //process not null
												{
													if ((cur->tok_value == K_NOT) &&
														  (cur->next->tok_value != K_NULL)) //checks if the current token value is NOT NULL
													{
														rc = INVALID_COLUMN_DEFINITION; //sets the return code to INVALID_COLUMN_DEFINITION
														cur->tok_value = INVALID; //sets the current token vlaue to INVALID
													}
													else if ((cur->tok_value == K_NOT) &&
																	 (cur->next->tok_value == K_NULL)) //checks if the token value is NOT NULL, sets default to not null
													{					
														col_entry[cur_id].not_null = true; //token identifies that the create statement has NOT NULL, so it sets the column to NOT NULL
														cur = cur->next->next; //moves the token two spaces
													}

													/*need fixing */
													if (!rc)
													{
														/* I must have either a comma or right paren */
														if ((cur->tok_value != S_RIGHT_PAREN) && (cur->tok_value != S_COMMA)) //end of the create statement create .... ( c1 int not null, ...)
														{
															rc = INVALID_COLUMN_DEFINITION; //return code is set to INVALID COLUMN DEFINITION
															cur->tok_value = INVALID; //sets the curren token value to INVALID
														}
														else
													    {
															if (cur->tok_value == S_RIGHT_PAREN) //checking if the current token value is set to  ")"
															{
																column_done = true; //column is done processing
															}
															cur = cur->next; //advances the token
														}
													}
												}
											}
										}	/* end char(n) processing */
									}
								} /* end char processing */
							}
						}  // duplicate column name
					} // invalid column name

					/* If rc=0, then get ready for the next column */
					if (!rc)
					{
						cur_id++;
					}

				} while ((rc == 0) && (!column_done));
	
				if ((column_done) && (cur->tok_value != EOC)) //any invalid character after statement
				{
					rc = INVALID_TABLE_DEFINITION; //sets the return code to INVALID TABLE DEFINITION
					cur->tok_value = INVALID; //advances the token to INVALID
				}

				if (!rc)
				{
					/* Now finished building tpd and add it to the tpd list */
					tab_entry.num_columns = cur_id; //sets table entry to cur.id which at this point is the number columns
					tab_entry.tpd_size = sizeof(tpd_entry) + 
															 sizeof(cd_entry) *	tab_entry.num_columns; //size of tpd + size of column in memory (fixed) * number of columns
				    tab_entry.cd_offset = sizeof(tpd_entry); //size of table in memory
					new_entry = (tpd_entry*)calloc(1, tab_entry.tpd_size); //moving pointer from null to what ever size the table packet descriptor is

					//if the table entry is still null after doing the command above a problem occured.
					if (new_entry == NULL)
					{
						
						rc = MEMORY_ERROR; //sets the return code to MEMORY ERROR
					}
					else
					{
						//copies about information about table itself in memory !!!!!!!!what does this mean?
						memcpy((void*)new_entry,
							     (void*)&tab_entry,
									 sizeof(tpd_entry));
		
						memcpy((void*)((char*)new_entry + sizeof(tpd_entry)),
									 (void*)col_entry,
									 sizeof(cd_entry) * tab_entry.num_columns); //copy into memory, the description of the columns
	
						rc = add_tpd_to_list(new_entry); //de allocates the new entry in memory 

						//create text file with the name as table.dat(append the .dat extension to the table name)
						tablename = new_entry->table_name;
						strcat(tablename, ".dat");
						fhandle = fopen(tablename, "a+tc");
						printf("The file '%s' was created. \n", tablename);
						fprintf(fhandle, "%d\n", 0);
						printf("The command completed successfully.");

						fflush(fhandle);
						fclose(fhandle);


						free(new_entry); //de allocates the new entry in memory 
					}
				}
			}
		}
	}
  return rc;
}

/* This method drops table from list, then deletes the table.tab file and clears memory */
int sem_drop_table(token_list *t_list)
{
	int rc = 0; //return code declaration
	token_list *cur; //cursor for the token list
	tpd_entry *tab_entry = NULL; //table packed descriptor

	cur = t_list; //assigns the cursor to the first element to of the tpd

	/* invalid table name format */
	if ((cur->tok_class != keyword) &&
		  (cur->tok_class != identifier) &&
			(cur->tok_class != type_name))
	{
		
		rc = INVALID_TABLE_NAME; // Error: sets the return code to invalid table format
		cur->tok_value = INVALID; //sets the cursor to invalid
	}
	else //the case where it is not the end of character
	{
		if (cur->next->tok_value != EOC) //if the next cursor is not end of character
		{
			rc = INVALID_STATEMENT; //set the return code to invalid
			cur->next->tok_value = INVALID; //sets the cursor value to invalid
		}
		else //look for the table inside the tpd list
		{
			if ((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL) // if it tries to find the table and does not exist
			{
				rc = TABLE_NOT_EXIST; //Error: assigns the return code to TABLE DOES NOT EXIST
				cur->tok_value = INVALID; //sets the cursor value to INVALID
				printf("ERROR - No Such a Table Existed.");
			}
			else //the case where it DOES find the table, get ready to drop it.
			{
				
				rc = drop_tpd_from_list(cur->tok_string);//assigns the return code to drop tpd from list

				char *tablename = strcat(cur->tok_string, ".dat"); //gets table.tab filename
				remove(tablename); //deletes the filename using remove method
				printf("The file '%s' was dropped. \n", tablename);
				printf("The command completed successfully.");

			}
		}
	}

  return rc;
}

int sem_list_tables()
{
	int rc = 0;
	int num_tables = g_tpd_list->num_tables;
	tpd_entry *cur = &(g_tpd_list->tpd_start);

	if (num_tables == 0)
	{
		printf("\nThere are currently no tables defined\n");
	}
	else
	{
		printf("\nTable List\n");
		printf("*****************\n");
		while (num_tables-- > 0)
		{
			printf("%s\n", cur->table_name);
			if (num_tables > 0)
			{
				cur = (tpd_entry*)((char*)cur + cur->tpd_size);
			}
		}
		printf("****** End ******\n");
		printf("The command completed successfully.\n");
	}

  return rc;
}

int sem_list_schema(token_list *t_list)
{
	int rc = 0;
	token_list *cur;
	tpd_entry *tab_entry = NULL;
	cd_entry  *col_entry = NULL;
	char tab_name[MAX_IDENT_LEN+1];
	char filename[MAX_IDENT_LEN+1];
	bool report = false;
	FILE *fhandle = NULL;
	int i = 0;

	cur = t_list;

	if (cur->tok_value != K_FOR)
  {
		rc = INVALID_STATEMENT;
		cur->tok_value = INVALID;
	}
	else
	{
		cur = cur->next;

		if ((cur->tok_class != keyword) &&
			  (cur->tok_class != identifier) &&
				(cur->tok_class != type_name))
		{
			// Error
			rc = INVALID_TABLE_NAME;
			cur->tok_value = INVALID;
		}
		else
		{
			memset(filename, '\0', MAX_IDENT_LEN+1);
			strcpy(tab_name, cur->tok_string);
			cur = cur->next;

			if (cur->tok_value != EOC)
			{
				if (cur->tok_value == K_TO)
				{
					cur = cur->next;
					
					if ((cur->tok_class != keyword) &&
						  (cur->tok_class != identifier) &&
							(cur->tok_class != type_name))
					{
						// Error
						rc = INVALID_REPORT_FILE_NAME;
						cur->tok_value = INVALID;
					}
					else
					{
						if (cur->next->tok_value != EOC)
						{
							rc = INVALID_STATEMENT;
							cur->next->tok_value = INVALID;
						}
						else
						{
							/* We have a valid file name */
							strcpy(filename, cur->tok_string);
							report = true;
						}
					}
				}
				else
				{ 
					/* Missing the TO keyword */
					rc = INVALID_STATEMENT;
					cur->tok_value = INVALID;
				}
			}

			if (!rc)
			{
				if ((tab_entry = get_tpd_from_list(tab_name)) == NULL)
				{
					rc = TABLE_NOT_EXIST;
					cur->tok_value = INVALID;
				}
				else
				{
					if (report)
					{
						if((fhandle = fopen(filename, "a+tc")) == NULL)
						{
							rc = FILE_OPEN_ERROR;
						}
					}

					if (!rc)
					{
						/* Find correct tpd, need to parse column and index information */

						/* First, write the tpd_entry information */
						printf("Table PD size            (tpd_size)    = %d\n", tab_entry->tpd_size);
						printf("Table Name               (table_name)  = %s\n", tab_entry->table_name);
						printf("Number of Columns        (num_columns) = %d\n", tab_entry->num_columns);
						printf("Column Descriptor Offset (cd_offset)   = %d\n", tab_entry->cd_offset);
					    printf("Table PD Flags           (tpd_flags)   = %d\n\n", tab_entry->tpd_flags); 

						if (report)
						{
							fprintf(fhandle, "Table PD size            (tpd_size)    = %d\n", tab_entry->tpd_size);
							fprintf(fhandle, "Table Name               (table_name)  = %s\n", tab_entry->table_name);
							fprintf(fhandle, "Number of Columns        (num_columns) = %d\n", tab_entry->num_columns);
							fprintf(fhandle, "Column Descriptor Offset (cd_offset)   = %d\n", tab_entry->cd_offset);
                            fprintf(fhandle, "Table PD Flags           (tpd_flags)   = %d\n\n", tab_entry->tpd_flags); 
						}

						/* Next, write the cd_entry information */
						
						for(i = 0, col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
								i < tab_entry->num_columns; i++, col_entry++)
						{
							printf("Column Name   (col_name) = %s\n", col_entry->col_name);
							printf("Column Id     (col_id)   = %d\n", col_entry->col_id);
							printf("Column Type   (col_type) = %d\n", col_entry->col_type);
							printf("Column Length (col_len)  = %d\n", col_entry->col_len);
							printf("Not Null flag (not_null) = %d\n\n", col_entry->not_null);

							if (report)
							{
								fprintf(fhandle, "Column Name   (col_name) = %s\n", col_entry->col_name);
								fprintf(fhandle, "Column Id     (col_id)   = %d\n", col_entry->col_id);
								fprintf(fhandle, "Column Type   (col_type) = %d\n", col_entry->col_type);
								fprintf(fhandle, "Column Length (col_len)  = %d\n", col_entry->col_len);
								fprintf(fhandle, "Not Null Flag (not_null) = %d\n\n", col_entry->not_null);
								printf("The command completed successfully.\n");
							}
						}
	
						if (report)
						{
							fflush(fhandle);
							fclose(fhandle);
						}
					} // File open error							
				} // Table not exist
			} // no semantic errors
		} // Invalid table name
	} // Invalid statement

  return rc;
}

int sem_insert(token_list *t_list)
{
	///////////////////////////////DECLARATIONS //////////////////////////////////
	int rc = 0; //return code
	token_list *cur; //pointer to current token
	cur = t_list; //assigns cursor to the token list
	tpd_entry *tab_entry = NULL; //table info
	cd_entry  *col_entry = NULL; //column info
	cd_entry *column_cur = NULL;//pointer to the column entry

	bool value_done = false; //the last right paren for creating table statement
	int num_of_values = 0;//first iteration is 1 if no errors
	token_list *startvalues = NULL; //values are what is inside the parenthesis
 	token_list *values = NULL; //pointer to traverse the values

	FILE *fhandle = NULL; //file declaration used for table info
	char tablename[MAX_IDENT_LEN + 1]; //table name
	char filename[MAX_IDENT_LEN + 1]; //file name
	memset(filename, '\0', MAX_IDENT_LEN + 1);
	memset(tablename, '\0', MAX_IDENT_LEN + 1);

	/////////////////////////////////SYNTAX CHECKING ///////////////////////////////////////////

	/* invalid table name format */
	if ((cur->tok_class != keyword) &&
		  (cur->tok_class != identifier) &&
			(cur->tok_class != type_name))
	{
		rc = INVALID_TABLE_NAME; // Error: sets the return code to invalid table format
		cur->tok_value = INVALID; //sets the cursor to invalid
	}
	else //the case where it is a valid table
	{
		if ((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL) // if it tries to find the table and does not exist
		{
			rc = TABLE_NOT_EXIST; //Error: assigns the return code to TABLE DOES NOT EXIST
			cur->tok_value = INVALID; //sets the cursor value to INVALID
			printf("ERROR - No Such a Table Existed.");
		}
		else //the case where it DOES find the table, move to see if next token is VALUES
		{
			strcpy(tablename, cur->tok_string); //assigns table name using cursor string
			strcpy(filename, cur->tok_string); //assigns file name using cursor string
			strcat(filename , ".dat"); //appends .dat to filename

			cur = cur->next; //advance pointer
			if(cur->tok_value != K_VALUES) // if the current token is not value throw an error
			{
				rc = MISSING_KEYWORD_VALUES;
				cur->tok_value = INVALID;
				printf("ERROR - Missing Keyword Values.");
			} 
			else // the case where the token is values
			{ 
				cur = cur->next; //advance the cursor to check left paren
				if(cur->tok_value != S_LEFT_PAREN) //checks if the next token is not a left paren
				{
					rc = MISSING_LEFT_PAREN;
					cur->tok_value = INVALID;
					printf("ERROR - Missing (.");
				} 
				else 
				{ 
					cur = cur->next; //advance cursor
					if(cur->tok_value == EOC)
					{
						rc = MISSING_RIGHT_PAREN;
						cur->tok_value = INVALID;
						printf("ERROR - Missing ).");
					}
					//after a left paren if the current token is a right paren throw error
					if(cur->tok_value == S_RIGHT_PAREN)
					{
						rc = NOT_ENOUGH_DATA; //set rc to not enough data
						cur->tok_value = INVALID; //set cursor token to invalid
						printf("ERROR - Not enough data."); //print not enough data
					}
					if(!rc)
					{
						col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);// gets information of the column type.
						column_cur = col_entry; //assigns column_cur to col_entry
					}
					startvalues = cur; //points to start of col_entry
					values = cur; //points values to col_entry
					do //start of do while loop
					{	
						if(cur->tok_value == K_NULL || 
							cur->tok_value == STRING_LITERAL || 
							cur->tok_value == INT_LITERAL) //case of value
						{
							num_of_values++;
							cur = cur->next;
						}
						else if(cur->tok_value == S_COMMA)
						{
							cur = cur->next;
						}
						else if(cur->tok_value == EOC)
						{
							rc = MISSING_RIGHT_PAREN;
							cur->tok_value = INVALID;
							printf("ERROR - MISSING RIGHT PAREN \n");
						}
						else
						{ //invalid input
							rc = INVALID_INPUT;
							cur->tok_value = INVALID;
							printf("ERROR - INVALID INPUT \n");

						}
					}while((rc == 0) && (cur->tok_value != S_RIGHT_PAREN));

					if(!rc)
					{
						if(cur->tok_value == S_RIGHT_PAREN)
						{
							if(num_of_values == tab_entry->num_columns)
							{
								int i = 0;
								for(i; i < num_of_values; i++)
								{
									if(!rc)
									{
										if(values->tok_value == K_NULL)
										{
											if(column_cur->not_null)
											{
												rc = NULL_NOT_ALLOWED;
												values->tok_value = INVALID;
												printf("NULL_NOT_ALLOWED \n");
											}
										}
										else if(values->tok_value == STRING_LITERAL)
										{
											if(column_cur->col_type != T_CHAR)
											{
												rc = INVALID_DATA_TYPE;
												values->tok_value = INVALID;
												printf("INVALID_DATA_TYPE \n");
											}
											else if(strlen(values->tok_string) > column_cur->col_len)
											{
												rc = TOO_LONG_STRING;
												values->tok_value = INVALID;
												printf("TOO_LONG_STRING");
											}
										}
										else if(values->tok_value == INT_LITERAL)
										{
											unsigned long temp = ((atol(values->tok_string) * 2)+1);
											if( (temp == MAX_INT) && (strcmp(values->tok_string,"4294967294") != 0))
											{
												rc = TOO_LARGE_SMALL_INT;
												cur->tok_value = INVALID;
											}

											if(column_cur->col_type != T_INT)
											{
												rc = INVALID_DATA_TYPE;
												values->tok_value = INVALID;
												printf("INVALID_DATA_TYPE \n");
											}
											else if( temp > MAX_INT)//TOO_LARGE_SMALL_INT needs to be added
											{
												rc = TOO_LARGE_SMALL_INT;
												values->tok_value = INVALID;
												printf("ERROR - Too Large/Small Integer \n");
											}
										}
										else
										{
											rc = INVALID_DATA_TYPE;
											values->tok_value = INVALID;
											printf("ERROR - INVALID_DATA_TYPE \n");
										}
									}
									if(!rc)
									{
										values = values->next->next;
										column_cur++;
									}
								}
								cur = cur->next;
								cur->tok_value = values->tok_value;
							}
							else if(num_of_values < tab_entry->num_columns)
							{
								rc = NOT_ENOUGH_DATA;
								cur->tok_value = INVALID;
								printf("NOT_ENOUGH_DATA \n");

							}
							else
							{
								rc = TOO_MANY_DATA_ITEMS;
								cur->tok_value = INVALID;
								printf("TOO_MANY_DATA_ITEMS \n");
							}
						}
						else
						{
							rc = MISSING_RIGHT_PAREN;
							cur->tok_value = INVALID;
							printf("ERROR - MISSING RIGHT PAREN \n");
						}

						if(!rc)
						{
							if(cur->tok_value != EOC)
							{
								rc = INVALID_STATEMENT;
								cur->tok_value = INVALID;
								printf("INVALID_SQL_STATEMENT \n");
							}
						}

					}
				}//process insert statement
			}//after keyword values is processed
		}//case where table does exist
	}//is a valid table name

	if(!rc)
	{
		if((fhandle = fopen(filename, "r+tc")) == NULL)
		{
			rc = FILE_OPEN_ERROR;
		}
		else
		{
			

			//WRITE TO FILE//
			int counter = 0; //row counter
			char row_counter[4] = ""; //string of row counter(for file purposes)
			fgets(row_counter,sizeof(row_counter),fhandle); //captures current row counter
			counter = atoi(row_counter); //assigns captured counter to variable
			counter++; //increment the counter

			fseek(fhandle, 0, SEEK_SET); //sets the file cursor to the start
			
			fprintf(fhandle,"%d", counter);//print the row counter to the start of file

			fseek(fhandle, 0, SEEK_END); //move cursor to the end of the file

			values = startvalues; //resets the value cursor to the start of values
		    int i;
			for(i = 0;i < num_of_values;i++) //at this point it the values inside the parenthesis are valid and is ready to be placed in file.
			{
				if(values->tok_value == K_NULL) //null case
				{
					fprintf(fhandle, "NULL\t");
				}
				else if(values->tok_value == STRING_LITERAL) //string case
				{
					fprintf(fhandle, "'%s\'\t", values->tok_string);
				}
				else //integer case
				{
					fprintf(fhandle, "%s\t", values->tok_string);
				}
				values = values->next->next; //move to next value
			}
			fprintf(fhandle, "\n");//new line after insertion

			fflush(fhandle); //fflush file
			fclose(fhandle); //close file

		}
	}
	return rc; //return code
}

int sem_delete(token_list *t_list)
{
	int rc = 0; //return code
	token_list *cur = NULL; //pointer to curent token
	token_list *where_data = NULL;
	cur = t_list; //assigns cursor to the token list

	tpd_entry *tab_entry = NULL; //table info
	cd_entry  *col_entry = NULL; //column info
	cd_entry *col_cur = NULL;//traverses the column
	cd_entry *where_column = NULL; //target data to delete

	FILE *fhandle = NULL; //file declaration used for table info
	char tablename[MAX_IDENT_LEN+1] = ""; //tablename
	char filename[MAX_IDENT_LEN+1] = "";//filename

	char relational_operator[5] = "";//relational operator specified by user
	int where_offset = 0; //offset for the where column
	char *block = NULL; //block memory

	/* checks if the token is a valid table name*/
		if ((cur->tok_class != keyword) &&
			  (cur->tok_class != identifier) &&
				(cur->tok_class != type_name))
		{
			// Error
			rc = INVALID_TABLE_NAME;
			cur->tok_value = INVALID;
		}
		else //it is a valid table name
		{
			//searches the table name
			if ((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL) // if it tries to find the table and does not exist
			{
			rc = TABLE_NOT_EXIST; //Error: assigns the return code to TABLE DOES NOT EXIST
			cur->tok_value = INVALID; //sets the cursor value to INVALID
			printf("ERROR - No Such a Table Existed.");
			}
			else //the case where it DOES find the table, move to see if next token is WHERE
			{
				col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
				col_cur = col_entry;
				strncpy(tablename, cur->tok_string, strlen(cur->tok_string));
				strncpy(filename,tablename, strlen(tablename));
				strcat(filename, ".dat");

				cur = cur->next; //advances the token
				/*if token is not WHERE*/
				if(cur->tok_value != K_WHERE)
				{
					rc = MISSING_KEYWORD_WHERE; //set rc to missing keyword where
					cur->tok_value = INVALID; //sets cursor value to invalid
					printf("ERROR - Missing Keyword WHERE.");

				}
				else //checks to see if column name is valid
				{
					cur = cur->next;//advances cursor

					int i; //iterator
					col_cur = col_entry; //resets the col_cur to start of col_entry
					bool column_found; //column found

					for(i = 0; i< tab_entry->num_columns; i++)//attempts to find the where_data
					{
						if(strcmp(cur->tok_string, col_cur->col_name) == 0)
						{
							printf("column found \n");
							where_column = col_cur;//assigns where_column to what the user specified
							column_found = true;//sets column found to true
							break;//exits the loop
						}
						where_offset += 1 + col_cur->col_len;//on going calculation of where_offset
						col_cur++;//increment the column cursor has you move on
					}
					
					if(column_found == false)//column name is not valid
					{
						rc = INVALID_COLUMN_NAME; //sets rc to invalid column
						cur->tok_value = INVALID; //cursor token value to invalid
						printf("ERROR - Invalid column name.");
					}
					
					else //next look for relational operator
					{
						cur = cur->next;//advance cursor
						if((cur->tok_value != S_LESS) &&
							(cur->tok_value != S_GREATER) &&
							(cur->tok_value != S_EQUAL))
						{
							rc = INVALID_RELATIONAL_OPERATOR;
							cur->tok_value = INVALID;
							printf("ERROR - Invalid Relational Operator.");
								
						}
						else
						{
							strcpy(relational_operator,cur->tok_string);//assign the relational operator to what the user specified
							cur = cur->next;//advance cursor
							if( (cur->tok_class != constant) && (cur->tok_class != keyword))
							{
								rc = MISSING_CONSTANT;
								cur->tok_value = INVALID;
								printf("ERROR - Missing Constant.");
							}
							else
							{
								//"ERROR - Missing ' at the end of String Literal.\n"
								printf("Process data values. \n");
								//strcpy(data, cur->tok_string); data declaration might not be needed
								where_data = cur; //assigns the token where_data to cur
								cur = cur->next; //advance the cursor
								if(cur->tok_value != EOC)
								{
									rc = TOO_MUCH_DATA;
									cur->tok_value = INVALID;
									printf("TOO_MUCH_DATA \n");
								}
							}
						}
					}
				}
			}
		}

		if(!rc) //semantic checking done, ready to delete
		{
			/*MEMORY STARTS HERE*/

			/*DECLARATIONS*/
			void *blockptr = NULL; //pointer to the block
			char s[512] = ""; //empty string buffer
			char *sptr = NULL; //pointer to s 
			int iterations = 0; //iterations
			col_cur = col_entry; //resets col_cur to col_entry
			int record_length = 0; //record length
			int i,j; //int counters

				/*LOAD FILE TO MEMORY*/

				if((fhandle = fopen(filename, "r+tc")) == NULL)
				{
				rc = FILE_OPEN_ERROR;
				cur->tok_value = INVALID;
				printf("ERROR - File Open error.");
				}
				else
				{

					/* Calculate Record Length */
					int num_of_columns = tab_entry->num_columns; //number of columns in table
					for(i = 0; i < num_of_columns; i++)
					{
						record_length += 1 + col_cur->col_len;//calculates record length
						col_cur++; //advances cursor
					}

					printf("record length is: %d \n", record_length);

					/* Get the row counter .*/

					fseek(fhandle, 0, SEEK_SET); //sets file cursor to iterator
					fgets(s, sizeof(s), fhandle); //assigns s to line where cursor is
					iterations = atoi(s); //assigns iterations to what global counter is

					/*Allocate memory*/

					block = (char *)malloc( record_length * iterations); //allocate block of memory to fit tuples
					memset(block, '\0', record_length * iterations); //clears block of memory
					blockptr = block; //assigns block pointer to block
					col_cur = col_entry; //resets the col_cur to col_entry
					sptr = strtok(s, "\t"); //reads first line (row counter)
					fgets(s, sizeof(s), fhandle); //assigns a tuple to the string s
					sptr = strtok(s, "\t");  //moves to the next tuple
					printf("Number of rows is: %d \n", iterations);

					/* Write from file to memory. */
					for(i = 0; i < iterations; i++) //for ever row
					{
						for(j = 0; j < num_of_columns; j++) //for every column
						{
							int column_len = col_cur->col_len;
							if(strncmp(sptr, "NULL", strlen(sptr)) == 0) //compare sptr with NULL
							{
								*(int *) blockptr = 0; //null header is always zero
								blockptr = (char *) blockptr + 1;//move blockptr to next data
							} 
							else if(col_cur->col_type == T_CHAR) //character case
							{
								if(memchr(sptr, '\'', 1) != NULL) //if detecting a single quote
								{
									strncpy(sptr, sptr + 1, strlen(sptr) - 1); //takes out the first single quote
									sptr[strlen(sptr)-2] = '\0'; //removes the second single quote
								}
								*(int *) blockptr = strlen(sptr); //assigns strlength to header
								blockptr = (char *) blockptr + 1; //increments the blockptr
								strncpy((char *) blockptr, sptr, column_len);//puts the string from textfile to blockptr
							}
							else //integer case
							{
								*(int *)blockptr = column_len;//assigns column length (should be 4)
								blockptr = (char *) blockptr + 1;//increments blockptr
								*(int *) blockptr = atoi(sptr);//converts the string file to integer
							}
							blockptr = (char*) blockptr + col_cur->col_len; //moves the blockptr to next column
							sptr = strtok(NULL, "\t"); //moves the tokenizer to next otken
							col_cur++; //advances the column cursor
						}
						fgets(s, sizeof(s), fhandle); //gets the next line
						sptr = strtok(s, "\t"); //moves tokenizer to next token
						col_cur = col_entry; //resets the col_cur to process the next row
					}
				}//DONE WRITING FROM FILE
				fflush(fhandle); // fflush file
				fclose(fhandle); // fclose file since done using it
						
						/* Tuple to delete*/
						char tuple[32] = "";
						blockptr = block;
						col_cur = col_entry;
						int num_of_columns = tab_entry->num_columns;
						int column_len = 0;
						/* Capture the values of the tuple */
						for(i = 0; i < num_of_columns; i++)
						{
							if(col_cur->col_type == T_CHAR)
							{
								char blkdata[32] = "";
								column_len = *(char *) blockptr;
								blockptr = (char *)blockptr +1;
								strncat(blkdata, (char *)blockptr, column_len);
								strcat(tuple,blkdata);
								strcat(tuple,"\t");
							}
							else
							{
								int blkdata = 0;
								char blkdata_str[11] = "";
								column_len = *(char *) blockptr;
								blockptr = (char *)blockptr +1;
								blkdata = *(int *) blockptr;
								strcat(tuple, itoa(blkdata,blkdata_str,10));
								strcat(tuple,"\t");
							}
							blockptr = (char *) blockptr + col_cur->col_len;
							col_cur++; //advances cursor
						
						}
						printf("tuple is: %s\n", tuple);

					/* Delete Rows specified by user. */

					blockptr = block; //resets blockptr to block
					col_cur = col_entry; //sets col_cur to col_entry
					blockptr = (char *) block + where_offset; //move block pointer to where offset is 
				    column_len = 0; //column length declaration
					int num_of_rows = iterations; //number of rows
					char *data = where_data->tok_string;
					

					printf("%d \n", where_offset);
					for(i = 0; i < iterations; i++)
					{
						if( where_data->tok_value == K_NULL &&
							where_column->not_null == 0) //NULL CASE
						{

							if(where_column->col_type == T_CHAR)
							{
								char blkdata[MAX_TOK_LEN + 1] = "";
								column_len = *(char *) blockptr;
								printf("column len is: %d \n", column_len);
								blockptr = (char *) blockptr + 1;
								strncpy(blkdata, (char *) blockptr, column_len);
								printf("%s \n",blkdata);

								if(strcmp(relational_operator,"=") == 0)
								{
									printf("operation is equals \n");
									if(column_len == 0 && where_data->tok_value == K_NULL)
									{
										void * rowptr = (char *)blockptr - (where_offset);
										void * lastptr = block;
										rowptr = (char *) rowptr - 1;
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length);
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length));
									//	printf("DELETED: %s\n", (char*) rowptr);
										memcpy(rowptr, lastptr, record_length);
										memset((char *)lastptr-1, '\0', record_length);
										num_of_rows--;
										blockptr = (char *) blockptr - record_length;

									}
								}
								else if(strcmp(relational_operator,">") == 0)
								{
									printf("operation is greater than \n");
									if(column_len == 0 && where_data->tok_value == K_NULL)
									{
										void * rowptr = (char *)blockptr - (where_offset);
										void * lastptr = block;
										rowptr = (char *) rowptr - 1;
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length);
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length));
									//	printf("DELETED: %s\n", (char*) rowptr);
										memcpy(rowptr, lastptr, record_length);
										memset((char *)lastptr-1, '\0', record_length);
										num_of_rows--;
										blockptr = (char *) blockptr - record_length;

									}
								}
								else
								{
									printf("operation is less than \n");
									if(column_len == 0 && where_data->tok_value == K_NULL)
									{
										void * rowptr = (char *)blockptr - (where_offset);
										void * lastptr = block;
										rowptr = (char *) rowptr - 1;
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length);
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length));
									//	printf("DELETED: %s\n", (char*) rowptr);
										memcpy(rowptr, lastptr, record_length);
										memset((char *)lastptr-1, '\0', record_length);
										num_of_rows--;
										blockptr = (char *) blockptr - record_length;

									}
								}

							}
							else //column is an integer
							{
								int data_int = atoi(data);//converts user where data to integer
								int blkdata = 0; //declaration of blkdata
								column_len = *(char *) blockptr; //column length of integer
								printf("column len is: %d\n", column_len); //prints column length
								blockptr = (char *) blockptr + 1; //advances the pointer
								blkdata = *(int *) blockptr; //assigns blkdata to specified integer
								printf("%d\n", blkdata); //print what blkdata is

								if(strcmp(relational_operator,"=") == 0) //if relational operator is equal
								{	
									if(column_len == 0 && where_data->tok_value == K_NULL)//see if user input is null and column is zero
									{
										printf("numbers are equals \n");//print they are equals
										void * rowptr = (char *) blockptr - (where_offset); //places point to the row to delete
										rowptr = (char *) rowptr - 1; // moves the pointer to the column length

										void *lastptr = block; //resets last ptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //puts last pointer to the last row
										printf("distance of last row is: %d\n", ((num_of_rows * record_length) - record_length));//prints the offset to last row
										memcpy(rowptr,lastptr,record_length); //places the last row to deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the number of rows
										blockptr = (char *)blockptr - record_length; //places blockptr to the previous record
									}
								}
								else if(strcmp(relational_operator,">") == 0) //if relational operator is greater than
								{
									if(column_len == 0 && where_data->tok_value == K_NULL)//see if user input is null and column is zero
									{
										printf("numbers are less than \n");//print they are greater than
										void * rowptr = (char *) blockptr - (where_offset); //places point to the row to delete
										rowptr = (char *) rowptr - 1; // moves the pointer to the column length

										void *lastptr = block; //resets last ptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //puts last pointer to the last row
										printf("distance of last row is: %d\n", ((num_of_rows * record_length) - record_length));//prints the offset to last row
										memcpy(rowptr,lastptr,record_length); //places the last row to deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the number of rows
										blockptr = (char *)blockptr - record_length; //places blockptr to the previous record
									}

								}
								else //relational operator is less than
								{
									if(column_len == 0 && where_data->tok_value == K_NULL)//see if user input is null and column is zero
									{
										printf("numbers are equals \n");//print they are equals
										void * rowptr = (char *) blockptr - (where_offset); //places point to the row to delete
										rowptr = (char *) rowptr - 1; // moves the pointer to the column length

										void *lastptr = block; //resets last ptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //puts last pointer to the last row
										printf("distance of last row is: %d\n", ((num_of_rows * record_length) - record_length));//prints the offset to last row
										memcpy(rowptr,lastptr,record_length); //places the last row to deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the number of rows
										blockptr = (char *)blockptr - record_length; //places blockptr to the previous record
									}
								}
							}

								if(column_len == 0)
								{
									printf("column length is ZERO!!!! Meaning this row is NULL\n");
								}
						}
						else if(where_column->col_type == T_CHAR) //CHARACTER CASE
						{
								char blkdata[MAX_TOK_LEN + 1] = ""; //data inside the block
								column_len = *(char *) blockptr; //column length of string
								printf("column len is: %d \n", column_len);//prints column length
								blockptr = (char *) blockptr + 1; //advances to the data
								strncpy(blkdata, (char *) blockptr, column_len);//assigns blkdata to whatever string length is specified in header
								printf("%s \n",blkdata); //prints the block data

								if(strcmp(relational_operator,"=") == 0) //equal case
								{ 
									printf("it is equals \n"); //prints it is equals
									if(where_column->col_type == T_CHAR && (strcmp(blkdata,data) == 0) && (column_len != 0)) //in column type is char and blockdata equals use input specified
									{
										void * rowptr = (char *)blockptr - (where_offset); //moves pointer to the user wants to delete
										rowptr = (char *) rowptr - 1; //moves the rowptr to the header
									
										void * lastptr = block; //assigns lastptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves to the last row 
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length)); //prints the last row
									
										memcpy(rowptr, lastptr, record_length); //copies the last row to the deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the row counter
										blockptr = (char *) blockptr - record_length; //puts the block pointer to the previous row
									}
								}
								else if(strcmp(relational_operator,">") == 0) //less than case
								{
									if(where_column->col_type == T_CHAR && (strcmp(blkdata,data) > 0) && (column_len != 0))
									{
										void * rowptr = (char *)blockptr - (where_offset); //moves pointer the start of the row.
										rowptr = (char *) rowptr - 1; //moves the rowptr to the header
									
										void * lastptr = block; //assigns lastptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves to the last row 
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length)); //prints the last row
									
										memcpy(rowptr, lastptr, record_length); //copies the last row to the deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the row counter
										blockptr = (char *) blockptr - record_length; //puts the block pointer to the previous row
									}
								}
								else //less than case
								{
									if(where_column->col_type == T_CHAR && (strcmp(blkdata,data) < 0) && (column_len != 0))
									{
										void * rowptr = (char *)blockptr - (where_offset); //moves pointer the start of the row.
										rowptr = (char *) rowptr - 1; //moves the rowptr to the header
									
										void * lastptr = block; //assigns lastptr to start of block
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves to the last row 
										printf("point to the last row is %d \n", ((num_of_rows * record_length) - record_length)); //prints the last row
									
										memcpy(rowptr, lastptr, record_length); //copies the last row to the deleted row
										memset((char *)lastptr-1, '\0', record_length); //memsets the last row
										num_of_rows--; //decrements the row counter
										blockptr = (char *) blockptr - record_length; //puts the block pointer to the previous row
									}
								}
							}
							else //INTEGER CASE
							{
								int data_int = atoi(where_data->tok_string); //converts user input as an integer
								int blkdata = 0; //declaration of blockdata
								column_len = *(char *) blockptr; //column length is set to what ever is set on the block
								printf("column len is: %d \n", column_len);//prints the column length
								blockptr = (char *) blockptr + 1; //moves the blockptr to what the data is
								blkdata = *(int *) blockptr; //assigns integer n block and sets it to block data
								printf("BLOCKDATA:%d \n", blkdata); //prints the block data

								if(strcmp(relational_operator,"=") == 0) //equals case
								{
									if(where_column->col_type == T_INT && (blkdata == data_int) && (column_len  != 0)) //if column type is integer and integer in block matches user put
									{
										printf("numbers are equals \n");//notifies they are equal
										void * rowptr = (char *) blockptr - (where_offset); //declares deleted row pointer
										rowptr = (char *) rowptr - 1; //moves pointer to header
										void *lastptr = block; //declaration of pointer to the last row
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves pointer to the last row

										printf("point to the last row is: %d\n", ((num_of_rows * record_length) - record_length)); //prints pointer to the last row
										memcpy(rowptr,lastptr,record_length); //replaces deleted row with last row
										num_of_rows--; //decrements last row
										blockptr = (char *)blockptr - record_length; //moves blockptr to previous row
									}
								}
								else if(strcmp(relational_operator,">") == 0) //less than case
								{
									if(where_column->col_type == T_INT && (blkdata > data_int) && (column_len  != 0)) //if column type is integer and integer in block matches user put
									{
										printf("numbers are equals \n");//notifies they are equal
										void * rowptr = (char *) blockptr - (where_offset); //declares deleted row pointer
										rowptr = (char *) rowptr - 1; //moves pointer to header
										void *lastptr = block; //declaration of pointer to the last row
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves pointer to the last row

										printf("point to the last row is: %d\n", ((num_of_rows * record_length) - record_length)); //prints pointer to the last row
										memcpy(rowptr,lastptr,record_length); //replaces deleted row with last row
										num_of_rows--; //decrements last row
										blockptr = (char *)blockptr - record_length; //moves blockptr to previous row
									}
								}
								else //greater than case
								{
									if(where_column->col_type == T_INT && (blkdata < data_int) && (column_len  != 0)) //if column type is integer and integer in block matches user put
									{
										printf("numbers are equals \n");//notifies they are equal
										void * rowptr = (char *) blockptr - (where_offset); //declares deleted row pointer
										rowptr = (char *) rowptr - 1; //moves pointer to header
										void *lastptr = block; //declaration of pointer to the last row
										lastptr = (char *) lastptr + ((num_of_rows * record_length) - record_length); //moves pointer to the last row

										printf("point to the last row is: %d\n", ((num_of_rows * record_length) - record_length)); //prints pointer to the last row
										memcpy(rowptr,lastptr,record_length); //replaces deleted row with last row
										num_of_rows--; //decrements last row
										blockptr = (char *)blockptr - record_length; //moves blockptr to previous row
									}
								}
							}
							blockptr = (char *) blockptr + record_length - 1; //advances the block pointer to the next tuple
					
					}
					printf("number of rows to write %d \n", num_of_rows); //prints the number of rows to write.

					/* Deleting Completed; Write Back to file */
					if((fhandle = fopen(filename, "w+tc")) == NULL)  //open an instance of fhandle
					{
					rc = FILE_OPEN_ERROR; //an error has occured when opening file
					cur->tok_value = INVALID; //sets cur value to invalid.
					printf("ERROR - File open error \n"); //prints error
					}
					else
					{
					char s[512] = "";//string declaration
					void *blockptr; // declares block pointer
					int i = 0; //iterator 
					int j = 0; //iterator
				
						fprintf(fhandle, "%d \n" ,num_of_rows); //prints the global counter
						col_cur = col_entry; //resets the col cur
						blockptr = block; //resets the blockptr

						for(i = 0; i < num_of_rows; i++) //for every row
						{
							col_cur = col_entry; //resets the col cur every iteration
							for(j = 0; j < num_of_columns;j++)  //for every column
							{
								int column_len  = *(char *)blockptr; //assigns column length from block
								blockptr = (char *) blockptr + 1; //increments blockptr to data in block
								if(column_len == 0) //NULL case
								{
									fprintf(fhandle, "NULL\t"); //write NULL to file

								}
								else if(col_cur->col_type == T_CHAR) //CHARACTER case
								{
									char data[MAX_TOK_LEN+1] = ""; //data declaration
									strncpy(data, (char *)blockptr, column_len); //copies block data to string
									fprintf(fhandle, "'%s'\t",data); //write data to file
								}
								else if(col_cur->col_type == T_INT) //INTEGER case
								{
									int data = 0; //integer declaration of data
									char data_string[11] = ""; //string representation of data
									data = *(int *) blockptr; //copies block data to integer
									itoa(data,data_string,10); //converts integer to string
									fprintf(fhandle, "%s\t",data_string); //prints string representation of data
								}
								blockptr = (char *)blockptr + col_cur->col_len; //advances blockptr to next column attribute
								col_cur++; //advances col_cur
							}
							fprintf(fhandle, "\n");//places a new line in file for set up of next row insertion
						}
					}	
					/*DONE WRITING BACK TO FILE*/
					printf("\n%d rows are deleted.\nThe command completed successfully.\n\n", (iterations - num_of_rows)); //alerts user
				/*MEMORY ENDS HERE*/
		}
	return rc;
}

int sem_update(token_list *t_list)
{
	int rc = 0; //return code
	token_list *cur = NULL; //pointer to crurent token
	cur = t_list; //assigns cursor to the token list
	tpd_entry *tab_entry = NULL; //table info
	cd_entry  *col_entry = NULL; //column info
	cd_entry *col_cur = NULL; //col_cur is column traverser


	FILE *fhandle = NULL; //file declaration used for table info
	char tablename[MAX_IDENT_LEN + 1] = "";//tablename
	char filename[MAX_IDENT_LEN + 1] = "";//filename

	cd_entry *where_column = NULL; //target column pointer
	cd_entry *set_column = NULL; //source column pointer
	
	int where_offset = 0;//column modifying
	int set_offset = 0; //where specified
	token_list *where_data = NULL; //the where data specified by the user. where = [data]
	token_list *set_data = NULL; //the set data specfied by the user  set = [data]
	char where_relational_op[5] = ""; //relational operator
	char set_relational_op[5] = ""; //set operator (may not be needed)

	char *block = NULL; //block of memory that stores the data

		if ((cur->tok_class != keyword) &&
			  (cur->tok_class != identifier) &&
				(cur->tok_class != type_name))
		{
			rc = INVALID_TABLE_NAME; //set return code to invalid
			cur->tok_value = INVALID; //set token value to invalid
			printf("ERROR - Invalid column name. \n"); //print error
		}
		else //table name valid
		{
			if((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL) //tab_entry declaration
			{
				rc = TABLE_NOT_EXIST; //Error: assigns the return code to TABLE DOES NOT EXIST
				cur->tok_value = INVALID; //sets the cursor value to INVALID
				printf("ERROR - No Such a Table Existed. \n");
			}
			else //table does exist
			{
				col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset); //assigns column entry declaration
				col_cur = col_entry; //resets column cursor
				
				strncpy(tablename, cur->tok_string, strlen(cur->tok_string)); //assigns table name from cursor
				strncpy(filename,tablename, strlen(tablename)); //assigns filename from cursor
				strcat(filename, ".dat"); //appends .dat to filename
				cur = cur->next; //advances cursor to next token

				if(cur->tok_value != K_SET)
				{
					rc = MISSING_KEYWORD_SET; //sets return code to missing keyword set
					cur->tok_value = INVALID; //sets cursor value to invalid
					printf("ERROR - Missing keyword SET. \n"); //prints missing keyword set
				}
				else
				{
					cur = cur->next; //advances cursor token

					int i = 0; //iterator counter 
					bool column_found = false; //boolean to see if column is found
					int num_of_columns = tab_entry->num_columns; //number of columns for optomization
					char user_column[MAX_NUM_COL+1] = ""; //declaration of user_column for optomization 
					strcpy(user_column, cur->tok_string); //copies user string to variable
					for(i = 0; i < num_of_columns; i++) //checks to see if column exist
					{
						if(strncmp(user_column,col_cur->col_name,strlen(user_column)) == 0) //compare user string with column name
						{
							set_column = col_cur; //set set_column to col_cur
							printf("%s\n", set_column); //prints set_column
							printf("column offset %d\n",set_offset); //prints column off set
							column_found = true; //column found
							break; //break from loop
						}
						set_offset += 1 + col_cur->col_len; //calculates set_offset
						col_cur++; //advances the colunmn cursor
					}

					if(column_found == false) //if column not found alert user
					{ 
						rc = INVALID_COLUMN_NAME; //sets return code to invalid column
						cur->tok_value = INVALID; //sets cursor to invalid
						printf("ERROR - Invalid column name. \n"); //alert user there is an error
					}
					else
					{
						cur = cur->next; //advances the cursor
						if(cur->tok_value != S_EQUAL) //if cursor is not equal
						{ 
							rc = MISSING_KEYWORD_EQUAL;//sets return code to missing keyword
							cur->tok_value = INVALID; //set cursor value to invalid
							printf("ERROR - Missing =. \n"); //alert user they are missing equals
						}
						else
						{
							cur = cur->next; //advances cursor
							set_data = cur; //set_data to cursor
							if(cur->tok_value == K_NULL) //if user input null check if column can allow null
							{
								if(col_cur->not_null) //if column canno't accept null throw errror
								{ 
									rc = NULL_NOT_ALLOWED; //sets return code
									cur->tok_value = INVALID; //set cur to invalid
									printf("ERROR - Null not allowed. \n"); //alert user
								}
							}
							else if(cur->tok_value == STRING_LITERAL) //if user input string literal check if column is character
							{
								if(col_cur->col_type != T_CHAR) //see if column is character
								{
									rc = INVALID_DATA_TYPE; //return code is invalid
									cur->tok_value = INVALID; //set cursor value to invalid
									printf("ERROR - Invalid Data Type. \n"); //alert user invalid data type
								}
							}
							else if(cur->tok_value == INT_LITERAL) //if user input int literal check if column is integer
							{
								if(col_cur->col_type != T_INT) //see if column is integer
								{
									rc = INVALID_DATA_TYPE; //set return code to invalid data type
									cur->tok_value = INVALID; //set cursor to invalid
									printf("ERROR - Invalid Data Type. \n"); //alert user invalid datatype
								}
							}
						}//column name

								cur = cur->next; //advance cursor
								if(cur->tok_value != K_WHERE) //check if cursor value is where
								{
									rc = MISSING_KEYWORD_WHERE; //return code to missing_keyword_where
									cur->tok_value = INVALID; //set cursor value to invalid
									printf("ERROR - Missing Keyword Where. \n"); //alert user missing keyword where
								}
								else
								{
									cur = cur->next; //advance cursor to next token
									col_cur = col_entry; //resets col_cur to beginning of column
									column_found = false; //set column_found to false;

									for(i = 0; i < tab_entry->num_columns; i++) //for loop to find the where column
									{
										if(strncmp(cur->tok_string, col_cur->col_name, strlen(cur->tok_string))==0)
										{
											where_column = col_cur;//set where_column to user input
											printf("%s \n", where_column); //prints where_column
											column_found = true; //set column found to true
											break; //break from loop
										}
											where_offset += 1 + col_cur->col_len; //on going calculation of where_offset
											col_cur++; //advances the column cursor
									}
									if(column_found == false) //if column not found alert user
									{ 
										rc = INVALID_COLUMN_NAME; //set return code to invalid column name
										cur->tok_value = INVALID; //set cursor vlaue to invalid
										printf("ERROR - Invalid Column name. \n"); //alert user invalid column name
									}
									else
									{
										cur = cur->next; //advances cursor to next token
										if((cur->tok_value != S_EQUAL) &&  //if is not a relational operator
											(cur->tok_value != S_LESS)&&
											(cur->tok_value != S_GREATER))
										{
											rc = INVALID_RELATIONAL_OPERATOR; //sets retrn code to invalid relational operator
											cur->tok_value = INVALID; //set cursor to invalid
											printf("ERROR - Invalid Relational Operator. \n"); //alert user error
										}
										else
										{
											strcpy(where_relational_op, cur->tok_string); //assigns where_relationa_op to whatever the user specified
											cur = cur->next; //advances to the next otken
											where_data = cur; //sets the where_data to this token
											if(cur->tok_value == K_NULL) //if the token value is null check if the column can allow nulls
											{
												if(col_cur->not_null) //checks if current column can allow nulls
												{
													rc = NULL_NOT_ALLOWED;//set return code to null not allowed
													cur->tok_value = INVALID; //sets cursor value to invalid
													printf("ERROR - Null Not Allowed \n"); //alerts user null is not allowed
												}

											}
											else if(cur->tok_value == STRING_LITERAL) //if user input string literal check if column is string literal
											{ 
												if(col_cur->col_type != T_CHAR) //if column is not string literal
												{
													rc = INVALID_DATA_TYPE; //set return code to invalid data type
													cur->tok_value = INVALID; //sets cursor token to invalid
													printf("ERROR - Invalid Data Type. \n"); //alert user that there is an invalid data type error
														
												}
											}
											else if(cur->tok_value == INT_LITERAL) //if the column is int literal, check if column is an int
											{
												if(col_cur->col_type != T_INT) //if the column is not an int alert the user
												{
													rc = INVALID_DATA_TYPE;//sets return code to invalid data type
													cur->tok_value = INVALID; //sets the cursor to invalid
													printf("ERROR - Invalid Data Type. \n"); //alert the user to invalid data type
												}												
											}
											else //what the user input satisfies the column specs 
											{
												cur = cur->next; //advances the token to next token
												if(cur->tok_value != EOC) //check if the token value is END-OF-CHARACTEr
												{
													rc = TOO_MUCH_DATA;//sets return code to too much data
													cur->tok_value = INVALID; //sets the cursor to invalid
													printf("ERROR - Too Much Data \n"); //alert the user they input too much data.
												}
											}
										}//invalid relational operator
									}//invalid column name
								}//keyword where
					}//keyword set
				}//table exist
			}//table name paren
		}
		/*UPDATE MEMORY STARTS HERE */
		if(!rc)
		{
			if((fhandle = fopen(filename, "r+tc")) == NULL) //opens file
			{
				rc = FILE_OPEN_ERROR; //sets return code to file open error
			}
			else
			{
				printf("file open \n"); //alerts the user file has opened
				void *blockptr = NULL; //declares block pointer
				char s[512] = ""; //string for the line
				char *sptr = NULL; //string pointer
				int iterations = 0; //number of iterations
				int i = 0; //iterator counter
				int j = 0; //iterator counter
				col_cur = col_entry; //column traverser
				//int size = 0; //size of 
				int record_length = 0;

				int num_of_columns = tab_entry->num_columns;
				/*Calculates Record Length*/
				for(i = 0; i < num_of_columns; i++) //calculates record length
				{
					record_length += 1 + col_cur->col_len;
					col_cur++;
				}
				printf("record length is: %d \n", record_length);

				col_cur = col_entry;//reset col_cur to start of entry
			
				/*Gets the row counter*/
				fseek (fhandle, 0, SEEK_SET); //set file cursor to the start of file
				fgets(s, sizeof(s), fhandle); //get the first line
				iterations = atoi(s); //set iterations to what the first line is (should be global counter)

				/*Allocate memory*/
				block = (char *)malloc( record_length * iterations); //allocates block to size of record length * global counter
				memset(block, '\0', record_length * iterations); //clears the junk of the block
				blockptr = block; //sets block pointer to block

				sptr = strtok(s, "\t"); //reads first line (row counter)
				fgets(s, sizeof(s), fhandle); //assigns s to the the current line
				sptr = strtok(s, "\t");  //goes to the next line

				/*LOAD FROM FILE TO MEMORY*/
				for(i = 0; i < iterations; i++)
				{
					for(j = 0; j < num_of_columns; j++)
					{
						if(strncmp(sptr,"NULL",strlen(sptr)) == 0) //null case
						{
							int column_len = col_cur->col_len;	
							*(int *) blockptr = 0;
							blockptr = (char *)blockptr + 1;
						}
						else if(col_cur->col_type == T_CHAR) //string case
						{
							int column_len = col_cur->col_len;
							if(memchr(sptr,'\'',1) != NULL)
							{
								strncpy (sptr, sptr+1, strlen(sptr)-1);
								sptr[strlen(sptr)-2]='\0';
							}
							*(int *) blockptr = strlen(sptr);
							blockptr = (char *)blockptr + 1;
							strncpy((char*)blockptr,sptr,column_len);
						}
						else //int case
						{
							int column_len = col_cur->col_len;
							*(int*) blockptr = column_len;
							blockptr = (char *)blockptr + 1;
							*(int*) blockptr = atoi(sptr);
						}
						blockptr = (char *)blockptr + col_cur->col_len; //advances the blockptr to next attribute
						sptr = strtok(NULL, "\t"); //tokenizes the next column
						col_cur++; //advances the col_cur
					}
					fgets(s, sizeof(s), fhandle); //assigns s to the current line
					sptr = strtok(s, "\t"); //tokenizes the next token
					col_cur = col_entry; //resets column cursor
				}
				/*DONE LOADING FILE INTO MEMORY*/
				
				/*FIND TARGET COLUMN(S) AND SETS IT TO VALUE SPECIFIED BY USER*/
				col_cur = col_entry; //reset column
				blockptr = block; //assigns blockptr to block 
				blockptr = (char *)blockptr + where_offset; //moves blockptr to block
				int num_of_rows = 0; //number of rows updated

				for(i = 0; i < iterations; i++) //traverses to every tuple to file to find specified tuple by user
				{
						int column_len = *(char*)blockptr; //gets column length
						blockptr = (char *)blockptr + 1; //advances the blockptr to data

						if(where_data->tok_value == K_NULL) //IF WHERE_DATA IS NULL
						{
							if(where_column->col_type == T_CHAR)
							{
								char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
								strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
								printf("%s \t\n",where_blk_data); //prints the user what the data is

								if(strcmp(where_relational_op, "=") == 0) //if where relational operator is = 
								{
									if(strcmp(where_blk_data, "") == 0) //if block data is equal to the user specified string
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
								}
								else if(strcmp(where_relational_op,">") == 0) //if where_relational_op is greater than
								{
									if(strcmp(where_blk_data, "") > 0) //if block data is equal to the user specified string
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
								}
								else //if where_relational_op is greater than
								{
									if(strcmp(where_blk_data, "") < 0) //if block data is equal to the user specified string
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}	
									}
								}
							}
							else //where_column->col_type == T_INT
							{
								int where_data_int = atoi(where_data->tok_string); //assigns where_data_int to where_data specified by user
								int where_blk_data = 0; //int data in memory

								where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
								printf("%d \n", where_blk_data); //prints where_blk_data

								if(strcmp(where_relational_op,"=") == 0) //if where_relational_op is equals
								{
									if(where_data_int == where_blk_data) //compares integer in block with user specified
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
								}
								else if(strcmp(where_relational_op,">") == 0) //if where relational operator is greater than
								{
									if(where_data_int > where_blk_data) //compares block data with user specified data
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
											
									}
								}
								else //if where relational operator is less than
								{
									if(where_data_int < where_blk_data) //compares block data with user specified data
									{
										if(set_data->tok_value == K_NULL) //at this point the table allows null values
										{
											if(set_column->col_type == T_CHAR) //set column is character 
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
												//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
												num_of_rows++; //updates the number of rows
											}
											else //if set column is integer
											{
												void *updated_value = blockptr;
												updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
												updated_value = (char *) updated_value - 1; //positions the old_data to the header length
												*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
												updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
												memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
												//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
												num_of_rows++; //updates the number of rows updated
											}
										}
										else if(set_column->col_type == T_CHAR) //if set_column is character
										{
											void *updated_value = blockptr; //assigns void pointer to what blockptr is
											updated_value = (char *) updated_value - 1; //moves old data to where column length is
											*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
											updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
											//void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //set_column is an integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1;
											*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
								}
							}
						}
						else if(where_column->col_type == T_CHAR) //if where column is character
						{
							char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
							strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
							printf("%s \t\n",where_blk_data); //prints the user what the data is

							if(strcmp(where_relational_op, "=") == 0) //if where relational operator is = 
							{
								if(strcmp(where_blk_data, where_data->tok_string) == 0) //if block data is equal to the user specified string
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
							else if(strcmp(where_relational_op,">") == 0) //if where_relational_op is greater than
							{
								if(strcmp(where_blk_data, where_data->tok_string) > 0) //if block data is equal to the user specified string
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
							else //if where_relational_op is greater than
							{
								if(strcmp(where_blk_data, where_data->tok_string) < 0) //if block data is equal to the user specified string
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
						}
						else //(where_column->col_type == T_INT) //if where_column is integer
						{
							int where_data_int = atoi(where_data->tok_string); //assigns where_data_int to where_data specified by user
							int where_blk_data = 0; //int data in memory

							where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
							printf("%d \n", where_blk_data); //prints where_blk_data

							if(strcmp(where_relational_op,"=") == 0) //if where_relational_op is equals
							{
								if(where_data_int == where_blk_data) //compares integer in block with user specified
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
							else if(strcmp(where_relational_op,">") == 0) //if where relational operator is greater than
							{
								if(where_data_int > where_blk_data) //compares block data with user specified data
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
							else //if where relational operator is less than
							{
								if(where_data_int < where_blk_data) //compares block data with user specified data
								{
									if(set_data->tok_value == K_NULL) //at this point the table allows null values
									{
										if(set_column->col_type == T_CHAR) //set column is character 
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
											//strncpy((char *) updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
											num_of_rows++; //updates the number of rows
										}
										else //if set column is integer
										{
											void *updated_value = blockptr;
											updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
											updated_value = (char *) updated_value - 1; //positions the old_data to the header length
											*(char *) updated_value = 0; //assigns the header length to 0 b/c set_data = NULL
											updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
											memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
											//*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
											num_of_rows++; //updates the number of rows updated
										}
									}
									else if(set_column->col_type == T_CHAR) //if set_column is character
									{
										void *updated_value = blockptr; //assigns void pointer to what blockptr is
										updated_value = (char *) updated_value - 1; //moves old data to where column length is
										*(char *)updated_value = strlen(set_data->tok_string); //updates column length to the set_data specified from user
										updated_value = blockptr; //repositions the old_data pointer to blockptr (block data)
										//void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); // repositions the block data to start of updated row
										memset((char *) updated_value, '\0', set_column->col_len);//clears out column data
										strncpy((char *)updated_value, set_data->tok_string, strlen(set_data->tok_string)); //copies updated data to block
										num_of_rows++; //updates the number of rows
									}
									else //set_column is an integer
									{
										void *updated_value = blockptr;
										updated_value = (char *) updated_value - (where_offset - set_offset); //repositions the blockptr to the old data
										updated_value = (char *) updated_value - 1;
										*(char *) updated_value = set_column->col_len; //assigns the header length to 0 b/c set_data = NULL
										updated_value = (char *) updated_value + 1; //positions the old data_to the actual data
										memset((char *) updated_value, '\0', set_column->col_len); //clears the old data
										*(int *) updated_value = atoi(set_data->tok_string); //updates the value to what the user specified in the set_data
										num_of_rows++; //updates the number of rows updated
									}
								}
							}
						}
					blockptr = (char *)blockptr + record_length-1; //moves the block pointer to the next row
				}
				fflush(fhandle); //flushes out file
				fclose(fhandle); //closes the opend file
				
				/*DONE MODIFYING RECORDS*/

				/*WRITE BACK TO FILE*/
				if((fhandle = fopen(filename, "w+tc")) == NULL) //opens the table to write back to memory
				{
				rc = FILE_OPEN_ERROR;
				cur->tok_value = INVALID;
				printf("ERROR - File open error \n");
				}
				else
				{
					char s[512] = "";
					void *blockptr = NULL;
					int i = 0;
					int j = 0;
					int num_of_columns = tab_entry->num_columns;

					fprintf(fhandle, "%d\n" ,iterations);
					col_cur = col_entry;
					blockptr = block;

					for(i = 0; i < iterations; i++)
					{
						col_cur = col_entry;
						for(j = 0; j < num_of_columns;j++)
						{
							int column_len  = *(char *)blockptr;
							blockptr = (char *) blockptr + 1;
							if(column_len == 0)
							{
								fprintf(fhandle, "NULL\t");

							}
							else if(col_cur->col_type == T_CHAR)
							{
								char data[MAX_TOK_LEN] = "";
								strncpy(data, (char *)blockptr, column_len);
								fprintf(fhandle, "'%s'\t",data);
							}
							else if(col_cur->col_type == T_INT)
							{
								int data = 0;
								char buffer[11] = "";
								data = *(int *) blockptr;
								itoa(data,buffer,10);
								fprintf(fhandle, "%s\t",buffer);
							}
							blockptr = (char *)blockptr + col_cur->col_len;
							col_cur++;
						}
						fprintf(fhandle, "\n");
					}
				}	
				/*DONE WRITING BACK TO FILE*/
				printf("\n%d rows are updated.\nThe command completed successfully.n", num_of_rows);
				/*MEMORY ENDS HERE */
			}//done
		}
	return rc; //return code
}

int sem_select(token_list *t_list)
{
	int rc = 0; //return code
	token_list *cur = NULL; //cursor to tokenlist
	cur = t_list; //positions cursor to start of token list
	 
	FILE *fhandle = NULL; //file declaration that will point to the table
	tpd_entry *tab_entry = NULL; //tab_entry reference
	cd_entry *col_entry = NULL; //col_entry reference  
	cd_entry *col_cur = NULL; //col_cur traverses through the columns

	char tablename[MAX_IDENT_LEN + 1] = ""; //string for table name
	char filename[MAX_IDENT_LEN + 1] = ""; //string for filename

	char * block = NULL; //block of memory
	char * blockptr = NULL;//pointer to block
	int record_length = 0;//record length
	int iterations = 0; //number of rows

	/* Flags used for filtering */
	bool where_flag = false; //where_flag
	bool where_is_null_flag = false; //where is null flag
	bool where_is_not_null_flag = false; //where is not null flag
	bool and_flag = false; //and_flag
	bool or_flag = false; //or_flag
	bool and_or_is_null_flag = false;
	bool and_or_is_not_null_flag = false;
	bool order_by_flag = false; //order_by_flag
	bool desc_flag = false; //desc_flag

	/* Access information from user (select * from table where c1 = data1 or c2 = data2 order by c1 desc) */
	cd_entry *where_column = NULL; //column specified by where
	char where_relational_op[5] = ""; //where relational operator
	token_list *where_data = NULL; //where data
	int where_offset = 0; //where column offset

	cd_entry *and_or_column = NULL; //column specified by and/or
	char and_or_relational_op[5] = ""; //and or relational operator
	token_list *and_or_data = NULL; //and or data
	int and_or_offset = 0; //and of column offset

	cd_entry *order_by_column = NULL; //column specified by and or
	int order_by_offset = 0; //offset specifie by and or

	if (cur->tok_value == S_STAR) //select start case
	{
		cur = cur->next;//advances the token
		if(cur->tok_value != K_FROM) // if it isn't from then throw an error
		{
			rc = MISSING_KEYWORD_FROM; //set return code to missing keyword from
			cur->tok_value = INVALID; //set cursor token to invalid
			printf("ERROR - Missing Keyword From.\n"); //alert user ERROR missing keyword from
		}
		else //the token does equal from
		{
			cur = cur->next;//advances token(advances to table)
			strcpy(tablename, cur->tok_string); //set tablename to token string
			strcpy(filename, cur->tok_string); //set filename to token string
			strcat(filename,".dat"); //concat .dat to filename
			if(!rc)  //if error code is valid access the table
			{
				if((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL) //assign tab_entry using get_tpd_from list method
				{
					rc = TABLE_NOT_EXIST; //if it is null return code to table not exist
					cur->tok_value = INVALID; //set token to invalid
					printf("ERROR - TABLE_NOT_EXISTED\n"); //alert the user ERROR - table not exist
				}
				else
				{
					cur = cur->next; //advances the next token
				}
			}
		}
		

		if(!rc && cur->tok_value != EOC) //process where clause
		{
			if(cur->tok_value == K_WHERE) //processes where clause
			{
				where_flag = true; //set where_flag to true
				printf("where clause!\n"); //alert user it is a where clause
				cur = cur->next;//advances token to next token

				bool column_found = false; //declare column found flag
				col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
				col_cur = col_entry; //reset col_cur to col_entry
				int i = 0; //count iterator
				int num_of_columns = tab_entry->num_columns; //number of columns
				for(i = 0; i < num_of_columns ; i++) //iterates through each column
				{
					if(strcmp(cur->tok_string, col_cur->col_name) == 0) //if user specified column matches the one declared in table
					{
						where_column = col_cur; //assign where_column to col_cur
						column_found = true; //set column found flag to true
						printf("column found!\n"); //alert the user column is found
						break; //break from the loop
					}
					where_offset += 1 + col_cur->col_len; //on going calculation of the where_offset
					col_cur++; //advance to the next column
				}

				if(column_found == false) //if no column was found
				{
					rc = INVALID_COLUMN_NAME; //set return code to invalid column name
					cur->tok_value = INVALID; //set the token value to invalid
					printf("ERROR - Invalid Column Name.\n"); //alert the user invalid token name
				}
				else
				{
					cur = cur->next;//advances token
					if((cur->tok_value == K_IS) || 
						(cur->tok_value == S_EQUAL) ||
						(cur->tok_value == S_GREATER)||
						(cur->tok_value == S_LESS))
					{
						if((cur->tok_value == K_IS) &&
							(cur->next->tok_value == K_NOT) &&
							(cur->next->next->tok_value == K_NULL))
						{
							where_flag = false;
							where_is_not_null_flag = true;
							printf("is not null!\n");
							cur = cur->next->next->next;
						}
						else if((cur->tok_value == K_IS) &&
								(cur->next->tok_value == K_NULL))
						{
							where_flag = false;
							where_is_null_flag = true;
							printf("is null!\n");
							cur = cur->next->next;
						}
						else if((cur->tok_value == S_EQUAL) ||
								(cur->tok_value == S_GREATER) ||
								(cur->tok_value == S_LESS))
						{
							strcpy(where_relational_op, cur->tok_string);
							printf("where relational operator!\n");
							cur = cur->next;
							if((cur->tok_value != STRING_LITERAL) &&
								(cur->tok_value != INT_LITERAL) &&
								(cur->tok_value != K_NULL))
							{
								rc = INVALID_DATA_TYPE;
								cur->tok_value = INVALID;
								printf("ERROR - Invalid Data Type.\n");
							}
							else
							{
								where_data = cur;
								if(where_column->col_type == T_CHAR && 
									(where_data->tok_value == STRING_LITERAL) ||
									(where_data->tok_value == K_NULL))
								{
									cur = cur->next;
								}
								else if(where_column->col_type == T_INT && 
									(where_data->tok_value == INT_LITERAL) ||
									(where_data->tok_value == K_NULL))
								{
									cur = cur->next;
								}
								else
								{
									rc= INVALID_DATA_TYPE;
									cur->tok_value = INVALID;
									printf("ERROR - Invalid Data Type\n");
								}
							}
						}
						else
						{
							rc = INVALID_RELATIONAL_OPERATOR;
							cur->tok_value = INVALID;
							printf("ERROR - Invalid Relational Operator.\n");
						}
					}
				}
				//begin processing the and/or clause here
				if(!rc && cur->tok_value != EOC && cur->tok_value != K_ORDER)
				{
					//cur = cur->next;
					if((cur->tok_value != K_AND) && 
						(cur->tok_value != K_OR))
					{
						rc = INVALID_RELATIONAL_OPERATOR;
						cur->tok_value = INVALID;
						printf("ERROR - Invalid Relational Operator\n");
					}
					else
					{
						if(cur->tok_value == K_AND)
						{
							and_flag = true;
						}
						else
						{
							or_flag = true;
						}

						cur = cur->next;
						bool column_found = false;
						col_cur = col_entry;
						int i = 0;
						int num_of_columns = tab_entry->num_columns;
						for(i = 0;i < num_of_columns;i++)
						{
							if(strcmp(cur->tok_string, col_cur->col_name) == 0)
							{
								and_or_column = col_cur;
								column_found = true;
								printf("column found! \n");
								break;
							}
							and_or_offset += 1 + col_cur->col_len;
							col_cur++;
						}
						if(column_found == false)
						{
							rc = INVALID_COLUMN_NAME;
							cur->tok_value = INVALID;
							printf("ERROR - Invalid Column Name. \n");
						}
						else
						{
							cur = cur->next;
							
							if((cur->tok_value == K_IS) && 
									(cur->next->tok_value == K_NULL))
							{
								and_or_is_null_flag = true;
								printf("and or is null flag!\n");
								cur = cur->next->next;

							}
							else if((cur->tok_value == K_IS) &&
									(cur->next->tok_value == K_NOT) &&
									(cur->next->next->tok_value == K_NULL))
							{
								and_or_is_not_null_flag = true;
								printf("and or is not null flag!\n");
								cur = cur->next->next->next;
							}
							else if((cur->tok_value == S_EQUAL) ||
								(cur->tok_value == S_GREATER) || 
								(cur->tok_value == S_LESS))
							{
								strcpy(and_or_relational_op,cur->tok_string);
								printf("and or relational operator!\n");
								cur = cur->next;
								if((cur->tok_value != STRING_LITERAL) &&
									(cur->tok_value != INT_LITERAL) &&
									(cur->tok_value != K_NULL))
								{
									rc = INVALID_DATA_TYPE;
									cur->tok_value = INVALID;
									printf("ERROR - Invalid Data Type\n");
								}
								else
								{
									and_or_data = cur;
									cur = cur->next;
								}
							}
							else
							{
								rc = INVALID_RELATIONAL_OPERATOR;
								cur->tok_value = INVALID;
								printf("ERROR - Invalid Relational Operator.\n");
							}
						}
					}
				}
			}
		}
		if(!rc && cur->tok_value != EOC) //process order by clause
		{
			if(cur->tok_value == K_ORDER)
			{
				cur = cur->next;
				if(cur->tok_value != K_BY)
				{
					rc = MISSING_KEYWORD_BY;
					cur->tok_value = INVALID;
					printf("ERROR - Missing Keyword BY.\n");
				}
				else
				{
					order_by_flag = true;
					cur = cur->next;
					printf("order by clause!\n");

					bool column_found = false; //declare column found flag
					col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
					col_cur = col_entry; //reset col_cur to col_entry
					int i = 0; //count iterator
					int num_of_columns = tab_entry->num_columns; //number of columns
					for(i = 0; i < num_of_columns ; i++) //iterates through each column
					{
						if(strcmp(cur->tok_string, col_cur->col_name) == 0) //if user specified column matches the one declared in table
						{
							order_by_column = col_cur; //assign where_column to col_cur
							column_found = true; //set column found flag to true
							printf("column found!\n"); //alert the user column is found
							break; //break from the loop
						}
						order_by_offset += 1 + col_cur->col_len; //on going calculation of the where_offset
						col_cur++; //advance to the next column
					}

					if(column_found == false) //if no column was found
					{
						rc = INVALID_COLUMN_NAME; //set return code to invalid column name
						cur->tok_value = INVALID; //set the token value to invalid
						printf("ERROR - Invalid Column Name.\n"); //alert the user invalid token name
					}
					else
					{
						cur = cur->next;
						if(cur->tok_value == K_DESC)
						{
							desc_flag = true;
							cur = cur->next;
							printf("desc!\n");
						}
					}
				}
			}
		}
		if(!rc)//end of character line read
		{
			if(cur->tok_value != EOC)
			{
				rc = TOO_MUCH_DATA;
				cur->tok_value = INVALID;
				printf("ERROR - Too Much Data.\n");
			}
			else
			{
				printf("process data\n");
				/* SELECT * MEMORY STARTS HERE */
				if(!rc)
				{
					if((fhandle = fopen(filename, "r+tc")) == NULL) //opens file
					{
						rc = FILE_OPEN_ERROR; //sets return code to file open error
					}
					else
					{
						printf("file open \n"); //alerts the user file has opened
						void *blockptr = NULL; //declares block pointer
						char s[512] = ""; //string for the line
						char *sptr = NULL; //string pointer
						iterations = 0; //number of iterations
						int i = 0; //iterator counter
						int j = 0; //iterator counter
						col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);//col_entry declaration
						col_cur = col_entry; //column traverser
						record_length = 0;

						int num_of_columns = tab_entry->num_columns;
						/*Calculates Record Length*/
						for(i = 0; i < num_of_columns; i++) //calculates record length
						{
							record_length += 1 + col_cur->col_len;
							col_cur++;
						}
						printf("record length is: %d \n", record_length);

						col_cur = col_entry;//reset col_cur to start of entry
			
						/*Gets the row counter*/
						fseek (fhandle, 0, SEEK_SET); //set file cursor to the start of file
						fgets(s, sizeof(s), fhandle); //get the first line
						iterations = atoi(s); //set iterations to what the first line is (should be global counter)

						/*Allocate memory*/
						block = (char *)malloc( record_length * iterations); //allocates block to size of record length * global counter
						memset(block, '\0', record_length * iterations); //clears the junk of the block
						blockptr = block; //sets block pointer to block

						sptr = strtok(s, "\t"); //reads first line (row counter)
						fgets(s, sizeof(s), fhandle); //assigns s to the the current line
						sptr = strtok(s, "\t");  //goes to the next line

						/*LOAD FROM FILE TO MEMORY*/
						for(i = 0; i < iterations; i++)
						{
							for(j = 0; j < num_of_columns; j++)
							{
								if(strncmp(sptr,"NULL",strlen(sptr)) == 0) //null case
								{
									int column_len = col_cur->col_len;	
									*(int *) blockptr = 0;
									blockptr = (char *)blockptr + 1;
								}
								else if(col_cur->col_type == T_CHAR) //string case
								{
									int column_len = col_cur->col_len;
									if(memchr(sptr,'\'',1) != NULL)
									{
										strncpy (sptr, sptr+1, strlen(sptr)-1);
										sptr[strlen(sptr)-2]='\0';
									}
									*(int *) blockptr = strlen(sptr);
									blockptr = (char *)blockptr + 1;
									strncpy((char*)blockptr,sptr,column_len);
								}
								else //int case
								{
									int column_len = col_cur->col_len;
									*(int*) blockptr = column_len;
									blockptr = (char *)blockptr + 1;
									*(int*) blockptr = atoi(sptr);
								}
								blockptr = (char *)blockptr + col_cur->col_len; //advances the blockptr to next attribute
								sptr = strtok(NULL, "\t"); //tokenizes the next column
								col_cur++; //advances the col_cur
							}
							fgets(s, sizeof(s), fhandle); //assigns s to the current line
							sptr = strtok(s, "\t"); //tokenizes the next token
							col_cur = col_entry; //resets column cursor
						}
					}
					/* DONE LOADING FILE INTO MEMORY*/
				
					/* WRITE FROM MEMORY TO CONSOLE */

					/* Format Heading */
					col_cur = col_entry; //reset column cursor to col_entry;
					int i = 0; // iterator count
					int num_of_columns = tab_entry->num_columns;
					for(i = 0; i < num_of_columns; i++)//prints the column names
					{
						if(col_cur->col_type == T_CHAR)//right justified
						{
							if(col_cur->col_len >= strlen(col_cur->col_name)) //declared string column length is less than or equal to the name of the column
							{
								printf("%-*s", col_cur->col_len, col_cur->col_name);
							}
							else //the column name is longer than the string declared
							{
								printf("%-*s", strlen(col_cur->col_name), col_cur->col_name);
							}
						}
						else //column is an integer
						{
							if(strlen(col_cur->col_name) > 10)
							{
								printf("%*s", strlen(col_cur->col_name), col_cur->col_name);
							}
							else
							{
								printf("%*s", 10, col_cur->col_name);
							}
						}
						col_cur++;
					}

					/* FILTER USER INPUT */
					printf("\n");//print new line
					col_cur = col_entry;//reset col_cur
					char *tuples = NULL; //block of tuples
					void * row_ptr = NULL;//pointer to row
					void * and_or_ptr = NULL; //pointer to and_or data
					tuples = (char *) malloc(iterations * (record_length));
					void * tuples_ptr = tuples; //used to add to array of tuples
					int num_of_tuples = 0;
					blockptr = block;//reset blockptr(to point to the where clause)
					and_or_ptr = block; //reset and_or_ptr
					row_ptr = block;//reset row_ptr to block
					memset(tuples, '\0', iterations * record_length);
				    i = 0;
					int j = 0;
					num_of_columns = tab_entry->num_columns;
					int column_len = 0;
					int and_or_column_len = 0;
					if(where_flag == true)
					{
						blockptr = (char *)blockptr + where_offset; //moves blockptr to block
						and_or_ptr = (char *) and_or_ptr + and_or_offset;
						int num_of_rows = 0; //number of rows selected
						
						for(i = 0; i < iterations; i++) //traverses to every tuple to file to find specified tuple by user
						{
								column_len = *(char*)blockptr; //gets column length
								and_or_column_len = *(char *) and_or_ptr;
								blockptr = (char *)blockptr + 1; //advances the blockptr to data
								and_or_ptr = (char *) and_or_ptr + 1;

								if(where_data->tok_value == K_NULL && column_len == 0) //IF WHERE DATA IS NULL (order matters here)
								{
									if(where_column->col_type == T_CHAR) //where_data is null and column type is char
									{
										char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
										strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
										//printf("%s \t\n",where_blk_data); //prints the user what the data is

										if(strcmp(where_relational_op, "=") == 0) //if where relational operator is = 
										{
											if(and_flag == true && strcmp(where_blk_data, "") == 0)// && column_len == 0)
											{
												
												if(and_or_is_null_flag == true)//user input and is null
												{
													memcpy(tuples_ptr,(char*) row_ptr, record_length); 
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
												}
												else if(and_or_is_not_null_flag == true)// && strcmp(where_blk_data, "") == 0 && column_len == 0) //user input and is not null
												{
													if(where_data->tok_value != K_NULL)
													{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
													}
												}
												else //user input, and c1 = data
												{
													if(and_or_data->tok_value == K_NULL && and_or_column_len == 0) //and data = null
													{
														if(and_or_column->col_type == T_CHAR)//and_or_column is character
														{
															char and_blk_data[MAX_TOK_LEN] = "";
															strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
															if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else //if less than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
														else //and_or_data is integer
														{
															int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
															int and_blk_data = 0; //int data in memory
															and_blk_data = *(int *) and_or_ptr;
															if(strcmp(and_or_relational_op, "=") == 0) //equal to
															{
																if(((and_blk_data == and_int) == 1)&& and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //greater than
															{
																if(((and_blk_data == and_int) == 1) && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else//less than
															{
																if(((and_blk_data == and_int) == 1) && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
													}
													else if(and_or_column->col_type == T_CHAR) //and c1 = t_char
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //and relational operator is equals
														{
															if(strcmp(and_blk_data,and_or_data->tok_string) == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcpy(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if(strcmp(and_blk_data,and_or_data->tok_string) > 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if(strcmp(and_blk_data,and_or_data->tok_string) < 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and c1 = t_int
													{
														int and_data_int = atoi(and_or_data->tok_string);
														int and_blk_data = 0;
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
														{
															if((and_blk_data == and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if((and_blk_data > and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if((and_blk_data < and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
													}
												}
											}
											else if(or_flag == true && strcmp(where_blk_data, "") == 0) //OR CASES
											{
												if(and_or_is_null_flag == true)//now check the different conditions to see if they are valid
												{
													memcpy(tuples_ptr, (char *)row_ptr, record_length);
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
												}
												else if(and_or_is_not_null_flag == true)
												{
													if(where_data->tok_value != K_NULL)
													{
														memcpy(tuples_ptr, (char *)row_ptr, record_length);
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
													}
												}
												else //user input c1 = data
												{
													if(and_or_data->tok_value == K_NULL && and_or_column_len == 0) //and data = null
													{
														if(and_or_column->col_type == T_CHAR)//and_or_column is character
														{
															char or_blk_data[MAX_TOK_LEN] = "";
															strncpy(or_blk_data,(char *)and_or_ptr, and_or_column_len);
															if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
															{
																if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
															{
																if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else //if less than
															{
																if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
														else //and_or_data is integer
														{
															int or_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
															int or_blk_data = 0; //int data in memory
															or_blk_data = *(int *) and_or_ptr;
															if(strcmp(and_or_relational_op, "=") == 0) //equal to
															{
																if(((or_blk_data == or_int) == 1)&& and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //greater than
															{
																if(((or_blk_data == or_int) == 1) && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else//less than
															{
																if(((or_blk_data == or_int) == 1) && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
													}
													else if(and_or_column->col_type == T_CHAR)
													{
														char or_blk_data[MAX_TOK_LEN] = "";
														strncpy(or_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(or_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int or_data_int = atoi(and_or_data->tok_string);
														int or_blk_data = 0;
														or_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
														{
															if((or_blk_data == or_data_int) == 1)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if((or_blk_data > or_data_int) == 1)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if((or_blk_data < or_data_int) == 1)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
											}
											else if(strcmp(where_blk_data, "") == 0) //if block data is equal to the user specified string
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length); 
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
										}
										else if(strcmp(where_relational_op,">") == 0) //if where_relational_op is greater than
										{
											if(and_flag == true && strcmp(where_blk_data, "") == 0)// && column_len == 0)
											{
												int and_or_column_len = 0;
												and_or_column_len = *(char *) and_or_ptr;
												and_or_ptr = (char *) and_or_ptr + 1;
												if(and_or_is_null_flag == true)//user input and is null
												{
													memcpy(tuples_ptr,(char*) row_ptr, record_length); 
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
												}
												else if(and_or_is_not_null_flag == true && strcmp(where_blk_data, "") == 0)// && column_len == 0) //user input and is not null
												{
													if(where_data->tok_value != K_NULL)
													{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
													}
												}
												else //user input, and c1 = data
												{
													if(and_or_data->tok_value == K_NULL && and_or_column_len == 0) //and data = null
													{
														if(and_or_column->col_type == T_CHAR)//and_or_column is character
														{
															char and_blk_data[MAX_TOK_LEN] = "";
															strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
															if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else //if less than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
														else //and_or_data is integer
														{
															int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
															int and_blk_data = 0; //int data in memory
															and_blk_data = *(int *) and_or_ptr;
															if(strcmp(and_or_relational_op, "=") == 0) //equal to
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //greater than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else//less than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
													}
													else if(and_or_column->col_type == T_CHAR) //and c1 = t_char
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcpy(and_or_relational_op, "=") == 0) //and relational operator is equals
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcpy(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) > 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) < 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and c1 = t_int
													{
														int and_data_int = atoi(and_or_data->tok_string);
														int and_blk_data = 0;
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
														{
															if((and_blk_data == and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if((and_blk_data > and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if((and_blk_data < and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}	
													}
												}
											}
											else if(strcmp(where_blk_data, "") == 0) //if block data is equal to the user specified string
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length); 
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
										}
										else //if where_relational_op is less than
										{
											if(and_flag == true && strcmp(where_blk_data, "") == 0)// && column_len == 0)
											{
												int and_or_column_len = 0;
												and_or_column_len = *(char *) and_or_ptr;
												and_or_ptr = (char *) and_or_ptr + 1;
												if(and_or_is_null_flag == true)//user input and is null
												{
													memcpy(tuples_ptr,(char*) row_ptr, record_length); 
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
												}
												else if(and_or_is_not_null_flag == true && strcmp(where_blk_data, "") == 0)// && column_len == 0) //user input and is not null
												{
													if(where_data->tok_value != K_NULL)
													{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
													}
												}
												else //user input, and c1 = data
												{
													if(and_or_data->tok_value == K_NULL && and_or_column_len == 0) //and data = null
													{
														if(and_or_column->col_type == T_CHAR)//and_or_column is character
														{
															char and_blk_data[MAX_TOK_LEN] = "";
															strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
															if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else //if less than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
														else //and_or_data is integer
														{
															int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
															int and_blk_data = 0; //int data in memory
															and_blk_data = *(int *) and_or_ptr;
															if(strcmp(and_or_relational_op, "=") == 0) //equal to
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //greater than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else//less than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
													}
													else if(and_or_column->col_type == T_CHAR) //and c1 = t_char
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcpy(and_or_relational_op, "=") == 0) //and relational operator is equals
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) > 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) < 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and c1 = t_int
													{
														int and_data_int = atoi(and_or_data->tok_string);
														int and_blk_data = 0;
														and_blk_data = *(int *) and_or_ptr;
														if(strcpy(and_or_relational_op, "=") == 0)//and relational operator is equal
														{
															if((and_blk_data == and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if((and_blk_data > and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if((and_blk_data < and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}	
													}
												}
											}
											else if(strcmp(where_blk_data, "") == 0) //if block data is equal to the user specified string
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length); 
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
										}
									}
									else //where_column->col_type == T_INT (NULL CASE)
									{
										int where_data_int = atoi(where_data->tok_string); //assigns where_data_int to where_data specified by user
										int where_blk_data = 0; //int data in memory

										where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
										//printf("%d \n", where_blk_data); //prints where_blk_data

										if(strcmp(where_relational_op,"=") == 0) //if where_relational_op is equals
										{
											if(and_flag == true && where_blk_data == where_data_int)// && column_len == 0) //compares integer in block with user specified
											{
												int and_or_column_len = 0;
												and_or_column_len = *(char *) and_or_ptr;
												and_or_ptr = (char *) and_or_ptr + 1;
												if(and_or_is_null_flag == true) //user input and is null
												{
													memcpy(tuples_ptr,(char*) row_ptr, record_length);
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
												}
												else if(and_or_is_not_null_flag == true) //user input and is not null
												{
													if(where_data->tok_value != NULL)
													{
													memcpy(tuples_ptr,(char*) row_ptr, record_length);
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
													}
												}
												else //user input, and c1 = data
												{
													if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
													{
														if(and_or_column->col_type == T_CHAR)
														{
															char and_blk_data[MAX_TOK_LEN] = "";
															strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
															if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else //if less than
															{
																if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
														else //and_or_column->col_type == T_INT
														{
															int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
															int and_blk_data = 0; //int data in memory
															and_blk_data = *(int *) and_or_ptr;
															if(strcmp(and_or_relational_op, "=") == 0) //equal to
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else if(strcmp(and_or_relational_op, ">") == 0) //greater than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
															else//less than
															{
																if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
																{
																	memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																	tuples_ptr = (char *) tuples_ptr + record_length;
																	num_of_tuples++;
																}
															}
														}
													}
													else if(and_or_data->tok_value == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //and relational operator is equals
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) > 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if(strcmp(and_blk_data, and_or_data->tok_string) < 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_data->tol_value == T_INT
													{
														int and_data_int = atoi(and_or_data->tok_string);
														int and_blk_data = 0;
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
														{
															if((and_blk_data == and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
														{
															if((and_blk_data > and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
														else //and relational operator is less than
														{
															if((and_blk_data < and_data_int) == 1)
															{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
															}
														}
													}
												}
											}
											else if(where_blk_data == 0)
											{
													memcpy(tuples_ptr,(char*) row_ptr, record_length);
													tuples_ptr = (char *) tuples_ptr + record_length;
													num_of_tuples++;
											}
										}
										else if(strcmp(where_relational_op,">") == 0) //if where relational operator is greater than
										{
											if((where_blk_data > where_data_int) == 1 && column_len == 0) //compares block data with user specified data
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);	
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
										}
										else //if where relational operator is less than
										{
											if((where_blk_data < where_data_int) == 1 && column_len == 0) //compares block data with user specified data
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
										}
									}
								}
								else if(where_column->col_type == T_CHAR) //WHERE COLUMN = T_CHAR
								{
									char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
									strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
									//printf("%s \t\n",where_blk_data); //prints the user what the data is

									if(strcmp(where_relational_op, "=") == 0) //if where relational operator is = 
									{
										if(and_flag == true && strcmp(where_blk_data, where_data->tok_string) == 0  && column_len != 0) //if block data is equal to the user specified string
										{
											//int and_or_column_len = 0;
											//and_or_column_len = *(char *) and_or_ptr;
											//and_or_ptr = (char *) and_or_ptr + 1;
											if(and_or_is_null_flag == true && and_or_column == 0)//user input and is null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)//user input and is not null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else//user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
												else if(and_or_column->col_type == T_CHAR)
												{
													char and_blk_data[MAX_TOK_LEN] = "";
													strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
													if(strcmp(and_or_relational_op, "=") == 0) //and relational operator is equals
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) == 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) > 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) < 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
												else //and_or_column->col_type == T_INT
												{
													int and_data_int = atoi(and_or_data->tok_string);
													int and_blk_data = 0;
													and_blk_data = *(int *) and_or_ptr;
													if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
													{
														if((and_blk_data == and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if((and_blk_data > and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if((and_blk_data < and_data_int) == 1)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
											}
										}
										else if(strcmp(where_blk_data, where_data->tok_string) == 0  && column_len != 0)
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
									else if(strcmp(where_relational_op,">") == 0) //if where_relational_op is greater than
									{
										if(and_flag == true && strcmp(where_blk_data, where_data->tok_string) > 0  && column_len != 0) //if block data is equal to the user specified string
										{
											//int and_or_column_len = 0;
											//and_or_column_len = *(char *) and_or_ptr;
											//and_or_ptr = (char *) and_or_ptr + 1;
											if(and_or_is_null_flag == true && and_or_column == 0)//user input and is null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)//user input and is not null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else//user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
												else if(and_or_column->col_type == T_CHAR)
												{
													char and_blk_data[MAX_TOK_LEN] = "";
													strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
													if(strcmp(and_or_relational_op, "=") == 0) //and relational operator is equals
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) == 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) > 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) < 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
												else //and_or_column->col_type == T_INT
												{
													int and_data_int = atoi(and_or_data->tok_string);
													int and_blk_data = 0;
													and_blk_data = *(int *) and_or_ptr;
													if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
													{
														if((and_blk_data == and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if((and_blk_data > and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if((and_blk_data < and_data_int) == 1)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
											}
										}
										else if(strcmp(where_blk_data, where_data->tok_string) > 0  && column_len != 0)
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
									else //if where_relational_op is less than
									{
										if(and_flag == true && strcmp(where_blk_data, where_data->tok_string) < 0  && column_len != 0) //if block data is equal to the user specified string
										{
											//int and_or_column_len = 0;
											//and_or_column_len = *(char *) and_or_ptr;
											//and_or_ptr = (char *) and_or_ptr + 1;
											if(and_or_is_null_flag == true && and_or_column == 0)//user input and is null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)//user input and is not null
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else//user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
												else if(and_or_column->col_type == T_CHAR)
												{
													char and_blk_data[MAX_TOK_LEN] = "";
													strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
													if(strcmp(and_or_relational_op, "=") == 0) //and relational operator is equals
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) == 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) > 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if(strcmp(and_blk_data,and_or_data->tok_string) < 0)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
												else //and_or_column->col_type == T_INT
												{
													int and_data_int = atoi(and_or_data->tok_string);
													int and_blk_data = 0;
													and_blk_data = *(int *) and_or_ptr;
													if(strcmp(and_or_relational_op, "=") == 0)//and relational operator is equal
													{
														if((and_blk_data == and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else if(strcmp(and_or_relational_op, ">") == 0) //and relational operator is greater than
													{
														if((and_blk_data > and_data_int) == 1)
														{
														memcpy(tuples_ptr,(char*) row_ptr, record_length); 
														tuples_ptr = (char *) tuples_ptr + record_length;
														num_of_tuples++;
														}
													}
													else //and relational operator is less than
													{
														if((and_blk_data < and_data_int) == 1)
														{
															memcpy(tuples_ptr,(char*) row_ptr, record_length); 
															tuples_ptr = (char *) tuples_ptr + record_length;
															num_of_tuples++;
														}
													}
												}
											}
										}
										else if(strcmp(where_blk_data, where_data->tok_string) < 0  && column_len != 0)
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
								}
								else //(where_column->col_type == T_INT ) //WHERE COLUMN = T_INT
								{
									int where_data_int = atoi(where_data->tok_string); //assigns where_data_int to where_data specified by user
									int where_blk_data = 0; //int data in memory

									where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
									//printf("%d \n", where_blk_data); //prints where_blk_data

									if(strcmp(where_relational_op,"=") == 0) //if where_relational_op is equals
									{
										if(and_flag == true && ((where_blk_data == where_data_int) == 1) && column_len != 0)
										{
											if(and_or_is_null_flag == true && and_or_column == 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else //user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
											}
										}
										if(((where_blk_data == where_data_int) == 1) && column_len != 0) //compares integer in block with user specified
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
									else if(strcmp(where_relational_op,">") == 0 && column_len != 0) //if where relational operator is greater than
									{
										if(and_flag == true && ((where_blk_data > where_data_int) == 1) && column_len != 0)
										{
											if(and_or_is_null_flag == true && and_or_column == 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else //user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
											}
										}
										if(((where_blk_data > where_data_int) == 1) && column_len != 0) //compares integer in block with user specified
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
									else //if where relational operator is less than
									{
										if(and_flag == true && ((where_blk_data < where_data_int) == 1) && column_len != 0)
										{
											if(and_or_is_null_flag == true && and_or_column == 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else if(and_or_is_not_null_flag == true && and_or_column != 0)
											{
												memcpy(tuples_ptr,(char*) row_ptr, record_length);
												tuples_ptr = (char *) tuples_ptr + record_length;
												num_of_tuples++;
											}
											else //user input, and c1 = data
											{
												if(and_or_data->tok_value == K_NULL && and_or_column_len == 0)
												{
													if(and_or_column->col_type == T_CHAR)
													{
														char and_blk_data[MAX_TOK_LEN] = "";
														strncpy(and_blk_data,(char *)and_or_ptr, and_or_column_len);
														if(strcmp(and_or_relational_op, "=") == 0) //if where relational operator is = 
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //if greater than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else //if less than
														{
															if(strcmp(and_blk_data, "") == 0)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
													else //and_or_column->col_type == T_INT
													{
														int and_int = atoi(and_or_data->tok_string); //assigns where_data_int to where_data specified by user
														int and_blk_data = 0; //int data in memory
														and_blk_data = *(int *) and_or_ptr;
														if(strcmp(and_or_relational_op, "=") == 0) //equal to
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else if(strcmp(and_or_relational_op, ">") == 0) //greater than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
														else//less than
														{
															if((and_blk_data == and_int) == 1)// && and_or_column_len == 0)
															{
																memcpy(tuples_ptr,(char*) row_ptr, record_length); 
																tuples_ptr = (char *) tuples_ptr + record_length;
																num_of_tuples++;
															}
														}
													}
												}
											}
										}
										if(((where_blk_data < where_data_int) == 1) && column_len != 0) //compares integer in block with user specified
										{
											memcpy(tuples_ptr,(char*) row_ptr, record_length);
											tuples_ptr = (char *) tuples_ptr + record_length;
											num_of_tuples++;
										}
									}
								}
							blockptr = (char *)blockptr + record_length-1; //moves the block pointer to the next row
							and_or_ptr = (char *)and_or_ptr + record_length-1;
							row_ptr = (char *) row_ptr + record_length;
						}
						/* Done adding to array */

						/* Memory to file */
						tuples_ptr = tuples;//reset pointer to tuples
						if(num_of_tuples == 0)
						{
							printf("no rows selected\n");
						}
						else
						{
							for(i = 0; i < num_of_tuples; i++)
							{
								for(j = 0; j < num_of_columns; j++)
								{
									int column_len  = *(char *)tuples_ptr;
									tuples_ptr = (char *) tuples_ptr + 1;
									if(column_len == 0)
									{
										if(col_cur->col_type == T_CHAR)
										{
											if(strlen(col_cur->col_name) > col_cur->col_len)
											{
											printf("%-*c",strlen(col_cur->col_name),'-');
											}
											else
											{
											printf("%-*c",col_cur->col_len,'-');
											}
										}
										else //null integer case
										{
											if(strlen(col_entry->col_name) < 10)
											{
												printf("%*s", 10, "-");
											}
											else
											{
												printf("%s", 16, "-");
											}
										}
									}
									else if(col_cur->col_type == T_CHAR)
									{
										char data[MAX_TOK_LEN] = "";
										strncpy(data, (char *)tuples_ptr, column_len);
										if(strlen(col_cur->col_name) > col_cur->col_len)
										{
											printf("%-*s",strlen(col_cur->col_name), data);
										}
										else
										{
											printf("%-*s",col_cur->col_len,data);
										}
									}
									else if(col_cur->col_type == T_INT)
									{
										int data = 0;
										char data_str[11] = "";
										data = *(int *) tuples_ptr;
										itoa(data,data_str,10);
										if(strlen(col_cur->col_name) < 10)
										{
											printf("%*s",10, data_str);
										}
										else
										{
											printf("%*s",16, data_str);
										}
									}
									tuples_ptr = (char *)tuples_ptr + col_cur->col_len;
									col_cur++;
								}//end of inner for loop
								col_cur = col_entry;
								printf("\n");
							}//end of outer for loop
						}
					}
					else if(where_is_null_flag == true)
					{
						blockptr = (char *)blockptr + where_offset; //moves blockptr to block
						int num_of_rows = 0; //number of rows selected
						
						for(i = 0; i < iterations; i++) //traverses to every tuple to file to find specified tuple by user
						{
								int column_len = *(char*)blockptr; //gets column length
								blockptr = (char *)blockptr + 1; //advances the blockptr to data

								if(where_column->col_type == T_CHAR)
								{
									char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
									strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
									if(column_len == 0) //if block data is equal to the user specified string
									{
										memcpy(tuples_ptr,(char*) row_ptr, record_length); 
										tuples_ptr = (char *) tuples_ptr + record_length;
										num_of_tuples++;
									}
								}
								else //where_column->col_type == T_INT
								{
									int where_blk_data = 0; //int data in memory
									where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
									if(column_len == 0) //compares integer in block with user specified
									{
										memcpy(tuples_ptr,(char*) row_ptr, record_length);
										tuples_ptr = (char *) tuples_ptr + record_length;
										num_of_tuples++;
									}
								}
							blockptr = (char *)blockptr + record_length-1; //moves the block pointer to the next row
							row_ptr = (char *) row_ptr + record_length;	
						}
						/* Done adding to array */

						/* Memory to file */
						tuples_ptr = tuples;//reset pointer to tuples
						for(i = 0; i < num_of_tuples; i++)
						{
							for(j = 0; j < num_of_columns; j++)
							{
								int column_len  = *(char *)tuples_ptr;
								tuples_ptr = (char *) tuples_ptr + 1;
								if(column_len == 0)
								{
									if(col_cur->col_type == T_CHAR)
									{
										if(strlen(col_cur->col_name) > col_cur->col_len)
										{
										printf("%-*c",strlen(col_cur->col_name),'-');
										}
										else
										{
										printf("%-*c",col_cur->col_len,'-');
										}
									}
									else //null integer case
									{
										if(strlen(col_entry->col_name) < 10)
										{
											printf("%*s", 10, "-");
										}
										else
										{
											printf("%s", 16, "-");
										}
									}
								}
								else if(col_cur->col_type == T_CHAR)
								{
									char data[MAX_TOK_LEN] = "";
									strncpy(data, (char *)tuples_ptr, column_len);
									if(strlen(col_cur->col_name) > col_cur->col_len)
									{
										printf("%-*s",strlen(col_cur->col_name), data);
									}
									else
									{
										printf("%-*s",col_cur->col_len,data);
									}
								}
								else if(col_cur->col_type == T_INT)
								{
									int data = 0;
									char data_str[11] = "";
									data = *(int *) tuples_ptr;
									itoa(data,data_str,10);
									if(strlen(col_cur->col_name) < 10)
									{
										printf("%*s",10, data_str);
									}
									else
									{
										printf("%*s",16, data_str);
									}
								}
								tuples_ptr = (char *)tuples_ptr + col_cur->col_len;
								col_cur++;
							}//end of inner for loop
							col_cur = col_entry;
							printf("\n");
						}//end of outer for loop
					}
					else if(where_is_not_null_flag == true)
					{
						blockptr = (char *)blockptr + where_offset; //moves blockptr to block
						int num_of_rows = 0; //number of rows selected
						
						for(i = 0; i < iterations; i++) //traverses to every tuple to file to find specified tuple by user
						{
								int column_len = *(char*)blockptr; //gets column length
								blockptr = (char *)blockptr + 1; //advances the blockptr to data

								if(where_column->col_type == T_CHAR)
								{
									char where_blk_data[MAX_TOK_LEN] = ""; //data from blk to see if it matches the user specified where_data
									strncpy(where_blk_data, (char *)blockptr, column_len); //copies string from block to data
									if(column_len != 0) //if block data is NOT equal to the user specified string
									{
										memcpy(tuples_ptr,(char*) row_ptr, record_length); 
										tuples_ptr = (char *) tuples_ptr + record_length;
										num_of_tuples++;
									}
								}
								else //where_column->col_type == T_INT
								{
									int where_blk_data = 0; //int data in memory
									where_blk_data = *(int *) blockptr; //gets the integer stored in the block and stoes it to where_blk_data
									if(column_len != 0) //sees if not null(column len != 0) 
									{
										memcpy(tuples_ptr,(char*) row_ptr, record_length);
										tuples_ptr = (char *) tuples_ptr + record_length;
										num_of_tuples++;
									}
								}
							blockptr = (char *)blockptr + record_length-1; //moves the block pointer to the next row
							row_ptr = (char *) row_ptr + record_length;	
						}
						/* Done adding to array */

						/* Memory to file */
						tuples_ptr = tuples;//reset pointer to tuples
						for(i = 0; i < num_of_tuples; i++)
						{
							for(j = 0; j < num_of_columns; j++)
							{
								int column_len  = *(char *)tuples_ptr;
								tuples_ptr = (char *) tuples_ptr + 1;
								if(column_len == 0)
								{
									if(col_cur->col_type == T_CHAR)
									{
										if(strlen(col_cur->col_name) > col_cur->col_len)
										{
										printf("%-*c",strlen(col_cur->col_name),'-');
										}
										else
										{
										printf("%-*c",col_cur->col_len,'-');
										}
									}
									else //null integer case
									{
										if(strlen(col_entry->col_name) < 10)
										{
											printf("%*s", 10, "-");
										}
										else
										{
											printf("%s", 16, "-");
										}
									}
								}
								else if(col_cur->col_type == T_CHAR)
								{
									char data[MAX_TOK_LEN] = "";
									strncpy(data, (char *)tuples_ptr, column_len);
									if(strlen(col_cur->col_name) > col_cur->col_len)
									{
										printf("%-*s",strlen(col_cur->col_name), data);
									}
									else
									{
										printf("%-*s",col_cur->col_len,data);
									}
								}
								else if(col_cur->col_type == T_INT)
								{
									int data = 0;
									char data_str[11] = "";
									data = *(int *) tuples_ptr;
									itoa(data,data_str,10);
									if(strlen(col_cur->col_name) < 10)
									{
										printf("%*s",10, data_str);
									}
									else
									{
										printf("%*s",16, data_str);
									}
								}
								tuples_ptr = (char *)tuples_ptr + col_cur->col_len;
								col_cur++;
							}//end of inner for loop
							col_cur = col_entry;
							printf("\n");
						}//end of outer for loop
					}
					else if(and_flag == true)
					{

					}
					else if(or_flag == true)
					{

					}
					else if (and_or_is_null_flag == true)
					{

					}
					else if(and_or_is_not_null_flag == true)
					{

					}
					else if(order_by_flag == true)
					{

					}
					else if(desc_flag == true)
					{

					}
					else
					{
						for(i = 0; i < iterations; i++)
						{
							for(j = 0; j < num_of_columns; j++)
							{
								int column_len  = *(char *)blockptr;
								blockptr = (char *) blockptr + 1;
								if(column_len == 0)
								{
									if(col_cur->col_type == T_CHAR)
									{
										if(strlen(col_cur->col_name) > col_cur->col_len)
										{
										printf("%-*c",strlen(col_cur->col_name),'-');
										}
										else
										{
										printf("%-*c",col_cur->col_len,'-');
										}
									}
									else //null integer case
									{
										if(strlen(col_entry->col_name) < 10)
										{
											printf("%*s", 10, "-");
										}
										else
										{
											printf("%s", 16, "-");
										}
									}
								}
								else if(col_cur->col_type == T_CHAR)
								{
									char data[MAX_TOK_LEN] = "";
									strncpy(data, (char *)blockptr, column_len);
									if(strlen(col_cur->col_name) > col_cur->col_len)
									{
										printf("%-*s",strlen(col_cur->col_name), data);
									}
									else
									{
										printf("%-*s",col_cur->col_len,data);
									}
								}
								else if(col_cur->col_type == T_INT)
								{
									int data = 0;
									char data_str[11] = "";
									data = *(int *) blockptr;
									itoa(data,data_str,10);
									if(strlen(col_cur->col_name) < 10)
									{
										printf("%*s",10, data_str);
									}
									else
									{
										printf("%*s",16, data_str);
									}
								}
								blockptr = (char *)blockptr + col_cur->col_len;
								col_cur++;
							}//end of inner for loop
							col_cur = col_entry;
							printf("\n");
						}//end of outer for loop
					}
				}
			}
		}
	}
	else if(cur->tok_value == F_SUM || 
		cur->tok_value == F_AVG ||
		cur->tok_value == F_COUNT) //AGGREGATE CASES: select avg(column) from class 2 where c1 = c1_data and c1 = c1_data order by c1 column
	{
		/* DECLARATIONS */
		token_list * aggregate_column = NULL;//aggregate column specified by user
		int aggregate_column_offset = 0;
		if(cur->tok_value == F_SUM)
		{
			cur = cur->next;//advances token
			if(cur->tok_value != S_LEFT_PAREN)
			{
				rc = MISSING_LEFT_PAREN; //return code to missing left paren
				cur->tok_value = INVALID;//set cursor token to invalid
				printf("ERROR - Missing (.\n");//alert user missing ) paren.
			}
			else
			{
				cur = cur->next;//advances token
				if(cur->tok_value == S_RIGHT_PAREN)
				{
					rc = NOT_ENOUGH_DATA;
					cur->tok_value = INVALID;
					printf("ERROR - Not Enougn Data.\n");
				}
				else if (cur->tok_value == EOC)
				{
					rc = INVALID_COLUMN_NAME;
					cur->tok_value = INVALID;
					printf("ERROR - Invalid Column Name.\n");
				}
				else
				{
					aggregate_column = cur;
					cur = cur->next;
					if(cur->tok_value != S_RIGHT_PAREN)
					{
						rc = MISSING_RIGHT_PAREN;
						cur->tok_value = INVALID;
						printf("ERROR - Missing ).\n");
					}
					else
					{
						cur = cur->next;
						if(cur->tok_value != K_FROM)
						{
							rc = MISSING_KEYWORD_FROM;
							cur->tok_value = INVALID;
							printf("ERROR - Missing Keyword FROM.\n");
						}
						else
						{
							cur = cur->next;
							if((cur->tok_class != keyword) &&
								(cur->tok_class != identifier) &&
								(cur->tok_class != type_name))
							{
								rc = INVALID_TABLE_NAME;
								cur->tok_value = INVALID;
								printf("ERROR - INVALID TABLE NAME.\n");
							}
							else
							{
								strcpy(tablename, cur->tok_string);
								strcpy(filename, cur->tok_string);
								strcat(filename,".dat");
								if((tab_entry = get_tpd_from_list(cur->tok_string)) == NULL)
								{
									rc = TABLE_NOT_EXIST;
									cur->tok_value = INVALID;
									printf("ERROR - No Such Table Exist.\n");
								}
								else //check if the column inside the parenthsis is valid
								{
									col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
									bool column_found = false;
									col_cur = col_entry;
									int i = 0;
									record_length = 0;
									int num_of_columns = tab_entry->num_columns;

									/* Calculate Record Length*/
									for(i = 0; i < num_of_columns; i++)
									{
										record_length += 1 + col_cur->col_len;
										col_cur++;
									}

									col_cur = col_entry;
									for(i = 0; i < num_of_columns; i++)
									{
										if(strcmp(aggregate_column->tok_string, col_cur->col_name) == 0)
										{
											column_found = true;
											printf("column found! \n");
											break;
										}
										aggregate_column_offset += 1 + col_cur->col_len;
										col_cur++;
									}
									if(column_found == false)
									{
										rc = INVALID_COLUMN_NAME;
										cur->tok_value = INVALID;
										printf("ERROR - Invalid Column Name\n");
									}
									else
									{
										cur = cur->next;
									}
								}
							}
						}
					}
				}
			}
			
			if(!rc && cur->tok_value != EOC) //process where clause
			{
				if(cur->tok_value == K_WHERE) //processes where clause
				{
					where_flag = true; //set where_flag to true
					printf("where clause!\n"); //alert user it is a where clause
					cur = cur->next;//advances token to next token

					bool column_found = false; //declare column found flag
					col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
					col_cur = col_entry; //reset col_cur to col_entry
					int i = 0; //count iterator
					int num_of_columns = tab_entry->num_columns; //number of columns
					for(i = 0; i < num_of_columns ; i++) //iterates through each column
					{
						if(strcmp(cur->tok_string, col_cur->col_name) == 0) //if user specified column matches the one declared in table
						{
							where_column = col_cur; //assign where_column to col_cur
							column_found = true; //set column found flag to true
							printf("column found!\n"); //alert the user column is found
							break; //break from the loop
						}
						where_offset += 1 + col_cur->col_len; //on going calculation of the where_offset
						col_cur++; //advance to the next column
					}

					if(column_found == false) //if no column was found
					{
						rc = INVALID_COLUMN_NAME; //set return code to invalid column name
						cur->tok_value = INVALID; //set the token value to invalid
						printf("ERROR - Invalid Column Name.\n"); //alert the user invalid token name
					}
					else
					{
						cur = cur->next;//advances token
						if((cur->tok_value == K_IS) || 
							(cur->tok_value == S_EQUAL) ||
							(cur->tok_value == S_GREATER)||
							(cur->tok_value == S_LESS))
						{
							if((cur->tok_value == K_IS) &&
								(cur->next->tok_value == K_NOT) &&
								(cur->next->next->tok_value == K_NULL))
							{
								where_flag = false;
								where_is_not_null_flag = true;
								printf("is not null!\n");
								cur = cur->next->next->next;
							}
							else if((cur->tok_value == K_IS) &&
									(cur->next->tok_value == K_NULL))
							{
								where_flag = false;
								where_is_null_flag = true;
								printf("is null!\n");
								cur = cur->next->next;
							}
							else if((cur->tok_value == S_EQUAL) ||
									(cur->tok_value == S_GREATER) ||
									(cur->tok_value == S_LESS))
							{
								strcpy(where_relational_op, cur->tok_string);
								printf("where relational operator!\n");
								cur = cur->next;
								if((cur->tok_value != STRING_LITERAL) &&
									(cur->tok_value != INT_LITERAL) &&
									(cur->tok_value != K_NULL))
								{
									rc = INVALID_DATA_TYPE;
									cur->tok_value = INVALID;
									printf("ERROR - Invalid Data Type.\n");
								}
								else
								{
									where_data = cur;
									if(where_column->col_type == T_CHAR && 
										(where_data->tok_value == STRING_LITERAL) ||
										(where_data->tok_value == K_NULL))
									{
										cur = cur->next;
									}
									else if(where_column->col_type == T_INT && 
											(where_data->tok_value == INT_LITERAL) ||
											(where_data->tok_value == K_NULL))
									{
										cur = cur->next;
									}
									else
									{
										rc= INVALID_DATA_TYPE;
										cur->tok_value = INVALID;
										printf("ERROR - Invalid Data Type\n");
									}
								}
							}
							else
							{
								rc = INVALID_RELATIONAL_OPERATOR;
								cur->tok_value = INVALID;
								printf("ERROR - Invalid Relational Operator.\n");
							}
						}
					}
					//begin processing the and/or clause here
					if(!rc && cur->tok_value != EOC && cur->tok_value != K_ORDER)
					{
						//cur = cur->next;
						if((cur->tok_value != K_AND) && 
							(cur->tok_value != K_OR))
						{
							rc = INVALID_RELATIONAL_OPERATOR;
							cur->tok_value = INVALID;
							printf("ERROR - Invalid Relational Operator\n");
						}
						else
						{
							if(cur->tok_value == K_AND)
							{
								and_flag = true;
							}
							else
							{
								or_flag = true;
							}
							cur = cur->next;
							bool column_found = false;
							col_cur = col_entry;
							int i = 0;
							int num_of_columns = tab_entry->num_columns;
							for(i = 0;i < num_of_columns;i++)
							{
								if(strcmp(cur->tok_string, col_cur->col_name) == 0)
								{
									and_or_column = col_cur;
									column_found = true;
									printf("column found! \n");
									break;
								}
								and_or_offset += 1 + col_cur->col_len;
								col_cur++;
							}
							if(column_found == false)
							{
								rc = INVALID_COLUMN_NAME;
								cur->tok_value = INVALID;
								printf("ERROR - Invalid Column Name. \n");
							}
							else
							{
								cur = cur->next;		
								if((cur->tok_value == K_IS) && 
									(cur->next->tok_value == K_NULL))
								{
									and_or_is_null_flag = true;
									printf("and or is null flag!\n");
									cur = cur->next->next;
								}
								else if((cur->tok_value == K_IS) &&
										(cur->next->tok_value == K_NOT) &&
										(cur->next->next->tok_value == K_NULL))
								{
									and_or_is_not_null_flag = true;
									printf("and or is not null flag!\n");
									cur = cur->next->next->next;
								}
								else if((cur->tok_value == S_EQUAL) ||
										(cur->tok_value == S_GREATER) || 
										(cur->tok_value == S_LESS))
								{
									strcpy(and_or_relational_op,cur->tok_string);
									printf("and or relational operator!\n");
									cur = cur->next;
									if((cur->tok_value != STRING_LITERAL) &&
										(cur->tok_value != INT_LITERAL) &&
										(cur->tok_value != K_NULL))
									{
										rc = INVALID_DATA_TYPE;
										cur->tok_value = INVALID;
										printf("ERROR - Invalid Data Type\n");
									}
									else
									{
										and_or_data = cur;
										cur = cur->next;
									}
								}
								else
								{
									rc = INVALID_RELATIONAL_OPERATOR;
									cur->tok_value = INVALID;
									printf("ERROR - Invalid Relational Operator.\n");
								}
							}
						}
					}
				}
			}
			if(!rc && cur->tok_value != EOC) //process order by clause
			{
				if(cur->tok_value == K_ORDER)
				{
					cur = cur->next;
					if(cur->tok_value != K_BY)
					{
						rc = MISSING_KEYWORD_BY;
						cur->tok_value = INVALID;
						printf("ERROR - Missing Keyword BY.\n");
					}
					else
					{
						order_by_flag = true;
						cur = cur->next;
						printf("order by clause!\n");

						bool column_found = false; //declare column found flag
						col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);
						col_cur = col_entry; //reset col_cur to col_entry
						int i = 0; //count iterator
						int num_of_columns = tab_entry->num_columns; //number of columns
						for(i = 0; i < num_of_columns ; i++) //iterates through each column
						{
							if(strcmp(cur->tok_string, col_cur->col_name) == 0) //if user specified column matches the one declared in table
							{
								order_by_column = col_cur; //assign where_column to col_cur
								column_found = true; //set column found flag to true
								printf("column found!\n"); //alert the user column is found
								break; //break from the loop
							}
							order_by_offset += 1 + col_cur->col_len; //on going calculation of the where_offset
							col_cur++; //advance to the next column
						}
						if(column_found == false) //if no column was found
						{
							rc = INVALID_COLUMN_NAME; //set return code to invalid column name
							cur->tok_value = INVALID; //set the token value to invalid
							printf("ERROR - Invalid Column Name.\n"); //alert the user invalid token name
						}
						else
						{
							cur = cur->next;
							if(cur->tok_value == K_DESC)
							{
								desc_flag = true;
								cur = cur->next;
								printf("desc!\n");
							}
						}
					}
				}
			}
			if(!rc)//end of line is expected and ready to process date
			{
				if(cur->tok_value != EOC)
				{
					rc = TOO_MUCH_DATA;
					cur->tok_value = INVALID;
					printf("ERROR - Too Much Data.\n");
				}
				else
				{
					/* SELECT * MEMORY STARTS HERE */
					if(!rc)
					{
						if((fhandle = fopen(filename, "r+tc")) == NULL) //opens file
						{
							rc = FILE_OPEN_ERROR; //sets return code to file open error
						}
						else
						{
							printf("file open \n"); //alerts the user file has opened
							void *blockptr = NULL; //declares block pointer
							char s[512] = ""; //string for the line
							char *sptr = NULL; //string pointer
							iterations = 0; //number of iterations
							int i = 0; //iterator counter
							int j = 0; //iterator counter
							col_entry = (cd_entry*)((char*)tab_entry + tab_entry->cd_offset);//col_entry declaration
							col_cur = col_entry; //column traverser
							record_length = 0;

							int num_of_columns = tab_entry->num_columns;
							/*Calculates Record Length*/
							for(i = 0; i < num_of_columns; i++) //calculates record length
							{
								record_length += 1 + col_cur->col_len;
								col_cur++;
							}
							printf("record length is: %d \n", record_length);

							col_cur = col_entry;//reset col_cur to start of entry
			
							/*Gets the row counter*/
							fseek (fhandle, 0, SEEK_SET); //set file cursor to the start of file
							fgets(s, sizeof(s), fhandle); //get the first line
							iterations = atoi(s); //set iterations to what the first line is (should be global counter)

							/*Allocate memory*/
							block = (char *)malloc( record_length * iterations); //allocates block to size of record length * global counter
							memset(block, '\0', record_length * iterations); //clears the junk of the block
							blockptr = block; //sets block pointer to block

							sptr = strtok(s, "\t"); //reads first line (row counter)
							fgets(s, sizeof(s), fhandle); //assigns s to the the current line
							sptr = strtok(s, "\t");  //goes to the next line

							/*LOAD FROM FILE TO MEMORY*/
							for(i = 0; i < iterations; i++)
							{
								for(j = 0; j < num_of_columns; j++)
								{
									if(strncmp(sptr,"NULL",strlen(sptr)) == 0) //null case
									{
										int column_len = col_cur->col_len;	
										*(int *) blockptr = 0;
										blockptr = (char *)blockptr + 1;
									}
									else if(col_cur->col_type == T_CHAR) //string case
									{
										int column_len = col_cur->col_len;
										if(memchr(sptr,'\'',1) != NULL)
										{
											strncpy (sptr, sptr+1, strlen(sptr)-1);
											sptr[strlen(sptr)-2]='\0';
										}
										*(int *) blockptr = strlen(sptr);
										blockptr = (char *)blockptr + 1;
										strncpy((char*)blockptr,sptr,column_len);
									}
									else //int case
									{
										int column_len = col_cur->col_len;
										*(int*) blockptr = column_len;
										blockptr = (char *)blockptr + 1;
										*(int*) blockptr = atoi(sptr);
									}
									blockptr = (char *)blockptr + col_cur->col_len; //advances the blockptr to next attribute
									sptr = strtok(NULL, "\t"); //tokenizes the next column
									col_cur++; //advances the col_cur
								}
								fgets(s, sizeof(s), fhandle); //assigns s to the current line
								sptr = strtok(s, "\t"); //tokenizes the next token
								col_cur = col_entry; //resets column cursor
							}
						/* DONE LOADING FILE INTO MEMORY*/

						/* WRITE FROM MEMORY TO CONSOLE */

							/* Format Heading */
							col_cur = col_entry; //reset column cursor to col_entry;
							i = 0; // iterator count
							num_of_columns = tab_entry->num_columns;
							for(i = 0; i < num_of_columns; i++)//prints the column names
							{
								if(col_cur->col_type == T_CHAR)//right justified
								{
									if(col_cur->col_len >= strlen(col_cur->col_name)) //declared string column length is less than or equal to the name of the column
									{
										printf("%-*s", col_cur->col_len, col_cur->col_name);
									}
									else //the column name is longer than the string declared
									{
										printf("%-*s", strlen(col_cur->col_name), col_cur->col_name);
									}
								}
								else //column is an integer
								{
									if(strlen(col_cur->col_name) > 10)
									{
										printf("%*s", strlen(col_cur->col_name), col_cur->col_name);
									}
									else
									{
										printf("%*s", 10, col_cur->col_name);
									}
								}
								col_cur++;
							}

							/* FILTER USER INPUT */
							printf("\n");//print new line
							col_cur = col_entry;//reset col_cur
							char *tuples = NULL; //block of tuples
							void * row_ptr = NULL;//pointer to row
							void * and_or_ptr = NULL; //pointer to and_or data
							tuples = (char *) malloc(iterations * (record_length));
							void * tuples_ptr = tuples; //used to add to array of tuples
							int num_of_tuples = 0;
							blockptr = block;//reset blockptr(to point to the where clause)
							and_or_ptr = block; //reset and_or_ptr
							row_ptr = block;//reset row_ptr to block
							memset(tuples, '\0', iterations * record_length);
							i = 0;
							j = 0;
							num_of_columns = tab_entry->num_columns;
							int column_len = 0;
							int and_or_column_len = 0;
						}
					}
				}
			}
		}
		else if(cur->tok_value == F_AVG)
		{

		}
		else //cur->tok_value == F_COUNT
		{

		}
	}
	else //single nad multi-column processing
	{

	}
	return rc; //returns the return code
}

int initialize_tpd_list()
{
	int rc = 0;
	FILE *fhandle = NULL;
	struct _stat file_stat;

  /* Open for read */
  if((fhandle = fopen("dbfile.bin", "rbc")) == NULL)
	{
		if((fhandle = fopen("dbfile.bin", "wbc")) == NULL)
		{
			rc = FILE_OPEN_ERROR;
		}
		else
		{
			g_tpd_list = NULL;
			g_tpd_list = (tpd_list*)calloc(1, sizeof(tpd_list));
			
			if (!g_tpd_list)
			{
				rc = MEMORY_ERROR;
			}
			else
			{
				g_tpd_list->list_size = sizeof(tpd_list);
				fwrite(g_tpd_list, sizeof(tpd_list), 1, fhandle);
				fflush(fhandle);
				fclose(fhandle);
			}
		}
	}
	else
	{
		/* There is a valid dbfile.bin file - get file size */
		_fstat(_fileno(fhandle), &file_stat);
		printf("dbfile.bin size = %d\n", file_stat.st_size);

		g_tpd_list = (tpd_list*)calloc(1, file_stat.st_size);

		if (!g_tpd_list)
		{
			rc = MEMORY_ERROR;
		}
		else
		{
			fread(g_tpd_list, file_stat.st_size, 1, fhandle);
	//		fflush(fhandle);
			fclose(fhandle);

			if (g_tpd_list->list_size != file_stat.st_size)
			{
				rc = DBFILE_CORRUPTION;
			}
		}
	}
	return rc;
}
	
int add_tpd_to_list(tpd_entry *tpd)
{
	int rc = 0;
	int old_size = 0;
	FILE *fhandle = NULL;

	if((fhandle = fopen("dbfile.bin", "wbc")) == NULL)
	{
		rc = FILE_OPEN_ERROR;
	}
  else
	{
		old_size = g_tpd_list->list_size;

		if (g_tpd_list->num_tables == 0)
		{
			/* If this is an empty list, overlap the dummy header */
			g_tpd_list->num_tables++;
		 	g_tpd_list->list_size += (tpd->tpd_size - sizeof(tpd_entry));
			fwrite(g_tpd_list, old_size - sizeof(tpd_entry), 1, fhandle);
		}
		else
		{
			/* There is at least 1, just append at the end */
			g_tpd_list->num_tables++;
		 	g_tpd_list->list_size += tpd->tpd_size;
			fwrite(g_tpd_list, old_size, 1, fhandle);
		}
		fwrite(tpd, tpd->tpd_size, 1, fhandle);
		fflush(fhandle);
		fclose(fhandle);
	}
	return rc;
}

int drop_tpd_from_list(char *tabname)
{
	int rc = 0;
	tpd_entry *cur = &(g_tpd_list->tpd_start);
	int num_tables = g_tpd_list->num_tables;
	bool found = false;
	int count = 0;

	if (num_tables > 0)
	{
		while ((!found) && (num_tables-- > 0))
		{
			if (stricmp(cur->table_name, tabname) == 0)
			{
				/* found it */
				found = true;
				int old_size = 0;
				FILE *fhandle = NULL;

				if((fhandle = fopen("dbfile.bin", "wbc")) == NULL)
				{
					rc = FILE_OPEN_ERROR;
				}
			  else
				{
					old_size = g_tpd_list->list_size;

					if (count == 0)
					{
						/* If this is the first entry */
						g_tpd_list->num_tables--;

						if (g_tpd_list->num_tables == 0)
						{
							/* This is the last table, null out dummy header */
							memset((void*)g_tpd_list, '\0', sizeof(tpd_list));
							g_tpd_list->list_size = sizeof(tpd_list);
							fwrite(g_tpd_list, sizeof(tpd_list), 1, fhandle);
						}
						else
						{
							/* First in list, but not the last one */
							g_tpd_list->list_size -= cur->tpd_size;

							/* First, write the 8 byte header */
							fwrite(g_tpd_list, sizeof(tpd_list) - sizeof(tpd_entry),
								     1, fhandle);

							/* Now write everything starting after the cur entry */
							fwrite((char*)cur + cur->tpd_size,
								     old_size - cur->tpd_size -
										 (sizeof(tpd_list) - sizeof(tpd_entry)),
								     1, fhandle);
						}
					}
					else
					{
						/* This is NOT the first entry - count > 0 */
						g_tpd_list->num_tables--;
					 	g_tpd_list->list_size -= cur->tpd_size;

						/* First, write everything from beginning to cur */
						fwrite(g_tpd_list, ((char*)cur - (char*)g_tpd_list),
									 1, fhandle);

						/* Check if cur is the last entry. Note that g_tdp_list->list_size
						   has already subtracted the cur->tpd_size, therefore it will
						   point to the start of cur if cur was the last entry */
						if ((char*)g_tpd_list + g_tpd_list->list_size == (char*)cur)
						{
							/* If true, nothing else to write */
						}
						else
						{
							/* NOT the last entry, copy everything from the beginning of the
							   next entry which is (cur + cur->tpd_size) and the remaining size */
							fwrite((char*)cur + cur->tpd_size,
										 old_size - cur->tpd_size -
										 ((char*)cur - (char*)g_tpd_list),							     
								     1, fhandle);
						}
					}
					fflush(fhandle);
					fclose(fhandle);
				}
			}
			else
			{
				if (num_tables > 0)
				{
					cur = (tpd_entry*)((char*)cur + cur->tpd_size);
					count++;
				}
			}
		}
	}
	
	if (!found)
	{
		rc = INVALID_TABLE_NAME;
	}

	return rc;
}

tpd_entry* get_tpd_from_list(char *tabname)
{
	tpd_entry *tpd = NULL;
	tpd_entry *cur = &(g_tpd_list->tpd_start);
	int num_tables = g_tpd_list->num_tables;
	bool found = false;

	if (num_tables > 0)
	{
		while ((!found) && (num_tables-- > 0))
		{
			if (stricmp(cur->table_name, tabname) == 0)
			{
				/* found it */
				found = true;
				tpd = cur;
			}
			else
			{
				if (num_tables > 0)
				{
					cur = (tpd_entry*)((char*)cur + cur->tpd_size);
				}
			}
		}
	}
	return tpd;
}