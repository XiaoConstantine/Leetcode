/*
 * =====================================================================================
 *
 *       Filename:  PartitionPalindromeII.cc
 *
 *    Description:  LeetCode Partition Palindrome II
 *        Version:  1.0
 *        Created:  03/28/13 17:46:51
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
 *         Name:  isPalindorme
 *  Description:  
 * =====================================================================================
 */
bool
isPalindorme (string s, int start, int end)
{
	while(start < end){
		if(s[start] == s[end]){
			start++;
			end--;
		}else{
			return false;
		}
	}
	return true;
}		/* -----  end of function isPalindorme  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  Recursive way  
 * =====================================================================================
 */
void
DFS (string s, int start, int dep, int& min)
{
	if(start == s.size()){
		if(min > dep - 1){
			min = dep - 1;
		}
		return;
	}

	for(int i = s.size()-1; i>=start; i--){
		if(isPalindrome(s, start, i)){
			DFS(s, start+1, dep+1, min);
		}
		if(min != INT_MAX){
			break;
		}
	}
}		/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  minCut
 *  Description:  
 * =====================================================================================
 */
int
minCut (string s)
{
	int min  = INT_MAX;
	DFS(s,0,0,min);
	return min;
}		/* -----  end of function minCut  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  minCutDP
 *  Description:  using two dp: 1. dp for [1-n] min cut
 *                                 formula dp[i, n] = min(dp[i,j], dp[j+1, n])
 *                                 > to 1 dimen dp[i] = dp[j+1] + 1 if(s[i,j] is palin, j from i->n)
 *                              2. dp for palindrome
 *                                 
 * =====================================================================================
 */
int
minCutDP (string s)
{
	int len = s.size();
	int dp[len+1];
	bool isPalindrome[len][len];
    
	for(int i = 0; i<=len; i++){
		dp[i] = len-i; //worst case every charac is a palin
	}
	for(int i = 0; i < len; i++){
		for(int j = 0; j< len; j++){
			isPalindrome[i][j] = false;
		}
	}

	for(int i = len-1; i>=0; i++){
		for(int j = i; j < len; j++){
			if(s[i] == s[j] && (j-i < 2 || isPalindrome[i+1][j-1] == true)){
				dp[i] = min(dp[i], dp[j+1] + 1);
				isPalindrome[i][j] = true;
			}
		}
	}

	return dp[0] - 1;
}		/* -----  end of function minCutDP  ----- */
