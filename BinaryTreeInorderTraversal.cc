/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeInorderTraversal.cc
 *
 *    Description:  LeetCode Binary Tree Inorder Traversal
 *        Version:  1.0
 *        Created:  03/27/13 16:37:49
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
void
helper (TreeNode* root, vector<int>& result)
{
	if(!root) return;
	if(!root->left && !root->right) {
		result.push_back(root->val);
		return;
	}

	helper(root->left, result);
	result.push_back(root->val);
	helper(root->right, result);
}		/* -----  end of function helper  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  inorderTraversal
 *  Description:  Recursive way 
 * =====================================================================================
 */
vector<int>
inorderTraversal (TreeNode* root)
{
	vector<int> result;
	helper(root, result);
	return result;
}		
/* -----  end of function inorderTraversal  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  inorderTraversalII
 *  Description:  Iterative way with help of stack
 * =====================================================================================
 */
vector<int>
inorderTraversalII (TreeNode* root)
{
	vector<int> result;
	vector<TreeNode* > left;
	TreeNode* runner = root;
	if(!root) return result;
    
	while(left.size() > 0 || runner){
		while(runner){
			left.push_back(runner);
			runner = runner->left;
		}
		runner = left.back();
		left.pop_back();
		result.push_back(runner->val);
		runner = runner->right;
	}
	return result;
}		
/* -----  end of function inorderTraversalII  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  inorderTraversalIII
 *  Description:  Iterative way without of stack
 *				  Initilize curr as root;
 *				  While curr is not null
 *				  if curr does not have left child
 *				    a print curr data
 *				    b go to right
 *				  else
 *				    a make curr as right child of the rightmost node in current left substree
 *				    b go to this left chid
 * =====================================================================================
 */
vector<int>
inorderTraversalIII (TreeNode* root)
{
	TreeNode* curr, *pre;
	vector<int> result;
	if(root == NULL) return result;

	curr = root;
	while(curr){
		
		if(curr->left == NULL){
			result.push_back(curr->val);
			curr = curr->right;
		}else{
			/* find predecessor of curr */
			pre = curr->left;
			while(pre->right && pre->right != current){
				pre = pre->right;
			}
			/* make curr as right child of its inorder predecessor */
			if(pre->right == NULL){
				pre->right = curr;
				curr = curr->left;
			}
			/* revert the changes made in if part to store the original tree
			 * i.e. fix the right child of predecessor
			 * */
			else{

				pre->right = NULL;
				result.push_back(curr->val);
				curr = curr->right;
			}
		}
	}
	return result;
}		/* -----  end of function inorderTraversalIII  ----- */
