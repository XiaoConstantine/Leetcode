/*
 * =====================================================================================
 *
 *       Filename:  EditDistance.cc
 *
 *    Description:  LeetCode Edit Distance
 *        Version:  1.0
 *        Created:  03/25/13 18:44:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  minDistance_recursive
 *  Description:  
 * =====================================================================================
 */
int
minDistance_recursive (string word1, string word2)
{
	if(word1.size() == 0) return word2.size();
	if(word2.size() == 0) return word1.size();

	if(word1[0] == word2[0]){
		return minDistance_recursive(word1.substr(1), word2.substr(1));
	}else{
		return min(minDistance_recursive(word1.substr(1), word2), min(minDistance_recursive(word1, word2.substr(1)), minDistance_recursive(word1.substr(1), word2.substr(1)))) + 1;
	}
}		
/* -----  end of function minDistance_recursive  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  minDistance
 *  Description:  DP formula: if(word[i] == word[j]) dp[i][j] = dp[i-1][j-1]
 *							  else dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))
 *							  we should have dp[][] sizeof word1.size()+1* word2.size()+1
 * =====================================================================================
 */
int
minDistance(string word1, string word2)
{
	int m = word1.size();
	int n = word2.size();
	if(m ==0) return n;
	if(n == 0) return m;

	int dis[m+1][n+1];
	dis[0][0] = 0;
	for(int i = 1; i<=m; i++){
		dis[i][0] = i;
	}
	for(int i = 1; i<=n; i++){
		dis[0][i] = i; 
	}

	for(int i = 1; i<=m; i++){
		for(int j = 1; j<=n; j++){
			if(word1[i-1] == word2[j-1]){
				dis[i][j] = dis[i-1][j-1];
			}else if(i-2>= 0 && j-2 >= 0 &&word1[i-2] == word2[j-1] && word1[i-1] == word2[j - 2]){
                printf("---------"); 
				//dis[i+1][j+1] = dis[i-1][j-1] + 1;
				 dis[i][j] = dis[i-2][j-2] + 1;
			}else{
				dis[i][j] = 1 + min(dis[i-1][j-1], min(dis[i-1][j], dis[i][j-1]));
			}
		}
	}

	for(int i = 0; i <m; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
	return dis[m][n];
}	
/* -----  end of function minDistance  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	string word1 = "ogogle";
	
	string word2 = "gogol";
	printf("%d\n", minDistance(word1, word2));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
