#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

class ExchangeRates {
 private:
  std::map<std::string, std::map<std::string, double>> rates = {
      {"PLN", {{"USD", 0.25}, {"CHF", 0.23}}},
      {"USD", {{"PLN", 3.8}, {"CHF", 0.86}}}};

 public:
  ExchangeRates() {}
  
  double get_rate(std::string input_currency, std::string output_currency);

  std::vector<std::string> get_all_currencies() {
    std::vector<std::string> vec;
    for (const auto& pair : this->rates) {
      vec.push_back(pair.first);
    }

    return vec;
  }
};