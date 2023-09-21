// https://leetcode.com/problems/sum-of-two-integers

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry = 0;
        
        while (b != 0) {
            
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        
        return a;
    }
};

/*
    Explaination :
    
    Inside the loop, the function calculates the carry by performing 
    bitwise AND operation between "a" and "b", and then left shifting 
    the result by 1 to the left.

    The function calculates the sum of "a" and "b" without considering 
    the carry by performing bitwise XOR operation between "a" and "b".

    The function updates "a" with the calculated sum and "b" with the 
    calculated carry for the next iteration.

    The loop continues until there is no carry left (i.e., "b" becomes 0).

    Finally, the function returns the calculated sum of "a" and "b" as the result.
*/

/*
    Complexity :
    
    Bit manipulation is used to simulate addition without using the "+" 
    or "-" operators, and has a time complexity of O(1) as it takes constant time 
    to perform bitwise operations. 

    The space complexity of the function is also O(1) as it uses a constant amount 
    of memory to store the variables "a", "b", and "carry".
*/