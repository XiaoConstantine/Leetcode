/*
 * =====================================================================================
 *
 *       Filename:  RecoverBinarySearchTree.cc
 *
 *    Description:  LeetCode Recover Binary Search Tree
 *        Version:  1.0
 *        Created:  03/30/13 21:06:08
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
 *         Name:  inorderTraverse
 *  Description:  O(n) space method use inorder to get sorted val then reassgin  
 * =====================================================================================
 */
void
inorderTraverse (vector<int> &result, vector<TreeNode* >&list, TreeNode* root)
{
	if(root == NULL) return;
    inorderTraverse(result, list, root->left);
	result.push_back(root->val);
	list.push_back(root);
	inorderTraverse(result, list, root->right);
}		
/* -----  end of function inorderTraverse  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  recoverTree
 *  Description:  
 * =====================================================================================
 */
void
recoverTree (TreeNode* root)
{
	vector<int> result;
	vector<TreeNode* >list;
	inorderTraverse(result, list, root);
	sort(result.begin(), result.end());
	for(int i = 0; i < list.size(); i++){
		list[i]->val = result[i];
	}
}		
/* -----  end of function recoverTree  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  recoverTree
 *  Description:  O(1) place using parent->val > current->val to find violation (cause using 
 *                inorder traverse if it is right, then parent->val should less then current->val)
 *                find the first violation's parent and swap with second violation's current
 * =====================================================================================
 */
void
recoverTree (TreeNode* root)
{
    TreeNode* f1 = NULL, *f2 = NULL;
	TreeNode* current, *pre, *parent = NULL;

	if(root == NULL){
		return;
	}
	bool found = false;
	current = root;
	while(current){
		if(current->left == NULL){
			if(parent && parent->val > current->val){
				if(!found){
					f1 = parent;
					found = true;
				}
				f2 = current;
			}
			parent = current;
			current = current->right;
		}else{
			pre = current->left;
			while(pre->right && pre->right != current){
				pre = pre->right;
			}
			if(pre->right == NULL){
				pre->right = current;
				current = current->left;
			}else{
				pre->right = NULL;
				if(parent->val > current->val){
					if(!found){
						f1 = parent;
						found = true;
					}
					f2 = current;

				}
				parent = current;
				current = current->right;
			}
		}
	}
	if(f1&&f2){
		swap(f1->val, f2->val);
	}
}		
/* -----  end of function recoverTree  ----- */
