// https://leetcode.com/problems/profitable-schemes

/*
    Problem Statement:
    
    Given the following inputs:
    An integer n representing the number of people in a group.
    An integer minProfit representing the minimum profit that needs to be achieved.
    Two vectors of integers, group and profit, of the same size. group[i] represents the size of the group required for the i-th job, 
    and profit[i] represents the profit that can be obtained from the i-th job.
    The task is to find the number of different schemes that can be formed to achieve at least minProfit profit, given the constraint 
    that each job can only be assigned to one group, and the total size of the assigned groups cannot exceed n.
*/

/*
    Approach :

    The solution uses dynamic programming with memoization to avoid redundant calculations. 
*/

/*
    int dp[102][102][102];

    The 3-dimensional array dp of size 102 x 102 x 102 is used to store the results of subproblems, 
    where dp[k][i][j] represents the number of schemes that can be formed considering the first k jobs, 
    with i people already assigned and j profit already achieved.

    But why this specific size ?

    The 3-dimensional array dp of size 102 x 102 x 102 is used in this solution to store the results of subproblems 
    in the dynamic programming approach. The size of 102 is chosen based on the constraints of the problem, 
    which state that the maximum size of group and profit vectors is 100, and the maximum value of n and minProfit is also 100.

    By using an array of size 102 x 102 x 102, the solution provides an additional buffer to account for the indices 
    ranging from 0 to 101, which allows for convenient indexing and storage of intermediate results without causing 
    out-of-bounds access or memory overflow issues.

*/

/*
    The solve() function is a recursive helper function that implements the dynamic programming approach. 
    It takes the current job index k, the number of people already assigned i, the profit already achieved j, 
    the total number of people n, the minimum profit required minProfit, and the group and profit vectors as input.

*/

/*
    The base cases for the recursion are:

    If k is equal to the size of profit vector, meaning all jobs have been considered, 
    then the function checks if j is greater than or equal to minProfit and i is less than 
    or equal to n. If both conditions are satisfied, it returns 1, otherwise 0.
    If n is less than i, meaning the total number of people assigned exceeds the limit, then it returns 0.
*/

/*
    The recursive calls in the solve() function are as follows:

    notInclude: Calls solve() with the next job index k+1, i, j, n, minProfit, group, and profit, 
    without including the current job in the assignment.

    include: Calls solve() with the next job index k+1, i incremented by group[k], 
    j incremented by profit[k] (but limited by minProfit), n, minProfit, group, and profit, 
    including the current job in the assignment.
*/

/*
    The final result is stored in the dp[k][i][j] array to avoid redundant calculations, 
    and it is returned as (include % mod + notInclude % mod) % mod, where mod is a constant value of 1e9+7, 
    which is used for taking modulo to prevent integer overflow. 
*/

/*
    The profitableSchemes() function initializes the dp array with -1, and then calls the solve() function 
    with initial parameters k=0, i=0, j=0, and returns the resul
*/

class Solution {
public:
    int dp[102][102][102]; // 3D array to store results of subproblems
    int mod = 1e9 + 7; // modulo constant for preventing integer overflow
    
    int solve(int k, int i, int j, int n, int minProfit, vector<int>& group, vector<int>& profit) {

        // Base case 1: All jobs have been considered
        if(k == profit.size()) {
            // Check if minimum profit is achieved and people assigned is within limit
            if(j >= minProfit && n >= i) {
                return 1;
            } else {
                return 0;
            }
                
        }
        // Base case 2: Number of people assigned exceeds the limit
        else if(n < i) {
            return 0;
        }
            
        
        // If result already calculated, return it
        if(dp[k][i][j] != -1) {
            return dp[k][i][j];
        }
            
        
        int include = 0, notInclude = 0; // Variables to store results with/without including current job
        
        // Recursive call without including current job
        notInclude = solve(k + 1, i, j, n, minProfit, group, profit);
        
        // Recursive call including current job
        include = solve(k + 1, i + group[k], min(j + profit[k], minProfit), n, minProfit, group, profit);
        
        // Store result in dp array and return
        return dp[k][i][j] = (include % mod + notInclude % mod) % mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, 0, 0, n, minProfit, group, profit); // Call solve with initial parameters
    }
};



