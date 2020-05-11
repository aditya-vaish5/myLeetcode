/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* , bool> m;
        while(head!=NULL){
            if(m.find(head)!=m.end()){
                return head;
            }
            m[head] =true;
            head = head->next;
        }
        return NULL;
    }
};
// @lc code=end

