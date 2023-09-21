// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = 0, average = 0;
        for(int i = 1; i < (salary.size() - 1); i++) {
            sum += double(salary[i]);
        }
        average = sum / (salary.size() - 2);
        return (average); 
    }
};