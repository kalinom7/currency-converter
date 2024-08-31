#include "../src/converter.hpp"

#include <iostream>
#include <map>

#include "../src/exchange_rates.hpp"

void test_is_converted_amount_valid(std::string input_currency,
                                    std::string output_currency,
                                    double input_amount,
                                    double expected_converted_amount,
                                    int &errCnt) {
  ExchangeRates exchange_rates = ExchangeRates();
  auto converter =
      Converter(exchange_rates, input_amount, input_currency, output_currency);

  auto result = converter.convert() == expected_converted_amount;

  if (!result) {
    std::cerr << "Test failed for: " << input_currency << " " << output_currency
              << std::endl;
    errCnt++;
  }
}

int main() {
  int errCnt = 0;

  test_is_converted_amount_valid("PLN", "USD", 50, 12.5, errCnt);

  test_is_converted_amount_valid("USD", "PLN", 50, 190, errCnt);

  test_is_converted_amount_valid("USD", "CHF", 20, 17.2, errCnt);

  test_is_converted_amount_valid("PLN", "CHF", 30, 6.9, errCnt);

  if (errCnt != 0) {
    std::cout << "Number of failed tests: " << errCnt << std::endl;
    return 1;
  } else {
    std::cout << "All tests passed validation" << std::endl;
    return 0;
  }
}