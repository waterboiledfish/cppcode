#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int k,m;
double n;
while(cin>>n>>k>>m){
bool canafford=false;
double sum=n;
double room=270;
    double ratemoney=1+0.01*m,rateroom=1+0.01*k;

    for(int i=2;i<=30;i++){
        n*=ratemoney;
        sum+=n;
        room*=rateroom;
        if(room>sum){
            continue;
        }else {
            canafford=true;
            cout<<i<<endl;
            break;
        }
    }
    if(!canafford){
cout<<"Impossible"<<endl;
    }
}
    return 0;
}