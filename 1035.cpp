//文件排序
//多次比较，最后一行不输出空格转化成第一次开头不输出空格，日后一直开头输出
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
struct files{
    string date;
    string time;
    long long size;
    string name;

};
int main(){
int n;
int isfirst=1;
while(cin>>n&&n!=0){
    vector<files> v;
    string list;
    if(isfirst){
        isfirst=0;
        
    }else{
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        files f;
        cin>>f.date>>f.time>>f.size>>f.name;
        cin.ignore();
        v.push_back(f);
    }
getline(cin,list);
if(list=="LIST /NAME"){
sort(v.begin(),v.end(),[](const files &a,const files &b){
    return a.name<b.name;
});
}else if(list=="LIST /SIZE"){
sort(v.begin(),v.end(),[](const files &a,const files &b){
   if(a.size!=b.size) return a.size<b.size;
  else return a.name<b.name;
});
}else if(list=="LIST /TIME"){
sort(v.begin(),v.end(),[](const files &a,const files &b){
    if(a.date!=b.date) return a.date<b.date;
    if(a.time!=b.time) return a.time<b.time;
  else  return a.name<b.name;
});
}
for(int i=0;i<n;i++){
    printf("%s %s %16lld %s\n",v[i].date.c_str(),v[i].time.c_str(),v[i].size,v[i].name.c_str());
}
}
    return 0;
}



