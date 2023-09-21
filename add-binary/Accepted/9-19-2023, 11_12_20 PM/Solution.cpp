// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }
            carry = sum / 2;
            res = to_string(sum % 2) + res;
        }

        return res;
    }
};


//     11
//   + 01
    
// sum = 0 + 1 + 1 = 2(10), if sum > 1 -> carry = 1(01), set sum = 0
// sum = 1 + 1 + 0 = 2(10), if sum > 1 -> carry = 1(01), set sum = 0
// sum = 1, !(sum > 1), carry = 0, sum = 1
        
// string -> 100
