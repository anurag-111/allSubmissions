// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
private: 
    map<int, int> map;

public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int sum = 0;
        
        for(auto it = map.begin(); it != map.end(); it++) {
            sum += it->second;

            if(sum > 1) {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true; 

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */