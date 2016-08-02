#include<iostream>
#include"LinkList.h"

using namespace std;

bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {return true;}
        
        ListNode *slow = head, *fast = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;

            ListNode *tmp_next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp_next;
            
        } //'prev' is head of reversed 1st half
        
        if (fast) { // odd length
            slow = slow->next;
        }
        
        while (slow) {
            if (slow->val != prev->val) {return false;}
            slow = slow->next;
            prev = prev->next;
        }
        
        return true;
    }

int main(int argc, char** argv) {
      int a [] = {1,2,3,2,1};
      LinkList ll;
      ListNode *head = ll.createList(a, 5);
      ll.printList(head);
      cout<<isPalindrome(head)<<endl;
      return 0;
}
