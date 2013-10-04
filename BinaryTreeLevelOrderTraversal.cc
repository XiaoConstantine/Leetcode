/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeLevelOrderTraversal.cc
 *
 *    Description:  LeetCode Binary Tree Level Order Traversal
 *        Version:  1.0
 *        Created:  04/22/13 17:55:07
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
 *         Name:  levelOrder
 *  Description:  BFS  
 * =====================================================================================
 */
vector<vector<int> >
levelOrder (TreeNode* root)
{
	vector<vector<int> > result;
	if(root == NULL){
		return result;
	}
	vector<TreeNode*> s;
	s.push_back(root);
	int index = 0;
	int nextCount = 1;
	while(index < s.size()){
		int curCount = nextCount;
		nextCount = 0;
		vector<int> level;
		for(int i = index; i< index + curCount; i++){
			root = s[i];
			level.push_back(root->val);
			if(root->left != NULL){
				s.push_back(root->left);
				nextCount++;
			}
			if(root->right != NULL){
				s.push_back(root->right);
				nextCount++;
			}
		}
		result.push_back(level);
		index = index+curCount;
	}
	return result;
}		/* -----  end of function levelOrder  ----- */

