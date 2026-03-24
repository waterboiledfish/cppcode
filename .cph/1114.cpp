#include<iostream>
#include<set>
#include<vector>
using namespace std;
int isxun(int n){
    while(n%5==0){
        n/=5;
    }while(n%2==0){
        n/=2;
    }if(n%3!=0||n%7!=0)
    return 1;
    else return 0;
}
void yuefen(int &m,int &n){
int max=n,min=m;
int temp=max;
while(max%min!=0){
max=min,min=temp%min;
}
}
int main(){
    int m,n;
    while(scanf("%d/%d",&m,&n)==2){
        double res=m/n;
        yuefen(m,n);
if(!isxun){
cout<<"0"<<endl;
}else{


    
}
    }

    return 0;
}