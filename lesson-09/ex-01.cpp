#include<iostream>
using namespace std;
class Game{
	public:
	virtual int result()=0;
};
class FakeFootballGame : public Game{
	public:
	int result(){return 10;}
};
int main(){
	FakeFootballGame game_05_01;
	cout<<game_05_01.result()<<endl;
	if (game_05_01.result()==10){cout<<"This is a fake score"; return 1;}else {cout<<"This is a real score"<<endl;return 0;}
//	cout<<game_05_01.result()<<endl;
}
