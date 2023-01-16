#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

struct compare{
  bool operator() (Node* &n1, Node* &n2){
    return a->val > b->val;
  }
}

Node* mergeKLL(vector<Node*> lists){
  priority_queue<Node*, vector<Node*>,compare> minh;
  for(int i=0; i<n; i++){
    if(lists[i]) minh.push(arr[i]);
  }
  
  Node* dummy = new Node(-1);
  Node* temp = head;
  
  while(minh.size() > 0){
    Node* p = minh.top();
    minh.pop();
    temp->next = p;
    temp = temp->next;
    if(p->next) minh.push(p->next);
  }
  return dummy->next;
}