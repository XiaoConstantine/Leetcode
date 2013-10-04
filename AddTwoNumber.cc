/*
 * =====================================================================================
 *
 *       Filename:  AddTwoNumber.cc
 *
 *    Description:  LeetCode Add Two Numbers  
 *        Version:  1.0
 *        Created:  03/23/13 21:51:34
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
 *         Name:  addTwoNumber
 *  Description:  
 * =====================================================================================
 */
ListNode*
addTwoNumber (ListNode* l1, ListNode* l2)
{
	int carry = 0;
	ListNode* result = new LinkList(-1);
	ListNode* temp = result;
	ListNode* runner1 = l1;
	ListNode* runner2 = l2;
   
	while(l1 || l2){
		int l1_v = (runner1 == NULL)?0:runner1->val;
		int l2_v = (runner2 == NULL)?0:runner2->val;

		ListNode* node = new ListNode((l1_v+l2_v+carry)%10);
		carry = (l1_v + l2_v + carry)/10;
		temp->next = node;
		temp = temp->next;
		runner1 = (runner1== NULL)?NULL:runner1->next;
		runner2 = (runner2 == NULL)?NULL:runner2->next;
	}

	if(carry){
		temp->next = new ListNode(1);
	}

	temp = result->next;
	delete result;
	return temp;
}		/* -----  end of function addTwoNumber  ----- */
