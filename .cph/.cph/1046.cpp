#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include<vector>
using namespace std;
typedef struct DmA{
string s;
int cnt;
}DNA;
int main(){
long long n;
cin>>n;
cin.ignore();
DNA str;
set<string>s1;
str.cnt=1;
vector<DNA> v;
while(n--){
    getline(cin,str.s);
    int num=s1.size();
s1.insert(str.s);
if(s1.size()-num==1){
    v.push_back(str);
}else if(s1.size()-num==0){
    for(int i=0;i<v.size();i++){
        if(str.s==v[i].s)
        v[i].cnt++;
    }
}
}
sort(v.begin(),v.end(),[](const DNA d1, const DNA d2){
    if(d1.cnt!=d2.cnt)
    return d1.cnt<d2.cnt;
    return d1.s<d2.s;
});
for(int i=0;i<v.size();i++){
    cout<<v[i].s<<endl;
}
    return 0;
}