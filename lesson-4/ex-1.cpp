#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void separator()
{
    cout<<endl<<"------------------------------------------"<<endl;
}
class Train
{
    public:
        virtual int CalculateSeats()=0;
        virtual double MaxV()=0;
        virtual int CalculateLength()=0;
        virtual void TellTheStats()=0;
        
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
        int CalculateLength()
        {
            return nof_wagons*30;
        }
        void TellTheStats()
        {
            cout<<"This is the electrical multiple unit "<<type<<"."<<endl;
            cout<<"It has "<<nof_locomotives<<" engine wagons and "<<nof_wagons-nof_locomotives<<" non-engine wagons."<<endl;
            cout<<"It has a maximal velocity of "<<maximalVelocity<<" km/h."<<endl;
            cout<<"It measures "<<length<<" meters."<<endl;
            cout<<"It also seats "<<nof_seats<<" people."<<endl;
            separator();
        }
        EMU(string t, int n, int l)
        {
            cout<<"New EMU came out of factory!"<<endl;
            this->type=t;
            this->nof_wagons=n;
            this->nof_locomotives=l;
            this->nof_seats=CalculateSeats();
            this->maximalVelocity=MaxV();
            this->length=CalculateLength();
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
        int CalculateLength()
        {
            return nof_locomotives*20+nof_wagons*30;
        }
        int CalculateSeats()
        {
           return nof_wagons*48;
        }
        double MaxV()
        {
            return sqrt(this->nof_locomotives)*140;
        }
        void TellTheStats()
        {
            cout<<"This is the classic train "<<type<<"."<<endl;
            cout<<"It has "<<nof_locomotives<<" locomotives and "<<nof_wagons<<" wagons."<<endl;
            cout<<"It has a maximal velocity of "<<maximalVelocity<<" km/h."<<endl;
            cout<<"It measures "<<length<<" meters."<<endl;
            cout<<"It also seats "<<nof_seats<<" people."<<endl;
            separator();
        }
        ClassicTrain(string t, int n, int l)
        {
            cout<<"New classic train came out of factory"<<endl;
            this->type=t;
            this->nof_wagons=n;
            this->nof_locomotives=l;
            this->nof_seats=CalculateSeats();
            this->maximalVelocity=MaxV();
            this->length=CalculateLength();
        }
        ClassicTrain AddedWagons(string t,int n,int l)
        {
            return ClassicTrain(t,this->nof_wagons+n,l);
        }
        
};
int main()
{
    ClassicTrain IC_Halny("InterCity",8,1);
    ClassicTrain IC_Podhalanin=IC_Halny.AddedWagons(IC_Halny.type,2,IC_Halny.nof_locomotives);
    ClassicTrain TLK_Gwarek("TLK",5,1);
    ClassicTrain TLK_Spodek=TLK_Gwarek.AddedWagons(TLK_Gwarek.type,3,TLK_Gwarek.nof_locomotives);
    EMU KW_Calisia("EN76-034",5,2);
    EMU KW_Andrut("EN76-033",5,2);
    EMU KW_77792("EN57-1025",3,2);
    
    separator();
    //display information about all the trains!
    IC_Halny.TellTheStats();
    IC_Podhalanin.TellTheStats();
    TLK_Gwarek.TellTheStats();
    TLK_Spodek.TellTheStats();
    KW_Calisia.TellTheStats();
    KW_Andrut.TellTheStats();
    KW_77792.TellTheStats();
}
