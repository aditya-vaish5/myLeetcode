/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        if (n == 0)
        {
            return head;
        }
        k = k % n;
        if(k==0){
            return head;
        }
        temp = head;
        for (int i = 0; i < n - k - 1; i++)
        {
            temp = temp->next;
        }
        ListNode *kt = temp->next;
        temp->next = NULL;
        temp = kt;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        return kt;
    }
};
// @lc code=end
