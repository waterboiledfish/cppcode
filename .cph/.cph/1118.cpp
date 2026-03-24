#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include<algorithm>
int main(){
int n,s;
set<int>s;
vector<int>v;
int sum=0;
for(int i=0;i<n;i++){
int num;
cin>>num;
sum+=num;
    v.push_back(num);
}sort(v[0],v[n-1]);
vector<int >v1;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int a=v[i]+v[j];
        v1.push_back(a);
    }
}int len=n*(n-1)/2;
sort(v[0],v[len-1]);

    return 0;
}