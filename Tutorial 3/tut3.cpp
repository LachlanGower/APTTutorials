#include <iostream>

#define EXIT_SUCCESS  0

using std::cout;
using std::cin;
using std::string;
using std::endl;

void incrementFloat(float* param);
void incrementInt(int * param);
void incrementInt(int & param);
void dump(int * param, int length);

int main(void){
  int x;
  int array[5] = {6,12,18};
  float y = 5;
  int* ptr;
  ptr = &x;
  x = 3;
  *ptr = 10;
  float* y_ptr = &y;
  int& x_ref = x;
  incrementFloat(y_ptr);
  incrementInt(x_ref);
  incrementInt(array);
  cout << x << " " << y << " " <<array[0] << endl;

  dump(array,5);
  incrementInt(array);
  dump(array,5);


  return EXIT_SUCCESS;
}

void incrementFloat(float * param){
  (*param)++;
}
void incrementInt(int & param){
  param++;
}
void incrementInt(int * param){
  (*param)++;
}
void dump(int * param, int length){
  for(int i = 0; i < length;i++){
    std::cout << param[i] << ' ';
  }
  std::cout << std::endl;
}
