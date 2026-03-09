#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(){
string s;
while(getline(cin,s)){
  
    int totalnum=(int)s.length();
     vector <int> rank(totalnum);
     rank[0]=0;

    for(int i=0,j=i+1;i<totalnum-1;i++,j++){
        
            if(s[j]>s[i]){
               rank[j]=rank[i]-1;
            }           
             else if(s[j]<s[i]){
                 rank[j]=rank[i]+1;
            }else{
               rank[j]=rank[i];
            }
        
    }   int minR=rank[0],maxR=rank[0];
    for(int i=0;i<totalnum;i++){
       minR= rank[i]<minR?rank[i]:minR;
       maxR= rank[i]>maxR?rank[i]:maxR;
    } 
        int rows = maxR - minR + 1;
        for(int r=minR;r<=maxR;r++){
            string line(totalnum,' ');
            for(int col=0;col<totalnum;col++){
                if(rank[col]==r)
                    line[col]=s[col];
            }
            while(!line.empty()&&line.back()==' ')
                line.pop_back();
            cout<<line<<endl;
        }
}

    return 0;
}