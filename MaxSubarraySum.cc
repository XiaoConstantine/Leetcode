/*
 * =====================================================================================
 *
 *       Filename:  MaxSubarraySum.cc
 *
 *    Description:  Find the contiguous subarray within an array(containing at least one
 *                  number) which has the largest sum  
 *
 *        Version:  1.0
 *        Created:  03/20/13 21:43:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include <stdio.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  maxSubArray
 *  Description:  
 * =====================================================================================
 */
int
maxSubArray (int A[], int n )
{
	int max = -1000;
	int sum = 0;
	for(int i = 0; i< n; i++){
		sum += A[i];
		max = max > sum?max:sum;
		sum = sum > 0? sum:0;
	}
	return max;
}		/* -----  end of function maxSubArray  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int A[] = {31,-41,59,26,-53,58,97,-93,-23,84};
	printf("%d\n", maxSubArray(A, 10));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
