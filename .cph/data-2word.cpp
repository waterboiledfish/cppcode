#include<iostream>
using namespace std;
#define maxnum 100
class stack{
private:
int arr[maxnum];
int count;
public:
stack():count(0){};
void clear();
bool full () const;
bool empty() const;
int sizes() const;
bool push(int num);
bool pop();
bool top(int *ptr) const;
};

void stack:: clear(){
    count=0;
}
bool stack:: full() const{
    if(count==maxnum)
    return true;
    return false;
}
bool stack::empty() const{
return count==0;
}
int stack:: sizes() const{
return count;
}
bool stack::push(int num){
 if(full()){
    return false;
 }
    arr[count++]=num;
    return true;
 
}
bool stack:: pop(){
    if(empty()){
        return false;
    }
        count--;
        return true;
    
}bool stack::top(int *ptr) const{
    if(empty()){
        return false;
    }
        *ptr=arr[count-1];
        return true;
    
}

int main(){
stack s1;
int num=0;
int putout;
while(cin>>num&&num!=-1)
s1.push(num);
while(s1.top(&putout)){
    s1.pop();
    cout<<putout<<" ";
}
    return 0;
}