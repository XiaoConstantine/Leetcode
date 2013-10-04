/*
 * =====================================================================================
 *
 *       Filename:  RemoveElement.cc
 *
 *    Description:  LeetCode Remove Element 
 *        Version:  1.0
 *        Created:  03/23/13 19:40:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  removeElement
 *  Description:  Two pointer (notice not only linkedlist can use this method)  
 * =====================================================================================
 */
int
removeElement (int A[], int n, int elem)
{
	int count = 0;
	for(int i = 0, j = n - 1; i<=j){
		if(A[i] == elem){
			if(A[j] != elem){
				A[i] = A[j];
				i++;
				j--;
			}else{
				j--;
			}
			count++;
		}else{
			i++;
		}
	}
	return (n-count);
}		/* -----  end of function removeElement  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
