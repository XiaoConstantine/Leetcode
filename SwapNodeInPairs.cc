/*
 * =====================================================================================
 *
 *       Filename:  SwapNodeInPairs.cc
 *
 *    Description:  LeetCode Swap Pairs
 *        Version:  1.0
 *        Created:  03/23/13 20:06:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  swapPairs
 *  Description:  two pointers method  
 * =====================================================================================
 */
ListNode*
swapPairs (ListNode* head)
{
	ListNode* runner1 = head;
	ListNode* ret = head;
	if(runner1 == NULL || runner1->next == NULL){
		return ret;
	}else{
		ListNode* runner2 = runner1->next;
		while(runner2 != NULL){
			swap(runner1->val, runner2->val);
			if(runner1->next->next){
				runner1 = runner1->next->next;
				runner2 = runner2->next->next;
			}else{
				break;
			}
		}
		return ret;
	}
}		
/* -----  end of function swapPairs  ----- */




/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

