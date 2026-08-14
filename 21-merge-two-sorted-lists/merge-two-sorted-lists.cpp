class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Your original base cases
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        if(list1 != NULL && list2 == NULL){
            return list1;
        }
        if(list1 == NULL && list2 != NULL){
            return list2;
        }
        
        ListNode* tempA = list1;
        ListNode* tempB = list2;
        ListNode* main = NULL;
        ListNode* head = NULL; // We need this to remember where the merged list starts

        // 1. Initialize 'main' and 'head' to avoid the NULL crash
        if(tempA->val <= tempB->val){
            main = tempA;
            tempA = tempA->next;
        } else {
            main = tempB;
            tempB = tempB->next;
        }
        head = main;

        // 2. Your main loop
        while(tempA != NULL && tempB != NULL){
            if(tempA->val <= tempB->val){ 
                main->next = tempA;       // Link the smaller node
                tempA = tempA->next;      // 3. FIXED: Reassign pointer to move forward
            }
            else { 
                main->next = tempB;       // Link the smaller node
                tempB = tempB->next;      // FIXED: Reassign pointer to move forward
            }
            main = main->next;            // 4. FIXED: Move 'main' forward so it's ready for the next loop
        }
        
        // 5. FIXED: No while loops needed here. Just link the rest of whichever list isn't empty.
        if(tempA != NULL){
            main->next = tempA;
        }
        if(tempB != NULL){
            main->next = tempB;
        }
        
        // 6. FIXED: Missing return statement
        return head; 
    }
};