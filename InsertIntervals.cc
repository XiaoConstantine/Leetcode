/*
 * =====================================================================================
 *
 *       Filename:  InsertIntervals.cc
 *
 *    Description: Given a set of no-overlapping intervals, insert a new interval into it
 *                 merge if necessary. You may assume that the intervals were initially 
 *                 sorted
 *        Version:  1.0
 *        Created:  03/18/13 19:23:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <vector>
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
	intervals.insert(intervals.end(), newInterval); // for empty intervals case and [1,5] [2,3] after while loop intervals is [],
													// insert newInterval
	return intervals;
}		
/* -----  end of function insert  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

