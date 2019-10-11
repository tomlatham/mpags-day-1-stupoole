//
// Created by stu on 11/10/2019.
//

#include "MPAGSCipher.h"
#include <iostream>
#include <string>

void print(double input) { std::cout << input << std::endl;}

void print(int input) { std::cout << input << std::endl;}

void print(char input) { std::cout << input << std::endl;}

void print(const std::string& input) { std::cout << input << std::endl;}


void exercise1(){  std::cout << "Hello World \n";}

void exercise2(){
  int anInt{1};
  double aDouble{1.111};
  anInt++;
  aDouble++;
  std::cout << aDouble << std::endl;
  std::cout << anInt << std::endl;
}

void exercise3(){
  const std::string message {"Hello world?"};
  std::cout << message << "\n";
}

void exercise4(){
  double d{6};
  int i{4};
  int j{5};
  print(i*d);
  print(d/i);
  print(i/j);

}

int main()
{
  //This prints hello world to console

  exercise1();
  exercise2();
  exercise3();
  exercise4();
  return 0;
}

