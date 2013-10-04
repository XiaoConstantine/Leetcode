/*
 * =====================================================================================
 *
 *       Filename:  ConstructBinaryTreeFromPostorderAndInorder.cc
 *
 *    Description:  LeetCode Construct Binary Tree From Post order and Inorder
 *        Version:  1.0
 *        Created:  03/28/13 15:26:45
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
helper (vector<int> &inorder, vector<int> &postorder, int i_s, int i_e, int p_s, int p_e)
{
	if(i_s > i_e){
		return NULL;
	}
	int root = postorder[p_e];
	int root_index;
	for(int i = i_s; i<=i_e; i++){
		if(inorder[i] == root){
			root_index = i;
			break;
		}
	}
	int len = root_index - i_s;
	TreeNode *node = new TreeNode(root);
	node->left = helper(inorder, postorder, i_s, root_index-1, p_s, p_s+len-1); // attention! the last para cannot change to p_e-len-1 cause if left subtree is null then p_s should > p_e
	node->right = helper(inorder, postorder, root_index+1, i_e, p_s+len, p_e-1);
	return node;
}		/* -----  end of function helper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  buildTree
 *  Description:  
 * =====================================================================================
 */
TreeNode*
buildTree (vector<int>& inorder, vector<int> &postorder)
{
	return helper(inorder, postorder, 0, inorder,size()-1, 0, postorder.size()-1);
}		/* -----  end of function buildTree  ----- */
