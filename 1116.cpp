#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
void printout(const string &s,int start,string base){
    cout<<base<<endl;
    for (int i=start+1;i<s.size();++i){
        printout(s,i,base+s[i]);
    }
    
}
int main(){
    int T;
    cin>>T;
    int cnt12=0;
      cin.ignore();
    while(T--){
    
        cout<<"case #"<<cnt12++<<":"<<endl;
        set<char> s;
        string s1;
      
       getline(cin,s1);
    
       for(int i=0;i<s1.size();i++)
        s.insert(s1[i]);

    string res="";
    for(auto c=s.begin();c!=s.end();c++){
        res+=*c;
    }
    for(int i=0;i<res.size();++i){
        printout(res,i,string(1,res[i]));
    }
   
    }
    return 0;
}