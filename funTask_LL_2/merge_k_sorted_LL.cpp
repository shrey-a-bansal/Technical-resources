#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* merge2LL(Node* l1, Node* l2){
  if(!l1) return l2;
  if(!l2) return l1;
  Node* nnode;
  if(l1->val < l2->val){
    nnode = l1;
    nnode->next = merge2LL(l1->next,l2);
    return nnode;
  }
  else{
    nnode = l2;
    nnode->next = merge2LL(l1,l2->next;
    return nnode;
  }
}

Node* mergekLL(vector<Node*> &lists){
  int n = lists.size();
  if(n==0) return NULL;
  for(int i=1; i<n; i++) lists[0] = mergekLL(lists[0],lists[i]);
  return lists[0];
}