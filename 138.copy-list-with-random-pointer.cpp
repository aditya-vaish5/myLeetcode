/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void print(Node * head){
        cout << "printing" <<endl;
        while(head!=NULL){
            cout << head->val << ' ';
            if(head->random != NULL) {
                cout << head->random->val << endl;
            }else{
                cout << " NULL " <<endl;
            }
            head = head->next;
        }
    }
    Node* copyRandomList(Node* h) {
        Node* p,* ans,* head=h;
        if(h ==NULL){
            return NULL;
        }
        while(head!=NULL){
            p =head->next;
            head->next = new Node(head->val);
            head->next->next =p;
            head = p;
        }
        print(h);
        head =h;
        while(head!=NULL){
            p = head->next->next;
            if(head->random!=NULL){
                head->next->random =head->random->next;
            }
            head=p;
        }
        print(h);
        head = h;
        ans = new Node(0);
        Node* q =ans;
        while(head!=NULL){
            p= head->next->next;
            ans->next = head->next;
            ans = ans->next;
            head->next =p;
            head = p;
        }
        print(h);
        print(q);
        return q->next;
    }
};
// @lc code=end

