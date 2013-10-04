/*
 * =====================================================================================
 *
 *       Filename:  GrayCode.cc
 *
 *    Description:  LeetCode Gray Code
 *        Version:  1.0
 *        Created:  03/31/13 17:28:55
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
 *         Name:  grayCode
 *  Description:  
 * =====================================================================================
 */
vector<int>
grayCode (int n)
{
	vector<int> result;
	result.push_back(0);

	for(int i = 0; i< n; i++){
		int high = 1<<i;
		cout << high << endl;
		int len = result.size();
		cout << len << "----";
		for(int j = len -1; j>= 0; j--){	
			result.push_back(high + result[j]);
		}
	}

	return result;
}

/* -----  end of function grayCode  ----- */
int main(){
	int n = 2;
	vector<int> result = grayCode(n);
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	return 0;
}
