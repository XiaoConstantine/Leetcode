/*
 * =====================================================================================
 *
 *       Filename:  ValidateBST.cc
 *
 *    Description: Given a binary tree, determine if it is a valid binary search tree 
 *        Version:  1.0
 *        Created:  03/17/13 17:37:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){

	}
};				
/* ----------  end of struct TreeNode  ---------- */
typedef struct TreeNode TreeNode;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isValidBST
 *  Description:  
 * =====================================================================================
 */
bool
isValidBST (TreeNode *root )
{
	if(!root)
		return true;
	bool left = true;
	bool right = true;
    
	if(root->left && !root->right){
		if(root->left->val >= root->val){
			return false;
		}else{
			left = isValidBST(root->left);

			/*Check right most element in left subtree */
			while(root->left->right){
				root->left = root->left->right;
			}
			if(root->left->val >= root->val){
				right = false;
			}
			return left&right;
		}
	}else if(!root->left && root->right){
		if(root->right->val <= root->val){
			return false;
		}else{
			right = isValidBST(root->right);

			/*Check left most element in right substree */
			while(root->right->left){
				root->right = root->right->left;
			}
			if(root->right->val <= root->val){
				left = false;
			}
			return left&right;
		}
	}else if(root->left && root->right){
		if(root->left->val >= root->val || root->right->val <= root->val){
			return false;
		}else{
			left = isValidBST(root->left);
	    
		 /*Check right most element in left subtree */
			while(root->left->right){
				root->left = root->left->right;
			}
			if(root->left->val >= root->val){
				left = left&false;
			}		

			right = isValidBST(root->right);
			
		 /*Check left most element in right substree */
			while(root->right->left){
				root->right = root->right->left;
			}
			if(root->right->val <= root->val){
				right = right&false;
			}

			return left&right;
		}
	}else{
		return true;
	}
}		
/* -----  end of function isValidBST  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  helper
 *  Description:  
 * =====================================================================================
 */
bool
helper (TreeNode* root, int low, int high)
{
	if(!root) return true;
	if(root->val > low && root->val < high){
		return helper(root->left, low, root->val) && helper(root->right, root->val, high);
	}else{
		return false;
	}
}		/* -----  end of function helper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isValidBSTII
 *  Description:  Simple way O(n)
 * =====================================================================================
 */
bool
isValidBSTII (TreeNode* root)
{
	return helper(root, INT_MIN, INT_MAX);
}		/* -----  end of function isValidBSTII  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{ 
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
