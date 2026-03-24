#include<iostream>
using namespace std;
#define maxnum 100
class queun{
private:
int arr[maxnum];
int count=0;
int front=0;
int rear=-1;
public:
bool retrieve(int &num) const;
bool empty() const;
bool full() const;
bool push(int num);
bool pop();
};
bool queun ::full() const{
if(count==maxnum)
return true;
return false;
}
bool queun::empty() const{
    if(count==0)
    return true;
    return false;
}
bool queun::retrieve(int &num)const{
if(count==0)
return false;
num=arr[front];
return true;
}
bool queun::push(int num){
    if(count==maxnum)
    return false;
    rear=(rear+1)%maxnum;
    
    arr[rear]=num;
    count++;
    return true;
}
bool queun::pop(){
    if(count==0)
    return false;
    front=(front+1)%maxnum;
    count--;
    return true;
}
int main(){
int num; queun q1;
while(cin>>num&&num!=-1){
   
    q1.push(num);
}
while(!q1.empty()){
    int x;
    q1.retrieve(x);
    q1.pop();
    cout<<x<<" ";
}
    return 0; 
}