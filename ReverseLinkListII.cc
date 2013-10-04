/*
 * =====================================================================================
 *
 *       Filename:  ReverseLinkListII.cc
 *
 *    Description:  LeetCode Reverse Link List
 *        Version:  1.0
 *        Created:  03/31/13 16:32:38
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
 *         Name:  reverseBetween
 *  Description:  
 * =====================================================================================
 */
ListNode*
reverseBetween (ListNode* head, int m, int n)
{
	ListNode* g = new ListNode(-1);
	g->next = head;
	head = g;
	ListNode* pre = head;
	int step = n - m;
	while(m>1){
		pre = pre->next;
		m--;
	}
	ListNode* cur = pre->next;
	ListNode* post = cur->next;

	if(step >= 1){
		while(step > 0 && post){
			ListNode* temp = post->next;
			post->next = cur;
			cur = post;
			post = temp;
			step--;
		}
		ListNode* temp = pre->next;
		pre->next = cur;
		temp->next = post;

	}
    head = g;
	return head->next;
}		/* -----  end of function reverseBetween  ----- */
