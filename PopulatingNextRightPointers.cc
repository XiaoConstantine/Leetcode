/*
 * =====================================================================================
 *
 *       Filename:  PopulatingNextRightPointers.cc
 *
 *    Description:  LeetCode Populating Next Right Pointers
 *        Version:  1.0
 *        Created:  03/30/13 16:24:49
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
 *         Name:  connect
 *  Description:  
 * =====================================================================================
 */
	void
connect (TreeLinkNode* root)
{
	if(root == NULL){
		return;
	}

	if(root->left){
		root->left->next = root->right;
	}
	if(root->right){
		root->right->next = root->next?root->next->left:NULL;
	}
	connect(root->left);
	connect(root->right);
}		
/* -----  end of function connect  ----- */
