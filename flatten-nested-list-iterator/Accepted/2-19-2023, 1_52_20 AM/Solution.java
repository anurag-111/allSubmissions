// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    
    List<Integer> flattenList = null;
    List<NestedInteger> nestedIntegerList = null;
    private int current = 0;
    
    public NestedIterator(List<NestedInteger> nestedList) {
        flattenList = new ArrayList<>();
        nestedIntegerList = nestedList;
        
        for (NestedInteger nestedInteger : nestedIntegerList) {
            helper(nestedInteger);
        }
    }

    @Override
    public Integer next() {
        
        if (hasNext()) {
            return flattenList.get(current++);
        }
        
        return null;
    }

    @Override
    public boolean hasNext() {
        
        return current < flattenList.size();
    }
    
    private void helper(NestedInteger nestedInteger) {
        
        if (nestedInteger.isInteger()) {
                flattenList.add(nestedInteger.getInteger());
        } else {
            for (NestedInteger value : nestedInteger.getList()) {
                helper(value);
            }
        }
        
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */