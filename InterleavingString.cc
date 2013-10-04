/*
 * =====================================================================================
 *
 *       Filename:  InterleavingString.cc
 *
 *    Description:  LeetCode Interleaving String
 *        Version:  1.0
 *        Created:  03/31/13 15:49:25
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
 *         Name:  isInterleavingString
 *  Description:  DP match[i][j] =    s3.last == s1.last && match[i-1][j]
 *                                 || s3.last == s2.last && match[i][j-1]
 *
 * =====================================================================================
 */
bool
isInterleavingString (string s1, string s2, string s3)
{
	int l1 = s1.size();
	int l2 = s2.size();
	int l3 = s3.size();
	if(l3 != l1 + l2) return false;

	vector<vector<bool> > match(l1+1, vector<bool>(l2+1, false));
	match[0][0] = true;
	for(int i = 1; i <= l1; i++){
		char c1 = s1[i-1];
		char c3 = s3[i-1];
		if(c1 == c3){
			match[i][0] = true;
		}
	}

	for(int i = 1; i<=l2; i++){
		char c2 = s2[i-1];
		char c3 = s3[i-1];
		if(c2 == c3){
			match[0][i] = true;
		}
	}

    for(int i = 1; i <= l1; i++){
		char c1 = s1[i-1];
		for(int j = 1; j<=l2; j++){
			char c2 = s2[i-1];
			char c3 = s3[i+j-1];
			if(c1 == c3){
				match[i][j] = match[i-1][j] || match[i][j];
			}
			if(c2 == c3){
				match[i][j] = match[i][j-1]||match[i][j];
			}
		}
	}

	return match[l1][l2];
}		/* -----  end of function isInterleavingString  ----- */
