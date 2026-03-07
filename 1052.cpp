#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
struct answery{
    double ans;
    int rank;
};
int main(){
    int T;
    cin>>T;
    int cnt=0;
    while(T--){
        int K,N;
        cin>>K>>N;
        cout<<"case #"<<cnt++<<":"<<endl;
    vector<int>v(K);
    vector<double>px(K);
    vector<answery>answer(N);
    int sumx=0;
    for(int i=0;i<K;i++){
        cin>>v[i];
        sumx+=v[i];
    }
    for(int i=0;i<K;i++){
        px[i]=((double)v[i]+1.0/K)/(sumx+1); 
    }
    //y部分
    for(int j=0;j<N;j++){
    vector<int>v1(K);
    vector<double>py(K);
    int sum=0;
    double res=0;
    for(int i=0;i<K;i++){
        cin>>v1[i];
        sum+=v1[i];
    }
    for(int i=0;i<K;i++){
        py[i]=((double)v1[i]+1.0/K)/(sum+1);
res+=px[i]*log(px[i]/py[i]);
    }
    if(res<0)res=0;//杜绝-0.0000的情况，这个地方需要debug
answer[j].ans=res;
answer[j].rank=j+1;
    }sort(answer.begin(),answer.end(),[](const answery &a,const answery &b){
    if(fabs(a.ans-b.ans)<=1e-9) return a.rank<b.rank;
else return a.ans<b.ans;
});
for(int i=0;i<N;i++){
    printf("%d %.4lf\n",answer[i].rank,answer[i].ans);
}

    }
return 0;
}

