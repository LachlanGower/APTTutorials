#include <iostream>
#include <string>

using std::string;
using std::cout;

typedef float* FloatPtr;

int main(void){
  int x = 0;
  char c = 'a';
  string s = "this is broken";
  double da[10] = {4.0,3.4};
  float f = 4.0;
  FloatPtr fptra[10];
  fptra[0] = &f;

  int* z = new int(1);
  char* d = new char('b');
  string* s1 = new string("still broken");
  double* ds = new double[1];
  ds[0] = 4.2;
  ds[1] = 5.3;
  FloatPtr* fp = new FloatPtr[100];
  //can delete this pointer as it is defined on the heap
  fp[0] = new float(10.5);
  //can't delete this pointer as it points to a stack variable
  fp[1] = &f;

  cout << x << " " << c << " " << s << " " << da[0]
      << " " << da[1] << " " << fptra[0] << std::endl;

  cout << *z << " " << d << " " << *s1 << " " << ds[0]
  << " " << ds[1] << " " << fp[0] << std::endl;
  delete(z);
  delete(d);
  delete(s1);
  delete(ds);
  delete(fp[0]);
  delete(fp);
}
