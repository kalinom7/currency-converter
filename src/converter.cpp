#include "converter.hpp"

Converter::Converter(ExchangeRates &exchange_rates, double input_amount,
                     std::string input_currency, std::string output_currency)
    : exchange_rates(exchange_rates),
      input_amount(input_amount),
      input_currency(input_currency),
      output_currency(output_currency) {}

double Converter::convert() {
  const auto rate = this->exchange_rates.get_rate(this->input_currency,
                                                  this->output_currency);

  return this->input_amount * rate;
}

double Converter::get_input_amount() { return this->input_amount; }