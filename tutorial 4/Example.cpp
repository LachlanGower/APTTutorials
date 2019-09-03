#include "???"

Example::Example(double value) {
  this->ptrValue = new double(value);
}

void Example::setValue(DblRef value) {
  this->ptrValue = value;
}

double Example::getValue() {
  return this->ptrValue;
}
