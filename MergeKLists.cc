/*
 * =====================================================================================
 *
 *       Filename:  MergeKLists.cc
 *
 *    Description:  LeetCode Merge K Sorted Lists
 *        Version:  1.0
 *        Created:  03/23/13 20:42:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xiao Cui (XC), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mergeTwoLists
 *  Description:  
 * =====================================================================================
 */
ListNode*
mergeTwoLists (ListNode* l1, ListNode* l2)
{
	if(!l1) return l2;
	if(!l2) return l1;

    ListNode* head = (l1->val <= l2->val)?l1:l2;
	ListNode* p = head;

	if(p == l1){
		l1 = l1->next;
	}else if(p == l2){
		l2 = l2->next;
	}

	while(l1&&l2){
		ListNode*& temp = (l1->val <= l2->val)?l1:l2;
		p->next = temp;
		temp = temp->next;
		p = p->next;
	}

	if(l1) p->next = l1;
	if(l2) p->next = l2;

	return	head; 
}		/* -----  end of function mergeTwoLists  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mergeKLists
 *  Description:  Use mergeTwoLists as assist   
 * =====================================================================================
 */
ListNode*
mergeKLists (vector<ListNode* >&lists)
{
	ListNode* head = NULL;

	if(lists.size() == 0){
		return head;
	}else{
		while(lists.size() > 0){
			if(lists.back()){
				ListNode* l1 = lists.back();
				head = mergeTwoLists(l1, head);
				lists.pop_back();
			}else{
				lists.pop_back();
			}
		}
		return head;
	}
}		
/* -----  end of function mergeKLists  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  heapSort
 *  Description:  
 * =====================================================================================
 */
int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return (i<<1)+1;
}

int right(int i){
	return (i<<1)+2;
}


void minHeapify(vector<ListNode* > &lists, int start, int end){
	int l, r;
	int index_min;
	ListNode* tmp;
	if(start < end){
		l = left(start);
		r = right(start);
		index_min = start;
		if(l <= end && lists[l]->val < lists[start]->val){
			index_min = l;
		}
		if(r <= end && lists[r]->val < lists[index_min]->val){
			index_min = r;
		}

		if(index_min != start){
			tmp = lists[start];
			lists[start] = lists[index_min];
			lists[index_min] = tmp;
			minHeapify(lists, index_min, end);
		}
	}
}

void buildHeap(vector<ListNode* >&lists){
	int heap_size = lists.size();
	for(int i = (heap_size-1)>>1; i>=0; i--){
		minHeapify(lists, i, heap_size-1);
	}
}


ListNode*
heapSort (vector<ListNode* >&lists)
{
	vector<ListNode* >::iterator it = lists.begin();
	while(it != lists.end()){
		if(it == NULL) lists.erase(it);
		else
			it++;
	}

	buildHeap(lists);
	int heap_count = lists.size();
	ListNode* head = NULL;
	ListNode* cur =NULL;
	ListNode* pre = NULL;
	while(heap_count > 0){
		cur = lists[0];
		if(pre == NULL){
			head = cur;
		}else{
			pre->next = cur;
		}
		pre = cur;

		if(lists[0]->next){
			lists[0] = lists[0]->next;
		}else{
			lists[0] = lists[heap_count - 1];
			heap_count--;
		}
		minHeapify(lists, 0, heap_count-1);
	}
	return head;
}		/* -----  end of function heapSort  ----- */
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

