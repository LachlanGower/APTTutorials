#include <iostream>
#include <string>

#define EXIT_SUCCESS 0
#define LENGTH 1

using std::string;
using std::cout;
using std::endl;

int foo();
int main(void){
  //string class allows concatenation
  string c = "Hello";
  c = c + " World!";

  //this must be 13 or more
  char stringTest[13] = "Hello World!";

  //array is boundless unless on init
  int a[LENGTH] = {1};
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  cout << endl << c << endl;
  cout << a[1] << endl;
  cout << stringTest << endl;
  cout << endl;

  return EXIT_SUCCESS;
}
int foo(){
  return 6;
}
