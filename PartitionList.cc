/*
 * =====================================================================================
 *
 *       Filename:  PartitionList.cc
 *
 *    Description:  LeetCode Partition List
 *        Version:  1.0
 *        Created:  03/27/13 14:30:08
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
 *         Name:  partition
 *  Description:  
 * =====================================================================================
 */
ListNode*
partition (ListNode* head, int x)
{
	ListNode* less = new ListNode(-1);
	ListNode* more = new ListNode(-1);
	ListNode* result = less;
	ListNode* temp = more;
	while(head){
		if(head->val < x){
			less->next = head;
			less = less->next;
		}else{
			more->next = head;
			more = more->next;
		}
		head = head->next;
	}
	more->next = NULL; // pay attention to this!
	less->next = temp->next;

	return result->next;;
}		/* -----  end of function partition  ----- */

