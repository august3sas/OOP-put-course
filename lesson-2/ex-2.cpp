#include <iostream>
#include <string>
#include <vector>
//nail clippers,  mp3 player
using namespace std;
const string BASICCOMPANY="Mann Co ";
const int BASICMEMORYSIZE=64;
const int BASICYEAR=2022;
class Mp3Player
{
    private:
    
    string company;
    int memory_size;
    int year_of_production;
    vector<string> songs;
    
    public:
    
    Mp3Player()
    {
        this->company=BASICCOMPANY;
        this->memory_size=BASICMEMORYSIZE;
        this->year_of_production=BASICYEAR;
    }
    Mp3Player(string com, int mem, int yea)
    {
        this->company=com;
        this->memory_size=mem;
        this->year_of_production=yea;
    }
    Mp3Player(string com,int mem, int yea, vector<string>son)
    {
        this->company=com;
        this->memory_size=mem;
        this->year_of_production=yea;
        this->songs=son;
    }
    
    void Informate()
    {
        cout<<"This is a MP3 Player made by "<<this->company<<". ";
        cout<<"It was produced in "<<this->year_of_production<<". ";
        cout<<"It has a memory size of "<<this->memory_size<<" songs. ";
        cout<<"It has "<<(this->songs).size()<<" songs which it can play!"<<endl;
    }
    int NumberOfSongs()
    {
        return (this->songs).size();
    }
    vector<string> SongList()
    {
        return this->songs;
    }
    string CompanyData()
    {
        return this->company;
    }
    int ProductionData()
    {
        return this->year_of_production;
    }
    int MemoryData()
    {
        return this->memory_size;
    }
    
    
};

int main()
{
    Mp3Player Mp1;
    Mp1.Informate();
    
    Mp3Player Mp2("Fony",128,2010);
    Mp2.Informate();
    
    vector<string> playlist={"Programmers Ballad","Segmentation Fault","The Power Of Brain","Arabian Rhapsody"};
    Mp3Player Mp3("Famfung",256,2011,playlist);
    Mp3.Informate();
}
