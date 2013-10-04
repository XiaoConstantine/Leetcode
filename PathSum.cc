/*
 * =====================================================================================
 *
 *       Filename:  PathSum.cc
 *
 *    Description:  LeetCode Path Sum
 *        Version:  1.0
 *        Created:  03/28/13 16:42:11
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
 *  Description:  Recursive when comes to leaf judge if it equals to target
 * =====================================================================================
 */
bool
helper (TreeNode* root, int sum, int target)
{
	if(root == NULL) return false;
	sum += root->val;
	if(root->left == NULL && root->right == NULL){
		if(sum == target){
			return true;
		}else{
			return false;
		}
	}
	return helper(root->left, sum, target)||helper(root->right, sum, target);
}		/* -----  end of function helper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  hasPathSum
 *  Description:  
 * =====================================================================================
 */
bool
hasPathSum (TreeNode* root, int sum)
{
	return helper(root, 0, sum);
}		/* -----  end of function hasPathSum  ----- */
