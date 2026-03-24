#include<iostream>
#include<string>
using namespace std;
#define maxnum 1000
class queun{
private:
char arr[maxnum];
int count=0;
int front=0;
int rear=-1;
public:
bool retrieve(char &num) const;
bool empty() const;
bool full() const;
bool push(char num);
bool pop();
int size()const;
};
int queun::size()const{
    return count;
}
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
bool queun::retrieve(char  &num)const{
if(count==0)
return false;
num=arr[front];
return true;
}
bool queun::push(char num){
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
int n;
cin>>n;
cin.ignore();
while(n--){
string s;
queun q1;
queun q2;
string s1;
string s2;
getline(cin,s);
int sizeleft,sizeright;
int pos=0;
int isfound=0;
for(int i=0;i<s.size();i++){
if(s[i]==':'){
    pos=i;
    isfound=1;
    break;
}q1.push(s[i]);
s1+=s[i];
}
if(!isfound){
    cout<<"N"<<endl;
    continue;
}sizeleft=q1.size();
for(int i=pos+1;i<s.size();i++){
    q2.push(s[i]);
    s2+=s[i];
}sizeright=q2.size();
if(sizeleft>sizeright)
cout<<"L"<<endl;
else if(sizeleft<sizeright)
cout<<"R"<<endl;
else if(sizeleft==sizeright&&s1!=s2)
cout<<"D"<<endl;
else if(sizeleft==sizeright&&s1==s2)
cout<<"S"<<endl;
}
    return 0;
}