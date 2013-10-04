/*
 * =====================================================================================
 *
 *       Filename:  CountAndSay.cc
 *
 *    Description:  LeetCode Count and Say
 *        Version:  1.0
 *        Created:  04/14/13 00:31:36
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
 *         Name:  countAndSay
 *  Description:  
 * =====================================================================================
 */
string
countAndSay (int n)
{
	string seq = "1";
	int it = 1;
	while(it < n){
		stringstream newSeq;
		char last = seq[0];
		int count = 0;
		for(int i = 0; i <= seq.size(); i++){
			if(seq[i] == last){
				count++;
				continue;
			}else{
				newSeq<<count<<last;
				last = seq[i];
				count = 1;
			}
		}
		seq = newSeq.str();
		it++;
	}
	return seq;
}		/* -----  end of function countAndSay  ----- */

