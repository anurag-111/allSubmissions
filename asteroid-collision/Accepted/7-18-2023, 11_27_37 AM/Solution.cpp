// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            int current = asteroids[i];

            // case 1 : moves to right
            if(current > 0) {
                st.push(current);
            } 
            // case 2 : moves to left
            else {    
                // case 2.1 : collision occurs 
                while(!st.empty() && st.top() < abs(current) && st.top() > 0) {
                    st.pop();
                }

                // case 2.2 : the negative survives
                if(st.empty() || st.top() <= 0) {
                    st.push(current);
                }

                // case 2.3 : equal magnitude
                if(st.top() == abs(current)) {
                    st.pop();
                }
            }
        }

        int size = st.size();
        vector<int> result(size);
        while(!st.empty()) {
            result[size - 1] = st.top();
            st.pop();
            size--;
        }

        return result;

    }
};