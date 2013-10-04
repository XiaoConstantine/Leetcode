/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeMaxSum.cc
 *
 *    Description:  LeetCode Binary Tree Max Path Sum
 *
 *        Version:  1.0
 *        Created:  03/21/13 18:53:25
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
 *         Name:  DFS
 *  Description: Like max subarray sum in a array  
 * =====================================================================================
 */
int
DFS (TreeNode* root, int &sum, int& maxEnd )
{
	if(root == NULL){
		return 0;
	}
	int l = DFS(root->left, sum, maxEnd);
	int r = DFS(root->right, sum, maxEnd);
	maxEnd = root->val;
	if(l > 0)
		maxEnd += l;
	if(r > 0)
		maxEnd += r;
	sum  = max(sum, maxEnd);
	return max(l,r)>0?max(l,r)+root->val:root->val;
}		

/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  maxPathSum
 *  Description:  
 * =====================================================================================
 */
int
maxPathSum (TreeNode* root)
{
	int sum = INT_MIN;
	int maxEnd = 0;
	DFS(root, sum, maxEnd);
	return sum;
}		/* -----  end of function maxPathSum  ----- */
