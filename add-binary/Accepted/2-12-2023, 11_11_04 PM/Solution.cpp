// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            } 

            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);      // moduling the sum so, we can get remainder and add it into our result
        }

        if(carry) {
            res += to_string(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


/*

    Time Complexity :- 
        O(max(m, n)), m & n is the length of string a, b.

    Space Complexity :- 
        O(max(m, n)), which is the size of "res" object.

*/