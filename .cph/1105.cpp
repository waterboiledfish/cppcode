#include<vector>
#include<iostream>
using namespace std;
int main(){
int T;
cin>>T;
int cnt=0;
while( T--){
    int n;
    cin>>n;
    cout<<"case #"<<cnt++<<":"<<endl;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    long long res=1;
    int isin=0;
   long long times=0;
for(int i=0;i<n;i++){
    if(v[i]==1){
        isin=1;
        times=1;
        
    }
    if(isin&&v[i]==0){
        times++;
    }
    if(v[i]==0&&i+1<n&&v[i+1]==1&&times){
        res*=times;
    }
}
if(!isin)
res=0;
cout<<res<<endl;
}
return 0;
}
