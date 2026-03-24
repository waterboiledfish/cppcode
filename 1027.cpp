#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
char str[41][41];
int yvalue(int c3,int c2, int c1,int c0,int x){
    return c3*x*x*x+c2*x*x+c1*x+c0;
}
char * getint(string s){
    int res=0;
    int isnum=0;
    for(auto c:s){
        isnum=0;
        if(c>='0'&&c<='9'){
            isnum=1;
        }
        if(isnum==1){
            res=res*10+c-'0';
        }
    }
    return res;
}
int main(){
string s;
for(int i=0;i<41;i++){
    for(int j=0;j<41;j++){
        str[i][j]='.';
    }
}
for(int i=0;i<41;i++){
    str[i][20]='|';
}
for(int j=0;j<41;j++){
    str[20][j]='-';
}
str[0][20]='^';
str[20][20]='+';
str[20][40]='>';
while(getline(cin,s)){
    int c3,c2,c1,c0;

   size_t pos1= s.find("x^3");
   size_t pos2=s.find("x^2");
    size_t pos3=s.find("x");
    string s3=s.substr(0,pos1);
    string s2=s.substr(pos1+1,pos2);
    string s1=s.substr(pos2+1,s.find("x"));
    string s0=s.substr(s.find("x")+1);
    if(s3==""){
        c3=1;
    }else{
        c3=stoi(s3);
    }    if(s2==""){
        c2=1;
    }else{
        c2=stoi(s2);
    }
    if(s1==""){
        c1=1;
    }else{
        c1=stoi(s1);
    }
    if(s0==""){
        c0=1;
    }else{
        c0=stoi(s0);
}int y=0;
for(int i=0;i<41;i++){
    int y=yvalue(c3,c2,c1,c0,i-20);
    if(y<21&&y>-21){
        str[y+20][i]='*';
    }
}for(int i=0;i<41;i++){
    for(int j=0;j<41;j++){
        cout<<str[i][j];
    }
    cout<<endl;
}
}
}
