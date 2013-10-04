#include <stdio.h>

int search(int* a, int n, int target){
	int l = 0;
	int r = n - 1;

	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == target) return mid;

		if(a[mid] >= a[l]){
			if(a[l] <= target&& target<=a[mid]){
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}else{
			if(a[mid] >= target || a[l] <=target){
				r = mid - 1;
			}else{

				l = mid + 1;
			}
		}
	}
	return -1;
}

int findMin(int* a, int low, int high){
	if(low > high) return -1;
	while(low < high){
		int mid = (low+high)/2;
		if(a[mid] > a[high]){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low;
}

int findKthSmall(int *a, int n, int k){
    int index = findMin(a, 0, n-1);
	int pos = (index+k-1)%n;
	return pos;
}

int main(){

	int a[] = {4,5,7,0,1,2};
	printf("%d\n", findKthSmall(a, 6, 3));
	return 0;
}
