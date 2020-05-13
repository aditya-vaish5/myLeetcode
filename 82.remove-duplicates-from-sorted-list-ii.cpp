/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
        ListNode *t = head->next, *pastNode, *ans = new ListNode(0), *rem = ans;
        int prev = head->val;
        int count = 1;
        while (t != NULL)
        {
            while (t != NULL && t->val == prev)
            {
                t = t->next;
                count++;
            }
            if (count == 1)
            {
                ans->next = new ListNode(prev);
                ans = ans->next;
            }
            cout << prev << ' ' << count << endl;
            count = 0;
            if (t != NULL)
            {
                prev = t->val;
                count = 1;
                t = t->next;
            }
        }
        if(count == 1){
            ans->next = new ListNode(prev);
        }
        return rem->next;
    }
};
// @lc code=end
