#include<bits/stdc++.h>
using namespace std;
typedef struct birth{
    int year;
    int month;
    int day;
}Birth;
typedef struct link{
    Birth b;
    struct link* next;
}Link;
typedef struct myQueue{
    Link* f;
    Link* r;
}MyQueue;
MyQueue q[32];
void link(Link* head,int cnt){
    Link* tail = head;
    while(tail->next!=NULL){
        int sortIndex;
        if(cnt==0){
            sortIndex=tail->next->b.day;
        }else if(cnt==1){
            sortIndex=tail->next->b.month;
        }else{
            sortIndex=(tail->next->b.year)-1999;
        }
        if(q[sortIndex].f==NULL){
            q[sortIndex].f = tail->next;
            q[sortIndex].r = tail->next;
        }else{
            q[sortIndex].r->next = tail->next;
            q[sortIndex].r = q[sortIndex].r->next;
        }
        tail = tail->next;
    }
    tail = head;
    for(int i=31;i>0;i--){
        if(q[i].f!=NULL){
            tail->next = q[i].f;
            tail = q[i].r;
            tail->next = NULL;
        }
        q[i].f=NULL;
        q[i].r=NULL;
    }
}
void radixSort(Link* head){
    for(int i=0;i<3;i++){
        link(head,i);
    }
}
int main(){
    int n=10;
    Link* head = (Link*)malloc(sizeof(Link));
    head->next = NULL;
    Link* thead = head;
    for(int i=1;i<32;i++){
        q[i].f=NULL;
        q[i].r=NULL;
    }
    for(int i=0;i<n;i++){
        Link *t = (Link*)malloc(sizeof(Link));
        t->b.year = 2000 + rand() % ( 10 ) ;
        t->b.month = 1 + rand() % ( 12 ) ;
        t->b.day = 1 + rand() % ( 31 ) ;
        t->next = NULL;
        thead->next = t;
        thead = thead->next;
    }
    thead = head;
    while(thead->next!=NULL){
        cout<<thead->next->b.year<<" "<<thead->next->b.month<<" "<<thead->next->b.day<<endl;
        thead = thead->next;
    }
    cout<<"-----------"<<endl;
    radixSort(head);
    thead = head;
    while(thead->next!=NULL){
        cout<<thead->next->b.year<<" "<<thead->next->b.month<<" "<<thead->next->b.day<<endl;
        thead = thead->next;
    }
}
