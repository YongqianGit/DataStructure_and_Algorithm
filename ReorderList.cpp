#include<iostream>
#include"LinkList.h"
using namespace std;

void reorderList(ListNode* head) {
        if (!head || !head->next) {return;}
        
        ListNode *slow = head, *fast = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        if (fast) { // odd length
            ListNode *tmp = slow->next;
            slow->next = NULL; //cut off first half's last node
            slow = tmp;
        }
        else {prev->next = NULL;}//cut off first half's last node
        
        prev = NULL;
        while (slow) { // reverse 2nd half
            ListNode *cur_next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = cur_next;
        }// 'prev' is head of reversed 2nd half
        
        while (prev) { // 2nd half is shorter
            ListNode *next1 = head->next, *next2 = prev->next;
            head->next = prev;
            prev->next = next1;
            
            head = next1;
            prev = next2;
        }
        
    }

int main(int argc, char** argv) {
      int a [] = {1,2,3,4,5};
      LinkList ll;
      ListNode *head = ll.createList(a, 5);
      ll.printList(head);
      reorderList(head);
      ll.printList(head);
      return 0;
}
