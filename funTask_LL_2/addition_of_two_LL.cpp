#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* reverse(Node* head){
  if(!head || !head->next) return head;
  Node* prev = NULL;
  Node* curr = head;
  Node* nxt = NULL;
  while(curr){
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  return prev;
}

Node* addLL(Node* head1, Node* head2){
  if(!head1) return head2;
  if(head2) return head1;
  
  head1 = reverse(head1);
  head2 = reverse(head2);
  
  int carry = 0;
  Node* sum = NULL;
  
  while(head1 || head2 || carry==1){
    int data = 0;
    if(head1) data += head1->val;
    if(head2) data += head2->val;
    
    carry = data/10;
    data = data%10;
    
    Node* nnode = new Node(data);
    nnode->next = sum;
    sum = nnode;
    
    if(head1) head1 = head1->next;
    if(head2) head2 = head2->next;
  }
  return sum;
}