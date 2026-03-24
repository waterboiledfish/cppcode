#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    int cnt=0;
    while(T--){
        cout<<"case #"<<cnt++<<":"<<endl;
        int num;
        cin>>num;
        int hun=0,wus=0,ers=0,shi=0,wu=0,one=0;
        while(num>=100){
        num-=100;
        hun++;
    }while(num>=50){
        num-=50;
        wus++;
    }while(num>=20){
        num-=20;
        ers++;
    }while(num>=10){
        num-=10;
        shi++;
    
    }while(num>=5){
        num-=5;wu++;
    }while(num>=1){
        num--;
        one++;
    }cout<<hun<<" "<<wus<<" "<<ers<<" "<<shi<<" "<<wu<<" "<<one<<endl;
    }
    return 0;
}