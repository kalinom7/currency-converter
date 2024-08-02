#include "converter.hpp"

Converter::Converter(double input_amount, std::string input_currency,
                     std::string output_currency) {
  this->input_amount = input_amount;
  this->input_currency = input_currency;
  this->output_currency = output_currency;
}

double Converter::convert() {
  const auto rate =
      this->exchange_rates[this->input_currency][this->output_currency];

  return this->input_amount * rate;
}

double Converter::get_input_amount() { return this->input_amount; }