// https://leetcode.com/problems/summary-ranges

// [0,1,2,4,5,7]
// ["0->2", "4->5", "7"]

// Breakpoint occurs at 4, inserting 0 -> 2
// Update the pointers at 4

// Algo : Find the breakpoint, insert the already found sequence and then update 
// the pointers and repeat the process.

// Testcase : [0, 2, 4]
// Output : ["0", "2", "4"]

class Solution {
    private :
        string formatRange(int start, int end) {
            if(start == end) {
                return to_string(start);
            } else {
                return to_string(start) + "->" + to_string(end);
            }
        }
    
    public:
        vector<string> summaryRanges(vector<int> &nums) {
            vector<string> result;

            if(!nums.size()) {
                return result;
            }
            
            int start = nums[0];
            int end = nums[0];

            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] == end + 1) {
                    end = nums[i];
                } else {
                    // Insert start and end
                    result.push_back(formatRange(start, end));
                    start = end = nums[i];
                }
            }
            
            result.push_back(formatRange(start, end));
            return result;
            
        }
};






