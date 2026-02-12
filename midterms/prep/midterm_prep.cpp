//#include <bits/stdc++.h> // GNU GCC way to include every STL. Does not work for MSVC
#include <iomanip>       // setprecision()
// #define NDEBUG      // disable asserts
#include <cassert>  //assert
#include <cmath>    // power function
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <fstream>  // ifstream
#include <iostream> // cin cout
#include <limits>   // numeric limits
#include <math.h>   //sqrt() pow()
#include <stdio.h>  // printf, scanf
#include <string>   // strings
#include <vector>   // vectors

// Custom Exception inheriting from BaseClass std::exception
// Probably won't come up since he hasn't covered classes
class FileOpenException : public std::exception {
  std::string message;

public:
  explicit FileOpenException(const std::string &filename) {
    message = "Could not open file: " + filename;
  }

  // const noexcept override is a standard way of saying "this won’t modify the
  // object, won’t throw, and replaces the base version."
  const char *what() const noexcept override { return message.c_str(); }
};

// clang-format off
// argc is argument count; argv is the CLI arguments.
// Ex: ./midterms input1 input2
// argc is 3 (INCLUDING ./midterms) and argv is ['./midterms', 'input1', 'input2']
// clang-format on
int random_number_generator(const int &max, const int &min) {
  const long current_time = time(nullptr);
  srand(static_cast<unsigned int>(current_time)); // Seed rand func to curr time

  int random_value = max + (rand() % (max - min + 1));

  return random_value;
}

void file_io(const std::string &file_name) {
  std::string line;
  std::ifstream file(file_name);

  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::cout << line << '\n'; // print every line of the file
    }
    // file.close(); Not needed. The C++ compiler uses RAII to automatically
    // free up the file resource when it goes out of scope
  }

  else {
    throw FileOpenException(file_name);
  }
}

void print_arguments(const int argument_count, char **const arguments) {
  for (int i = 0; i < argument_count; i++) { // use <, not <=
    std::cout << arguments[i] << "\n";       // print argument i
  }

  for (double i = 0.00; i < 1.20; i += 0.10) {
    printf("Prinf with:\n\t1. Long float (%%lf): %lf\n\tChar "
           "with no trailing zeros (%%g): %g\n",
           i, i);
    std::cout << std::fixed; // shows trailing zeros
    std::cout << "std::cout with setprecision + trailing zeros: "
              << std::setprecision(3) << i << "\n";
  }
}

void get_charcaters(std::istream &input) {
  // std::vector<char> c_string_representation(num_values, value_of_elements);
  std::cout << "Please enter charcaters to convert into a vector of chars\n";
  std::vector<char> c_string_representation = {};
  char character = '~';
  while (input.get(character)) {
    switch (character) {
    case '~':
      break;
    default:
      c_string_representation.push_back(character);
    }
  }

  int size_of_vector =
      static_cast<int>(c_string_representation.size()); // Size of Vector

  bool is_Vector_Empty = c_string_representation.empty(); // Is Vector Empty

  c_string_representation.push_back('\0'); // signal termination of the C string
  char tail_of_the_vector = c_string_representation.back(); // always \0 so null
  char head_of_the_vector = c_string_representation.front();

  // std::swap(c_string_representation.at(1), c_string_representation.at(2));

  std::cout << "Head element of the vector:  " << head_of_the_vector << "\n";
  std::cout << "All the elements of the vector:";
  for (char i : c_string_representation) {
    std::cout << i;
  }
}

void demo_string_ops() {
  std::string text = "Hello world, world!";

  // 1. Find
  size_t pos = text.find("world");
  if (pos != std::string::npos) { // npos = "not found"
    std::cout << "First 'world' found at index: " << pos << "\n";
  }

  // 2. Replace
  text.replace(pos, 5, "C++"); // replace 5 chars starting at pos with "C++"
  std::cout << "After replace: " << text << "\n";

  // 3. Find next occurrence (starting from pos+1)
  size_t pos2 = text.find("world", pos + 1);
  if (pos2 != std::string::npos) {
    std::cout << "Second 'world' found at index: " << pos2 << "\n";
  }

  // 4. Substring
  std::string sub = text.substr(0, 5); // first 5 characters
  std::cout << "Substring (first 5 chars): " << sub << "\n";

  // 5. Insert
  text.insert(0, "Wow! "); // insert at beginning
  std::cout << "After insert: " << text << "\n";

  // 6. Erase
  text.erase(0, 5); // remove first 5 characters
  std::cout << "After erase: " << text << "\n";

  // 7. Length / size
  std::cout << "Length of string: " << text.size() << "\n";

  // 8. Iterate characters
  std::cout << "Characters: ";
  for (char c : text) {
    std::cout << "[" << c << "]";
  }
  std::cout << "\n";

  /*
    First 'world' found at index: 6
    After replace: Hello C++, world!
    Second 'world' found at index: 11
    Substring (first 5 chars): Hello
    After insert: Wow! Hello C++, world!
    After erase: Hello C++, world!
    Length of string: 18
    Characters: [H][e][l][l][o][ ][C][+][+][,][ ][w][o][r][l][d][!]
  */
}

void print_integer_limits() {
  int min_val = std::numeric_limits<int>::max();
  int max_val = std::numeric_limits<int>::min();
  std::cout << "Max integer in C++: " << min_val << "\n"
            << "Min Integer in C++: " << max_val << "\n";
}

std::vector<int> read_numbers() {
  std::vector<int> numbers;
  int n;

  while (true) {
    if (std::cin >> n) {
      numbers.push_back(n); // good input
    } else {
      if (std::cin.eof())
        break;          // stop if end-of-file
      std::cin.clear(); // clear failbit
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Bad input ignored. Try again.\n";
    }
  }

  return numbers;
}

int main(int argc, char *argv[]) {
  // print_arguments(argc, argv);

  // Throws FileOpenException if file is not present in the dir or cannot be
  // opened for another reason

  try {
    file_io(static_cast<std::string>((argv[0] + 2)) +
            ".cpp"); // remove the leading "./
  } catch (FileOpenException &exception) {
    std::cout
        << "File could not be opened. Have you tried:\n1. Checking if "
           "you are in the correct directory\n2. Have you tried creating "
           "a .cpp file with the same name as the binary?\n\nFull exception:\n"
        << exception.what() << "\n";
  }

  get_charcaters(std::cin);

  print_integer_limits();

  get_charcaters(std::cin);

  return 0;
}
