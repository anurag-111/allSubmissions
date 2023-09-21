// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

class Solution {
public:
    int match(vector<int>& A, vector<int>& B, int low, int high) {
        unordered_map<int, int> umap;
        
        for(int i = low; i <= high; i++) {
            umap[A[i]]++;
        }
        int match = 0;
        for(int i = low; i <= high; i++) {
            if (umap.find(B[i]) != umap.end()) {
                match++;
            }
        }
        
        return match;
    }
    
    
    
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        vector<int> count;
        
        for (int i = 0; i < A.size(); i++) {
            count.push_back(match(A, B, 0, i));
        }
        
        return count;
    }
};