// https://leetcode.com/problems/implement-stack-using-queues

#include <queue>

class MyStack {
public:
    std::queue<int> q; // Queue to simulate the stack

    MyStack() {} // Constructor, no explicit initialization needed

    // Pushes the given element 'x' onto the stack
    void push(int x) {
        q.push(x); // Push the new element to the back of the queue
        int size = q.size(); // Get the size of the queue

        // Rotate the queue to move the newly pushed element to the front
        while (size > 1) {
            int element = q.front(); // Store the front element
            q.push(element); // Move the front element to the back of the queue
            q.pop(); // Remove the front element (rotate the queue)
            size--; // Decrement the size to continue rotating
        }
    }

    // Removes and returns the top element of the stack.
    // If the stack is empty, returns -1.
    int pop() {
        int element = q.front(); // Retrieve the front element (top of stack)
        q.pop(); // Remove the front element (top of stack)
        return element; // Return the removed element
    }

    // Returns the top element of the stack without removing it.
    int top() {
        return q.front(); // Return the front element (top of stack) from the queue
    }

    // Checks if the stack is empty.
    bool empty() {
        return q.empty(); // Return true if the queue is empty (stack is empty), otherwise return false
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
