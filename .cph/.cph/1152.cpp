#include<iostream>
#include<string>
using namespace std;
void solve(int casenum){
    string M;
    int p;
    if (!(cin >> M >> p)) return;
    int dotPos = M.find('.');
    if (dotPos == string::npos) dotPos = M.size();
    string allDigits = "";
    for (char c : M) {
        if (isdigit(c)) allDigits += c;
    }
    int firstsigidx=-1;
    int firstsiginm=-1;
    for(int i=0;i<M.size();i++){
        if(M[i]>='1'&&M[i]<='9'){
            firstsiginm=i;
            break;
        }
    }
    int b=0;
    if(firstsiginm<dotPos){
b=dotPos-firstsiginm-1;
    }else {
        b=dotPos-firstsiginm;
    }int start=0;
    while(start<allDigits.size()&&allDigits[start]=='0')start++;
    string s=allDigits.substr(start);
    string a=s.substr(0,min((int)s.size(),p));
    while(a.size()<p)a+='0';
    if(s.size()>p&&s[p]>='5'){
        int i=p-1;
        while(i>=0&&a[i]=='9'){
            a[i]='0';
            i--;
        }
        if(i>=0)
        a[i]++;
        else{
            a="1"+a.substr(0,p-1);
            b++;
        }
    }
    cout<<"case #"<<casenum<<":"<<endl;
    cout<<a[0];
    if(p>1){
        cout<<"."<<a.substr(1);
    }if(b!=0){
        cout<<"F"<<b;
    }cout<<endl;
}
int main(){
    int T;
    cin>>T;
    cin.ignore();
for(int i=0;i<T;i++){
    solve(i);
}return 0;
}