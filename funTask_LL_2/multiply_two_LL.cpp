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

Node* multiplyWithdigit(Node* head, int digit){
  if(digit==0) return NULL;
  
  Node* dummy = NULL;
  Node* curr = head;
  int carry = 0;
  
  while(curr || carry){
    int sum=0;
    if(curr) sum += curr->val * digit;
    sum += carry;
    int digit = sum%10;
    carry = sum/10;
    
    Node* nnode = new Node(digit);
    nnode->next = dummy;
    dummy = nnode;
  }
  return dummy;
}

Node* multiplyLL(Node* head1, Node* head2){
  if(!head1 || !head2) return NULL;
  Node* l1 = head1;
  Node* l2 = head2;
  
  l1 = reverse(l1);
  l2 = reverse(l2);
  
  int carry = 0;
  Node* ans = NULL;
  Node* temp = ans;
  
  while(l2){
    Node* product = multiplyWithDigit(l1,l2->val);
    l2 = l2->next;
    addLL(product,temp);
    temp = temp->next;
  }
  return ans;
}