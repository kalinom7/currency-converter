#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

class ExchangeRates {
 private:
  std::map<std::string, std::map<std::string, double>> rates = {};

 public:
  ExchangeRates() {}

  bool load(std::string filename);
  void print();
  double get_rate(std::string input_currency, std::string output_currency);
  bool check_for_input_currency(std::string input_currency);
  bool check_for_output_currency(std::string input_currency,
                                 std::string output_currency);
};