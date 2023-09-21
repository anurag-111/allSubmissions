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
        int current_fleet_time = 0;
        for(auto x : mymap) {
            if(x.second > current_fleet_time) {      // current car does not belong to the previous fleet as 
                fleet++;                             // it reaches the target desitnation late. 
                current_fleet_time = x.second;       // Therefore, create a new fleet for the current car
                }
        }
        return fleet;
    }
};