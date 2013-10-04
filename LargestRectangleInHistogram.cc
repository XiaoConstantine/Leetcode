/*
 * =====================================================================================
 *
 *       Filename:  LargestRectangleInHistogram.cc
 *
 *    Description:  LeetCode Largest Rectangle In Histogram
 *        Version:  1.0
 *        Created:  04/01/13 17:01:26
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
 *         Name:  largestRectangleArea
 *  Description:  DP way: take end sum and rect length as f(p,l), area = l*f(p,l)
 *                f(P,L) = L not = 1: min(f(p-1, l-1), height[p]);
 *                            1: height[p];
 *                COMPRESS p TO O(n) space complexity
 *                O(n*n)
 * =====================================================================================
 */
int
largestRectangleArea (vector<int> &height)
{
	vector<int> dp(height.size()+1, 0);
	dp[0] = INT_MAX;
	int amax = 0;
	for(int i = 0; i < height.size(); i++){
		for(int l = i+1; l>0; l--){
			dp[l] = min(dp[l-1], height[i]);
			amax = max(amax, dp[l]*l);
		}
	}
	return amax;
}		
// Cant pass large set time limit exceed
/* -----  end of function largestRectangleArea  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  largestRectangleAreaII
 *  Description:  Recursive way with delete overlap calculation
 *                Only check left side with specific right height value(i.e. if a new
 *                height value is less then previous one, we pass through left)
 *                O(n*n)
 * =====================================================================================
 */
int
largestRectangleAreaII (vector<int> &height)
{
	int maxV = 0;
	int start = 0;
	int end = height.size();
	while(start < height.size()){
		end = height.size()-1;
		for(int i = start+1; i<=end; i++){
			if(height[i] < height[k-1]){
				end = k-1;
				break;
			}
		}
		int minV = height[end];
		for(int j = end; j>=0; j--){
			minV = min(minV, height[j]);
			maxV = max(minV*(end-j+1), maxV);
		}
		start = end+1;
	}
	return maxV;
}		
/* -----  end of function largestRectangleAreaII  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  largestRectangleAreaIII
 *  Description:  O(n) way  
 * =====================================================================================
 */
int
largestRectangleAreaIII (vector<int> &height )
{
	int stack[height.size()+1], width[height.size()+1];
	if(height.size() == 0) return 0;
	int top = 0, area = INT_MIN;
	stack[0] = 0, width[0] = 0;
	int newHeight;
	for(int i = 0; i <= height.size(); i++){
		if(i < height.size()){
			newHeight = height[i];
		}else{
			newHeight = -1;
		}
		if(newHeight >= stack[top]){
			stack[++top] = newHeight;
			width[top] = 1;
		}else{
			int minV = INT_MAX;
			int wid = 0;
			while(stack[top] > newHeight){
				minV = min(minV, stack[top]);
				wid += width[top];
				area = max(area, minV*wid);
				top--;
			}
			stack[++top] = newHeight;
			width[top] = wid+1;
		}
	}
	return area;
}		/* -----  end of function largestRectangleAreaIII  ----- */
