// https://leetcode.com/problems/longest-consecutive-sequence

int longestConsecutive(vector<int>& nums) {
	if(!size(nums)) return 0;
	sort(begin(nums), end(nums));
	int longest = 0, cur_longest = 1;
	for(int i = 1; i < size(nums); i++) 
		if(nums[i] == nums[i - 1]) continue;
		else if(nums[i] == nums[i - 1] + 1) cur_longest++; // consecutive element - update current streak length
		else longest = max(longest, cur_longest), cur_longest = 1;  // reset current streak length
	return max(longest, cur_longest);
}