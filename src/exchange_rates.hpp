#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

class ExchangeRates {
 private:
  std::map<std::string, std::map<std::string, double>> rates = {
      {"PLN", {{"USD", 0.25}, {"CHF", 0.23}}},
      {"USD", {{"PLN", 3.8}, {"CHF", 0.86}}},
      {"CHF", {{"PLN", 4.57}, {"USD", 1.18}}},
  };

 public:
  ExchangeRates() {}

  double get_rate(std::string input_currency, std::string output_currency);
  bool check_for_input_currency(std::string input_currency);
  bool check_for_output_currency(std::string input_currency,
                                 std::string output_currency);
};