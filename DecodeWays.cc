/*
 * =====================================================================================
 *
 *       Filename:  DecodeWays.cc
 *
 *    Description:  LeetCode Decode Ways
 *        Version:  1.0
 *        Created:  03/24/13 16:14:37
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
 *         Name:  check
 *  Description:  
 * =====================================================================================
 */
int
check (char a)
{
	return (a!='0')?1:0;
}		
/* -----  end of function check  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  check
 *  Description:  
 * =====================================================================================
 */
int
check (char a, char b)
{
	return (a == '1'||( a == '2' && b <= '6'))?1:0;
}		/* -----  end of function check  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  numDecodings
 *  Description:  DP  count[i] = count[i-1] if(S[i-1] is valid)
 *                or  count[i] = count[i-1] + count[i-2] if S[i-1]and S[i-2] is valid
 * =====================================================================================
 */
int
numDecodings (string s)
{
	if(s.empty() || s[0] == '0') return 0;
	if(s.size() == 1) return check(s[0]);
	int fn = 0, fn_1 = 0, fn_2 = 1;
    fn_1 = (check(s[0])*check(s[1])) + check(s[0], check[1]);

	for(int i = 2; i < s.size(); i++){
		if(check(s[i])) fn += fn_1;
		if(check(s[i-1], s[i])) fn += fn_2;
		if(fn == 0){
			return 0;
		}
		fn_2 = fn_1;
		fn_1 = fn;
		fn = 0;
	}

	return fn_1;
}		
/* -----  end of function numDecodings  ----- */
