// https://leetcode.com/problems/design-an-ordered-stream

class OrderedStream {
private:
    vector<string> data;    // Stores the input stream
    int currentIndex;       // Index to keep track of the current position
    
public:
    OrderedStream(int n) {
        data.resize(n);     // Resize the vector when OrderedStream is called
        currentIndex = 0;   // Initialize currentIndex to 0
    }
    
    vector<string> insert(int id, string value) {
        vector<string> result;
        data[id - 1] = value;   // Store the value in the corresponding index position

        // Check if the current index and the stream value are not empty
        while (currentIndex < data.size() && data[currentIndex] != "") {
            result.push_back(data[currentIndex]);   // Add the value to the result vector
            currentIndex++;                         // Move to the next index
        }

        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id, value);
 */
