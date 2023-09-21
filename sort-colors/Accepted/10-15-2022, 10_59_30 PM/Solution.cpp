// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;
        
        while(mid <= high) {
            switch(nums[mid]) {
                
                //element = 0
                case 0: 
                    swap(nums[low++],nums[mid++]);
                    break;
                
                //element = 1
                case 1:
                    mid++;
                    break;
                
                //element = 2
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};