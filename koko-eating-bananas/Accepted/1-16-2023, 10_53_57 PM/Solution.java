// https://leetcode.com/problems/koko-eating-bananas

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = Integer.MIN_VALUE;
        
        for (int val : piles) {
            max = Math.max(val, max);
        }
        
        /**
        * When number of piles == number of hours available, then return 
        * minimum eating speed = max pile size
        **/
        
        // for cases such as:
        // [30,23,15,12,29] where h = 5 
        // therefore k has to be equal to 30 so as to eat 
        // the bananas under h = 5
        
        if (h == piles.length) {
            return max;
        }
        
        int low = 0; // lowest speed at which koko can eat a pile of banana
        int high = max;  // max speed at which koko can eat a pile of banana
        int speed = Integer.MAX_VALUE;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            
            if (isPossible(piles, h, mid)) {
                speed = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return speed;
    }
    
    private boolean isPossible (int[] piles, int h, int sp) {
        int time = 0;
        
        for (int i = 0; i < piles.length; i++) {
            time += (int)Math.ceil((piles[i] * 1.0)/sp);
        }
        
        return time <= h;
     }
}