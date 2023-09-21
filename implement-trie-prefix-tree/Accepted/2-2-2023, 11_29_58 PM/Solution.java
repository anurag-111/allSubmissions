// https://leetcode.com/problems/implement-trie-prefix-tree

// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
    
    private TrieNode root;
    
    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode temp = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int index = (int) (ch - 'a');
            
            if (temp.children[index] == null) {
                temp.children[index] = new TrieNode();
            }
            
            temp = temp.children[index];
        }
        temp.isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        
        TrieNode temp = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int index = (int) (ch - 'a');
            
            if (temp.children[index] == null) {
                return false;
            }
            
            temp = temp.children[index];
        }
        
        return temp.isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);
            int index = (int) (ch - 'a');
            
            if (temp.children[index] == null) {
                return false;
            }
            
            temp = temp.children[index];
        }
        return true;
    }
    
    class TrieNode {
        TrieNode[] children;
        boolean isEndOfWord;
        
        public TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
        
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */