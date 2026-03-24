#include<iostream>
#include<string>
#include<vector>
using namespace std;
int wrongnum(string s){
    int num=0;
    for(auto c:s){
if(c=='!')
num++;
return num;
    }
}
int main(){
int T;
cin>>T;
int cases=0;
cin.ignore();
while(T--){
string s;
getline(cin,s);
cout<<"case #"<<cases++<<":"<<endl;
if(!wrongnum){
    cout<<"0 0 0 0"<<endl;
}else{
    int num=0;
    int R,B,Y,G;
    int Rloc=-1,Bloc=-1,Yloc=-1,Gloc=-1;
for(int i=0;i<s.length();i++){
    if(s[i]!='!'){
        switch (s[i]){
     case 'R':Rloc=i%4;
    break;
         case 'B':B=i%4;break;
 case 'Y':Y=i%4;break;
  case 'G':Gloc=i%4;break;
    }
}
for(int i=0;i<s.length();i++){
    if(s[i]=='!'){
        if(s[i]==Rloc){
            Rloc++;
        }else if(s[i]==Bloc)
        Bloc++;
        else if(s[i]==Yloc)
        Yloc++;
        else if(s[i]==Gloc)
        Gloc++;
    }
}
}
}

    return 0;
}