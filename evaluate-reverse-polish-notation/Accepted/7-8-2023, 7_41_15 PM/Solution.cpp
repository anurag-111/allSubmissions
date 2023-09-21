// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
private:
    // Function to perform arithmetic operations
    int performOperation(char op, int operand1, int operand2) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                return operand1 / operand2;
            default:
                return 0;
        }
    }

public:
    // Function to evaluate Reverse Polish Notation expression
    int evalRPN(vector<string>& tokens) {
        stack<int> evalStack;

        for (int i = 0; i < tokens.size(); i++) {
            // If the token is an operator
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int operand2 = evalStack.top();
                evalStack.pop();
                int operand1 = evalStack.top();
                evalStack.pop();

                // Perform the operation and push the result back to the stack
                int result = performOperation(tokens[i][0], operand1, operand2);
                evalStack.push(result);
            } else {
                // If the token is a number, convert it to integer and push to the stack
                int num = stoi(tokens[i]);
                evalStack.push(num);
            }
        }

        // The final result is at the top of the stack
        return evalStack.top();
    }
};
