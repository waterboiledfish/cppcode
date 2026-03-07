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

*******************************************************
//下附上另一种别人的解法
#include <bits/stdc++.h>
const int MAX_K = 11;
const int MAX_N = 201;
using namespace std;
typedef struct _Tset {
	int order, sum; //记录顺序与总和
	double klx; //记录计算得到的KL值
	double label[MAX_K]; //以数组记录:基本数据+1/K
}Tset;
int cmp(const void *a, const void *b) {
	if (fabs(((Tset*)a)->klx - ((Tset*)b)->klx) < 1e-7)
		//KL值相等按输入顺序
		return ((Tset*)a)->order - ((Tset*)b)->order < 0 ? -1 : 1;
	else
		//否则按KL值从小到大
		return ((Tset*)a)->klx - ((Tset*)b)->klx < 0 ? -1 : 1;
}
double KL(Tset *x, Tset *y, int k) { //输入数组指针及长度k
	double kld = 0.0; //初始化KL值
	for (int j = 0; j<k; j++)
		//label已包含1/k，其它按算式计算
		kld += x->label[j] / x->sum *log(x->label[j] / x->sum * y->sum / y->label[j]);
	return kld;
}
 
 
void solve() /* Define function solve() to process one case of the problem    */
{
	int K, N;
	int i, j;
	int t;
	Tset trials[MAX_N]; //以结构体数组记录所有数据
	scanf("%d %d", &K, &N);  double frac_k = 1.0 / K;
	for (i = 0; i <= N; i++) { //包括第一组总共N+1组数据
		trials[i].order = i;
		trials[i].sum = 1;
		for (j = 0; j < K; j++) { //读入并保存每组数据，带1/K
			scanf("%d", &t);  trials[i].label[j] = t + frac_k;
			trials[i].sum += t; //记录总和加1 }
			trials[i].klx = KL(trials, trials + i, K); //计算KL值并记录
		}
	}
	qsort(trials + 1, N, sizeof(Tset), cmp);
	for (i = 1; i <= N; i++)
		printf("%d %.4f\n", trials[i].order, fabs(trials[i].klx));
}
 
void init()  /* Define function init() to do global intialization if needed   */
{
 
}
 
/******************************************************************************/
/*                                                                            */
/*  DON'T MODIFY main() function anyway!                                      */
/*                                                                            */
/******************************************************************************/
 
 
void solve(); /* write function solve() to process one case of the problem    */
 
int main()
{
	int i, t; init();
	std::cin >> t;
	for (i = 0; i<t; i++)
	{
		std::cout << "case #" << i << ":" << std::endl;
		solve();
	}
	return 0;
}////