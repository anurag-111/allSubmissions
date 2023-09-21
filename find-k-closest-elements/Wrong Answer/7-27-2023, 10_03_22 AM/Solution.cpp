// https://leetcode.com/problems/find-k-closest-elements

// Two pointer appraoch :

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // // Check edge cases when x is outside the range of array elements
        // if (x <= arr.front()) {
        //     return vector<int>(arr.begin(), arr.begin() + k);
        // }
        // if (x >= arr.back()) {
        //     return vector<int>(arr.end() - k, arr.end());
        // }
        
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
        
        int left = mid - 1;
        int right = mid;
        //cout<<"left: "<<left<<"right: "<<right<<endl;
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