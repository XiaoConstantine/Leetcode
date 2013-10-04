/*
 * =====================================================================================
 *
 *       Filename:  RemoveDupFromSortedList.cc
 *
 *    Description:  LeetCode Remove Dup from Sorted List
 *
 *        Version:  1.0
 *        Created:  03/25/13 23:11:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  deleteDup
 *  Description:  Two Pointer 
 * =====================================================================================
 */
ListNode*
deleteDup (ListNode* head)
{
	if(head == NULL || head->next == NULL) return head;
	ListNode* runner1 = head;
	ListNode* runner2 = head->next;
	while(runner2){
		if(runner2->val == runner1->val){
			runner2 = runner2->next;
			runner1->next = runner2;
			continue;
		}
		runner1 = runner1->next;
		runner2 = runner2->next;
	}
	return head;
}		/* -----  end of function deleteDup  ----- */

