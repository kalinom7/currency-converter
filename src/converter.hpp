#pragma once
#include <map>
#include <string>

class Converter {
 private:
  double input_amount;
  std::string input_currency;
  std::string output_currency;
  std::map<std::string, std::map<std::string, double>> exchange_rates{
      {"PLN", {{"USD", 0.25}, {"CHF", 0.23}}},
      {"USD", {{"PLN", 3.8}}},
  };

 public:
  Converter(double input_amount, std::string input_currency,
            std::string output_currency);
  double convert();
  double get_input_amount();
};