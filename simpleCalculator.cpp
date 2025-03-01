#include <iostream>
using namespace std;

//gồm cộng, trừ, nhân, chia lấy nguyên, chia lấy dư
int cal(int num1, int num2, char op);

int main(){
  int num1, num2;
  char op;
  cin >> num1 >> op >> num2;
  cout << cal(num1, num2, op) << endl;
  return 0;
}

int cal(int num1, int num2, char op){
    switch (op){
      case '+':
          return num1 + num2;
      case '-':
          return num1 - num2;
      case '*':
          return num1 * num2;
      case '/':
          if(num2 == 0){
            cout << "Invalid divisor" << endl;
            exit(1);
          }
          else return num1 / num2;
      case '%':
          if(num2 == 0){
            cout << "Invalid divisor" << endl;
            exit(1);
          }
          else return num1 % num2;
      default:
        cout << "Invalid operator" << endl;
        exit(1);
     }
}
