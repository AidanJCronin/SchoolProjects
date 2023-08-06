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

void deadcodeRecursive(Instruction* curr);
void nonCritical(Instruction *head);

Instruction *dead_code_elimination(Instruction *head) {

	/* STUDENTS - BEGIN */
	Instruction *current = head;
	head->prev = NULL;

	while(current->next != NULL){ // Get to bottom of list
		if (current->opcode == LOADI){
			if (current->field1 == 1024){
				current->critical = 'c'; //Mark as critical
			}
		}
		current = current->next;
	}
	while(current->prev != NULL){
		if(current->opcode == OUTPUTAI){ // Look for OUTPUTAI	
			current->critical = 'c';
			if(current != head){
				deadcodeRecursive(current); // Call recursive function deadcodeRecursive
			}
		}
		current = curr->prev;
	}
	/* STUDENTS - END */
	nonCritical(head);
	return head;
}

// Helper method to remove non critical instructions
void nonCritical(Instruction *head)
{ // Go through list and remove non critical instructions
	Instruction *ptr = head; 
	Instruction *temp = NULL;
	while(ptr)
	{
		if(ptr->critical != 'c') // Find non critical
		{
			temp = ptr->next;
			if(ptr->prev != NULL)
				ptr->prev->next = ptr->next;
			if(ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			free(ptr); // Get rid of non critical
			ptr = temp;
		}
		else
			ptr = ptr->next;
	}
}

// Helper method to recursively go through list and mark all critical instructions
void deadcodeRecursive(Instruction* current){

	Instruction* ptr;
	ptr = current->prev;

	while(ptr->prev != NULL){
		if(current->opcode == OUTPUTAI){
			if(current->field2 == ptr->field3){
				if(ptr->opcode != LOADI){
					ptr->critical = 'c';
					deadcodeRecursive(ptr);
					return;
				}
			}
		}
		else if(current->opcode == LOADAI){
                        if((ptr->opcode == STOREAI) && (current->field2 == ptr->field3)){
                                ptr->critical = 'c';
                                deadcodeRecursive(ptr);
                                return;
                        }
                }
		else if(current->opcode == STOREAI){
			if((current->field1 == ptr->field1) || (current->field1 == ptr->field2) || (current->field1 == ptr->field3)){
				ptr->critical = 'c';
				deadcodeRecursive(ptr);
				return;
			}
		}
		else if (curr->opcode == LOADI){
			//Noting necessary
		}
		else{
			if ((current->field1 == ptr->field3) || (current->field2 == ptr->field3)|| (current->field1 == ptr->field2) || (current->field2 == ptr->field2)){
				if (ptr->opcode != STOREAI){
					ptr -> critical = 'c';
					deadcodeRecursive(ptr);
				}
			}
		}
		ptr = ptr->prev;
	}
}

int main()
{
	Instruction *head;

	head = ReadInstructionList(stdin);
	if (!head) {
		WARNING("No instructions\n");
		exit(EXIT_FAILURE);
	}

	head = dead_code_elimination(head);

	if (head) 
		PrintInstructionList(stdout, head);
	
	return EXIT_SUCCESS;
}

