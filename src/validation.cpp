#include "validation.hpp"

#include <iostream>
#include <map>
#include <string>

#include "exchange_rates.hpp"

Validator::Validator(ExchangeRates &exchange_rates)  : exchange_rates(exchange_rates){}



bool Validator::is_input_currency_valid(std::string input_currency) {
  auto isValid = exchange_rates.check_for_input_currency(input_currency);

  if (!isValid) {
    std::cerr << "Input currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_output_currency_valid(std::string input_currency, std::string output_currency) {
  auto isValid = exchange_rates.check_for_output_currency(input_currency,output_currency);
     

  if (!isValid) {
    std::cerr << "Output currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_argc_valid(int argc) {
  auto isValid = argc == 4;

  if (!isValid) {
    std::cerr << "Invalid number of arguments" << std::endl;
  }
  return isValid;
}
