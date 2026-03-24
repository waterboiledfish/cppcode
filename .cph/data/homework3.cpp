#include<iostream>
#include<string>
using namespace std;
#define maxnum 1000
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
bool push(int member);
bool pop();
int size()const;
bool inqueun(int num);
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
bool queun::retrieve(int  &num)const{
if(count==0)
return false;
num=arr[front];
return true;
}
bool queun::push(int member){
    if(count==maxnum)
    return false;
rear=(rear+1)%maxnum;
arr[rear]=member;
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
bool queun::inqueun(int num){
    int pos=front;
    for(int i=0;i<count;i++){
        if(arr[pos]==num){
            return true;
        }
        pos=(pos+1)%maxnum;
    }return false;
}
int main (){
int cases=1;
int t;

while(cin>>t&&t!=0){
    cout<<"Scenario #"<<cases++<<endl;
string s;
queun teamlist;
queun everyteam[12];
while(cin>>s&&s!="STOP"){
if(s=="ENQUEUE"){
    int num,mem;
    cin>>num>>mem;
    if(!teamlist.inqueun(num))
    teamlist.push(num);
    everyteam[num-1].push(mem);
}else if(s=="DEQUEUE"){
    int loc;
    int num;
    teamlist.retrieve(loc);
everyteam[loc-1].retrieve(num);
cout<<num<<endl;
everyteam[loc-1].pop();
if(everyteam[loc-1].empty()){
    teamlist.pop();
}
}
}cout<<endl;
    }
    return 0;
}