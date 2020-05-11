/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *h1=headA,*h2;
        while(h1!=NULL){
            h1=h1->next;
            l1++;
        }
        h2= headB;
        while(h2!=NULL){
            h2=h2->next;
            l2++;
        }
        if(l1 < l2){
            return getIntersectionNode(headB,headA);
        }
        h1 =headA;
        h2 = headB;
        while(l1 != l2){
            h1 =h1->next;
            l1--;
        }
        while(h1){
            if(h1 == h2){
                return h1;
            }
            h1 = h1->next;
            h2 =h2->next;
        }
        return NULL;
    }
};
// @lc code=end

