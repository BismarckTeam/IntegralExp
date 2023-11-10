#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 1/x;
}

int main()
{
    double left=1;
    double right=2.71;
    double h=0.01;
    double sum=0;
    for (double z=left; z<=right; z=z+h)
    {
        double x1=z;
        double x2=z+h;
        double x3=z+2*h;
        double y1=f(x1);
        double y2=f(x2);
        double y3=f(x3);

        double k=pow((y1-y2)/(y3-y2),1/h);
        double b=(y1-y2)/(pow(k,x1)-pow(k,x2));
        double c=y2-b*pow(k,x2);

        cout << k << " " << b << " " << c << endl;

        double high=b/log(k)*pow(k,x3)+c*x3;
        double low=b/log(k)*pow(k,x1)+c*x1;

        sum=sum+high-low;
    }
    sum=sum/2;
    cout << sum << endl;
    return 0;
}
