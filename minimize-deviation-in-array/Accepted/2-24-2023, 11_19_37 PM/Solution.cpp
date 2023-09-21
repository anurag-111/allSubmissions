// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minVal = INT_MAX;

        for (int num : nums) {

            // maximising all odd numbers by multiplication by 2
            if (num % 2 == 1) {
                num *= 2;
            }
              
            // insertion into the priority queue
            pq.push(num);

            // storing the minimum value
            minVal = min(minVal, num);
        }

        int minDeviation = INT_MAX;

        while (true) {
            // The top element is removed
            int maxVal = pq.top();
            pq.pop();

            // Calculating the minimum deviation between the max and the min values
            minDeviation = min(minDeviation, maxVal - minVal);

            // If a odd number is found we break out of the loop as it had been formed 
            // by the division by 2 of even integers and that should not be undone.
            if (maxVal % 2 == 1) {
                break;
            }

            // Updating the value of minVal and inserting maxVal in the priority queue
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n)