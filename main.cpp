#include <iostream>
#include <math.h>
#include <numeric>
#include <valarray>
// Adhitya Padmanabhan
/*
Class notes:
-	Important for projects:
o	Comments to understand
o	Organization/structure
o	Code works
o	Readable/syntax
o	Efficient
-	Comments only when code is complicated/needed
 */
bool is_power_of_2_loop(int);
bool is_power_of_2_(int);
bool is_prime(int);
void reduce_fraction_(int, int);
void test();

class Fraction {
public:
  int num;
  int den;

  Fraction(int num, int den) : num(num), den(den) {
  }
  std::string to_string() {
    return std::to_string(num) + "/" + std::to_string(den);
  }
  //operator overload
  bool operator == (Fraction &other) {
    return this -> num == other.num && this -> den == other.den;
  }
};

int main() {
  test();
  return 0;
}

bool is_power_of_2_loop(int num) {
  while (num % 2 == 0) {
    num /= 2;
  }
  if (num == 1) {
    return true;
  } else {
    return false;
  }
}
// asked chatgpt to walk me through the options for non loop methods
bool is_power_of_2_(int num) {
  return (num > 0) && (num & (num - 1)) == 0;
}

bool is_prime(int num) {
  if (num <= 1) {
     return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// saw the std::gcd function on the google ai result
void reduce_fraction_(int num, int den) {
  int div = std::gcd(num, den);
  num /= div;
  den /= div;
  std::cout << "the reduced fraction is " << num << "/" << den << "\n";
}


Fraction reduce_fraction(Fraction input) {
  // in class solution
  int div = 2;
  while (div <= input.num && div <= input.den) {
    if (input.num % div == 0 && input.den % div == 0) {
      input.num /= div;
      input.den /= div;
      continue;
    }
    div++;
  }
  return input;

}

void test() {
  int num = 8;
  int num2 = 9;
  int num3 = 9;
  bool result = is_power_of_2_loop(num);
  bool result2 = is_power_of_2_(num2);
  bool result3 = is_prime(num3);
  if (result == true) {
    printf("%d is div by 2\n", 8);
  } else {
    printf("%d is not div by 2\n", 8);
  }
  // no loop
  if (result2 == true) {
    printf("%d is div by 2 (non loop)\n", 9);
  } else {
    printf("%d is not div by 2 (non loop)\n", 9);
  }
  if (result3 == true) {
    //printf("%d is prime\n", 7);
    std::cout << "PASS\n";
  } else {
    //printf("%d is not prime\n", 7);
    std::cout << "FAIL\n";
  }
  reduce_fraction_(2, 4);
  Fraction num1(2, 4);
  std::cout << num1.to_string() << "\n";
  //reduce to min terms
  //given input, output should match expected output
  Fraction inputs[4] = {Fraction(1, 2),
                      Fraction(2, 4),
                      Fraction(4, 2),
                      Fraction(6, 8),
                      };
  Fraction outputs[4] = {Fraction(1, 2),
                      Fraction(1, 2),
                      Fraction(2, 1),
                      Fraction(3, 4),
                    };

  //call function
  for (int i = 0; i < 4; i++) {
    Fraction input = inputs[i];
    Fraction expect = outputs[i];
    Fraction actual = reduce_fraction(input);

    //compare expected vs actual
    if (expect == actual) {
      std::cout << "PASS!\n";
    } else {
      std::cout << "FAIL! case is: " << input.to_string() << "\n";
    }
  }
}