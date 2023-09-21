// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            int num = x % 10;
            if((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            ans = (ans * 10) + num;
            x = x / 10;
        }
        return ans;
    } 
};

/*
    if((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
    }

    Explaination :
    ______________

    If ans (which represents the partially reversed integer) is greater than INT_MAX / 10,
    it means that multiplying ans by 10 would result in an integer value that exceeds the 
    maximum representable value, causing integer overflow. 
    
    Similarly, if ans is less than INT_MIN / 10, it means that multiplying ans by 10 
    would result in an integer value that is lower than the minimum representable value, 
    also causing integer overflow.

    In either of these cases, the code returns 0, indicating that the reversed integer
    would be out of the valid integer range and cannot be calculated correctly. 
    This check helps to prevent integer overflow and ensures that the reversed integer 
    stays within the valid integer range.
*/