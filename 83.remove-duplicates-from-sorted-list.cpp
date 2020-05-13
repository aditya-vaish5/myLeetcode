/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *t = head->next, *ans = head;
        head->next=NULL;
        int prev = head->val;
        // ListNode *prevNode = head;
        while (t != NULL)
        {
            if (t->val == prev)
            {
                t = t->next;
            }
            else
            {
                prev = t->val;
                // t = t->next;
                ans->next = t;
                t = t->next;
                // ans = prevNode;
                ans = ans->next;
                ans->next = NULL;
            }
        }
        return head;
    }
};
// @lc code=end
