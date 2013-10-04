/*
 * =====================================================================================
 *
 *       Filename:  PathSumII.cc
 *
 *    Description:  LeetCode Path Sum II
 *        Version:  1.0
 *        Created:  03/30/13 17:19:40
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
 *         Name:  DFS
 *  Description:  Recursive  
 * =====================================================================================
 */
void
DFS (vector<vector<int> >&result, vector<int>& temp, TreeNode* root, int sum, int target)
{
	if(!root) return;
	sum += root->val;
	temp.push_back(root->val);
	if(sum == target&&root->left == NULL && root->right == NULL){
		result.push_back(temp);
	}else{
		if(root->left){
			DFS(result, temp, root->left, sum, target);
		}
		if(root->right){
			DFS(result, temp, root->right, sum, target);
		}
	}
	sum -= root->val;
	temp.pop_back();
	return;
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  pathSum
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
pathSum (TreeNode* root, int num)
{
	vector<vector<int> >result;
	vector<int> temp;
	DFS(result, temp, root, 0, sum);
	return result;;
}		/* -----  end of function pathSum  ----- */

