// https://leetcode.com/problems/queue-reconstruction-by-height

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(b[0] == a[0]) {
                    return a[1] - b[1];
                }
                return b[0] - a[0];
            }
        });

        List<int[]> result = new ArrayList<>();

        for(int[] p : people) {
            result.add(p[1], p);
        }

        int n = people.length;
        return result.toArray(new int[n][2]);

    }
}