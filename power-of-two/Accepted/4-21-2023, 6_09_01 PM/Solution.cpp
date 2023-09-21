// https://leetcode.com/problems/power-of-two

// O(1) approach

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }

        return floor(log2(n)) == ceil(log2(n)) ? true : false;
    }
};

/*
    Time Complexity : O(1)

    The time complexity of the given "isPowerOfTwo" function is O(1). 
    The reason is that the function simply computes the logarithm base 2 of "n" 
    using the "log2" function from the C++ standard library, which has a constant 
    time complexity. The function then compares the rounded-down ("floor") and 
    rounded-up ("ceil") values of the logarithm base 2 of "n", which also takes 
    constant time. 
    Therefore, the time complexity of the function is O(1), which means that the 
    time taken by the function to execute is constant and does not depend on the value of "n".

    Space Complexity : O(1)

    The space complexity of the function is also O(1), as the function only uses 
    a constant amount of memory. The function does not create any data structures or 
    variables that depend on the input size "n". Therefore, the space taken by the 
    function to execute is constant and does not depend on the value of "n".
*/
