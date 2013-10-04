/*
 * =====================================================================================
 *
 *       Filename:  LongestValidParentheies.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/20/13 16:00:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lvp(string s){
	const char* str = s.c_str();
	int nM = 0;
	const char* p = str;
	vector<const char* >sta;
	while(*p != '\0'){
		if(*p == '('){
			sta.push_back(p);
			cout<< sta.back() << endl;
		}else{
			if(!sta.empty() && *sta.back() == '('){
				sta.pop_back();
				//nM = std::max(nM, p-(sta.empty()?str-1:sta.back()));
				if(sta.empty()){
					if(nM < p- (str-1)){
						nM = p - (str-1);
					}else{
						nM = p - sta.back();
					}
				}
				cout << nM << endl;
			}else{
				sta.push_back(p);
			}
		}
		p++;
	}
	return nM;
}

int main(){
	string s = ")()())";
	const char* s1 = "()())";
	const char* s2 = ")()())";
	cout << s1-(s2-1)<< endl;
	lvp(s);
	return 0;
}
