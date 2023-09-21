// https://leetcode.com/problems/car-fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        map<int, double, greater<int>> mymap; 
        
        //descending order
        for (int i = 0; i < position.size(); i++) {
            mymap[position[i]] = (double) (target - position[i])/ speed[i];
        }
        
        int fleet = 0;
        double current_fleet_time = 0;
        for(auto x : mymap) {
            if(x.second > current_fleet_time) {      // current car does not belong to the previous fleet as 
                current_fleet_time = x.second;       // it reaches the target desitnation late. 
                fleet++;                             // Therefore, create a new fleet for the current car
            }
        }
        return fleet;
    }
};