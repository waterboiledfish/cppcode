#include<iostream>
using namespace std;
int main(){
long long n;
while(cin>>n){
    long long res=1;
    long long up=n*(n-1)*(n-2)*(n-3);
    long long down=24;
    res=up/down;
    cout<<res<<endl;
}

}