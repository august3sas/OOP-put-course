#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Train
{
    public:
        virtual int CalculateLength()=0;
        virtual double MaxV()=0;
        virtual int CalculateSeats()=0;
        
};
class EMU : public Train //EMU - Electric Multiple Unit 
{
    public:
        string type;
        int nof_wagons;
        int nof_locomotives;
        int nof_seats;
        double maximalVelocity;
        int length;
        
        int CalculateSeats()
        {
           return nof_wagons*24;
        }
        double MaxV()
        {
            return sqrt(nof_locomotives)*104;
        }
        EMU(string t, int n, int l)
        {
            cout<<"New EMU came out of factory!"<<endl;
            this.type=t;
            this.nof_wagons=n;
            this.nof_locomotives=l;
            this.nof_seats=CalculateSeats();
            this.maximalVelocity=MaxV();
        }
        void TellTheStats()
        {
            cout<<"The EMU "<<type<<" has a length of"
        }
        
};
class ClassicTrain : public Train
{
    public:
        string type;
        int nof_wagons;
        int nof_locomotives;
        int nof_seats;
        double maximalVelocity;
        int length;
        int CalculateSeats()
        {
           return this->nof_wagons*48;
        }
        double MaxV()
        {
            return sqrt(this->nof_locomotives)*140;
        }
        ClassicTrain(string t, int n, int l)
        {
            cout<<"New EMU came out of factory!"<<endl;
            this->type=t;
            this->nof_wagons=n;
            this->nof_locomotives=l;
            this->nof_seats=CalculateSeats();
            this->maximalVelocity=MaxV();
        }
        ClassicTrain AddedWagons(int n)
        {
            return ClassicTrain(string this->type, int this->nof_wagons+n, int this->nof_locomotives);
        }
        
};
int main()
{
    ClassicTrain IC_Halny("InterCity",8,1);
    ClassicTrain IC_Podhalanin=IC_Halny.AddedWagons(2);
}
