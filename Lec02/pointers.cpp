#include <iostream>

#define EXIT_SUCCESS 0

using std::cout;
using std::endl;

void swap(int* a, int* b);
void swap (int& a, int& b);
int main(void){
  int i = 10;
  //pointer to i
  int* ptr = &i;
  int j = 32;
  int* ptr2 = &j;
  //pointer of a pointer
  int** ptrptr = &ptr;

  //dereference
  *ptr = 3;
  cout << i << " " << j << endl;
  swap(ptr, ptr2);
  cout << i << " " << j << endl;
  cout << ptrptr << endl;

  i = 10;
  //pointer to i
  int& ref = i;
  j = 32;
  int& ref2 = j;

  //dereference
  cout << i << " " << j << endl;
  swap(ref, ref2);
  cout << i << " " << j << endl;

  return EXIT_SUCCESS;
}
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
void swap (int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}
