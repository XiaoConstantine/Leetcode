/*
 * =====================================================================================
 *
 *       Filename:  SymmetricTree.cc
 *
 *    Description:  LeetCode Symmetric Tree
 *
 *        Version:  1.0
 *        Created:  03/30/13 20:11:25
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
 *         Name:  isSym
 *  Description:  Recursive way 
 * =====================================================================================
 */
bool
isSym (TreeNode* n1, TreeNode* n2)
{
	if(n1 == NULL){
		return n2 == NULL;
	}

	if(n2 == NULL){
		return n1 == NULL;
	}

	if(n1->val != n2->val){
		return false;
	}

	if(!isSym(n1->left, n2->right)){
		return false;
	}
	if(!isSym(n1->right, n2->left)){
		return false;
	}

	return true;
}		
/* -----  end of function isSym  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isSymmetric
 *  Description:  
 * =====================================================================================
 */
bool
isSymmetric (TreeNode* root)
{
	if(root == NULL) return true;

	return isSym(root->left, root->right);
}		
/* -----  end of function isSymmetric  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isSymmetricII
 *  Description:  Iterative way
 * =====================================================================================
 */
bool
isSymmetricII (TreeNode* root)
{
	if(root == NULL) return true;
	vector<TreeNode* >preLevel;
	vector<TreeNode* >curLevel;
	preLevel.push_back(root);

	while(preLevel.size() > 0){
		while(preLevel.size() > 0){
			TreeNode* temp = preLevel.back();
			preLevel.pop_back();
			if(temp == NULL) continue;
			curLevel.push_back(temp->left);
			curLevel.push_back(temp->right);
		}
		int start = 0, end = curLevel.size()-1;
		while(start < end){
			TreeNode* pl = curLevel[start];
			TreeNode* pr = curLevel[end];
			int l = pl==NULL?-1:pl->val;
			int r = pr==NULL?-1:pr->val;
			if(l != r){
				return false;
			}
			start++;
			end--;
		}
		preLevel.clear();
		preLevel.insert(preLevel.begin(), curLevel.begin(), curLevel.end());
		curLevel.clear();
	}
	return true;
}		/* -----  end of function isSymmetricII  ----- */
