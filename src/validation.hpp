#pragma once

#include <string>

class Validator
{
private:
  std::string input_currency;
  std::string output_currency;
  int argument_counter;

public:
  Validator(int argc, std::string input_currency, std::string output_currency);
  bool is_input_currency_valid();
  bool is_output_currency_valid();
  bool is_argc_valid();
  bool are_curriencies_diffrent();
};