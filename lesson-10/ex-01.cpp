#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void separator(){
    cout<<endl<<"-------------------------------"<<endl;
}
void printVector(vector<string> &vec){
    if(vec.size()==0)
    {
        cout<<"[]"<<endl;
        return;
    }
    cout<<"[";
    for(int i=0;i<vec.size();i++)
    {
        cout<<"\""<<vec[i]<<"\"";
        if(i<vec.size()-1)cout<<",";
    }
    cout<<"]"<<endl;
}
bool inVector(vector<string> &vec,string s){
    if( find(vec.begin(),vec.end(),s)!=vec.end())return true;
    return false;
}
void restartVector(vector<string> &vec){
    vector<string>newVec(0);
    vec=newVec;
}
class Shiritori final{
    private:
        vector<string>words;
        bool game_over;
        int wsize;
    public:
        Shiritori(){
            game_over=false;
            wsize=0;
            restartVector(words);
        }
        void play(string w){
            if(game_over){
                cout<<"Can't play, the game is over. Restart it please!"<<endl;
                return;
            }
            if(words.size()==0){
                words.push_back(w);
                wsize++;
                return;
            }
            if(inVector(words,w)){
                gameOverUsed(w);
                game_over=true;
                return;
            }
            
            
            int last_letter_id=words[wsize-1].size()-1;
            if(w[0]!=words[wsize-1][last_letter_id]){
                gameOverWrong(w);
                game_over=true;
                return;
            }
            words.push_back(w);
            wsize++;
        }
        void printWords(){
            printVector(words);
        }
        void restart(){
            restartVector(words);
            game_over=false;
            cout<<"game restarted"<<endl;
        }
        void gameOverUsed(string w){
            cout<<"game over : "<<w<<" has already been said!"<<endl;
        }
        void gameOverWrong(string w){
            int last_letter_id=words[wsize-1].size()-1;
            cout<<"game over : "<<w<<" does not start with "<<words[wsize-1][last_letter_id]<<endl;
        }
};
void gameControl(Shiritori &game){
    while(1)
    {
        separator();
        cout<<"what do you want to do:"<<endl;
        cout<<"1. Play"<<endl;
        cout<<"2. Print all previous words"<<endl;
        cout<<"3. Restart the game"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"Input a number: ";
        int choice;
        string a;
        bool quit=false;
        cin>>choice;
        switch(choice)
        {
            case 1: 
                
                cout<<"Input a word: ";
                cin>>a;
                game.play(a);
                break;
            case 2:
                game.printWords();
                break;
            case 3:
                game.restart();
                break;
            case 4:
                quit=true;
                break;
            default:
                cout<<"WRONG NUMBER"<<endl;
                break;
        }
        if(quit)break;
    }
}
int main()
{
    Shiritori wordgame;
    gameControl(wordgame);
    return 0;
}
