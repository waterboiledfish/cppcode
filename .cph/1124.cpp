#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string add(string s1,string s2){
  reverse(s1.begin(),s1.end());
   reverse(s2.begin(),s2.end());
    string smin=s1;
    string smax=s2;
    string res="";
    if(s1.size()>s2.size()){
        smin=s2;
        smax=s1;
    }
    int lenmax=smax.size();
    int lenmin=smin.size();
int val=0;
    for(int i=0;i<lenmin;i++){
res.push_back((smin[i]-'0'+smax[i]-'0'+val)%10+'0');
val=(smin[i]-'0'+val+smax[i]-'0')/10;
}for(int i=lenmin;i<lenmax;i++){
    res.push_back((smax[i]+val-'0')%10+'0');
    val =(smax[i]-'0'+val)/10;
}
if(val>0)
res.push_back(val+'0');
reverse(res.begin(),res.end());    
return res;
}
int main(){
long long n;
cin>>n;
 vector<long long>v(n);
long long min;
 string sum="0";
 long long iszero;
for(int c=0;c<n;c++){
   string num;
cin>>num;
v[c]=stoll(num);
}min=v[0];
long long locate=0;
for(int c=0;c<n;c++)
if(min>v[c]){
min=v[c];locate=c;
}
for(int i=0;i<n;i++){
    if(i==locate)
    continue;
     string num=to_string(v[i]);
    sum= add(sum,num);
}
iszero=v[0];
for(int i=1;i<n;i++)
iszero=iszero^v[i];
if(!!iszero){
    cout<<"-1";
    return 0;
}cout<<sum;
return 0;
}