// https://leetcode.com/problems/snakes-and-ladders

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();
        if(n == 0) {
            return 0;
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][0] = true;

        queue<int> q;
        q.push(1);

        int target = n * n;
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int curr = q.front();

                if(curr == target) {
                    return steps;
                }

                q.pop();

                for(int k = 1; k <= 6; k++) {
                    if(curr + k > target) {
                        break;
                    }

                    vector<int> pos = getPositionOf(curr + k, n);

                    int row = pos[0], col = pos[1];

                    if(visited[row][col]) {
                        continue;
                    }
                    visited[row][col] = true;

                    if(board[row][col] != -1) {
                        q.push(board[row][col]);
                    } else {
                        q.push(curr + k);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

private:
    vector<int> getPositionOf(int cur, int n){
        
        int quot = (cur - 1) / n;
        int rem = (cur - 1) % n;
        
        int row = n - quot - 1;
        int col;
        
        if(row % 2 == n % 2) {
            col = n - rem - 1;
        } else {
            col = rem;
        }

        return {row, col};
    }
};