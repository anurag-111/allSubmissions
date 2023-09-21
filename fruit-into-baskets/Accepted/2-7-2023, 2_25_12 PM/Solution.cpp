// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        int n = tree.size();
        int start = 0;
        unordered_map<int, int> map;
        int type = 0;
        int max_freq = INT_MIN;

        for(int end = 0; end < n; end++) {  
            if (map.count(tree[end]) == 0) {            // storing the frequency of types of elements
                type++;
            }
           map[tree[end]]++;

           while(type > 2) {                            // reducing the frequency or removing the element when it exceeds the condition.
               map[tree[start]]--;
               if(map[tree[start]] == 0) {
                   map.erase(tree[start]);
                   type--;
               }
               start++;
           } 
           max_freq = max(max_freq, end - start + 1);   // maximum number of fruits that can be picked.
        }
        return max_freq;
    }
};

/*  
    Explanation :
    The longest length of subarrays with at most 2 different elements.

    Approach :
    Solve with sliding window,
    and maintain a hashmap counter,
    which count the number of elements between the two pointers.

    Complexity :
    Time  : O(n)
    Space : O(1)

*/
