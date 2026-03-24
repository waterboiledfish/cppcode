#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct syudem{
long long id;
double score;
}stu;
int main(){
    int n;
    cin>>n;
  stu stud[n];
  double s2=0,ave=0;
  double sum=0;

    for(int i=0;i<n;i++){
        cin>>stud[i].id>>stud[i].score;
ave+=stud[i].score/n;
    }
    for(int i=0;i<n;i++){
        s2+=(ave-stud[i].score)*(ave-stud[i].score);
    }s2/=(n-1) ;
double res=sqrt(s2);
    printf("%.2lf %.2lf",ave,res);
    return 0;
}