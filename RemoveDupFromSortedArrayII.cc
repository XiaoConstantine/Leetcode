/*
 * =====================================================================================
 *
 *       Filename:  RemoveDupFromSortedArrayII.cc
 *
 *    Description:  LeetCode Remove Duplicates From Sorted Array
 *        Version:  1.0
 *        Created:  04/01/13 18:44:27
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
 *  Description:  Two Pointers with a variable to track occurences  
 * =====================================================================================
 */
int
removeDup (int A[], int n)
{
	int pre = 1, cur = 1;
	if(n < 1) return 0;
    int occur = 1;
	while(cur < n){
		if(A[cur] == A[cur - 1]){
			if(occur >= 2){
				cur++;
				continue;
			}else{
				occur++;
			}
		}else{
			occur = 1;
		}
		A[pre] = A[cur];
		pre++;
		cur++;
	}

	return pre;
}		/* -----  end of function removeDup  ----- */
