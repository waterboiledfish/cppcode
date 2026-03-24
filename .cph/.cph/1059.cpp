#include<iostream>
#include<vector>
using namespace std;
int main(){
    bool hasout=false;
    for(int i=1002;i<=9999;i++){
        int a=i/1000;
        int b=(i-a*1000)/100;
        int d=i%10;
        int c=i%100/10;
        a*=a*a*a;
        b*=b*b*b;
        c*=c*c*c;
        d*=d*d*d;
        if(a+b+c+d==i){
        cout<<i<<endl;
        hasout=true;
    }
    }if(!hasout){
        cout<<"no answer";
    }
    return 0;
}