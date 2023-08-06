/*
 *********************************************
 *  314 Principles of Programming Languages  *
 *  Spring 2023                              *
 *  Student Version                          *
 *  Author:                                  *
 *********************************************
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "InstrUtils.h"
#include "Utils.h"

/*
* Will traverse instructions in groups of 3, searching for a patten of LOADI, LOADI, and ADD | SUB | MUL instructions 
*/

Instruction *constant_folding(Instruction *head) {

		/* STUDENTS - BEGIN */
	Instruction *first, *second, *third; // Creating Variables for a 3 size window
	first = NULL;
	second = NULL; 
	third = NULL;

        first = head;
        
	while (first){ //Start of iterations
        	second = first->next;
		int temp1, temp2, temp3;
        	if(!second){ // No second
                	first = first->next;
                	continue;
        	}
        	third = second->next;
        	if(!third){ //No third
        		first = first->next;
                	continue;
            	}
		// check if instructions are valid for constant folding
        	if (!first->opcode == LOADI || !second->opcode == LOADI){
                	first = first->next;
                	continue;
        	}
		if (third->field1 == second->field2 && third->field2 == first->field2){
                        temp1 = second->field1;
                        temp2 = first->field1;
                }
                else if(third->field1 == first->field2 && third->field2 == second->field2){
                        temp1 = first->field1;
                        temp2 = second->field1;
                }
         	else{
                	first = first->next; // Move on to next window
                	continue;
        	}
		// Constant folding optimization
         	switch (third->opcode){
                	case ADD:
                		temp3 = temp1 + temp2;
                		break;
                	case SUB: 
                		temp3 = temp1 - temp2;
                		break;
                	case MUL:
                		temp3 = temp1 * temp2;
                		break;    
                	default:
               			first = first->next; // Move on to next window 
                		continue;
            	}
		third->opcode = LOADI;
            	third->field2 = third->field3;
		third->field1 = temp3;
            	 // Move next window to third instruction
            	first = first->next;
        }	
 		/* STUDENTS - END */
	
	return head;
}

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	head = constant_folding(head);

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

