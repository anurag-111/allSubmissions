// https://leetcode.com/problems/design-hashset

class MyHashSet {
private: 
    int prime;
    vector<list<int>> table;
    int hashValue;

    // Hashes the key using modulo division
    void createHash(int key) {
        hashValue = key % prime;
    }

    // Searches for the key in the list at the hash index
    auto search(int key) {
        return find(table[hashValue].begin(), table[hashValue].end(), key);
    }

public:
    MyHashSet() {
        prime = 10007;
        table.resize(prime);
    }
    
    // Adds the key to the set if it is not already present
    void add(int key) {
        createHash(key);
        if (!contains(key)) {
            table[hashValue].push_back(key);
        }
    }
    
    // Removes the key from the set if it exists
    void remove(int key) {
        createHash(key);
        auto itr = search(key);
        if (itr != table[hashValue].end()) {
            table[hashValue].erase(itr);
        }
    }
    
    // Checks if the set contains the key
    bool contains(int key) {
        createHash(key);
        return search(key) != table[hashValue].end();
    }
};

/**
 * Usage:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

