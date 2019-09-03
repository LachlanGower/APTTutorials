#include <iostream>
#include <string>

#define EXIT_SUCCESS  0

using std::string;
using std::cout;
using std::cin;

int main (void){
  double a = 0;
  double b = 0;
  while(cin >> a && cin >> b){
    if(b < a){
      cout << "The smaller number is " << b << "\n";
      cout << "The larger number is " << a << "\n";
      if((a-b) < (1/10000000)){
        cout << "The numbers are almost equal\n";
      }
    }
    if(a < b){
      cout << "The smaller number is " << a << "\n";
      cout << "The larger number is " << b << "\n";
      if((b-a) < (1/10000000)){
        cout << "The numbers are almost equal\n";
      }
    }
    if(a == b){
      cout << "The numbers both equal " << a << "\n";
    }

  }
  return EXIT_SUCCESS;
}
