#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* kthFromLast(node* head, int k){
    node* s=head;
    node* f=head;

    for(int i=0; i<k; i++){
        f=f->next;
    }

    while(f!=tail){
        s=s->next;
        f=f->next;
    }

    return s->data;
}