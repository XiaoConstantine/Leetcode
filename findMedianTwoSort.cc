#include <stdio.h>

int getMedian(int *a, int m, int *b, int n, int k){
	if( m <= 0) return b[k-1];
	if( n <= 0) return a[k-1];
	if( k <= 1) return a[0]>b[0]?b[0]:a[0];

	if(a[m/2] >= b[n/2]){
		if( (m/2 + n/2 + 1) >= k ){
			return getMedian(a, m/2, b, n, k);
		}else{
			return getMedian(a,m, b+n/2+1, n/2-1, k-(n/2+1));
		}
	}else{
		if( (m/2 + n/2 +1) >= k){
			return getMedian(a,m, b, n/2, k);
		}else{
			return getMedian(a+m/2+1, m/2-1,b,n, k-(m/2+1));
		}
	}
}

int getKthElement(int *a, int m, int *b, int n, int k){
	if(m > k) return getKthElement(a,k,b,n,k);
	if(n > k) return getKthElement(a,m,b,k,k);
	
	
	if( m <= 0) return b[k-1];
	if( n <= 0) return a[k-1];
	if( k <= 1) return a[0]>b[0]?b[0]:a[0];

	if(a[m/2] >= b[n/2]){
		if( (m/2 + n/2 + 1) >= k ){
			return getMedian(a, m/2, b, n, k);
		}else{
			return getMedian(a,m, b+n/2+1, n/2-1, k-(n/2+1));
		}
	}else{
		if( (m/2 + n/2 +1) >= k){
			return getMedian(a,m, b, n/2, k);
		}else{
			return getMedian(a+m/2+1, m/2-1,b,n, k-(m/2+1));
		}
	}
}

double findKth(int *A, int m, int *B, int n, int k){
	if(m > n) return findKth(B, n, A, m, k);
	if(m == 0) return B[k-1];
	if(k == 1) return min(A[0], B[0]);
	int pa = min(k/2, m);
	int pb = k - pa;
	if(A[pa-1] < B[pb-1]) return findKth(A+pa, m+pa, B, n, k-pa);
	return findKth(A, m, B+pb, n-pb, k-pb);
}


double findMedian(int *A, int m, int *B, int n){
	if((m+n)%2 == 0){
		return (getMedian(A, m, B, n, (m+n)/2) + getMedian(A,m,B,n, (m+n)/2+1))/2.0; 
	}else
		return getMedian(A,m,B,n, (m+n)/2+1);
}

int main(){
	int a[] = {1,3,5,7};
	int b[] = {2,4,6,8};
	printf("%d\n", getKthElement(a,4,b,4, 3));
	return 0;
}
