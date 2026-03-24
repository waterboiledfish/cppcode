#include<iostream>
#include<vector>
using namespace std;


int main(){
    int T;
    cin>>T;
    int cases=0;
    while(T--){
        cout<<"case #"<<cases++<<":"<<endl;
        int num;
        cin>>num;
        int cnt=0;
        for(int k=1;2*k+1<=num;k++){
            if(num%(2*k+1)==0)
cnt++;
        }
        cout<<cnt<<endl;
    }
}