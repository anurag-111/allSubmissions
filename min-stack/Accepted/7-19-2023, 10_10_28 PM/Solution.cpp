// https://leetcode.com/problems/min-stack

class MinStack {
public:

    stack<int> st1;
    stack<int> st2;

    MinStack() {
    }
    
    void push(int val) {
        st1.push(val); // Push the element onto the main stack 'st1'.

        // If the auxiliary stack 'st2' is empty or the top element of 'st2' is greater than or equal to the new value,
        // then push the new value onto 'st2', making it the new minimum element.
        if(st2.empty() || st2.top() >= val) {
            st2.push(val);
        }
    }
    
    void pop() {
        // If the top element of the main stack 'st1' is equal to the top element of the auxiliary stack 'st2',
        // then it means the minimum element is being removed, so we also pop it from 'st2'.
        if(st1.top() == st2.top()) {
            st2.pop();
        }

        st1.pop(); // Always pop the top element from the main stack 'st1'.
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

// Time complexity of all operations is O(1), and the space complexity is O(N)


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */