#include<iostream>
#include<set>
#include <cmath>
#include<algorithm>
#define pi 3.14159265
using namespace std;
typedef struct LOCATION{
    double len;
    double angle;
    double x;
    double y;
}located;
int main(){
int T;
cin>>T;
int num=0;
while(T--){
    int N;
    cin>>N;
    cout<<"case #"<<num++<<":"<<endl;
  located s1[N];
    for(int i=0;i<N;i++){
        double x,y;
        cin>>x>>y;
    s1[i].x=x;
        s1[i].y=y;
s1[i].len=sqrt(x*x+y*y);
s1[i].angle=atan2(y,x);
while(s1[i].angle<0){
    s1[i].angle=s1[i].angle+pi*2;
}
    }
sort(s1,s1+N,[]( located s2, located s3){
if (abs(s2.angle-s3.angle)>0.000000001) return s2.angle<s3.angle;
if(abs(s2.len-s3.len>0.000000001))return s2.len>s3.len;
else return s2.len>s3.len;
});
for(int i=0;i<N;i++){
printf("(%.4lf,%.4lf)\n",s1[i].len,s1[i].angle);
}
}

    return 0;
}