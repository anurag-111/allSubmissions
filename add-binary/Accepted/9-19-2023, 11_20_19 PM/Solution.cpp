// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) {
                sum += a[i--] - '0';
            }
            if(j >= 0) {
                sum += b[j--] - '0';
            }
            carry = sum / 2;
            result = to_string(sum % 2) + result;
        }
        return result;
    }
};


/*
Time Complexity: O(max(N, M))

N and M are the lengths of the input binary strings 'a' and 'b'.
The code iterates through both input strings once, processing each digit.
Space Complexity: O(max(N, M))

The primary space usage comes from the 'res' string, which stores the binary sum.
In the worst case, the result string can have a length equal to the longer of the two input strings, so the space complexity is O(max(N, M)).
*/