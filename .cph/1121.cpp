#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int main(){

int T;
cin>>T;
int cases=0;
while(T--){
int n,m;
cout<<"case #"<<cases++<<":"<<endl;
cin>>n>>m;
vector <int>v1(n);
multiset <long long>s2;
vector<long long> v(n*(n+1)/2);
for(int i=0;i<n;i++){
    cin>>v1[i];
}
for(int i=0;i<n;i++){
   long long num=0;
    for(int j=i;j<n;j++){
num+=v1[j];
s2.insert(num);
    }
}
 int index0=0;
    for(auto i=s2.begin();i!=s2.end();i++){
        v[index0++]=*i;
    }
   vector <long long>prefix(s2.size()+1,0);
int index=1;
for(auto c:s2){
    prefix[index]=prefix[index-1]+c;
    index++;
}
while(m--){
    int L,U;
    cin>>L>>U;
long long sum=prefix[U]-prefix[L-1];
    cout<<sum<<endl;
}}
return 0;}