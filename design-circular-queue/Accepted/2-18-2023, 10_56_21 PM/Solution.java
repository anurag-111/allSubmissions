// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
    
    private int[] queue;
    private int size;
    private int front;
    private int rear;

    public MyCircularQueue(int k) {
        this.size = k;
        queue = new int[size];
        rear = -1;
        front = -1;
    }
    
    public boolean enQueue(int value) {
        
        if (isFull()) {
            return false;
        }
        
        rear = (rear + 1) % size;
        
        if (front == -1) {
            front = (front + 1) % size;
        }

        queue[rear] = value;
        return true;
    }
    
    public boolean deQueue() {
        
        if (isEmpty()) {
            return false;
        }
        
        if (front == rear) {
            front = -1;
            rear = -1;
            return true;
        }
        
        front = (front + 1) % size;
        return true;
    }
    
    public int Front() {
        
        if (isEmpty()) {
            return -1;
        }
        
        return queue[front];
    }
    
    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return queue[rear];
    }
    
    public boolean isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        
        return false;
    }
    
    public boolean isFull() {
        // return true if queue is full
        if (((rear + 1) % size) == front) {
            return true;
        }
        
        return false;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */