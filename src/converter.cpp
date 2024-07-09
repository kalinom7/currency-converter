#include "converter.hpp"

Converter::Converter(double input_amount, std::string input_currency, std::string output_currency)
{
  this->input_amount = input_amount;
  this->input_currency = input_currency;
  this->output_currency = output_currency;
}

double Converter::convert()
{
  return this->input_amount / 3.8;
}

double Converter::get_input_amount()
{
  return this->input_amount;
}