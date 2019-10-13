//
// Created by stu on 11/10/2019.
//

#include "MPAGSCipher.h"
#include <iostream>
#include <string>
#include <vector>
// These print functions take the different known variable types we would like to print and prints them. This is a shorthand for std::cout

const std::string VERSION = "Development version: 0.0.0.19.10.13";

void print(double input) { std::cout << input << std::endl;}

void print(int input) { std::cout << input << std::endl;}

void print(char input) { std::cout << input << std::endl;}

void print(const std::string& input) { std::cout << input << std::endl;}

// Checks if an input character is a number
bool isNumber(char input){
  return input == '1' | input == '2' | input == '3' | input == '4' |
         input == '5' | input == '6' | input == '7' | input == '8' |
         input == '9' | input == '0';
}

// returns the written word form of an input number
std::string convertToWord(char input){
  switch(input){
  case '1':
    return "ONE";
  case '2':
    return "TWO";
  case '3':
    return "THREE";
  case '4':
    return "FOUR";
  case '5':
    return "FIVE";
  case '6':
    return "SIX";
  case '7':
    return "SEVEN";
  case '8':
    return "EIGHT";
  case '9':
    return "NINE";
  case '0':
    return "TEN";
  default:
    return "";
  }

}



int main(int argc, char* argv[])
{
  // This section processes the input arguments -h --help --version -i and -o. Loop starts at 1 because 0 is the program call.
  const std::vector<std::string> CMDLINEARGS {argv, argv+argc};
  for (int i=1; i<argc; i++)
  {
    std::string arg = argv[i];
    if (arg=="-h"|arg=="--help")
    {
      std::string helpstr = "Usage: ./mpags-cipher.o <inputfile>\nOptions: \n -h or --help  Display this help text.\n -o <outputfile>  chooses a filename. If blank file will be saved with inputfile name appended with '_out'";
      print(helpstr);
    } else if(arg=="-i") {
      // gets next argument and assigns this to the output file name.
      i++;
      const std::string INPUT_FILE_NAME = argv[i];
      print(INPUT_FILE_NAME);
    } else if(arg=="-o") {
      // gets next argument and assigns this to the output file name.
      i++;
      const std::string OUTPUT_FILE_NAME = argv[i];
      print(OUTPUT_FILE_NAME);
    } else if (arg=="-k") {
      i++;
      const int KEY  = std::stoi(argv[i]);
    } else if (arg=="--version") {
      print(VERSION);
    } else {
      print(std::string{"Unexpected input argument: "} + arg);
      break;
    }
  }


}

