// https://leetcode.com/problems/valid-perfect-square/

// use sqrt


// prime factors in even pairs


// not efficient (eg. n = 10^10)
/*
    for(i = 1 to i*i < N; i++)
        i = 1	1 x 1	<25
        i = 2	2 x 2	<25
        i = 3	3 x 3	<25
        i = 4	4 x 4	<25
        i = 5	5 x 5 	!<25 break;
        if(i*i == N) return true;
        else return false;
		
        time -> O(n^1/2)
*/


// Efficient -> Binary Search O(log(n^1/2))
/*
    	4. Efficient solution -> use binary search
		let N <= 100   (1 to 10)
		
		eg. N = 16
		
		1	2	3	4	5	6	7	8	9	10
        l               m                   h

            mid*mid = N
                    < N
                    > N
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long int high = 100000;
        long long int low = 1, mid, sq;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            sq = mid * mid;
            if(sq == num)
                return true;
            else if(sq > num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
