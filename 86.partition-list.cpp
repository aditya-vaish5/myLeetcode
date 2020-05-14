/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *l = new ListNode(0);
        ListNode *r = new ListNode(0);
        ListNode *t = head, *r1 = r, *l1 = l;
        while (t != NULL)
        {
            if (t->val < x)
            {
                l->next = t;
                l = l->next;
                t = t->next;
                l->next = NULL;
            }
            else
            {
                r->next = t;
                r = r->next;
                t = t->next;
                r->next = NULL;
            }
        }
        t = l1;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next = r1->next;
        return l1->next;
    }
};
// @lc code=end
