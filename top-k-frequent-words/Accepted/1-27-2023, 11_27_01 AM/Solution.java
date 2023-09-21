// https://leetcode.com/problems/top-k-frequent-words

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        
        if (words == null) {
            return null;
        }
        
        Map<String, Integer> counts = new HashMap<>();
        
        for (String word : words) {
            counts.put(word, counts.getOrDefault(word, 0) + 1);
        }
        
        PriorityQueue<String> minHeap = new PriorityQueue<>((a, b) -> counts.get(a) != counts.get(b) ? counts.get(a) - counts.get(b) : b.compareTo(a));
        
        for (String word : counts.keySet()) {
            minHeap.add(word);
            
            if (minHeap.size() > k) {
                minHeap.remove();
            }
        }
        
        List<String> result = new ArrayList<>();
        
        while (!minHeap.isEmpty()) {
            result.add(minHeap.remove());
        }
        
        Collections.reverse(result);
        return result;
    }
}