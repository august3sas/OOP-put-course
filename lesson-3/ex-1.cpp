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
            mother_name=BASIC_MNAME; 
            father_name=BASIC_FNAME;
        }
        Family(string n1,string n2)
        {
            mother_name=n1;
            father_name=n2;
        }
        void tellTheNames()
        {
            cout<<"Mother's name is "<<mother_name<<endl;
            cout<<"Father's name is "<<father_name<<endl;
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
            habitat_type=BASIC_HABITAT;
            has_fresh_water=true;
            human_presence=false;
        }
        Habitat(string ht,bool wa,bool hu)
        {
            habitat_type=ht;
            has_fresh_water=wa;
            human_presence=hu;
        }
        void showHabitatInformation()
        {
            cout<<"The habitat type is: "<<habitat_type<<endl<<"It ";
            if(has_fresh_water)cout<<"has ";
            else cout<<"doesn't have";
            cout<<"fresh water. Also, there ";
            if(human_presence)cout<<"are ";
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
        species=BASIC_ATYPE;
        name=BASIC_NNAME;
        can_be_domesticated=false;
    }
    Animal(string animal_type)
    {
        cout<<"An animal: "<<animal_type<<" was born!"<<endl;
        species=animal_type;
        name=BASIC_NNAME;
        can_be_domesticated=false;
        
    }
    Animal(string animal_type, string n)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born!"<<endl;
        species=animal_type;
        name=n;
        can_be_domesticated=false;
    }
    Animal(string animal_type, string n, Habitat h)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born!"<<endl;
        species=animal_type;
        name=n;
        can_be_domesticated=false;
        habitat=h;
    }
    Animal(string animal_type, string n, Family f, Habitat h,bool c)
    {
        cout<<"An animal: "<<animal_type<<" named "<<n<<" was born! And it even has family!"<<endl;
        species=animal_type;
        name=n;
        family=f;
        habitat=h;
        can_be_domesticated=c;
    }
    void showAnimalInformation()
    {
        cout<<"The animal's name is: "<<name<<endl<<"It is of "<<species<<" species"<<endl;
        cout<<"Its family: "<<endl;
        family.tellTheNames();
        habitat.showHabitatInformation();
        cout<<"It ";
        if(can_be_domesticated)cout<<"can be domesticaded";
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
