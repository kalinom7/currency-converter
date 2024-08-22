#include "validation.hpp"

#include <iostream>
#include <map>
#include <string>

#include "exchange_rates.hpp"

Validator::Validator(ExchangeRates &exchange_rates, int argument_counter, std::string input_currency,
                     std::string output_currency) : exchange_rates(exchange_rates), argument_counter(argument_counter) , input_currency(input_currency) , output_currency(output_currency){}



bool Validator::is_input_currency_valid() {
  auto isValid = exchange_rates.check_for_input_currency(input_currency);

  if (!isValid) {
    std::cerr << "Input currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_output_currency_valid() {
  auto isValid = exchange_rates.check_for_output_currency(input_currency,output_currency);
     

  if (!isValid) {
    std::cerr << "Output currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_argc_valid() {
  auto isValid = this->argument_counter == 4;

  if (!isValid) {
    std::cerr << "Invalid number of arguments" << std::endl;
  }
  return isValid;
}

bool Validator::are_currencies_different() {
  auto isValid = this->input_currency != this->output_currency;

  if (!isValid) {
    std::cerr << "Curriencies must be diffrent" << std::endl;
  }
  return isValid;
}
