#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Elf
{
	public:
	int start, finish;
	Elf();
	Elf(int a,int b){start=a;finish=b;}
};
class Assignment
{	
	public:
	Elf e1,e2;
	Assignment(Elf e, Elf f){e1=e;e2=f;}
	bool FullContain(){
		if((e1.start<=e2.start&&e1.finish>=e2.finish)||(e2.start<=e1.start&&e2.finish>=e1.finish)){
			return true;
		}
		return false;
	}
};

int main()
{
	int ct=0;
	string input="";
	do{
		getline(cin,input);
		vector<int>toAssignment;
		string temp="";
		for(int i=0;i<input.size();i++)
		{
			if(input[i]!=','||input[i]!='-'){temp+=input[i];}
			else{toAssignment.push_back(stoi(temp));temp="";}
		}
		Elf e1(toAssignment[0],toAssignment[1]);
		Elf e2(toAssignment[2],toAssignment[3]);
		Assignment a(e1,e2);
		if(a.FullContain()){ct++;}
	}while(cin);
	cout<<ct<<endl;
}
