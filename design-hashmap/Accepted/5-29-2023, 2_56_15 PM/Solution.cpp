// https://leetcode.com/problems/design-hashmap

class MyHashMap {
private:
    std::vector<int> arr; // Vector to store key-value pairs

public:
    MyHashMap() : arr(1000001, -1) {
        // Constructor: Initializes the vector with size 1000001 and sets all elements to -1
    }
    
    // Inserts a key-value pair into the map
    void put(int key, int value) {
        arr[key] = value;
    }
    
    // Retrieves the value associated with a given key
    int get(int key) {
        return arr[key];
    }
    
    // Removes a key-value pair from the map
    void remove(int key) {
        arr[key] = -1;
    }
};
