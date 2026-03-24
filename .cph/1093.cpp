#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool isperfect(int num){
    if(num==1)
    return false;
    vector<int>v (num,0);
    int cnt=0;
    for(int i=1;i<num;i++){
        if(num%i==0){
            v[cnt++]=i;
        }
    }
    int sum=0;
    for(int i=0;i<cnt;i++){
sum+=v[i];
    }return sum==num;
}
int main(){
for(int i=1;i<=4000;i++){
    vector<int> v(i);
    int cnt=0;
    if(isperfect(i)){
        cout<<i<<endl;
        cout<<i<<" its factors are ";
        if(i==1){
            cout<<"1."<<endl;
            continue; 
        }
        for(int j=1;j<i;j++){
            if(i%j==0){
                v[cnt++]=j;
            }
        }
        for(int j=0;j<cnt-1;j++){
cout<<v[j]<<",";
        }cout<<v[cnt-1]<<"."<<endl;
    }
}
}