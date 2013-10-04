/*
 * =====================================================================================
 *
 *       Filename:  PermutationII.cc
 *
 *    Description:  LeetCode Permutation II
 *
 *        Version:  1.0
 *        Created:  04/08/13 00:29:55
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
 *  Description:  Add a visited to check element.
 *				  1. sort original array
 *				  2. only if num[i-1] == num[i] && visited[i-1] == 1
 *				     then can add num[i] to array
 * =====================================================================================
 */
void
DFS (vector<vector<int> >&result, vector<int> &temp, vector<int> &visited, vector<int>&num, int dep)
{
	if(dep == num.size()){
		result.push_back(temp);
		return;
	}

	for(int i = 0; i < num.size(); i++){
		if(visited[i] == 0){
			if(i>0 && num[i] == num[i-1] && visited[i-1] == 0)
				continue;
			visited[i] = 1;
			temp.push_back(num[i]);
			DFS(result, temp, visited, num, dep+1);
			temp.pop_back();
			visited[i] = 0;
		}
	}
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  permuteUnique
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> > 
permuteUnique (vector<int> & num)
{
	vector<vector<int> > result;
	vector<int> temp;
	vector<int> visited(num.size(), 0);
	sort(num.begin(), num.end());
	DFS();
	return result;
}		/* -----  end of function permuteUnique  ----- */
