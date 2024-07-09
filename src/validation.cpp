#include "validation.hpp"
#include <string>
#include <iostream>

Validator::Validator(int argc, std::string input_currency, std::string output_currency)
{
  this->argument_counter = argc;
  this->input_currency = input_currency;
  this->output_currency = output_currency;
}

bool Validator::is_input_currency_valid()
{
  auto isValid = this->input_currency == "PLN";

  if (!isValid)
  {
    std::cerr << "Input currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_output_currency_valid()
{
  auto isValid = this->output_currency == "USD";

  if (!isValid)
  {
    std::cerr << "Output currency is invalid" << std::endl;
  }

  return isValid;
}

bool Validator::is_argc_valid()
{
  auto isValid = this->argument_counter == 4;

  if (!isValid)
  {
    std::cerr << "Invalid number of arguments" << std::endl;
  }

  return isValid;
}
