/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *h)
    {
        if (h == NULL || h->next == NULL)
        {
            return;
        }
        vector<ListNode *> arr;
        ListNode *temp = h;
        while (temp != NULL)
        {
            arr.push_back(temp);
            temp = temp->next;
        }
        int n = arr.size();
        for (int i = 0; i < (n+1 ) / 2; i++)
        {
            cout << i <<endl;
            cout << arr[i] ->val << ' ' << arr[n-i-1]->val << ' '<<arr[i+1]->val << endl;
            if(n-i-1 == i){
                arr[i] ->next =NULL;
                return;
            }
            arr[i]->next = arr[n - i - 1];
            if(n-i-1 == i+1){
                arr[i+1] ->next =NULL;
                return;
            }
            arr[n - i - 1]->next = arr[i + 1];
        }
        arr[n+1/2]->next =NULL;
        return;
    }
};
// @lc code=end
