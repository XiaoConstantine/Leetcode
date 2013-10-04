/*
 * =====================================================================================
 *
 *       Filename:  SortColors.cc
 *
 *    Description:  LeetCode Sort Colors
 *        Version:  1.0
 *        Created:  04/02/13 18:58:29
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
 *         Name:  countSort
 *  Description:  
 * =====================================================================================
 */
	void
countSort (int A[], int n)
{
	int r = 0, w = 0, b = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == 0){
			r++;
		}else if(A[i] == 1){
			w++;
		}else{
			b++;
		}
	}

	for(int i = 0; i < n; i++){
		if(r > 0){
			A[i] = 0;
			r--;
			continue;
		}
		if(w > 0){
			A[i] = 1;
			w--;
			continue;
		}
		A[i] = 2;
	}
}		/* -----  end of function countSort  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  qsort
 *  Description:  
 * =====================================================================================
 */
void
qsort (int A[], int l, int r)
{
	if(l >= r) return;
	int m = l;
	for(int i = l+1; i <= r; i++){
		if(A[i] < A[l]){
			swap(A[++m], A[i]);
		}
	}
	swap(A[l], A[m]);
	qsort(A, l, m-1);
	qsort(A, m+1, r);
}		
/* -----  end of function qsort  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sortColors
 *  Description:  
 * =====================================================================================
 */
void
sortColors (int A[], int n)
{
	qsort(A, 0, n-1);
}		
/* -----  end of function sortColors  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sortColors
 *  Description:  one pass like count algorithm use constant space 
 * =====================================================================================
 */
void
sortColorsII (int A[], int n)
{
	int red = 0, blue = n-1;
	int i = 0;
	while(i < blue+1){
        if(A[i] == 0){
			swap(A[i], A[red]);
			red++;
			i++;
			continue;
		}
		if(A[i] == 2){
			swap(A[i], A[blue]);
			blue--;
			continue;
		}
		i++;
	}
}		
/* -----  end of function sortColors  ----- */
