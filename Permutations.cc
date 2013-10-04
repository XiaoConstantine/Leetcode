/*
 * =====================================================================================
 *
 *       Filename:  Permutations.cc
 *
 *    Description:  LeetCode Permutation
 *
 *        Version:  1.0
 *        Created:  03/22/13 18:11:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <vector>
bool canUse[100];
int a[100];
vector<vector<int> > result;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  top->bot
 * =====================================================================================
 */
void
DFS (vector<int>& num, int dep, int maxDep)
{
	if(dep == maxDep){
		vector<int> ans;
		for(int i = 0; i < maxDep; i++){
			ans.push_back(a[i]);
		}
		result.push_back(ans);
	    return;
	}

	for(int i = 0; i < maxDep; i++){
		if(canUse[i]){
			canUse[i] = false;
			a[dep] =  num[i];
			DFS(num, dep+1, maxDep);
			canUse[i] = true;
		}
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  permute
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
permute (vector<int> &num)
{
	result.clear();
	DFS(num, 0, num.size());
	return result;
}		
/* -----  end of function permute  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  permuteII
 *  Description:  another way of recursive bot->top
 * =====================================================================================
 */
vector<vector<int> >
permuteII (vector<int>& num)
{
	vector<vector<int> >result;
	if(num.size() == 1){
		vector<int> temp;
		temp.push_back(num.back());
		result.push_back(temp);
	}else{
		int ret = num.back();
		num.pop_back();
		vector<vector<int> > temp_result = permuteII(num);

		for(int i = 0; i < temp_result.size(); i++){
			for(int j =0; j <= temp_result[i].size(); j++){
				vector<int>temp_vec(temp_result[i]);
				temp_vec.insert(temp_vec.begin()+j, ret);
				result.push_back(temp_vec);
			}
		}
        return result;
	}
}		
/* -----  end of function permuteII  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
