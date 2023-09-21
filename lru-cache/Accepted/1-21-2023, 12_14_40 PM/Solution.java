// https://leetcode.com/problems/lru-cache

class LRUCache {
    
    private DoublyLinkedList head;
    private DoublyLinkedList tail;
    private int count;
    private int capacity;
    private Map<Integer, DoublyLinkedList> mp;
    
    public LRUCache(int capacity) {
        
        this.capacity = capacity;
        this.mp = new HashMap();
        
        head = new DoublyLinkedList();
        head.prev = null;
        
        tail = new DoublyLinkedList();
        tail.next = null;
        
        head.next = tail;
        tail.prev = head;
        
    }
    
    public int get(int key) {
        
        int value = -1;
        
        if (mp.containsKey(key)) {
            
            DoublyLinkedList node = mp.get(key);
            moveToHead(node);
            value = node.value;
        }
        
        return value;
    }
    
    public void put(int key, int value) {
     
        if (mp.containsKey(key)) {
            DoublyLinkedList node = mp.get(key);
            node.value = value;
            moveToHead(node);
        } else {
            
            DoublyLinkedList node = new DoublyLinkedList();
            node.key = key;
            node.value = value;
            
            mp.put(key, node);
            addNode(node);
            
            count++;

            if (count > capacity) {
                DoublyLinkedList tail = removeFromTail();
                mp.remove(tail.key);
                count--;
            }
        }
    }
    
    private void addNode(DoublyLinkedList node) {
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }
    
    private void removeNode(DoublyLinkedList node) {
        DoublyLinkedList next = node.next;
        DoublyLinkedList prev = node.prev;
        
        prev.next = next;
        next.prev = prev;
    }
    
    private void moveToHead(DoublyLinkedList node) {
        removeNode(node);
        addNode(node);
    }
    
    private DoublyLinkedList removeFromTail() {
        
        DoublyLinkedList prev = tail.prev;
        removeNode(prev);
        return prev;
    }
    
    class DoublyLinkedList {
    
        int key;
        int value;
        DoublyLinkedList prev;
        DoublyLinkedList next;
    }
}