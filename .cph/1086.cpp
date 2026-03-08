#include<iostream>
#include<vector>
using namespace std;
typedef struct Node
{ int value;
struct Node *next;
}NODE;
void deletevalue (NODE* &head,NODE* &tail,int value){
   while(head!=NULL&&head->value==value){
    NODE*temp=head;
    head=head->next;
    delete temp;
   }
    if(head==NULL) {
tail=NULL;
return;
    }
NODE *prev=head;
    NODE* curr=head->next;
    while(curr!=NULL){
        if(curr->value==value){
            prev->next=curr->next;
            if(curr==tail){
                tail=prev;
            }delete curr;
            curr=curr->next;
        }else{prev=curr;
        curr=curr->next;
    }
}
}
void print(NODE*&head){
    NODE *p=head;
    while(p){
        cout<<p->value<<" ";
        p=p->next;
    }
}
int main(){
int T;
cin>>T;
int cnt=0;
while(T--){
    cout<<"case #"<<cnt++<<":"<<endl;
    int n;
    cin>>n;
    NODE *head=NULL;
    NODE *tail=NULL;
    for(int i=0;i<n;i++){  
        NODE *p=new NODE;
        cin>>p->value;
        p->next=NULL;
   if(head==NULL){
    head=p;
    tail=p;
   }else{
 tail->next=p;
 tail=p;
   }
    }
    int v;
    cin>>v;
deletevalue(head,tail,v);
print(head);
cout<<endl;
}
return 0;
}
