/*

 * =====================================================================================
 *
 *       Filename:  palindrome.cc
 *
 *    Description:  
*
 *        Version:  1.0
 *        Created:  03/16/13 16:09:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string helper(string s, int l, int r){
	int i = l;
	int j = r;
	while(i>= 0 && j < s.length() && s[i] == s[j]){
			i--;
			j++;
	}
	return s.substr(i+1, j-i-1);
}

string longestPalindrome(string s){
	if(s.length() == 0) return "";
	string longest = s.substr(0,1);

	/* here we loop 2n-1 times but not n times
	 * Because the center of palindrome may like "ab ba" 
	 * and like "abcba" so we need another n time to loop the
	 * empty center
	 * */
	for(int i = 0; i < s.length() - 1; i++){
	   string p1 = helper(s, i, i);
	   if(p1.length() > longest.length())
		   longest = p1;
	   string p2 = helper(s, i, i+1);
	   if(p2.length() > longest.length())
		   longest = p2;
	}
	return longest;
}
/*Solution to LeetCode: Valid Palindrome */
bool isPalindrome(string s){
	bool flag = false;
	string result = "";
	for(int i = 0; i < s.length(); i++){
		if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            // printf("s[i]:%c\n", s[i]);
		    result += s[i];
		}
	    else{
			//s.erase(s[i]);
	       // printf("erase :%s\n", s);
		}
	}
	if(result.empty() || result.length() == 1){
		flag = true;
	}else{
        int i = 0;
		int j = result.length() - 1;
		while(i <= j){
			if(result[i] == result[j] || result[i] - 32 == result[j] || result[j] - 32 == result[i]){
				flag = true;
				i++;
				j--;
			}else{
				flag = false;
				break;
			}
		}

	}
	return flag;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DFS
 *  Description:  
 * =====================================================================================
 */
void
DFS (string &s,int l, vector<string>&temp, vector<vector<string> >&result )
{
	if(l == s.size()){
		result.push_back(temp);
		return;
	}else{
		for(int i = l; i < s.size(); i++){
			if(isPalindrome(s, l,i)){
				temp.push_back(s.substr(l,i-l+1));
				DFS(s, i+1, temp,result);
				temp.pop_back();
			}
		}
	}
}		
/* -----  end of function DFS  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	string s = ".,";
	printf("%d", isPalindrome(s));
	return EXIT_SUCCESS;
}				
/* ----------  end of function main  ---------- */
