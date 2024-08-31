#include "../src/validation.hpp"

#include <iostream>
#include <string>

#include "../src/exchange_rates.hpp"

void test_is_input_currency_valid(std::string input, bool expectedOutput,
                                  int &errCnt) {
  ExchangeRates exchange_rates = ExchangeRates();
  exchange_rates.load("test_data_validation.csv");
  auto validator = Validator(exchange_rates);

  auto result = validator.is_input_currency_valid(input) == expectedOutput;
  if (!result) {
    std::cerr << "Test failed for: " << input << std::endl;
    errCnt++;
  }
}

void test_is_output_currency_valid(std::string input, std::string output,
                                   bool expectedOutput, int &errCnt) {
  ExchangeRates exchange_rates = ExchangeRates();
  exchange_rates.load("test_data_validation.csv");
  auto validator = Validator(exchange_rates);

  auto result =
      validator.is_output_currency_valid(input, output) == expectedOutput;
  if (!result) {
    std::cerr << "Test failed for: " << input << " " << output << std::endl;
    errCnt++;
  }
}

int main() {
  int errCnt = 0;

  test_is_input_currency_valid("USD", true, errCnt);

  test_is_input_currency_valid("PLN", true, errCnt);

  test_is_input_currency_valid("GBP", false, errCnt);

  test_is_output_currency_valid("USD", "PLN", true, errCnt);

  test_is_output_currency_valid("USD", "CAD", false, errCnt);

  test_is_output_currency_valid("PLN", "GBP", true, errCnt);

  test_is_output_currency_valid("TEST_ZERO", "ZERO", false, errCnt);

  test_is_output_currency_valid("TEST_NEGATIVE", "NEGATIVE", false, errCnt);

  test_is_output_currency_valid("TEST_IS_NOT_A_NUMBER", "432423", false,
                                errCnt);

  if (errCnt != 0) {
    std::cout << "Number of failed tests: " << errCnt << std::endl;
    return 1;
  } else {
    std::cout << "All tests passed!" << std::endl;
    return 0;
  }
}