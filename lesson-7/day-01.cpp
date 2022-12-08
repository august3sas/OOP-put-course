#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Elf{
    public:
        int calories=0;
        void addCalories(int x){calories+=x;}
        void resetElf(){calories=0;}
};
class Herd{
    public:
        vector<Elf>elves;
        void addElf(Elf e){elves.push_back(e);}
        int retrieveMax(){
        	int mx=0;
        	for(int i=0;i<elves.size();i++){
        		if(elves[i].calories>mx){
        		mx=elves[i].calories;
        		}
        	}
        	return mx;
}

};
int main()
{
	Herd GroupOfElves;
	Elf OneElf;
	string x="";
	do{
		getline(cin,x);
		if(x!=""){int temp=stoi(x);OneElf.addCalories(temp);}
		else {GroupOfElves.addElf(OneElf);Elf newElf;OneElf=newElf;}
	}while(cin);//CTRL-D to END
	cout<<GroupOfElves.retrieveMax()<<endl;
}
