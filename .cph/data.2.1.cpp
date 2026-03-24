#include<iostream>
#include<string>
#include<cmath>
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
bool add(stack &s1){
    if(s1.sizes()<2) return false;
    int num1,num2;
    s1.top(&num1); s1.pop();
    s1.top(&num2); s1.pop();
    s1.push(num2+num1);
    return true;
}
bool subtract(stack &s1){
    if(s1.sizes()<2) return false;
    int num1,num2;
    s1.top(&num1); s1.pop();
    s1.top(&num2); s1.pop();
    s1.push(num2-num1);
    return true;
}
bool multiply(stack &s1){
    if(s1.sizes()<2) return false;
    int num1,num2;
    s1.top(&num1); s1.pop();
    s1.top(&num2); s1.pop();
    s1.push(num2*num1);
    return true;
}
bool division(stack &s1){
    if(s1.sizes()<2) return false;
    int num1,num2;
    s1.top(&num1);
    if(num1==0) return false;
    s1.pop();
    s1.top(&num2); s1.pop();
    s1.push(num2/num1);
    return true;
}
bool processChar(char c, stack &s1){
    if(c>='0' && c<='9'){
        s1.push(c-'0');
        return true;
    }
    if(c=='+') return add(s1);
    if(c=='-') return subtract(s1);
    if(c=='*') return multiply(s1);
    if(c=='/') return division(s1);
    return false;
}
void printres(bool valid,stack &s1){
    int res;
    if(valid&&s1.sizes()==1&&s1.top(&res))
    cout<<res;
    else
    cout<<"none";
}
int main(){
    string s;
    stack s1;
    bool valid = true;
    getline(cin,s);
    for(char c:s)
       if(! (valid = processChar(c, s1)))
        break;
    printres(valid,s1);
    return 0;
}