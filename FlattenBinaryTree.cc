/*
 * =====================================================================================
 *
 *       Filename:  FlattenBinaryTree.cc
 *
 *    Description:  LeetCode Flatten Binary Tree
 *        Version:  1.0
 *        Created:  03/28/13 17:10:04
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
 *         Name:  flatten
 *  Description:  
 * =====================================================================================
 */
	void
flatten (TreeNode* root)
{
	if(root == NULL) return;
	if(root->left)
		flatten(root->left);
	if(root->right)
		flatten(root->right);
	if(root->left == NULL)
		return;
	TreeNode** temp = &(root->left->right);
	while(*temp){
		temp = &((*temp)->right);
	}
	*temp = root->right;
	root->right = root->left;
	root->left = NULL;
}		/* -----  end of function flatten  ----- */
