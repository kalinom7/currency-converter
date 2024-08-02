#include "../src/validation.hpp"

#include <iostream>
#include <string>

void test_is_input_currency_valid(std::string input, bool expectedOutput,
                                  int &errCnt) {
  auto validator = Validator(4, input, "mock");

  auto result = validator.is_input_currency_valid() == expectedOutput;
  if (!result) {
    std::cerr << "Test failed for: " << input << std::endl;
    errCnt++;
  }
}

int main() {
  int errCnt = 0;

  test_is_input_currency_valid("USD", true, errCnt);

  test_is_input_currency_valid("PLN", true, errCnt);

  test_is_input_currency_valid("GBP", true, errCnt);

  test_is_input_currency_valid("CHF", false, errCnt);

  if (errCnt != 0) {
    std::cout << "Number of failed tests: " << errCnt << std::endl;
    return 1;
  } else {
    std::cout << "All tests passed!" << std::endl;
    return 0;
  }
}