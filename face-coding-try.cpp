#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define pi 3.14159265
class circle {
public:
    circle(double r) : r(r) {}
    double area();
    double perimeter();
private:
    double r;
};
class rectangle {
public:
    rectangle(double a, double b) : a(a), b(b) {}
    double area();
    double perimeter();
private:
    double a, b;
};
class triangle {
public:
    triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double area();
    double perimeter();
private:
    double a, b, c;
};
int main() {
int T;
int cnt=0;
cin >>T;
while(T--){
    int n;
    cin>>n;
    cout<<"case #"<<cnt++<<":"<<endl;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        if(name=="Circle"){
            double r;
            cin>>r;
            circle c(r);
     
            cout<<"Circle "<<c.area()<<" "<<c.perimeter()<<endl;
        }
        else if(name=="Rectangle"){
            double a,b;
            cin>>a>>b;
            rectangle re(a,b);
          
            cout<<"Rectangle "<<re.area()<<" "<<re.perimeter()<<endl;
        }
        else if(name=="Triangle"){
            double a,b,c;
            cin>>a>>b>>c;
            triangle t(a,b,c);
       
            cout<<"Triangle "<<t.area()<<" "<<t.perimeter()<<endl;
        }
    }
}
    return 0;
}

double circle::perimeter(){
    return 2*pi*r;
}
double circle::area(){
    return pi*r*r;
}double rectangle::perimeter(){
    return 2*(a+b);
}double rectangle::area(){
    return a*b;
}double triangle::perimeter(){
    return a+b+c;
}double triangle::area(){
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}