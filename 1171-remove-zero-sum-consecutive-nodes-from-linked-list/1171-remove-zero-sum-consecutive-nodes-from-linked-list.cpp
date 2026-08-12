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
    ListNode* removeZeroSumSublists(ListNode* head) {

        // prefix sum + hashmap

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*>mp;

        ListNode* curr = dummy;

        int prefix = 0;

        while(curr != nullptr){
            prefix = prefix + curr->val;
            mp[prefix] = curr;
            curr = curr->next;
        }

        curr = dummy;
        prefix =0;

        while(curr != nullptr){
            prefix = prefix + curr->val;
            curr->next = mp[prefix]->next;
            curr = curr->next;
        }

        return dummy->next;
        
    }
};