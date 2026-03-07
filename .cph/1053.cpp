#include<iostream>
#include<string>
#include<vector>
#include<set>     
#include<algorithm>
using namespace std;
typedef struct Address{
    string majorcomputer;
    string username;
}address;
int cpm(address a,address b){
    if(a.majorcomputer!=b.majorcomputer) return a.majorcomputer<b.majorcomputer;
    else return a.username>b.username;
}
int main(){
    long long n;
    cin>>n;
    cin.ignore();
    address a[n];
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
      int pos=s.find('@');
        a[i].majorcomputer=s.substr(pos+1);
        a[i].username=s.substr(0,pos);
    }
sort(a,a+n,cpm);
for (size_t i = 0; i < n; i++)
{
    cout << a[i].username << "@" << a[i].majorcomputer << endl;
}

    return 0;
}