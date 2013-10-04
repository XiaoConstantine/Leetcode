/*
 * =====================================================================================
 *
 *       Filename:  UniqueBinarySearchTree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/13 16:25:56
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
 *         Name:  numTrees
 *  Description:  dp count[i] = Sum(count[0,k]*count[k+1,i])
 * =====================================================================================
 */
int
numTrees (int n)
{
	int count[n+1];
	count[0] = 1;
	count[1] = 1;
	for(int i = 2; i<=n; i++){
		count[i] = 0;
	}

	for(int i = 2; i<=n; i++){
		for(int j = 0; j < i; j++){
			count[i] += count[j]*count[i-j-1];
		}
	}
	return count[n];
}		/* -----  end of function numTrees  ----- */
