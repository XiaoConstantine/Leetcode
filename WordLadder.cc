/*
 * =====================================================================================
 *
 *       Filename:  WorldLadder.cc
 *
 *    Description:  Given two words and a dict, find the length of shortest	transform sequence
 *                  from one to another
 *                  e.g.: start = "hit" end = "cog" dict = ["hot", "dot", "dog", "log", "lot"]
 *                  shortest transform is : hit->hot->dot->dog->cog
 *                  Only one letter can change at a time
 *
 *        Version:  1.0
 *        Created:  03/17/13 16:53:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string>
#include <set>
#include <queue>
#include "/Users/Constantine/interviewPractice/UnitTest++/src/UnitTest++.h"
using namespace std;
using namespace UnitTest;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ladderLength
 *  Description:  Using BFS in the dict   
 * =====================================================================================
 */
	int
ladderLength (string start, string end, set<string> &dict)
{
    int count = 1;
	queue<string> q_Push, q_Pop;
	q_Pop.push(start);

	while(dict.size() > 0  && !q_Pop.empty()){
		while(!q_Pop.empty()){
			string str(q_Pop.front());
			q_Pop.pop();
			for(int i = 0; i < str.length(); i++){
				for(char j = 'a'; j < 'z'; j++){
					if(str[i] == j)
						continue;
					else{
						char temp = str[i];
						str[i] = j;
						if(str == end)
							return count+1;
						if(dict.count(str) > 0){
							q_Push.push(str);
							dict.erase(str);
						}
						str[i] = temp;
					}
				}
			}
		}
  	    swap(q_Push, q_Pop);
		count++;
	}

	return 0;
}	/* -----  end of function ladderLength  ----- */


TEST(EmptyDict){
	set<string> dict;
	CHECK_EQUAL(0, ladderLength("hit", "dog", dict));
}
TEST(NormalCase){
	set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	CHECK_EQUAL(3, ladderLength("hot", "cog", dict));
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	set<string> dict;
	
	return RunAllTests();
//	dict.insert("hot");
//	dict.insert("dog");
//	printf("%d\n", ladderLength("hot", "dog", dict));
	//return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

