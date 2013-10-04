/*
 * =====================================================================================
 *
 *       Filename:  ConstructBinaryTreeFromPreorderAndInorder.cc
 *
 *    Description:  LeetCode Construct Binary Tree From Preorder and Inorder
 *        Version:  1.0
 *        Created:  03/28/13 14:46:23
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
 *         Name:  buildHelper
 *  Description:  Recursive  
 * =====================================================================================
 */
TreeNode* 
buildHelper (vector<int>& preorder, vector<int> &inorder, int p_s, int p_e, int i_s, int i_e)
{
	if(p_s > p_e){
		return NULL;
	}

	int root = preorder[p_s];
	int root_index;
	int len;
	for(int i = i_s; i<=i_e; i++){
		if(inorder[i] == root){
			root_index = i;
		}
	}
	len = root_index - i_s;
	TreeNode* node = new TreeNode(root);
	node->left = buildHelper(preorder, inorder, p_s+1, p_s+len, i_s, root_index-1);
	node->right = buildHelper(preorder,inorder, p_s+len+1, p_e, root_index+1, i_e);
	return node;
}		/* -----  end of function buildHelper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  buildTree
 *  Description:  
 * =====================================================================================
 */
TreeNode*
buildTree (vector<int>& preorder, vector<int>& inorder)
{
	return 
}		/* -----  end of function buildTree  ----- */
