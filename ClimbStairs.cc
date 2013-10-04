/*
 * =====================================================================================
 *
 *       Filename:  ClimbStairs.cc
 *
 *    Description:  You are climbing a stair case. It takes n steps to reach top
 *                  Each time you can either climb 1 or 2 steps. In how many ways you can
 *                  climb
 *        Version:  1.0
 *        Created:  03/17/13 18:07:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#define	MAX 10000			/*DP array size */
int dp[MAX] = {0};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  climbStairs
 *  Description: Using DP way to solve but not recursive way  
 * =====================================================================================
 */
int 
climbStairs (int n )
{
	if(n == 0){
		return 0;
	}else if(n == 1){
		dp[1] = 1;
		return 1;
	}else if(n == 2){
		dp[2] = 2;
		return 2;
	}else{
        if(dp[n - 1] != 0 && dp[n - 2] != 0){
			dp[n] = dp[n - 1] + dp[n- 2];
			return dp[n];
		}else if(dp[n - 1] != 0 && dp[n - 2] == 0){
			return dp[n - 1] + climbStairs(n - 2);
		}else if(dp[n - 1] == 0 && dp[n - 2] != 0){
			return climbStairs(n - 1) + dp[n - 2];
		}else{
			return climbStairs(n - 1) + climbStairs(n - 2);
		}
	}
}		
/* -----  end of function climbStairs  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  climbStairsII
 *  Description:  Using DP function fn = fn_1 + fn_2 
 * =====================================================================================
 */
int climbStairs
climbStairsII (int n)
{
	int fn, fn_1 = 2, fn_2 = 1;
	if(n == 1) return fn_2;
	if(n == 2) return fn_1;
	for(int i = 3; i<=n i++){
		fn = fn_1+fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}		/* -----  end of function climbStairsII  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	printf("%d\n", climbStairs(38));
	return EXIT_SUCCESS;
}				
/* ----------  end of function main  ---------- */

