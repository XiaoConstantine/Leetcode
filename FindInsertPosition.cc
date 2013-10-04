/*
 * =====================================================================================
 *
 *       Filename:  FindInsertPosition.cc
 *
 *    Description:  LeetCode Find Insert Position
 *        Version:  1.0
 *        Created:  04/10/13 17:30:22
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
 *         Name:  searchInsert
 *  Description:  
 * =====================================================================================
 */
int
searchInsert (int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;
	while(l <= r){
		int mid = l+r/2;
		if(A[mid] == target) return mid;
		if(mid > l && A[mid] < target && A[mid-1] > target) return mid;
		if(A[mid] > target){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return l;
}		/* -----  end of function searchInsert  ----- */
