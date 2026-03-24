#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool isrun(int num){
if(num%400==0)
return true;
else if(num%100==0)
{return false;}
else if(num%4==0)
return true;
else{
    return false;
}
}
int main(){
    int year;
    cin>>year;
    int give=0,rece=0,cnt=0;
    for(int i=2001;i<=year;i++){
        give+=140;
        if(isrun(i)){
            rece+=700;
            cnt++;
        }
    }
    cout<<cnt<<" "<<give<<" "<<rece;
    return 0;
}