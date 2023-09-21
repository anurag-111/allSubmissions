// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
    public :
        // Stacks for performing operations
        stack<int> input;
        stack<int> output;
        
        MyQueue() {
            
        }
        
        // Push operation
        void push(int data) {
            input.push(data);
        }
        
        // Pop operation
        int pop() {
            int value = peek();
            output.pop();
            return value;
        }
        
        // Peek operation
        int peek() {
            if(output.empty()) {
                while(!input.empty()) {
                    int value = input.top();
                    output.push(value);
                    input.pop();
                }
            }
            return output.top();
        }
        
        // isEmpty operation
        bool empty() {
            return input.empty() && output.empty();
        }
};

/*
let's calculate the total cost of n pop() operations:

Total cost = O(n) (for the first pop()) + O(1) (for the subsequent pop() operations)

Since there are n pop() operations in the sequence, the total cost for the n pop() operations will be:

Total cost = n * O(1)

Now, to find the amortized time complexity per pop() operation, we divide the total cost by n:

Amortized time complexity = (n * O(1)) / n = O(1)

So, the amortized time complexity of the pop() method is O(1). This means that the average time taken 
for a single pop() operation over the entire sequence of n pop() operations is constant and not dependent on the number of elements in the queue
*/


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */