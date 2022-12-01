#include <iostream>
#include <cmath>
using namespace std;
class WrongBArg : public exception
{
    public:
    string what()
    {
        return "Wrong base of logarithm!";
    }
};
class WrongIArg : public exception
{
    public:
    string what()
    {
        return "Wrong input argument of logarithm!";
    }
};
class Number
{
    public:
        virtual double doubleValue()=0;
};
class Logarithm : public Number
{
    private:
        double base, argument;

    public:
        double doubleValue() { return log(this->argument) / log(this->base); }
        Logarithm(double inputBase, double inputArgument)
        {
            if(inputBase==1||inputBase<=0){throw WrongBArg();}
            if(inputArgument<=0){throw WrongIArg();}
            this->base = inputBase;
            this->argument = inputArgument;
        }

};
void separator(){cout<<"-----------------------------------------\n";}
int main()
{
    int bases[8]={3,1,5,6,2,4096,5,0};
    int argum[8]={8,9,0,3,4096,2,6,0};
    for(int i=0;i<8;i++)
    {
        separator();
        try
        {
            Logarithm* log = new Logarithm(bases[i],argum[i]);
            cout<<log->doubleValue()<<endl;
            delete log;
        }
        catch(WrongIArg e)
        {
            cerr<<e.what()<<endl;
        }
        catch(WrongBArg f)
        {
            cerr<<f.what()<<endl;    
        }
    }
}
