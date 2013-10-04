/*
 * =====================================================================================
 *
 *       Filename:  LetterCombinationsOfPhoneNumber.cc
 *
 *    Description:  LeetCode Letter Combinations of phone number 
 *        Version:  1.0
 *        Created:  03/25/13 00:17:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  Recursive 
 * =====================================================================================
 */
void
DFS (string digits, vector<string>&result, string& temp, string trans[], int dep)
{
	if(dep == digits.size()){
		result.push_back(temp);
		return;
	}
	int cur = digits[dep] - 48;

	for(int i = 0; i < trans[cur].size(); i++){
		temp.push_back(trans[cur][i]);
		DFS(digits, result, temp, trans, dep+1);
		temp.resize(temp.size() - 1);
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  letterCombinations
 *  Description:  
 * =====================================================================================
 */
vector<string>
letterCombinations (string digits)
{
	string trans[] = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"   
	};
	vector<string> result;
	string temp;
	DFS(digits,result, temp, trans, 0);
	return result;
}		/* -----  end of function letterCombinations  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{  
	string s = "413";
	vector<string> result(letterCombinations(s));
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<",";
	}

	for(vector<string>::iterator it = result.begin(); it!= result.end(); it++){
		cout<<*it<<",";
	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
