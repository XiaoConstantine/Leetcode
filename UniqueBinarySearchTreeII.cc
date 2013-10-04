/*
 * =====================================================================================
 *
 *       Filename:  UniqueBinarySearchTreeII.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/13 16:40:51
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
vector<TreeNode* >
helper (int start, int end)
{
	vector<TreeNode* > result;
	if(start > end){
		result.push_back(NULL);
		return result;
	}

	for(int i = start; i<=end; i++){
		vector<TreeNode* > leftS = helper(start, i-1);
		vector<TreeNode* > rightS = helper(i+1, end);
		for(int j = 0; j < leftS.size(); j++){
			for(int k = 0; k < rightS.size(); k++){
				TreeNode* node = new TreeNode(i);
				node->left = leftS[j];
				node->right = rightS[k];
				result.push_back(node);
			}
		}
	}
}		/* -----  end of function helper  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  generateTrees
 *  Description:  
 * =====================================================================================
 */
vector<TreeNode* >
generateTrees (int n)
{
	return helper(1, n);
}		/* -----  end of function generateTrees  ----- */
