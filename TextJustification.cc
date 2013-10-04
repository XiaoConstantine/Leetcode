/*
 * =====================================================================================
 *
 *       Filename:  TextJustification.cc
 *
 *    Description:  LeetCode Text Justification
 *        Version:  1.0
 *        Created:  04/06/13 17:13:30
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
 *         Name:  fullJustify
 *  Description:  
 * =====================================================================================
 */
vector<string>
fullJustify (vector<string> &words, int L)
{
	vector<string> result;
	int i = 0;
	if(words.size() == 0) return result;
	while(i < words.size()){
		int start = i;
		int sum = 0;
		while(sum <= L && i < words.size()){
			sum += words[i].size() + 1;
			i++;
		}
		if(sum - 1 > L){
			i--;
			sum -= words[i].size()+1;
		}
		bool isLastLine = false;
		if(i == words.size()){
			isLastLine = true;
		}
		int end = i - 1;
		int intercount = end - start;
		int avgS = 0, leftS = 0;
		if(intercount > 0){
			avgS = (L-sum+intercount+1)/intercount;
			leftS = (L-sum+intercount+1)% intercount;
		}
		string line;
		for(int j = start; j<end; j++){
			line += words[j];
			if(isLastLine){
				line.append(1, ' ');
			}else{
				line.append(avgS, ' ');
				if(leftS > 0){
					line.append(1, ' ');
					leftS--;
				}
			}
		}
		line += words[end];
		if(line.size() < L){
			line.append(L-line.size(), ' ');
		}
		result.push_back(line);
	}
	return result;
}		/* -----  end of function fullJustify  ----- */
