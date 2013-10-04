/*
 * =====================================================================================
 *
 *       Filename:  ConvertSortedListToBalancedBST.cc
 *
 *    Description:  LeetCode Convert Sorted List to Balanced BST  
 *
 *        Version:  1.0
 *        Created:  03/28/13 16:25:03
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
 *         Name:  helper
 *  Description:  
 * =====================================================================================
 */
TreeNode*
helper (ListNode* head, int start, int end)
{
	if(start > end) return NULL;

	int mid = start + end/2;
	ListNode* temp = head;
	for(int i = start; i<mid; i++){
		p = p->next;
	}
    TreeNode* left = helper(head, start, mid-1);
	TreeNode* right = helper(p->next, mid+1, end);
	TreeNode* node = new TreeNode(p->val);
	node->left = left;
	node->right = right;

	return node;
}		/* -----  end of function helper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sortedListToBST
 *  Description:  
 * =====================================================================================
 */
TreeNode*
sortedListToBST (ListNode* head)
{
	int len = 0;
	ListNode* temp = head;
	while(temp){
		len++;
		temp = temp->next;
	}

	return helper(head, 0, len-1);
}		/* -----  end of function sortedListToBST  ----- */
