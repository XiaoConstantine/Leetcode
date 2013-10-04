/*
 * =====================================================================================
 *
 *       Filename:  JumpGame.cc
 *
 *    Description:  LeetCode Jump Game
 *        Version:  1.0
 *        Created:  04/06/13 18:57:20
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
 *         Name:  canJump
 *  Description:  one dimension dp, dp[i] means means from 0-i, last max steps
 *				  dp[i] = max(dp[i-1], A[i-1])- 1 i!=0
 *						= 0 i =0
 * =====================================================================================
 */
bool
canJump (int A[], int n)
{
	vector<int> dp(n);
	dp[0] = 0;
	for(int i = 1; i< n; i++){
		dp[i] = max(dp[i-1], A[i-1])-1;
		if(dp[i] < 0){
			return false;
		}
	}
	return dp[n-1] >= 0;
}		/* -----  end of function canJump  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  canJumpII
 *  Description:  one round dp without track status  
 * =====================================================================================
 */
bool
canJumpII (int A[], int n)
{
	int max = 0;
	for(int start = 0; start<=max && start < n; start++){
		if(A[start] + start > max){
			max = A[start] + start;
		}
		if(max >= n-1){
			return true;
		}
	}
	return false;
}		/* -----  end of function canJumpII  ----- */
