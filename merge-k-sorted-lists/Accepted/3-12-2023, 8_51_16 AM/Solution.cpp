// https://leetcode.com/problems/merge-k-sorted-lists

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* node = lists[i];
            while (node != NULL) {
                pq.push(node->val);
                node = node->next;
            }
        }

        if (pq.empty()) {
            return NULL;
        }

        ListNode* node = new ListNode(pq.top());
        pq.pop();
        ListNode* head = node;

        while (!pq.empty()) {
            node->next = new ListNode(pq.top());
            pq.pop();
            node = node->next;
        }

        return head;
    }
};