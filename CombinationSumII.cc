/*
 * =====================================================================================
 *
 *       Filename:  CombinationSumII.cc
 *
 *    Description:  LeetCode Combination Sum II
 *        Version:  1.0
 *        Created:  04/09/13 13:23:16
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
 *  Description:  
 * =====================================================================================
 */
void
DFS (vector<vector<int> >&result, vector<int> &temp, vector<int>& num, int dep, int sum, int target)
{
	if(sum > target) return;
	if(sum == target){
		result.push_back(temp);
		return;
	}

	for(int i = dep; i< num.size(); i++){
		sum += num[i];
		temp.push_back(num[i]);
		DFS(result, temp, num, i+1, sum, target);
		temp.pop_back();
		sum -=num[i];
		while(i < num.size()-1 && num[i] == num[i+1]) i++;
	}
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  combinationSumII
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
combinationSumII (vector<int> &num, int target)
{
	vector<vector<int> > result;
	vector<int> temp;
	sort(num.begin(), num.end());
	DFS(result, temp, num, 0,0, target);
	return result;
}		/* -----  end of function combinationSumII  ----- */
