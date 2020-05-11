/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
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
    ListNode* reverseList(ListNode* head) {
        ListNode *ans =head,*t =NULL;
        if(head==NULL){
            return ans;
        }
        head =head->next;
        ans->next =NULL;
        while(head){
            t =head->next;
            head->next = ans;
            ans =head;
            head =t;
        }
        return ans;
    }
};
// @lc code=end

