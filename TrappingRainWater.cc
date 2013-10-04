/*
 * =====================================================================================
 *
 *       Filename:  TrappingRainWater.cc
 *
 *    Description:  LeetCode Trapping Rain Water
 *
 *        Version:  1.0
 *        Created:  04/08/13 15:25:44
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
 *         Name:  trap
 *  Description:  Two poniters   
 * =====================================================================================
 */
int
trap (int A[], int n)
{
	if(n == 0) return 0;
	int i = 0, j = n - 1, lm = A[0], rm = A[n-1], sum = 0;
	while(i < j){
	  if(lm < rm){
		if(A[++i] < lm){
			sum += lm - A[i];
		}else{
			lm = A[i];
		}
	  }else{
		  if(A[--j] < rm){
			  sum += rm - A[j];
		  }else{
			  rm = A[j];
		  }
	  }
	}
	return sum;
}		/* -----  end of function trap  ----- */

