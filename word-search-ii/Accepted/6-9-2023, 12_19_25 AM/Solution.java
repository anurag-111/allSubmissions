// https://leetcode.com/problems/word-search-ii

public class Solution {
    public class TrieNode {
        public boolean isWord = false; // Flag to indicate if the node represents a complete word
        public TrieNode[] children = new TrieNode[26]; // Array of child nodes for each character

        public TrieNode() {
        }
    }

    TrieNode root = new TrieNode(); // Root node of the trie
    boolean[][] visited; // 2D array to track visited cells in the board

    public List<String> findWords(char[][] board, String[] words) {
        Set<String> result = new HashSet<>(); // Set to store unique words found
        visited = new boolean[board.length][board[0].length]; // Initialize visited array with board dimensions

        addToTrie(words); // Add words to the trie

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (root.children[board[i][j] - 'a'] != null) {
                    // If the current cell has a starting character in the trie, perform search
                    search(board, i, j, root, "", result);
                }
            }
        }

        return new LinkedList<>(result); // Convert the set to a list and return
    }

    // Add words to the trie data structure
    private void addToTrie(String[] words) {
        for (String word : words) {
            TrieNode node = root;
            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                if (node.children[ch - 'a'] == null) {
                    // If the current character doesn't have a child node, create a new one
                    node.children[ch - 'a'] = new TrieNode();
                }
                node = node.children[ch - 'a']; // Move to the child node
            }
            node.isWord = true; // Mark the last node as a valid word
        }
    }

    // Search for words starting from a specific cell in the board
    private void search(char[][] board, int row, int col, TrieNode node, String word, Set<String> result) {
        // Base cases for terminating the search
        if (row >= board.length || row < 0 || col >= board[row].length || col < 0 || visited[row][col]
                || node.children[board[row][col] - 'a'] == null) {
            return; // Terminate the search
        }

        visited[row][col] = true; // Mark the cell as visited
        node = node.children[board[row][col] - 'a']; // Move to the next trie node
        if (node.isWord) {
            result.add(word + board[row][col]); // Add the word to the result set
        }

        // Recursive calls for exploring adjacent cells
        search(board, row - 1, col, node, word + board[row][col], result); // Up
        search(board, row + 1, col, node, word + board[row][col], result); // Down
        search(board, row, col - 1, node, word + board[row][col], result); // Left
        search(board, row, col + 1, node, word + board[row][col], result); // Right

        visited[row][col] = false; // Reset the visited flag for backtracking
    }
}
