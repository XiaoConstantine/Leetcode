/*
 * =====================================================================================
 *
 *       Filename:  3SumCloset.cc
 *
 *    Description:  LeetCode 3Sum Closet
 *        Version:  1.0
 *        Created:  04/15/13 17:44:59
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
 *         Name:  threeSumClosest
 *  Description:  
 * =====================================================================================
 */
int
threeSumClosest (vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	int minV = INT_MAX, record;
	int len = num.size();

	for(int i = 0; i < len; i++){
		int start = i+1, end = len-1;
		while(start < end){
			int sum = num[i] + num[start] + num[end];
			if(sum == target){
				minV = 0;
				record = target;
				break;
			}
			if(sum < target){
				if(target - sum < minV){
					minV = target-sum;
					record = sum;
				}
				start++;
			}else{
				if(sum - target < minV){
					minV = sum - target;
					record = sum;
				}
				end--;
			}
		}
		while(i < len - 1 && num[i] == num[i+1]) i++;
	}
	return record;
}		/* -----  end of function threeSumClosest  ----- */
