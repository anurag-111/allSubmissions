// https://leetcode.com/problems/palindrome-partitioning

class Solution {
    private List<List<String>> result = new ArrayList<>();

    public List<List<String>> partition(String s) {

        if (s == null || s.length() == 0) {
            return result;
        }
        List<String> partition = new ArrayList<>();    
        findPalindromicPartitions(s, partition);
        return result;
    }

    private void findPalindromicPartitions(String s, List<String> partition) {

        if (s.length() == 0) {
            result.add(new ArrayList<>(partition));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            String prefix  = s.substring(0, i + 1);
            if (isPalindrome(prefix)) {
                String remaining = s.substring(i + 1);
                partition.add(prefix);
                findPalindromicPartitions(remaining, partition);
                partition.remove(partition.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s) {
        int start = 0, end = s.length() - 1;

        while (start <= end) {
            if (s.charAt(start) != s.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}