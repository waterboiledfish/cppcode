#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool issushu(int num){
    for(int i=2;i<num;i++){
        if(num%i==0)
        return false;
    }
    return true;
}
int main(){
int n;
while(cin>>n){
for(int start=n/2;start<n;start++){
    if(issushu(start)&&issushu(n-start)){
        cout<<n-start<<" "<<start<<endl;
        break;
    }
}
}
    return 0;
}