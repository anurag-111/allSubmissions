// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // Sort the people vector in ascending order
        int size = people.size(); 
        int count = 0; // Number of boats needed

        int left = 0; 
        int right = size - 1;

        while (left <= right) { // Iterate until the two pointers meet
            int remainingWeight = limit - people[right]; // Calculate the remaining weight capacity for the boat
            right--; // Move to the next person from the end
            count++; // Increment the boat count as one person is placed on the boat

            if (left <= right && people[left] <= remainingWeight) {
                left++; // Move to the next person from the start if the weight allows
            }
        }

        return count; 
    }
};


    /*
    Input:
    - people: a vector of integers representing the weights of people
    - limit: an integer representing the maximum weight capacity of each boat

    Output:
    - Returns the minimum number of boats needed to rescue all people.

    Algorithm:
    1. Sort the 'people' vector in ascending order to ensure lighter people come first.
    2. Initialize 'count' to keep track of the number of boats needed.
    3. Initialize 'left' and 'right' pointers to the start and end of the 'people' vector, respectively.
    4. Iterate while 'left' is less than or equal to 'right':
        - Calculate 'remainingWeight' by subtracting the weight of the person at 'right' index from 'limit'.
        - Decrement 'right' to move to the next person from the end.
        - Increment 'count' as a boat is used to carry the person at 'right' index.
        - If 'left' is less than or equal to 'right' and the weight of the person at 'left' index is less than or equal to 'remainingWeight':
            - Increment 'left' to move to the next person from the start.
    5. Return 'count', which represents the minimum number of boats needed to rescue all people.

    Time complexity: O(N*logN), where N is the number of people.
    Space complexity: O(1).
    */
