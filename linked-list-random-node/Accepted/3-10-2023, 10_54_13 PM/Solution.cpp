// https://leetcode.com/problems/linked-list-random-node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int>values;
    Solution(ListNode* head) {
        ListNode *temp = head;
        int i = 0;
        
        while(temp) {
           values.push_back(temp->val);
           temp = temp->next;
        }    
    }

    int getRandom() {
        int n = values.size();
        int i = rand() % n;  // ((N-1)/N)* 1/(N-1) = 1/N
        return values[i];    
    }
};


/*
    i = 1, probability of selecting first node = 1/N

    i = 2, probability of selecting second node = 
           [probability that first node is not selected] * 
           [probability that second node is selected]
           = ((N-1)/N)* 1/(N-1) = 1/N
*/


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */