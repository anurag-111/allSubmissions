// https://leetcode.com/problems/similar-string-groups

class Solution {
private:
     /*
        This function takes in two strings str1 and str2 and checks if they are similar. 
        Two strings are considered similar if they differ by at most two characters. 
        The function returns a boolean value true if the strings are similar and false otherwise.
        bool isSimilar(string str1, string str2) {
    */
    bool isSimilar(string str1, string str2) {
        int count = 0;
        for(int i = 0; i < str1.size(); i++){
            if(str1[i] != str2[i]) {
                count++;
            }
        }
        return ((count == 2) || (count == 0)); 
    } 
    
    /*
        This is a depth-first search function that takes in an integer i,  
        a vector of boolean values visited, and a vector of strings strs. 
        It visits all the nodes in the graph of strings that are similar to strs[i]. 
        It does this by marking the current node as visited, and then visiting all 
        the nodes that are adjacent to it and have not been visited yet.
    */
    void dfs(int i, vector<bool>& visited,  vector<string>& strs) {
        visited[i] = true;
        for(int j = 0; j < strs.size(); j++) {
            if(visited[j]) {
                continue;
            }
            if (isSimilar(strs[i], strs[j])) {
                dfs(j, visited, strs);
            }
        }
    }

public:
    /*
        This function takes in a vector of strings strs and returns the number of groups 
        of strings that are similar. It does this by initializing a vector of boolean values 
        visited with false values, then iterating through all the strings in strs, calling dfs() 
        on each string that has not been visited yet, and incrementing the group count by one for 
        each group of strings that is found.
    */
    int numSimilarGroups(vector<string>& strs) {
        int size = strs.size();
        int groups = 0;
        vector<bool> visited(size, false);
        for(int i = 0; i < size; i++) {
            if(visited[i]) {
                continue;
            }
            groups++;
            dfs(i, visited, strs);
        }
        return groups;
    }
};
/*
    Time Complexity : O(N^2 * L)

        The time complexity of the provided solution is O(N^2 * L), where N is the 
        number of strings and L is the length of the longest string in the input vector.

        The reason for this complexity is the nested loop in the isSimilar() function, 
        which iterates over all characters of the two input strings to check if they 
        are similar. Since this function is called for each pair of strings in the input 
        vector, the overall time complexity becomes O(N^2 * L).

    Space Complexity : O(N * M)

        O(N) which comes from the use of the visited vector to keep track of visited 
        strings during the depth-first search algorithm and O(M) from the N strings
        to go in the recursive stack each of size M.
*/