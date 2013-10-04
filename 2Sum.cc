/*
 * =====================================================================================
 *
 *       Filename:  2Sum.cc
 *
 *    Description:  LeetCode 2Sum problem index are not zero-based
 *
 *        Version:  1.0
 *        Created:  03/20/13 19:51:29
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
#include <stdio.h>
#include <algorithm>
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  twoSum
 *  Description:  
 * =====================================================================================
 */
vector<int>
twoSum (vector<int>&num, int target)
{
	vector<int> result;
	vector<int> temp = num;
	int i = 0, k = num.size() - 1;
	int pos_1 = 0, pos_2 = 0;
    sort(temp.begin(), temp.end());
	while(i < k){
		if(temp[i] + temp[k] == target){
			pos_1 = i;
			pos_2 = k;
			break;
		}else if(temp[i] + temp[k] > target){
			k--;
		}else{
			i++;
		}
	}
	
	for(int j = 0; j < num.size(); j++){
		if(num[j] == temp[pos_1]){
			result.push_back(j);
		}else if(num[j] == temp[pos_2]){
			result.push_back(j);
		}
	}

	sort(result.begin(), result.end());

	return result;
}		/* -----  end of function twoSum  ----- */
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
