/*
 * =====================================================================================
 *
 *       Filename:  BalancedBinaryTree.cc
 *
 *    Description:  LeetCode Balanced Binary Tree
 *        Version:  1.0
 *        Created:  03/30/13 17:41:33
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
 *         Name:  getBalanced
 *  Description:  
 * =====================================================================================
 */
int
getBalanced (TreeNode* root)
{
	if(root == NULL)return 0;

	int left = getBalanced(root->left);
	if(left == -1)return -1;
	int right = getBalanced(root->right);
	if(right == -1)return -1;
	if(abs(left-right) > 1){
		return -1;
	}
	return left > right? left+1:right+1;
}		/* -----  end of function getBalanced  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isBalanced
 *  Description:  
 * =====================================================================================
 */
bool
isBalanced (TreeNode* root)
{
	if(root == NULL)return true;
	int val getBalanced(root);
	if(root == -1){
		return false;
	}else{
		return true;
	}
}		/* -----  end of function isBalanced  ----- */

