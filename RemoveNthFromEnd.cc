/*
 * =====================================================================================
 *
 *       Filename:  RemoveNthFromEnd.cc
 *
 *    Description:  LeetCode Remove Nth from end
 *        Version:  1.0
 *        Created:  03/25/13 01:00:58
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
 *         Name:  removeNthFromEnd
 *  Description:  Two Pointer method this also count as one pass 
 * =====================================================================================
 */
ListNode*
removeNthFromEnd (ListNode* head)
{
	ListNode* runner1 = head;
	ListNode* runner2 = head;
	int count = 0;
	while(runner2 && count < n){
		runner2 = runner2->next;
		count++;
	}

	if(count == n && runner2 == NULL){
		return head->next;
	}

	while(runner2->next){
		runner1 = runner1->next;
		runner2 = runner2->next;
	}

	runner1->next = runner1->next->next;
	return head;
}		/* -----  end of function removeNthFromEnd  ----- */
