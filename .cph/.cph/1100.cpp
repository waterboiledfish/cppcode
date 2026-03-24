#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long num;
        long long res;
        cin>>num;
        res=num;
        long long extra=0;
        while(num>=3){
           extra++;
            num-=2;
        }
        res+=extra;
        cout<<res<<endl;
    }
    return 0;
}