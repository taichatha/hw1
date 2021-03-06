/*All reports should begin with a statement of whether you were able to complete the assignment and get
*your code working. Also summarize your performance results in a sentence or two. Reports should
*contain typical information containing at least the following in whatever order/style/format you choose:
*- Problem Description
*- Approach
*-Results
*- Analysis
*- Conclusions
*- Pledge*/
/* Assignment 1: Writing your own Shell
* CS 4414: Operating Systems - Spring 2015 - Homework 1
* Taimoor Chatha - tuc4uw
* msh.c - shell 
* Pledge: On my honor as a student, i have neither given nor recieved aid on this 
* assignment. 
*
*
* the Folllowing code implements a Shell. 
* Modifications:
* Feb 2 - Start of Applicatoin
*/

#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <regex.h>


/* Initialize variables and methods */

int status;
int i;
int one_nonspace = -1;
int on = 1;
char input[101];
char *temp;
char* tokenized;
char operators[3] = {'>', '<', '|'};
char** tokens;


/*Credit for whitespace trimmer function:http://stackoverflow.com/questions/122616/how-*do-i-trim-leading-trailing-whitespace-in-a-standard-way*/
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void getInput(char *prmpt, char *buff){

    printf(">:");
    fgets(buff, 101, stdin); //segfault here when input spaces.
    
    /*printf("works!");*/
    

    if(buff[strlen(buff) -1] != '\n'){
        int over = 0;

        while(fgetc(stdin) != '\n')
            over++;

        if(over>0)
        {
            printf("Command is over 100 characters. Please try again\n");
            status = 1;
        }
    }

    else{
        buff[strlen(buff) - 1] = '\0';
        status = 0;
    }



}


char** tokenize(char *a_str)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last = 0;
    char delim[2];
    delim[0] = ' ';
    delim[1] = 0;

    /* Count how many elements will be extracted. */
   while (*tmp)
    {
        if (' ' == *tmp)
        {
            count++;
            last = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}



/* Create a parser Feb 2*/


int main(int argc, char **argv){

  while(on){

      getInput(">: ", input);
      temp = input;
      printf("%s", temp);
      
      

      if(status == 0){
          /*printf("%s\n", input);*/

      }




      /*Split the line into tokens*/
      if(input[0] != ' ')
        tokens = tokenize(input);

      /*if tokens[0] == 'exit', then quit.
      */

      /*if(strcmp(*(tokens),"exit") == 0){
        break;}*/


  /*2/3 Now we need to do something with the split up tokens*/
      /*printf("input after token: %s\n", input);*/
  /*Free the tokens at the end!!! Remember this!*/
      if (tokens)
      {
      int i;
      for (i = 0; *(tokens + i); i++)
      {
          printf("%s\n", *(tokens + i));
          free(*(tokens + i));
      }

      free(tokens);
      }
    }


    return 0;




}
