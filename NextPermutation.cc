/*
 * =====================================================================================
 *
 *       Filename:  NextPermutation.cc
 *
 *    Description:  LeetCode Next Permutation
 *
 *        Version:  1.0
 *        Created:  04/11/13 12:02:11
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
 *         Name:  nextPermutation
 *  Description:  
 * =====================================================================================
 */
void
nextPermutation (vector<int>& num)
{
	int vioIndex = num.size()-1;
	while(vioIndex > 0){
		if(num[vioIndex-1] < num[vioIndex]){
			break;
		}
		vioIndex--
	}

	if(vioIndex > 0){
		vioIndex--;
		int rightIndex = num.size()-1;
		while(rightIndex >= 0 && num[rightIndex] <= num[vioIndex]){
			rightIndex--;
		}
		swap(num[vioIndex++], num[rightIndex]);
	}
	int end = num.size()-1;
	while(end > vioIndex){
		swap(num[vioIndex++], num[end--]);
	}
}		/* -----  end of function nextPermutation  ----- */

