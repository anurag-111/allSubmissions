// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        vector<int> result;
        int index = num.size() - 1;
        
        
        while(index >= 0 || k > 0) {
            // For handling the carry
            int digit = carry;
            
            // Till the vector exists
            if(index >= 0) {
                digit += num[index--];
            }
            
            // Till the given number exists
            if(k > 0) {
                digit += k % 10; // Fetch the digit to be added
                k /= 10;         // Update the number
            }
            
            carry = digit / 10;  // Update the carry
            result.insert(result.begin(), digit % 10); // Insertion of the digit will be done from front
        }
        
        return result;
    }
};

// TC : O(N)
// SC : O(N)