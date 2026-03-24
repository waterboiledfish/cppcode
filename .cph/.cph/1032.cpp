#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=0;
    long long *arr=(long long *)malloc(sizeof(long long)*n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,[](const long  a,const long b){
        return a>b;
    });
for(int i=0;i<n;i++){
    if(i%3==2)
    continue;

    sum+=arr[i];
}cout<<sum;
    return 0;
}