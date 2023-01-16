#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* findIntersection(Node* headA, Node* headB){
  if(!headA || !headB) return NULL;
  Node* t1 = headA;
  Node* t2 = headB;
  while(t1 != t2){
    t1 = t1->next;
    t2 = t2->next;
    if(t1 == t2) return t1;
    if(!t1) t1 = headB;
    if(!t2) t2 = headA;
  }
  return t1;
}