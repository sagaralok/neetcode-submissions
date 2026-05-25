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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 
        ListNode* ans = new ListNode();
        int carrySum = 0;
        ListNode *dummy = ans;
        while(l1!=NULL && l2!=NULL){
            int num1 = l1->val;
            int num2 = l2->val;
            int totalSum = num1+num2+carrySum;
            if(totalSum>=10){
                carrySum = 1;
                totalSum = totalSum%10;
            }
            else{
                carrySum = 0;
            }
            ListNode* newNode = new ListNode(totalSum);
            ans->next = newNode;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int totalSum = l1->val+carrySum;
            if(totalSum>=10){
                carrySum = 1;
                totalSum = totalSum%10;
            }
            else{
                carrySum = 0;
            }
            ListNode* newNode = new ListNode(totalSum);
            ans->next = newNode;
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int totalSum = l2->val+carrySum;
            if(totalSum>=10){
                carrySum = 1;
                totalSum = totalSum%10;
            }
            else{
                carrySum = 0;
            }
            ListNode* newNode = new ListNode(totalSum);
            ans->next = newNode;
            ans = ans->next;
            l2 = l2->next;
        }
        if(carrySum == 1){
            ListNode* newNode = new ListNode(1);
            ans->next = newNode;
            ans = ans->next;
        }
        return dummy->next;
    }
};