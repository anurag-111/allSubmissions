// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
private:
    int size;       // Maximum size of the circular queue
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int* queue;     // Array to store the queue elements

public:
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        size = k;
        queue = new int[size];
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;   // Queue is full, unable to enqueue
        }

        rear = (rear + 1) % size;

        // Handle the case when the queue is initially empty
        if (front == -1) {
            front = (front + 1) % size;
        }

        queue[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;   // Queue is empty, unable to dequeue
        }

        if (front == rear) {
            front = -1;
            rear = -1;
            return true;
        }

        front = (front + 1) % size;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;      // Queue is empty
        }
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;      // Queue is empty
        }
        return queue[rear];
    }

    bool isEmpty() {
        return front == -1 && rear == -1;   // Queue is empty if both front and rear are -1
    }

    bool isFull() {
        return (rear + 1) % size == front;   // Queue is full if (rear+1)%size is equal to front
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
