#include<iostream>
using namespace std;
#define maxnum 50
class deck{
private:
char arr[50];
int count=0;
int front=0;
int rear=-1;
public:
bool append_front(char &num);
bool append_rear(char &num);
bool serve_front();
bool serve_rear();
bool retrieve_front(char &num)const;
bool retrieve_rear(char &num)const;
int size()const;
bool empty()const;
bool full()const;
};
int deck::size()const{
    return count;
}
bool deck::append_front(char &num){
    if(count==maxnum)
    return false;
    front=(front-1)%maxnum;
    arr[front]=num;
    count++;
    return true;
}
bool deck:: append_rear(char &num){
    if(count==maxnum)
    return false;
    rear=(rear+1)%maxnum;
    arr[rear]=num;
    count++;
    return true;
}
bool deck::empty()const{
if(count==0)
return true;
return false;
}bool deck::full()const{
    if(count==maxnum)
return true;
return false;
}bool deck::retrieve_front(char &num)const{
if(count==0)
return false;
num=arr[front];
return true;
}
bool deck::retrieve_rear(char &num)const{
    if(count==0)
    return false;
    num=arr[rear];
    return true;
}bool deck::serve_front(){
    if(count==0)
    return false;
    front=(front+1)%maxnum;
    count--;
    return true;
}
bool deck::serve_rear(){
    if(count==0)
    return false;
    rear=(rear-1+maxnum)%maxnum;
    count--;
    return true;
}
int main(){
int n;
cin>>n;
char c;
deck d1;
int cnt=0;
while(cin>>c){
    if(!d1.full())
 d1.append_rear(c);
 else {
d1.serve_front();
d1.append_rear(c);
 }
 cnt++;
}
int allow=n<=cnt?n:cnt;
while(allow--){
    char res;
    d1.retrieve_rear(res);
    d1.serve_rear();
    cout<<res<<" ";
}
    return 0;
}