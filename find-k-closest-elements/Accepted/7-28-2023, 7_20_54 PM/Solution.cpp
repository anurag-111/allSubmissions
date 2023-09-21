// https://leetcode.com/problems/find-k-closest-elements

// Brute force approach :

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> differences;
        vector<int> result;
        int size = arr.size();
        
        
        for(int i = 0; i < size; i++) {
            int difference = abs(arr[i] - x);
            differences.push_back(make_pair(difference, arr[i]));
        }
                                  
        sort(differences.begin(), differences.end());                         
        
        // for(auto pair : differences) {
        //     cout << pair.first << " "<< pair.second << endl;
        // }
        
        for(int i = 0; i < k; i++) {
            result.push_back(differences[i].second);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};