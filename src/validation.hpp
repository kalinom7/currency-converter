#pragma once

#include <string>
#include "exchange_rates.hpp"
class Validator  {
 private:
  std::string input_currency;
  std::string output_currency;
  int argument_counter;
  

 public:
  ExchangeRates &exchange_rates;
  Validator(ExchangeRates &exchange_rates);
  bool is_input_currency_valid(std::string input_currency);
  bool is_output_currency_valid(std::string input_currency, std::string output_currency);
  bool is_argc_valid(int argc);
  
  

};