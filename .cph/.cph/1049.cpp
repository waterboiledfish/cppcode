#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
int main(){
    int T;
    cin>>T;
    int cnt=0;
    while(T--){
        int n;
        cin>>n;
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            v1.push_back(num);
        }
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            v2.push_back(num);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),[](const int a,const int b){
            return a>b;
        });
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v1[i]*v2[i];
        }
        cout<<"case #"<<cnt++<<":"<<endl<<sum<<endl;
    }
    return 0;
}