#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
using namespace std;
typedef struct rOom{
int id,dis;
}room;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
int n;

while(cin>>n){
    int cases;
cin>>cases;
room rm[cases];
room able[cases];
int cnt=0;
for(int i=0;i<cases;i++){
    int r,c;
    cin>>rm[i].id>>rm[i].dis>>r>>c;
  char arr[r+2][c+2];
    memset(arr,'0',sizeof(arr));
    for(int x=1;x<=r;x++){
        string s;
        cin>>s;
        for(int y=1;y<=c;y++){
            arr[x][y]=s[y-1];
        }
    }
    bool haveseat=false;
    for(int x=1;x<=r;x++){
        for(int y=1;y<=c;y++){
            if(arr[x][y]=='0'&&arr[x-1][y]=='0'&&arr[x][y-1]=='0'&&arr[x][y+1]=='0'){
                haveseat=true;
                able[cnt++]=rm[i];
                break;
            }
        }if(haveseat)
        break;
    }
}
if(cnt==0){
    cout<<"Bad Luck,Rocker!"<<endl;
    continue;
}else {
sort(able,able+cnt,[](const room a1,const room a2){
    return a1.dis<a2.dis;
});
cout<<able[0].id<<endl;
}}
    return 0;
}