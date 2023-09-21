// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;
        for (int i = 0; i < asteroids.size(); i++) {
            int currentAsteroid = asteroids[i];

            // Case 1: Asteroid moves to the right
            if (currentAsteroid > 0) {
                asteroidStack.push(currentAsteroid);
            } 
            // Case 2: Asteroid moves to the left
            else {    
                // Case 2.1: Collision occurs with a positive asteroid moving to the right
                while (!asteroidStack.empty() && asteroidStack.top() < abs(currentAsteroid) && asteroidStack.top() > 0) {
                    asteroidStack.pop();
                }

                // Case 2.2: The negative asteroid survives (either no collision or all positive asteroids were destroyed)
                if (asteroidStack.empty() || asteroidStack.top() <= 0) {
                    asteroidStack.push(currentAsteroid);
                }

                // Case 2.3: Equal magnitude of asteroids collide and both get destroyed
                if (!asteroidStack.empty() && asteroidStack.top() == abs(currentAsteroid)) {
                    asteroidStack.pop();
                }
            }
        }

        int size = asteroidStack.size();
        vector<int> result(size);
        while (!asteroidStack.empty()) {
            result[size - 1] = asteroidStack.top();
            asteroidStack.pop();
            size--;
        }

        return result;
    }
};

/* 
   Time Complexity (TC): O(n)
   Explanation: The algorithm processes each asteroid once, and in each iteration, 
   the asteroid is either added to the stack or removed from it. In the worst case, 
   we process each asteroid twice (when it collides with the last asteroid in the stack and gets removed). 
   Therefore, the time complexity is linear in terms of the number of asteroids, which is O(n).

   Space Complexity (SC): O(n)
   Explanation: The algorithm uses a stack to store the positive asteroids. In the worst case, 
   all the asteroids are positive, and we store all of them in the stack. Hence, the space complexity is O(n).
*/
