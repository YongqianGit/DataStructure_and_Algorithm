#include<iostream>
#include<stdio.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class LinkList {
public:
      
      ListNode* createList(int a[], int n)
      {
          ListNode *p=NULL, *head = NULL;
          for(int i=0; i<n; i++){
              if (head == NULL){
                  head = p = new ListNode(a[i]);
              }else{
                  p->next = new ListNode(a[i]);
                  p = p->next;
              }
          }
          return head;
      }
      void printList( ListNode *head )
      {
          while(head!=NULL){
              printf("%d ", head->val);
              head = head->next;
          }
          printf("\n");
      }
};
