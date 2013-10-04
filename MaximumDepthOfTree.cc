/*
 * =====================================================================================
 *
 *       Filename:  MaximumDepthOfTree.cc
 *
 *    Description:  LeetCode Maximum Depth of Binary Tree
 *        Version:  1.0
 *        Created:  04/19/13 16:49:29
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
 *  Description:  
 * =====================================================================================
 */
int
DFS (TreeNode* root, int& depth)
{
	if(root == NULL){
		depth = 0;
		return 0;
	}

	int l = DFS(root->left, depth);
	int r = DFS(root->right, depth);
	if(l == 0 && r == 0){
		depth =1;
	}else if(l == 0){
		l = INT_MIN;
	}else if(r == 0){
		r = INT_MIN;
	}
	depth = max(l,r) + 1;
	return depth;
		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  maxDepth
 *  Description:  
 * =====================================================================================
 */
int
maxDepth (TreeNode* root)
{
	int depth = 0;
	DFS(root, depth);
	return depth;
}		/* -----  end of function maxDepth  ----- */
