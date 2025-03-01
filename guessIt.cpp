#include <iostream>
#include <cstdlib>
using namespace std;

//doan so tu 0 --> 100
int generateSecretNum();
int getPlayerGuess();
void printAnswer(int guess, int secretNum);
int getPoint(int times);
void playGuessIt();

int main(){
    srand(time(0));
    // roi ra cac so ngau nhien khac nhau trong cac lan choi khac nhau
    char choice;
    do{
        playGuessIt();
        cout << "Do you want to play again? (y/n): " << endl;
        cin >> choice;
    }while(choice == 'y' || choice == 'Y');
    cout << "Thanks for playing!" << endl;
return 0;
}

int generateSecretNum(){
    return rand() % 100 + 1;
}
int getPlayerGuess(){
    int guess;
    cout << "Enter your guess (1..100): " << endl;
    cin >> guess;
    return guess;
}
void printAnswer(int guess, int secretNum){
    if(guess < secretNum) cout << "Too small" << endl;
    else if(guess > secretNum) cout << "Too big" << endl;
    else cout << "Correct!" << endl;
}
int getPoint(int times){
    return 100 - times;
}
void playGuessIt(){
    int guess, times = 0;
    int secretNum = generateSecretNum();
    do{
       guess = getPlayerGuess();
       printAnswer(guess, secretNum);
       ++times;
    }while(guess != secretNum);
    cout << "Times total: " << times << endl;
    cout << "Point: " << getPoint(times) << endl;
}
