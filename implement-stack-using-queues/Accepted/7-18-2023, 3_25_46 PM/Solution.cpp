// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    
    queue<int> q1; // First queue used to simulate the stack
    queue<int> q2; // Second queue used for temporary storage during push operation
    
    MyStack() {
        // Constructor, no explicit initialization needed
    }
    
    // Pushes the given element 'x' onto the stack
    void push(int x) {
        q2.push(x); // Push the element to the temporary queue (q2)
        
        // Move elements from q1 to q2 to maintain stack order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2 to make q2 empty and keep the stack elements in q1
        swap(q1, q2);
    }
    
    // Removes and returns the top element of the stack.
    // If the stack is empty, returns -1.
    int pop() {
        if (!q1.empty()) {
            int element = q1.front(); // Retrieve the front element (top of stack)
            q1.pop(); // Remove the front element (top of stack)
            return element; // Return the removed element
        } else {
            return -1; // Stack is empty, return -1
        }
    }
    
    // Returns the top element of the stack without removing it.
    int top() {
        return q1.front(); // Return the front element (top of stack) from q1
    }
    
    // Checks if the stack is empty.
    bool empty() {
        if (q1.empty()) {
            return true; // If q1 is empty, the stack is empty, return true
        } else {
            return false; // If q1 is not empty, the stack is not empty, return false
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


/*
    Time Complexity:
    
    The time complexity for each operation is as follows:
    - Push  : O(n)
    - Pop   : O(1)
    - Top   : O(1)
    - Empty : O(1)

    Space complexity : O(n)

*/
