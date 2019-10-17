//
// Created by stu on 11/10/2019.
//

#include <iostream>
#include <string>
#include <vector>
// These print functions take the different known variable types we would like to print and prints them. This is a shorthand for std::cout

const std::string VERSION = "Development version: 0.0.0.19.10.13";

//void print(double input) { std::cout << input << std::endl;}

//void print(int input) { std::cout << input << std::endl;}

//void print(char input) { std::cout << input << std::endl;}

//void print(const std::string& input) { std::cout << input << std::endl;}

// Checks if an input character is a number
//bool isNumber(char input){
//  return input == '1' | input == '2' | input == '3' | input == '4' |
//         input == '5' | input == '6' | input == '7' | input == '8' |
//         input == '9' | input == '0';
//}

// returns the written word form of an input number
std::string convertToWord(const char input){
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
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> CMD_LINE_ARGS {argv, argv+argc};

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type N_CMD_LINE_ARGS {CMD_LINE_ARGS.size()};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  // This section processes the input arguments -h --help --version -i and -o. Loop starts at 1 because 0 is the program call.
  for (size_type i{1}; i<N_CMD_LINE_ARGS; i++)
  {
    std::string arg = CMD_LINE_ARGS[i];
    if (arg=="-h"|arg=="--help")
    {
      helpRequested = true;
    } else if(arg=="-i") {
      // gets next argument and assigns this to the output file name.
      if (i == N_CMD_LINE_ARGS-1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return 1;
      }
      i++;
      inputFile = CMD_LINE_ARGS[i];
    } else if(arg=="-o") {
      // gets next argument and assigns this to the output file name.
      if (i == N_CMD_LINE_ARGS-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return 1;
      }
      i++;
      outputFile = CMD_LINE_ARGS[i];
    //} else if (arg=="-k") {
      //i++;
      //const int KEY  = std::stoi(CMD_LINE_ARGS[i]);
      //print(KEY);
    } else if (arg=="--version") {
      versionRequested = true;
    } else {
      std::cerr << "Unexpected input argument: " << arg << std::endl;
      return 1;
    }
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << VERSION << std::endl;
    return 0;
  }

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "[warning] input from file ('"
      << inputFile
      << "') not implemented yet, using stdin\n";
  }

  char in_char{'x'};
  std::string end_string;
  while (std::cin >> in_char){
    if (!isalnum(in_char)){
      continue;
    }
    else if (isalpha(in_char)){
      end_string += toupper(in_char);
    }
    else {
      end_string += convertToWord(in_char);
    }
  }

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout << "[warning] output to file ('"
      << outputFile
      << "') not implemented yet, using stdout\n";
  }

  std::cout << end_string << std::endl;
}

