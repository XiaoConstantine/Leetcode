/*
 * =====================================================================================
 *
 *       Filename:  Combinations.cc
 *
 *    Description:  LeetCode Combinations
 *        Version:  1.0
 *        Created:  04/23/13 15:59:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
using namespace std;
void print(vector<int> t){
	for(int i = 0; i < t.size(); i++){
		cout<< t[i] << " ";
	}
	cout<< endl;
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
void
DFS (vector<vector<int> >&result, vector<int>&temp, int n, int k, int dep)
{
	if(temp.size() == k){
		result.push_back(temp);
		return;
	}

	for(int i = dep; i<=n; i++){
		temp.push_back(i);
		print(temp);
		cout << "-----------push elemnt" << endl;
		DFS(result, temp, n, k, i+1);
		cout << "---------return to upper f" << endl;
		print(temp);
		temp.pop_back();
	}
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  combine
 *  Description:  
 * =====================================================================================
 */
vector<vector<int> >
combine (int n, int k)
{
	vector<vector<int> > result;
	vector<int> temp;
	DFS(result, temp, n, k, 1);
	return result;
}		/* -----  end of function combine  ----- */
int main(){
	int n = 4;
	int k = 2;
	combine(n, k);
	return 0;
}
