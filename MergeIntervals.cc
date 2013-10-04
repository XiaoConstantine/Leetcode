/*
 * =====================================================================================
 *
 *       Filename:  MergeIntervals.cc
 *
 *    Description:  LeetCode Merge Intervals
 *        Version:  1.0
 *        Created:  04/08/13 01:37:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

struct Interval {
   int start;
   int end;
   Interval(): start(0), end(0){}
   Interval(int s, int e): start(s): start(s), end(e){

   }
};				
/* ----------  end of struct Interval  ---------- */

typedef struct Interval Interval;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  insert
 *  Description:  
 * =====================================================================================
 */
vector<Interval>	
insert (vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval>::iterator it = intervals.begin();
	while(it != intervals.end()){
		if(newInterval.end < it->start){
			intervals.insert(it, newInterval);
			return intervals;
		}else if(newInterval.start > it->end){
			it++;
			continue;
		}else{
			newInterval = min(newInterval.start, it->start);
			newInterval = max(newInterval.end, it->end);
		}
	}
	intervals.insert(intervals.end(), newInterval);
	return intervals;
}		
/* -----  end of function insert  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  merge
 *  Description:  
 * =====================================================================================
 */
vector<Interval>
merge (vector<Interval> &intervals)
{
	vector<Interval> result;
	for(int i = 0; i < intervals.size(); i++){
		insert(result, intervals[i]);
	}
	return result;
}		/* -----  end of function merge  ----- */
