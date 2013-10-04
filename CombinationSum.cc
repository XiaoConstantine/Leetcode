/*
 * =====================================================================================
 *
 *       Filename:  CombinationSum.cc
 *
 *    Description:  LeetCode Combination Sum
 *        Version:  1.0
 *        Created:  03/25/13 13:27:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
void
DFS (vector<int>& candidates, vector<int>& temp, vector<vector<int> >& result, int dep, int sum, int target)
{
	if(sum > target)return;
	if(sum == target){
	    result.push_back(temp);
		return;
	}

	for(int i = dep; i < candidates.size(); i++){
		temp.push_back(candidates[i]);
		sum += candidates[i];
		DFS(candidates, temp, result, i, sum, target);
		sum -= candidates[i];
		temp.resize(temp.size() -  1);
	}
}	
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  combinationSum
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
combinationSum (vector<int>& candidates, int target)
{
	vector<vector<int> > result;
	vector<int> temp;
	int sum = 0;
	sort(candidates.begin(), candidates.end());
	DFS(candidates, temp, result, 0, sum, target);
	return result;;
}		/* -----  end of function combinationSum  ----- */
int main(){
	vector<int> can;
	can.push_back(1);
	can.push_back(2);
	can.push_back(5);
	can.push_back(10);
	can.push_back(20);
	can.push_back(50);
	can.push_back(100);
	can.push_back(200);

	vector<vector<int> > ret = combinationSum(can, 200);
	cout << ret.size() << endl;
	return 0;
}
