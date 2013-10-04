/*
 * =====================================================================================
 *
 *       Filename:  UniquePathsII.cc
 *
 *    Description:  LeetCode Unique Paths II
 *        Version:  1.0
 *        Created:  03/25/13 15:55:25
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
 *         Name:  uniquePathWithObstacle
 *  Description:  DP formula max[i][j] = max[i][j-1] + max[i-1][j] simple as one dimesion
 *				  cause from a new row max[j] = max[i - 1][j]
 * =====================================================================================
 */
int
uniquePathWithObstacle (vector<vector<int> >& obstacles)
{
	int m = obstacles.size();
	int n = obstacles[0].size();
	if(obstacles[0][0] == 1)return 0;
	int *max = new int[n];
	for(int i = 1; i < 0; i++){
		max[i] = 0;
	}
	max[0] = 1;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(obstacles[i][j] == 1){
				max[j] = 0;
			}else if(j > 0){
				max[j] = max[j - 1] + max[j];
			}
		}
	}
	return max[n-1];
}		/* -----  end of function uniquePathWithObstacle  ----- */
