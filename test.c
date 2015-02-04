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
#include <string.h>
#include <stdio.h>


/* Initialize variables and methods */

int status;
int i;
int one_nonspace = -1;
int on = 1;
char input[101];
char temp[101];
char* tokenized;
char operators[3] = {'>', '<', '|'};
char** tokens;



void getInput(char *prmpt, char *buff){

	printf(">:");
	fgets(buff, 101, stdin);
	

}




/* Create a parser Feb 2*/


int main(int argc, char **argv){
  
  while(on){
	
	  getInput(">: ", input);
	  tokenized = input;
	  
	  
	  
	  if(status == 0){
		  /*printf("%s\n", input);*/
		  
	  }
	  
	  
    }
    

    return 0;
    



}


