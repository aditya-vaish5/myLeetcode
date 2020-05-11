/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *t , *mem = head, *prev = NULL;
        while(mem!=NULL && mem->val == val){
            mem =mem->next;
        }
        t=mem;
        while (t)
        {
            if(t->val == val){
                prev->next = t->next;
                t=t->next;
                continue;
            }
            prev = t;
            t = t->next;
        }
        return mem;
    }
};
// @lc code=end
