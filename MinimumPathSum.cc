/*
 * =====================================================================================
 *
 *       Filename:  MinimumPathSum.cc
 *
 *    Description:  LeetCode Minimum Path Sum
 *        Version:  1.0
 *        Created:  03/25/13 17:29:41
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
 *         Name:  minPathSum
 *  Description:  DP (two dimension)
 * =====================================================================================
 */
int
minPathSum (vector<vector<int> >&grid)
{
	int m = grid.size();
	int n = grid[0].size();

	int min[m][n];
	min[0][0] = grid[0][0];
	for(int i = 1; i<m; i++){
		min[i][0] = min[i-1][0] + grid[i][0];
	}
	for(int j = 1; j<n; j++){
		min[0][j] = min[0][j-1] + grid[0][j];
	}

	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			min[i][j] = min[i-1][j] < min[i][j-1]?min[i-1][j]:min[i][j-1];
			min[i][j] += grid[i][j];
		}
	}
	return min[m-1][n-1];
}		

/* -----  end of function minPathSum  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  minPathSumII
 *  Description:  DP(one dimension) with rolling array
 * =====================================================================================
 */
int
minPathSumII (vector<vector<int> > &grid)
{
	int m = grid.size();
	int n = grid[0].size();
	int min[n];
	min[0] = 0;
	for(int i = 1; i< n; i++){
		min[i] = INT_MAX;
	}
	for(int i = 0; i<m; i++){
		min[0] = min[0] + grid[i][0];
		for(int j = 1; j<n; j++){
			min[j] = min[j]< min[j-1]?min[j]:min[j-1];
			min[j] += grid[i][j];
		}
	}
	return min[n-1];
}		/* -----  end of function minPathSumII  ----- */
