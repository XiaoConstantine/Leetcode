/*
 * =====================================================================================
 *
 *       Filename:  UniquePaths.cc
 *
 *    Description:  LeetCode Unique Paths
 *        Version:  1.0
 *        Created:  03/25/13 15:32:44
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
 *         Name:  uniquePathsII
 *  Description:  Two Dimension DP
 * =====================================================================================
 */
int
uniquePathsII (int m , int n )
{
	int max[m][n];
	for(int i = 0; i < m; i++){
		max[i][0] = 1;
	}

	for(int i = 0; i < n; i++){
		max[0][i] = 1;
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j<n; j++){
			max[i][j] = max[i-1][j] + max[i][j-1];
		}
	}
	return max[m-1][n-1];
}		/* -----  end of function uniquePathsII  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uniquePaths
 *  Description:  
 * =====================================================================================
 */
int
uniquePaths (int m, int n)
{
	int* max = new int[n];
	for(int i = 1; i < n; i++){
		max[i] = 0;
	}
	max[0] = 1;
	for(int i = 0; i < m; i++){
		for(int j = 1; j < n; j++){
			max[j] = max[j-1] + max[j];
		}
	}
	return max[n-1];
}		/* -----  end of function uniquePaths  ----- */
