// https://leetcode.com/problems/detect-squares

class DetectSquares {

private:
    map<pair<int, int>, int> pointCounts;

public:
    DetectSquares() {
        //Constructor
    }
    
    void add(vector<int> point) {
        pair<int, int> coordinates = make_pair(point[0], point[1]);
        pointCounts[coordinates]++;

    }
    
    int count(vector<int> point) {
        int squareCount= 0;
        int x = point[0];
        int y = point[1];

        for(auto it : pointCounts) {
            pair<int, int> coordinates = it.first;
            int px = coordinates.first;
            int py = coordinates.second;

            if(px != x && py != y && (abs(y - py) == abs(px - x))) {
                int f1 = pointCounts[coordinates];
                int f2 = pointCounts[{px, y}];
                int f3 = pointCounts[{x, py}];
                squareCount += f1 * f2 * f3;
            }
        }
        return squareCount;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */