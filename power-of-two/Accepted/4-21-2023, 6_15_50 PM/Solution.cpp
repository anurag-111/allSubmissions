// https://leetcode.com/problems/power-of-two

// O(N) approach
 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }

        while(n > 1 && (n & 1) == 0) {
            n = n >> 1;
        }

        return n == 1 ? true : false;
    }
};


/*
Test Case:
Input: n = 16

Explanation:
The input "n" is 16, which is a power of two (2^4 = 16). Let's go through the code step by step:

The function begins with an "if" statement that checks if "n" is equal to 0. If "n" is indeed 0, the function returns false, as 0 is not considered a power of two. In this case, "n" is not equal to 0, so the "if" statement is skipped.

The code then enters the "while" loop, as "n" is greater than 1 and the least significant bit (LSB) of "n" is 0, which means "n" is an even number. The bitwise AND operator "&" is used to perform a bitwise AND operation between "n" and 1, and the result is compared with 0 to check if the LSB is 0.

Inside the loop, "n" is right-shifted by 1 bit using the bitwise right shift operator ">>=". This shifts all the bits of "n" to the right by 1 position, effectively dividing "n" by 2. After the first iteration, "n" becomes 8 (binary 1000).

The loop continues as long as "n" is greater than 1 and "n" is an even number (i.e., the LSB is 0). In each iteration, "n" is right-shifted by 1 bit, effectively dividing "n" by 2.

After the second iteration, "n" becomes 4 (binary 100), then 2 (binary 10), and finally 1 (binary 1) after the third iteration. At this point, the loop exits, as "n" becomes 1, which is an odd number (i.e., the LSB is 1).

The function then compares "n" with 1. If "n" is equal to 1, it means that "n" was originally a power of 2, as it became 1 after repeated right shifts. In that case, the function returns true, indicating that "n" is a power of two. Otherwise, the function returns false, indicating that "n" is not a power of two.

In the given test case, the function returns true, indicating that 16 is a power of two.

Time Complexity: The time complexity of this approach is O(N), where N is the number of bits in "n". In the worst case, "n" could have all bits set to 1, which would require N iterations to reach 1 after repeated right shifts.

Space Complexity: The space complexity of the function is O(1), as the function only uses a constant amount of memory. The function does not create any data structures or variables that depend on the input size "n". Therefore, the space taken by the function to execute is constant and does not depend on the value of "n".


*/