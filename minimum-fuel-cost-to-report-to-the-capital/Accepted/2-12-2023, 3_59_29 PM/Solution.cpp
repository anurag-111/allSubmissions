// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

class Solution {
public:
    long long fuel = 0;

    long long dfs(vector<vector<int>>& adj_list, int node,vector<int>& visited, int& seats) {
        visited[node] = true;

        long long count = 1;   //count of nodes
        
        for(int i = 0; i < adj_list[node].size(); i++) {
            int current = adj_list[node][i];

            if(!visited[current]) {
                // Add count of representatives in each child subtree 
                // to the parent subtree.
                count += dfs(adj_list, current, visited, seats);
            }
        }

        long long car_count = count / seats;

        if(count % seats != 0) {                   
            car_count++;
        }

        if(node != 0) {
            // Count the fuel it takes to move to the parent node.
            // Root node does not have any parent so we ignore it
            fuel += car_count;
        }

        return count;

    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        if(roads.size() == 0) {
            return 0;
        }
        
        fuel = 0;
        int n = roads.size();
        vector<vector<int>> adj_list(n + 1);  

        for (int i = 0; i < n; i++) {
            int x = roads[i][0];
            int y = roads[i][1];
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        
        vector<int> visited(n + 1, 0);
        dfs(adj_list, 0, visited, seats);

        return fuel;
    }
};


/*

    Complexity Analysis:

    Here n is the number of nodes.
    ____________________________________________________________________________________________________

    Time complexity: O(n)

    The dfs function visits each node once, which takes O(n) time in total. 
    Because we have n - 1 undirected edges, each edge can only be iterated twice (by nodes at the end), 
    resulting in O(n) operations total while visiting all nodes.
    We also need O(n) time to initialize the adjacency list.

    ____________________________________________________________________________________________________
    
    Space complexity: O(n)

    Building the adjacency list takes O(n) space.
    The recursion call stack used by dfs can have no more than nnn elements in the worst-case scenario. 
    It would take up O(n) space in that case.

*/