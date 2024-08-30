#pragma once
#include <map>
#include <string>

#include "exchange_rates.hpp"

class Converter {
 private:
  double input_amount;
  std::string input_currency;
  std::string output_currency;

 public:
  ExchangeRates &exchange_rates;
  Converter(ExchangeRates &exchange_rates, double input_amount,
            std::string input_currency, std::string output_currency);
  double convert();
  double get_input_amount();
};