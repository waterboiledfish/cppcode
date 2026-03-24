#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int m,int n){
    int max=m>=n?m:n;
    int min=m<n?m:n;
    if(m==n)
    return m;
    if(max%min!=0)
    return gcd(min,max%min);
    else return min;
}
int yinzi(int num){
    for(int i=2;i<=num;i++){
        if(num%i==0)
        return i;
    }
}
int main(){
int T;
cin>>T;
int cases=0;

while(T--){
    cout<<"case #"<<cases++<<":"<<endl;
    int m,n;
    cin>>n>>m;

if(gcd(n,m)!=1){
    int num=gcd(n,m);
cout<<"Yes "<<yinzi(num)<<endl;}
else
cout<<"No"<<endl;

}
    return 0;
}