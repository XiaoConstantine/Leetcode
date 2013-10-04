/*
 * =====================================================================================
 *
 *       Filename:  MultiplyString.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/15/13 15:03:08
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
 *         Name:  multiply
 *  Description:  
 * =====================================================================================
 */
string
multiply (string s1, string s2)
{
	if(s1.empty() || s2.empty()) return 0;
	int n1 = s1.size();
	int n2 = s2.size();
	string result(n1+n2+1, '0');
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());

	for(int i = 0; i < n1; i++){
		int d1 = s1[i] - '0';
		int carry = 0;
		for(int j = 0; j < n2; j++){
			int d2 = s2[j] - '0';
			int d3 = result[i+j] - '0';
			result[i+j] = (d1*d2 + carry + d3)%10;
			carry = (d1*d2 + carry + d3)/10;
		}
		if(carry > 0){
			result[i + n2] = carry + '0';
		}
	}
	std::reverse(result.begin(), result.end());
	int start = 0;
	while(start < result.size() && result[start] == '0'){
		start++;
	}
	if(start == result.size()) return "0";
	else return result.substr(start, result.size() - start);

}		/* -----  end of function multiply  ----- */
