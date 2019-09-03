#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#define EXIT_SUCCESS  0

using std::cout;
using std::cin;
using std::string;
using std::endl;

bool getCharacter(char* c);
void dumpArray(char * array, int length);

int main(void){
  char a = 'l';
  char * c = &a;
  char tutArray[100];
  for(int x = 0;x < 100; x++){
    if(getCharacter(c)){
      cout << "1:tut-" << tutArray[x] << "\n1:c-"<< *c <<endl;
      tutArray[x] = *c;
      cout << "2:tut-" <<tutArray[x] << "\n2:c-"<< *c <<endl;
    }else{
      tutArray[x] = cin.eof();
    }
  }

  cout << tutArray << endl;
  std::reverse(tutArray[0],tutArray[100]);
  cout << tutArray << endl << endl;
  dumpArray(tutArray, 100);
  return EXIT_SUCCESS;
}
void dumpArray(char * array, int length){
  for(int x = 0; x < length; x++){
    cout << x << ": "<< array[x] << ", ";
  }
  cout << endl;
}
bool getCharacter(char* c){
  char a;
  if(cin >> a){
    *c = a;
    return true;
  }
  else
    return false;
}
