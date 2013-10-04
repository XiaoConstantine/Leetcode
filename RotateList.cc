/*
 * =====================================================================================
 *
 *       Filename:  RotateList.cc
 *
 *    Description:  LeetCode Rotate List
 *        Version:  1.0
 *        Created:  04/06/13 17:42:03
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
 *         Name:  rotateList
 *  Description:  
 * =====================================================================================
 */
ListNode*
rotateList (ListNode* head, int k)
{
	if(head == NULL || k == 0) return head;
	ListNode* runner1 = head;
	ListNode* runner2 = head;
	int len = 1;
	while(runner1->next){
		runner1 = runner1->next;
		len++;
	}
	runner1->next = runner2;
	k = len - k%len;
	int step = 0;
	while(step < k){
		runner1 = runner1->next;
		step++;
	}
	head = runner1->next;
	runner1->next = NULL;
	return runner1;
}		
/* -----  end of function rotateList  ----- */

