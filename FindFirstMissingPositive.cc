/*
 * =====================================================================================
 *
 *       Filename:  FindFirstMissingPositive.cc
 *
 *    Description:  LeetCode Find First Missing Positive
 *        Version:  1.0
 *        Created:  04/08/13 15:51:10
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
 *         Name:  findFirstMissingPositive
 *  Description:  Bucket sort 
 * =====================================================================================
 */
int
findFirstMissingPositive (int A[], int n)
{
	for(int i = 0; i < n; i++){
		while(A[i] != i + 1){
			if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])break;
			int temp = A[i];
			A[i] = A[temp - 1];
			A[temp - 1] = temp;
		}
	}

	for(int i = 0; i < n; i++){
		if(A[i] != i + 1){
			return i+1;
		}
	}
	return n+1;
}		
/* -----  end of function findFirstMissingPositive  ----- */

