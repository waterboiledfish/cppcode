#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

long long gcb(int a,int b){
    if(b==0) return a;
    else {
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }return a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        long long len=0;
        long long totallen=s.size()*8;
       for(int i=0;i<s.size();i++){
    long long num=s[i];
len += __builtin_popcount(static_cast<unsigned char>(s[i]));
       }
       long long gcd=gcb(len,totallen);
       cout<<len/gcd<<"/"<<totallen/gcd<<endl;
    }return 0;

}