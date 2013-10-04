/*
 * =====================================================================================
 *
 *       Filename:  ConvertSortedArrayToBalancedBST.cc
 *
 *    Description:  LeetCode Convert Sorted Array To BST(height balanced)
 *
 *        Version:  1.0
 *        Created:  03/28/13 15:50:01
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
 *         Name:  helper2
 *  Description:  Construct tree from leaves to root O(n)
 * =====================================================================================
 */
TreeNode*
helper2 (vector<int>& num, int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start + end)/2;
	TreeNode* left = helper2(num, start, mid - 1);
	TreeNode* root = new TreeNode(num[mid]);
	root->left = left;
	root->right = helper2(num, mid+1, end);

	return root;
}		/* -----  end of function helper2  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  helper
 *  Description:  construct tree from root to leaves O(nlgn)
 * =====================================================================================
 */
TreeNode*
helper (vector<int> &num, int start, int end)
{
	if(start > end){
		return NULL;
	}
	int mid = start + (end-start)/2;
	int root = num[mid];
	TreeNode* node = new TreeNode(root);
	node->left = helper(num, start, mid-1);
	node->right = helper(num, mid+1, end);
	return node;
}		/* -----  end of function helper  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sortedArrayToBST
 *  Description:  Pay attention to height balanced meaning num[mid] is root
 * =====================================================================================
 */
TreeNode*
sortedArrayToBST (vector<int>& num)
{
	return helper(num, 0, num.size()-1);
}		/* -----  end of function sortedArrayToBST  ----- */
