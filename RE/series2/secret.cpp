#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int result;
    do
        result = time(0) % 50;
    while ( 0.0 == (double)((long double)result / 50.0) );
    double dbl_4063E8 = (long double)result / 50.0;
    for (int i=0;i<5;i++)
        dbl_4063E8=3.8*dbl_4063E8*(1.0-dbl_4063E8);
    dbl_4063E8=dbl_4063E8*10000;
    cout<<(int)dbl_4063E8<<endl;
}