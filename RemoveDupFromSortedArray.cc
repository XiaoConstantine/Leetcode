/*
 * =====================================================================================
 *
 *       Filename:  RemoveDupFromSortedArray.cc
 *
 *    Description:  LeetCode Remove Dup from Sorted Array
 *        Version:  1.0
 *        Created:  03/25/13 01:26:14
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
 *         Name:  removeDup
 *  Description:  Two pointer
 * =====================================================================================
 */
int
removeDup (int A[], int n)
{
	if(n == 0) return A[0];

	int count = 0;
	for(int i = 0; i < n; i++){
		if(A[count] == A[i]){
			continue;
		}
		count++;
		A[count] = A[i];
	}
	return count+1;
}		/* -----  end of function removeDup  ----- */
