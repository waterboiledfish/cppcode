#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    unsigned int s;
    while(cin>>s){
unsigned int curhig=s&0xffff;
unsigned int curdow=(s>>16)&0xffff;
curdow=~curdow;
curdow=curdow&0xffff;
curhig=curdow^curhig;
curhig=curhig<<16;
unsigned int res=curhig|curdow;
printf("%X\n",res);
    }
    return 0;
}