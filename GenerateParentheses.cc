/*
 * =====================================================================================
 *
 *       Filename:  GenerateParentheses.cc
 *
 *    Description:  LeetCode GenerateParentheses
 *        Version:  1.0
 *        Created:  03/21/13 14:38:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include <string>
#include <vector>
using namespace std;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
void
DFS (vector<string> &result, string &sample, int deep, int n, int left, int right)
{
	if(deep = n*2){
		result.push_back(sample);
		return;
	}

	if(left < n){
		sample.push_back('(');
		DFS(result, sample, deep+1, n, left+1, right);
		sample.resize(sample.size() - 1);
	}
	if(right < left){
		sample.push_back(')');
		DFS(result, sample, deep+1, n, left, right+1);
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  generateParetheses
 *  Description:  using dfs thought, when ( appears less then n, add (, when ) appears less
 *                then (, add ) 
 * =====================================================================================
 */
vector<string>
generateParetheses (int n )
{
	vector<string> result;
	string sample;
	DFS(result, sample, 0, n, 0,0);
	return result;
}		/* -----  end of function generateParetheses  ----- */
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
