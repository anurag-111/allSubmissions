// https://leetcode.com/problems/merge-k-sorted-lists

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
private:
    struct compare {
        bool operator()(const ListNode* first, const ListNode* second) {
            return first->val > second->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        for (ListNode* head : lists) {
            if (head != NULL) {
                minHeap.push(head);
            }
        }
        
        ListNode* dummy = new ListNode();
        // result list, intially empty
        ListNode* temp = dummy;
        
        while(!minHeap.empty()) {
            
            // remove the minimum element from the minHeap
            ListNode* current = minHeap.top();
            minHeap.pop();
            //attach current node after temp
            temp->next = current;
            //increment temp pointer
            temp = temp->next;
            // if current, then add the next element in the current list to minheap
            if (current->next != NULL) {
                minHeap.push(current->next);
            }
        }
        
        return dummy->next;
    }
};