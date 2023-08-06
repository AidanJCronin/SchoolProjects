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
#include <math.h>
#include "InstrUtils.h"
#include "Utils.h"

/*
* Will return log2(n) if it is an integer (meaning n is a power of 2), and -1 otherwise
*/
int int_log2(int n) {

	int s = 1, i = 0;

	while (s < n) {
		s = s << 1;
		i++;
	}

	if (s == n)
		return i;
	else
		return -1;

}

/*
* Will traverse instructions in groups of two, searching for a patten of LOADI and MUL | DIV instructions 
* where LOADI is a power of 2, and collapse these instructions into on shift operation of LSHIFTI | RSHIFTI
*/
Instruction *strength_reduction(Instruction *head) {

		/* STUDENTS - BEGIN */
	Instruction *first, *second;
        first = head;
	second = NULL;
        while (first){
		int shiftAmount;
            	second = first->next;
            	if(!second){
                	first = first->next;
                	continue;
		}
            	if(!first->opcode ==  LOADI){
                	first = first->next;
                	continue;
            	}
            	if(second->field2 != first->field2){
                	first = first->next;
                	continue;
            	}
	    	if(!(first->field1 && !(first->field1 & (first->field1-1)))){ // Checking if power of 2
			first = first->next;
			continue;
		}
	    	else{
                	shiftAmount = (int)int_log2(first->field1); // Find shift amount
		}
            	switch(second->opcode){ // Change opcode
                	case MUL:
                    		second->opcode = LSHIFTI; 
                    		break;
                	case DIV:
                    		second->opcode = RSHIFTI; 
                    		break;
                	default:
                    		first = first->next; // Next window
                    		continue;
            	}
            	second->field2 = shiftAmount; // Set shift amount
            	first = first->next; // Next window
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

	head = strength_reduction(head);

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

