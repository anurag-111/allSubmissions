// https://leetcode.com/problems/implement-trie-prefix-tree

struct Node {
    
	Node *links[26];
	bool flag = false;

	// Checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	// Creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	// To get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}

	// Setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}

	// Checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};

class Trie {

private:
	Node* root;

public:
	Trie() {

		// Creating new obejct
		root = new Node();
	}

	void insert(string word) {

		// Initializing dummy node pointing to root initially
		Node *node = root;

		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}

			// Moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */