#include<iostream>
using namespace std;
class Rec{
private:
double length;
double width;
public:
void printout();
double printsize();
double printlen();
void SET(int x,int y);
};
void Rec::printout(){
    cout<<length<<" "<<width<<endl;
}
double Rec::printsize(){
    return length*width;
}
double Rec::printlen(){
return 2.0*(length+width);
}
void Rec::SET(int x,int y){
    length=x;
    width=y;
}
int main(){
Rec re1;
re1.SET(4,3);
double num1=re1.printlen();
cout<<num1<<endl;
re1.printout();
double num2=re1.printsize();
cout<<num2<<endl;
    return 0;
}