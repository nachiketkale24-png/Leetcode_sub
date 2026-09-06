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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* tail = NULL;
        int size = 0;
        while(temp!=NULL){
            tail = temp;
            temp = temp->next;
            size++;
        }
        if(size==0){
            return head;
        }
        tail->next = head;
        k = k%size;
        int n = size - 1 - k; 
        int count = 0;
        temp = head;
        while(count<n){
            temp = temp->next;
            count++;
        }
        ListNode* head1 = temp->next;
        temp->next=NULL;
        return head1;
    }
};