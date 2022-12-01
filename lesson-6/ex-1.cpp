#include<iostream>
using namespace std;
class NumericalRelations
{
    private:
        int a, b;
    public:
        NumericalRelations(int a1,int b1){this->a=a1;this->b=b1;}
        int max(){return a>b?a:b;}
        int min(){return a<b?a:b;}
        float avg(){return (a+b)/2.0;}
};
int main()
{
    int c,d;
    c=577;
    d=420;
    NumericalRelations Nr(c,d);
    cout<<Nr.max()<<endl<<Nr.min()<<endl<<Nr.avg();
}