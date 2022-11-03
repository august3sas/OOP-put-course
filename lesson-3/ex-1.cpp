#include <iostream>
#include <string>
using namespace std;
const string BASIC_NNAME="Bert";
const string BASIC_MNAME="Mom";
const string BASIC_FNAME="Dad";
const string BASIC_ATYPE="Cub";
const string BASIC_HABITAT="Forest";
class Family
{
    private:
        string mother_name;
        string father_name;
    public:
        Family()
        {
            this->mother_name=BASIC_MNAME; 
            this->father_name=BASIC_FNAME;
        }
        Family(string n1,string n2)
        {
            this->mother_name=n1;
            this->father_name=n2;
        }
        void tellTheNames()
        {
            cout<<"Mother's name is "<<this->mother_name<<endl;
            cout<<"Father's name is "<<this->father_name<<endl;
        }
        
};
class Habitat
{
    private:
        string habitat_type;
        bool has_fresh_water;
        bool human_presence;
    public:
        Habitat()
        {
            this->habitat_type=BASIC_HABITAT;
            this->has_fresh_water=true;
            this->human_presence=false;
        }
        Habitat(string ht,bool wa,bool hu)
        {
            this->habitat_type=ht;
            this->has_fresh_water=wa;
            this->human_presence=hu;
        }
        void showHabitatInformation()
        {
            cout<<"The habitat type is: "<<this->habitat_type<<endl<<"It ";
            if(this->has_fresh_water)cout<<"has ";
            else cout<<"doesn't have";
            cout<<"fresh water. Also, there ";
            if(this->human_presence)cout<<"are ";
            else cout<<"aren't ";
            cout<<"humans around."<<endl;
        }
};
class Animal
{
    private:
        string species;
        string name;
        Family family;
        Habitat habitat;
        bool can_be_domesticated;
    public:
    Animal()
    {
        cout<<"An animal was born!"<<endl;
        this->species=BASIC_ATYPE;
        this->name=BASIC_NNAME;
        this->can_be_domesticated=false;
    }
    Animal(string animal_type)
    {
        cout<<"An animal: "<<animal_type<<" was born!"<<endl;
        this->species=animal_type;
        this->name=BASIC_NNAME;
        this->can_be_domesticated=false;
        
    }
    Animal(string animal_type, string n)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born!"<<endl;
        this->species=animal_type;
        this->name=n;
        this->can_be_domesticated=false;
    }
    Animal(string animal_type, string n, Habitat h)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born!"<<endl;
        this->species=animal_type;
        this->name=n;
        this->can_be_domesticated=false;
        this->habitat=h;
    }
    Animal(string animal_type, string n, Family f, Habitat h,bool c)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born! And it even has family!"<<endl;
        this->species=animal_type;
        this->name=n;
        this->family=f;
        this->habitat=h;
        this->can_be_domesticated=c;
    }
    void showAnimalInformation()
    {
        cout<<"The animal's name is: "<<this->name<<endl<<"It is of "<<this->species<<" species"<<endl;
        cout<<"Its family: "<<endl;
        this->family.tellTheNames();
        this->habitat.showHabitatInformation();
        cout<<"It ";
        if(this->can_be_domesticated)cout<<"can be domesticaded";
        else cout<<"can't be domesticated";
        cout<<endl;
    }
};
void separator()
{
    cout<<"----------------------------------------------------"<<endl;
}
int main()
{
    separator();
    Family dogs_family("Louise","George");
    Habitat dogs_habitat("City",true,true);
    Animal dog("Dog","Toto Wolff",dogs_family,dogs_habitat,true);
    dog.showAnimalInformation();
    
    separator();
    Animal bear;
    bear.showAnimalInformation();
    
    separator();
    Habitat polar_fox_habitat("Tundra",true,false);
    Animal polar_fox("polar_fox","Foxie",polar_fox_habitat);
    polar_fox.showAnimalInformation();
    
    separator();
}
