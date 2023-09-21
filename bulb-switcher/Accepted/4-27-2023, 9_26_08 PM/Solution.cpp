// https://leetcode.com/problems/bulb-switcher

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n); //O(log(n))
    }
};

// Approach :
    /*
    This solution is based on a mathematical observation: a bulb will be toggled once    
    for every divisor it has. For example, the first bulb will be toggled on rounds 1 and n, 
    so it will be on if and only if n has an odd number of divisors (since the divisors come 
    in pairs, except when n is a perfect square). 
    Therefore, the problem reduces to counting the number of perfect squares between 1 and n, 
    since those are the only bulbs that will be on at the end. This can be done by taking the 
    square root of n and rounding down to the nearest integer, which is what the function sqrt() does. 
    So the function simply returns the floor of the square root of n.
    */
