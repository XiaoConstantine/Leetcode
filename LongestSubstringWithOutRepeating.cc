/*
 * =====================================================================================
 *
 *       Filename:  LongestSubstringWithOutRepeating.cc
 *
 *    Description:  LeetCode Longest Substring Without Repeating Character
 *        Version:  1.0
 *        Created:  04/15/13 16:35:06
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
 *         Name:  ls
 *  Description:  dp way dp[i] = dp[i-1] + 1 if(s[i] != s[j])
 *						else dp[i] = i-j
 * =====================================================================================
 */
int 
ls (string s)
{
	int n = s.length();
	if(n == 0 || n == 1) return n;
	int l[n];
	l[0] = 1;
	int max = 0;
	int last_start = 0;
	for(int i = 1; i< n; i++){
		for(int j = i - 1; j >= last_start; j++){
			if(s[i] == s[j]){
				l[i] = i - j;
				last_start = j+1;
				break;
			}else if(j == last_start){
				l[i] = l[i-1] + 1;
			}
		}
		if(max < l[i]){
			max = l[i];
		}
	}

	return max;
}		/* -----  end of function ls  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lengthOfLongestSubstring
 *  Description:  Two pointer method  
 * =====================================================================================
 */
int
lengthOfLongestSubstring (string s )
{
	int n = s.length();
	int maxLen = 0;
	int i = 0, j = 0;
	bool exist[256] = {false};

	while(j < n){
		if(exist[s[j]]){
			maxLen = max(maxLen, j-i);
			while(s[j] != s[i]){
				exist[s[i]] = false;
				i++;
			}
			i++;
			j++;
		}else{
			exist[s[j]] = true;
			j++;
		}
	}
	maxLen = max(maxLen, n-i);
	return maxLen;
}		/* -----  end of function lengthOfLongestSubstring  ----- */
