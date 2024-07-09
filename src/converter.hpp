#pragma once
#include <string>

class Converter
{
private:
  double input_amount;
  std::string input_currency;
  std::string output_currency;

public:
  Converter(double input_amount, std::string input_currency, std::string output_currency);
  double convert();
  double get_input_amount();
};