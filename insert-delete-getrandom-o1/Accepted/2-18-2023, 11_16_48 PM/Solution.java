// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {

    /* Initialize your data structure here. */
    
    private List<Integer> arr;
    private HashMap<Integer,Integer>mp;
    
    public RandomizedSet() {
        
        arr = new ArrayList<Integer>();
        mp = new HashMap<Integer,Integer>();
    }
    
    /* Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if(mp.containsKey(val))
            return false;
        
        arr.add(val);
        int index = arr.size()-1;
        mp.put(val,index);
        return true;
    }
    
    /* Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if(!mp.containsKey(val)) 
            return false;
        
        int index = mp.get(val);
        int lstElement = arr.get(arr.size()-1);
        arr.set(index,lstElement);
        arr.remove(arr.size()-1);
        
        mp.put(lstElement,index);
        mp.remove(val);
        return true;
    }
    
    /* Get a random element from the set. */
    public int getRandom() {
        
        Random rand = new Random();
        
        return arr.get(rand.nextInt(arr.size()));
    }
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */