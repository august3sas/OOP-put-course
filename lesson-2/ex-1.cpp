#include <iostream>
#include <string>
//nail clippers,  mp3 player
using namespace std;
const int BASICYEAR=2022;
const string BASICMATERIAL="Stainless Steel";
const string BASICCOMPANY="Mann Co.";
class NailClippers
{
    private:
    
    string material;
    string company;
    int year_of_production;
    int nails_clipped;
    
    public:
    
    NailClippers()
    {
        this->material=BASICMATERIAL;
        this->company=BASICCOMPANY;
        this->year_of_production=BASICYEAR;
        this->nails_clipped=0;
     
    }
    NailClippers(string mat, string com, int yr)
    {
        this->material=mat;
        this->company=com;
        this->year_of_production=yr;
        this->nails_clipped=0;
    }
    NailClippers(int nai)
    {
        this->material=BASICMATERIAL;
        this->company=BASICCOMPANY;
        this->year_of_production=BASICYEAR;
        this->nails_clipped=nai;
    }
    void Informate()
    {
        cout<<"You've got some nailclippers made out of "<<this->material;
        cout<<" by a company named "<<this->company;
        cout<<". They were made in "<<this->year_of_production<<". "<<endl;
        cout<<"They were used "<<this->nails_clipped<<" times already!"<<endl;
    }
};

int main()
{
    NailClippers nail1;
    nail1.Informate();
    NailClippers nail2("Rusty steel","Sheffield Steel Works ltd.",2019);
    nail2.Informate();
    NailClippers nail3(123);
    nail3.Informate();
}
