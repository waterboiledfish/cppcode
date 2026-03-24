#include<iostream>
#include<vector>
using namespace std;
int main(){
int T;
cin>>T;
int num=0;
vector<int >v;
for(int i=1;i<=10000;i++){
    v.push_back(i);
}
for(int k=1;k<v.size();k++){
vector<int>v_next;
int step=k+1;
for(int i=0;i<v.size();i++){
    if((i+1)%step!=0)
    v_next.push_back(v[i]);
}
v=v_next;
if(step>v.size())break;
}
while(T--){
    int N;
    cout<<"case #"<<num++<<":"<<endl;
    cin>>N;
    int locate=0;
    int isri=0;
for(int i=0;i<v.size();i++){
    locate++;
    if(v[i]==N){
        isri=1;
        cout<<"Yes "<<locate<<endl;
        break;
    }
}if(!isri)
cout<<"No"<<endl;
}
    return 0;
}