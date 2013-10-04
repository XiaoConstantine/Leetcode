/*
 * =====================================================================================
 *
 *       Filename:  RemoveDupFromSortedListII.cc
 *
 *    Description:  LeetCode Remove Dup from Sorted List II
 *
 *        Version:  1.0
 *        Created:  03/26/13 00:03:17
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
 *  Description:  Add a guard in case of first node deleted two pointer method 
 * =====================================================================================
 */
ListNode*
deleteDup (ListNode* head)
{
	ListNode* guard = new ListNode(-1);
	guard->next = head;
	ListNode* runner1 = guard;
	ListNode* runner2 = head;
	while(runner2){
		bool isDup = false;
		while(runner2->next && runner2->val == runner2->next->val){
			isDup = true;
			runner2 = runner2->next;
		}
		if(isDup){
			runner2 = runner2->next;
			continue;
		}
		runner1->next = runner2;
		runner1 = runner1->next;
		runner2 = runner2->next;
	}
	runner1->next = runner2; // if runner2 is NULL then modify runner1
	ListNode* result = guard->next;
	return result;
}		

/* -----  end of function deleteDup  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  deleteDup
 *  Description:  
 * =====================================================================================
 */
ListNode*
deleteDup (ListNode* head)
{
	if(!head) return NULL;
	ListNode* r1 = head;
	while(r1->next){
		ListNode* r2 = r1->next;
		while(r2 && r2->val == r1->val){
			r2 = r2->next;
		}
		if(r1->next != r2){
			r1->next = r2;
		}else{
			r1 = r1->next;
		}
	}
	return head;
}		/* -----  end of function deleteDup  ----- */
