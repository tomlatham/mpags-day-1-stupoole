//
// Created by stu on 11/10/2019.
//

#include "MPAGSCipher.h"
#include <iostream>
#include <string>

void printString(){
  std::string message {"Hello world?"};
  std::cout << message << "\n";
}

int main()
{
  //This prints hello world to console
  std::cout << "Hello World \n";

  int anInt{1};
  double aDouble{1.111};
  anInt++;
  aDouble++;
  std::cout << aDouble << std::endl;
  std::cout << anInt << std::endl;
  printString();
  return 0;
}

