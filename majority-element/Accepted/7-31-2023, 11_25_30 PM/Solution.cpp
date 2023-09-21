// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], count = 1; //Boyer-Moore Majority Vote Algorithm 
        for(int i = 1; i < nums.size(); i++){
            if(ans == nums[i]){     //same element is found
                count++;
            } else{
                count--;            // different element is found    
            }
            
            if(count == 0){         /*current ans is no longer the majority*/       
                ans = nums[i];
                count = 1;
            }
        }
        return ans;
    }
};