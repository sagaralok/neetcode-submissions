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
    int countNodes(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Total/3 = 2

        int count = countNodes(head);
        count = count/k;

        ListNode* curr = head;
        ListNode* prevTail = NULL;
        ListNode* newHead = NULL;

        while(count>0){

            ListNode* currentHead = curr;
            for(int i = 0;i<k-1;i++){
                curr = curr->next;
            }
            ListNode* nextGroup = curr->next;
            curr->next = NULL;

            ListNode* reverseHead = reverse(currentHead);

            if(newHead==NULL){
                newHead = reverseHead;
            }
            else{
                prevTail->next = reverseHead;
            }

            prevTail = currentHead;
            currentHead -> next = nextGroup;
            curr = nextGroup;

            count--;
        }
        if(newHead == NULL){
            return head;
        }
        return newHead;
    }
};
