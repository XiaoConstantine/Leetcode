/*
 * =====================================================================================
 *
 *       Filename:  ScrambleString.cc
 *
 *    Description:  LeetCode Scramble String
 *        Version:  1.0
 *        Created:  03/31/13 18:03:56
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
 *         Name:  isScramble
 *  Description:  Recursive
 * =====================================================================================
 */
bool
isScramble (string s1, string s2)
{
	if(s1.size() != s2.size()) return false;
	int a[26];
	int len = s1.size();

	for(int i = 0; i < len; i++){
		a[s1[i] - 'a']++;
	}

	for(int i = 0; i < len; i++){
		a[s2[i] - 'a']++;
	}

	for(int i = 0; i< 26; i++){
		if(a[i] != 0){
			return false;
		}
	}

	for(int i = 1; i< len; i++){
		bool result = isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i, len-i), s2.substr(i, len-i));
		result = result||(isScramble(s1.substr(0,i), s2.substr(len-i, i))&& isScramble(s1.substr(i, len-i), s2.substr(0,len-i)));
		if(result) return true;
	}
	return false;
}		/* -----  end of function isScramble  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  isScramble
 *  Description:  DP way
 * =====================================================================================
 */
bool
isScramble (string s1, string s2)
{
	if(s1.length() != s2.length()) return false;
	int n = s1.length();
	bool dp[n][n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[0][i][j] = s1[i] == s2[j];
		}
	}
	for(int l = 1; l < n; l++){
		for(int i = 0; i + l < n; i++){
			for(int j = 0; j + l < n; j++){
				dp[l][i][j] = false;
				for(int k = 0; k < l; k++){
					if( (dp[k][i][j] && dp[l-k-1][i+k+1][j+k+1])|| (dp[k][i][j+l-k] && dp[l-k-1][i+k+1][j])){
						dp[l][i][j] = true;
						break;
					}
				}
			}
		}
	}


	return dp[n-1][0][0];
}		/* -----  end of function isScramble  ----- */
