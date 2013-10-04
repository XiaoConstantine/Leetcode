/*
 * =====================================================================================
 *
 *       Filename:  MinimumWindowString.cc
 *
 *    Description:  Leetcode: Minimus Window Substring. Given a String s and t like
 *                  s = "ADOBECODEBANC" t = "ABC" the minimum window string should
 *                  be "BANC"
 *
 *        Version:  1.0
 *        Created:  03/16/13 23:19:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string>
using namespace std;

string minWindow(string s, string t){
	int table_t[256] = {0};
	int table_s[256] = {0};

	for(int i = 0; i < t.length(); i++){
		table_t[t[i]]++;
	}
	int minL = INT_MAX;
	int start = 0;
	int count = 0; //check if in s find all char in t
	for(int begin = 0, end = 0; end < s.length(); end++){
		if(table_t[s[end]] == 0)
			continue;
		table_s[s[end]]++;
		if(table_s[s[end]] <= table_t[s[end]])
			count++;

		if(count == t.length()){
			while(table_t[s[begin]] == 0 || table_s[s[begin]] > table_t[s[begin]]){
				table_s[s[begin]]--;
				begin++;
			}
        	if(minL >= end - begin +1){
			minL = end - begin + 1;
			start = begin;
		}
	  }
	}
	if(minL == INT_MAX) return "";
	return s.substr(start, minL);
}


int main(){
    string s = "of_characters_and_as";
	string t = "aas";
	printf("%s\n", minWindow(s,t).c_str());

	return 0;
}
