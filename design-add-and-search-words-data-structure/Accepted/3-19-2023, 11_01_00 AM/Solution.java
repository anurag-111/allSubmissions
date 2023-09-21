// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
    
    private TrieNode root;
    
    public WordDictionary() {
        root = new TrieNode();    
    }
    
    public void addWord(String word) {
        
        TrieNode cur = root;
        
        for (char ch : word.toCharArray()) {
            int index = (int)(ch - 'a');
            
            if (cur.children[index] == null) {
                cur.children[index] = new TrieNode();
            }
            
            cur = cur.children[index];
        }
        cur.isEndOfWord = true;
    }
    
    public boolean search(String word) {
        return findWord(0, word, root);
    }
    
    private boolean findWord(int pos, String word, TrieNode root) {
        
        if (pos == word.length()) {
            return root.isEndOfWord;
        }
        
        char ch = word.charAt(pos);
        
        if (ch != '.') {
            int index = (int)(ch - 'a');
            if (root.children[index] != null) {
                return findWord(pos + 1, word, root.children[index]);
            }
            
            return false;
        } else {
            
            for (int i = 0; i < 26; i++) {
                if (root.children[i] != null && findWord(pos + 1, word, root.children[i])) {
                    return true;
                }
            }
            
            return false;
        }
    }
    
    private class TrieNode {
        
        private TrieNode[] children;
        private boolean isEndOfWord;
        
        public TrieNode() {
            children = new TrieNode[26];
            isEndOfWord = false;
        }
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */