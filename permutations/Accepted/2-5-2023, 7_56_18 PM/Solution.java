// https://leetcode.com/problems/permutations

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> permutation = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        boolean[] used = new boolean[nums.length];      //To make sure each element is used once, we establish boolean[] used.

        findPermutation(nums, permutation, result, used);

        return result;
    }

    private void findPermutation(int[] nums, List<Integer> permutation, List<List<Integer>> result, boolean[] used) {
        if (permutation.size() == nums.length) {        // If we exhausted the current branch, currResult.size() == nums.length, we will backtrack.
            result.add(new ArrayList<>(permutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (used[i] == true) {                     
                continue;
            }
            used[i] = true;
            permutation.add(nums[i]);
            findPermutation(nums, permutation, result, used);
            permutation.remove(permutation.size() - 1);
            used[i] = false;
        }
    }
}