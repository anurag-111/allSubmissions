// https://leetcode.com/problems/find-k-closest-elements

// Two pointer appraoch :

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // First find the element or it's nearest one by binary search
        int low = 0;
        int mid = 0;
        int high = arr.size() - 1;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == x) {
                break;
            } else if(arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // If x is not found, adjust the pointers to the nearest elements
        if (arr[mid] != x) {
            if (low > 0 && (low == arr.size() || abs(arr[low] - x) < abs(arr[high] - x))) {
                mid = low;
            } else {
                mid = high;
            }
        }
        
        int left = mid - 1;
        int right = mid;
        vector<int> closest;
        
        // Start the search in both left and right side search space of our array
        while(left >= 0 && right < arr.size() && k > 0) {
            if(abs(arr[left] - x) <= abs(arr[right] - x)) {
                closest.push_back(arr[left]);
                left--;
            } else {
                closest.push_back(arr[right]);
                right++;
            }
            k--;
        }
        
        while(left >= 0 && k > 0) {
            closest.push_back(arr[left]);
            left--;
            k--;
        }
        
        while(right < arr.size() && k > 0) {
            closest.push_back(arr[right]);
            right++;
            k--;
        }
        
        sort(closest.begin(), closest.end());
        return closest;
    }
};