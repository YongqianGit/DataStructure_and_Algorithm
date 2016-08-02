#include<iostream>
#include<queue>
#include<climits>
#include"LinkList.h"

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
public:
      void list2tree(ListNode *head, TreeNode* &root)
      {
          // queue to store the parent nodes
          queue<TreeNode *> q;
       
          // Base Case
          if (head == NULL)
          {
              root = NULL; // Note that root is passed by reference
              return;
          }
       
          // 1.) The first node is always the root node, and add it to the queue
          root = new TreeNode(head->val);
          q.push(root);
       
          // advance the pointer to the next node
          head = head->next;
       
          // until the end of linked list is reached, do the following steps
          while (head)
          {
              // 2.a) take the parent node from the q and remove it from q
              TreeNode* parent = q.front();
              q.pop();
       
              // 2.c) take next two nodes from the linked list. We will add
              // them as children of the current parent node in step 2.b. Push them 
              // into the queue so that they will be parents to the future nodes
              TreeNode *leftChild = NULL, *rightChild = NULL;
              if (head->val != INT_MIN) {
                  leftChild = new TreeNode(head->val);
                  q.push(leftChild);
              }
              head = head->next;
              if (head)
              {
                  if (head->val != INT_MIN) {
                        rightChild = new TreeNode(head->val);
                        q.push(rightChild);
                  }
                  head = head->next;
              }
       
              // 2.b) assign the left and right children of parent
              parent->left = leftChild;
              parent->right = rightChild;
          }
      }
      void printTree_level_order(TreeNode *root)
      {
          queue<TreeNode*> q;
          q.push(root);
          while (q.size()>0){
              TreeNode* n = q.front();
              q.pop();
              if (n==NULL){
                  cout << "# ";
                  continue;
              }
              cout << n->val << " ";
              q.push(n->left);
              q.push(n->right);
          }
          cout << endl;
      }
      
};
