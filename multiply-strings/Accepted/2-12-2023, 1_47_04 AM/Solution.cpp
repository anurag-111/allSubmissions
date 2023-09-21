// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "" || num2 == "") {
            return "";
        }
            
        if(num1=="0" || num2=="0") {
            return "0";
        }
            
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        //Always keep smaller number on the outer loop.
        if(num1.size() > num2.size()) {
            num1.swap(num2);
        }
        
        int m = num1.size();
        int n = num2.size();
        
        vector<int> partialProduct(m + n, 0);
        
        int shift =0;
        int k;

        for(int i = 0; i < m; i++){
            int digit1 = num1[i] - '0';
            int carry = 0;
            k = 0;

            for(int j = 0; j < n; j++){
                int digit2 = num2[j] - '0';
                int sum = (digit1 * digit2) + partialProduct[k + shift] + carry;
                carry = sum / 10;
                partialProduct[k + shift] = sum % 10;
                k++;
            }

            if(carry) {
                partialProduct[k + shift] += carry;
            }
            shift++;
        }
        
        string result;
        
        reverse(partialProduct.begin() , partialProduct.end());
        
        for(int d : partialProduct){
           result += to_string(d); 
        }
        
        int index = 0;
        for(char ch : result){
            if(ch == '0') {
                index++;
            } else {
                break;
            }
        }

        result = result.replace(0, index, "");
        return result;
    }
};