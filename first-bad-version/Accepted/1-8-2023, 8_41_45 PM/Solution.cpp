// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //[111110000] : find the minimum occurence of zero here representing bad version
        
        int low = 1, high = n;
        int ans = -1;
        
        while (low <= high) {
	        int mid = low + (high - low) / 2;
            
	        if (isBadVersion(mid)) {
		        ans = mid;
		        high = mid - 1;
	        } else {
		        low = mid + 1;
	        }
        }
        
        return ans;
    }
};