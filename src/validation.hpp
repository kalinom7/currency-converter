#pragma once

#include <string>
#include "exchange_rates.hpp"
class Validator  {
 private:
  std::string input_currency;
  std::string output_currency;
  int argument_counter;
  

 public:
  Validator(int argc, std::string input_currency, std::string output_currency);
  bool is_input_currency_valid();
  bool is_output_currency_valid();
  bool is_argc_valid();
  bool are_currencies_different();
  

};