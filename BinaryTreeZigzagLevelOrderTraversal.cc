/*
 * =====================================================================================
 *
 *       Filename:  BinaryTreeZigzagLevelOrderTraversal.cc
 *
 *    Description:  LeetCode Binary Tree Zigzag Level Order Traversal
 *        Version:  1.0
 *        Created:  03/27/13 18:47:23
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
 *         Name:  zigzagLevelOrder
 *  Description:  BFS with a mark for zigzag 
 * =====================================================================================
 */
vector<vector<int> >
zigzagLevelOrder (TreeNode* root)
{
	vector<TreeNode* > help_stack;
	vector<vector<int> >result;
	bool zigLeft = false;
	if(!root) return result;
	help_stack.push_back(root);
	while(help_stack.size() > 0){
		vector<TreeNode* > next;
		vector<int> level;
		for(int i = 0; i < help_stack.size(); i++){
			level.push_back(help_stack[i]->val);
			if(help[i]->left){
				next.push_back(help[i]->left);
			}
			if(help[i]->right){
				next.push_back(help[i]->right);
			}
		}
        if(zigLeft){
		  reverse(level.begin(), level.end());
	    }
		zigLeft = !zigLeft;
		result.push_back(level);
		help_stack = next;
	}
	return result;
}		
/* -----  end of function zigzagLevelOrder  ----- */
