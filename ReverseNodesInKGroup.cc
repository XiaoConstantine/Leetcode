/*
 * =====================================================================================
 *
 *       Filename:  ReverseNodesInKGroup.cc
 *
 *    Description:  LeetCode Reverse Nodes In K Group
 *        Version:  1.0
 *        Created:  04/15/13 17:05:15
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
 *         Name:  reverse
 *  Description:  
 * =====================================================================================
 */
ListNode*
reverse (ListNode* pre, ListNode* next)
{
	ListNode* last = pre->next;
	ListNode* cur = last->next;
	while(cur != next){
		last->next = cur->next;
		cur->next = pre->next;
		pre->next = cur;
		cur = last->next;
	}
	return last;
}		
/* -----  end of function reverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  reverseKGroup
 *  Description:  
 * =====================================================================================
 */
ListNode*
reverseKGroup (ListNode* head, int k)
{
	ListNode* g = new ListNode(-1);
	g->next = head;
	if(!head || k == 1) return head;
	ListNode* pre = g;

	int i = 0;
	while(head){
		i++;
		if(i % k == 0){
			pre = reverse(pre, head->next);
			head = pre->next;
		}else{
			head = head->next;
		}
	}

	head = g->next;
	delete g;

	return head;
}		/* -----  end of function reverseKGroup  ----- */
