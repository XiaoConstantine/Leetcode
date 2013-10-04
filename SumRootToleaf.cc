/*
 * =====================================================================================
 *
 *       Filename:  SumRootToleaf.cc
 *
 *    Description:  LeetCode Sum root to leaf 
 *                    1
 *                  2  3     return 12 + 13 = 25
 *        Version:  1.0
 *        Created:  03/21/13 17:41:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
	void
DFS (TreeNode *root, int& sum, int path )
{
	if(root == NULL) return;
    path = path*10 + root->val;
	if(root->left == NULL && root->right == NULL){
		sum+= path;
		return;
	}
	DFS(root->left, sum, path);
	DFS(root->right, sum, path);

}	
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sumNumbers
 *  Description:  
 * =====================================================================================
 */
int
sumNumbers (TreeNode* root )
{
	int result = 0;
	int path = 0;

	DFS(root, result, path);
	return result;
}		/* -----  end of function sumNumbers  ----- */
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
