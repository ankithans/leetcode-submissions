
/*
	1. decide the jump value ->  √n -> √12 = 3
	2. keep two pointers low and high -> initially low = 0, high = m 
	3. then compare the element to be searched with low and high -> if (arr[low]>target && arr[high]>target) then move low, high ahead to next block
	4. if above statement is false then do linear search in the block

	time -> O(n/m + (m-1))
	
    linear search > jump search > binary search
*/

int jumpSearch(int a[], int n, int target) {
	int i = 0;
	int m = sqrt(n);
	
	while(a[m] < target && m < n) {
		i = m;
		m += sqrt(n);
		if(m > n - 1)
			return -1;
	}
	
	for(int x = i; x < m; x++) {
		if(a[x] == target)
			return x;
	}
	return -1;
}
