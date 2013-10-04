/*
 * =====================================================================================
 *
 *       Filename:  ContainerWithMostWater.cc
 *
 *    Description:  LeetCode Container With Most Water
 *        Version:  1.0
 *        Created:  04/13/13 23:38:50
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
 *         Name:  maxArea
 *  Description:  Two Pointers , for any container, its volume depends on the shortest
 *				  board. Always move with shorter board index
 * =====================================================================================
 */
int
maxArea (vector<int> &height)
{
	int maxV = INT_MIN;
	int start = 0;
	int end = height.size()- 1;
	int minV;
	while(start < end){
		minV = min(height[start], height[end])*(end - start);
		if(height[start] <= height[end]){
			start++;
		}else{
			end--;
		}
	}
	return maxV;
}		
/* -----  end of function maxArea  ----- */
