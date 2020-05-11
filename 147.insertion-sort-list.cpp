/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    void print(ListNode * x){
        while(x!= NULL){
            cout << x->val << ' ';
            x= x->next;
            
        }
        cout << endl;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans =NULL;
        ListNode* temp,*a,*prev;
        while(head!=NULL){
            // print(ans);
            temp=head;
            head = head->next;
            a = ans;
            prev =NULL;
            while(a!=NULL && temp->val > a->val){
                prev = a;
                a = a->next;
            }
            temp->next = a;
            if(prev == NULL){
                ans = temp;
                continue;
            }
            prev->next = temp;
        }
        return ans;
    }
};
// @lc code=end

