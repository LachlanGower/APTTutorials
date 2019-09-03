#define EXIT_SUCCESS 0

#include <iostream>
#include "FunctionCeption.h"

int main(void){
    FunctionCeption* fc = new FunctionCeption();
    std::cout << fc->funkyTown("can you take me to ");
    return EXIT_SUCCESS;
}