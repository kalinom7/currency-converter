#include "exchange_rates.hpp"

#include <fstream>
#include <map>
#include <sstream>
#include <string>

double ExchangeRates::get_rate(std::string input, std::string output) {
  const auto rate = this->rates[input][output];
  return rate;
}

bool ExchangeRates::check_for_input_currency(std::string input_currency) {
  const auto rates = this->rates;
  bool is_input_currency_in_rates = rates.find(input_currency) != rates.end();

  return is_input_currency_in_rates;
}

bool ExchangeRates::check_for_output_currency(std::string input_currency,
                                              std::string ouput_currency) {
  bool is_output_currency_in_rates =
      this->rates[input_currency][ouput_currency] > 0;

  return is_output_currency_in_rates;
}

bool ExchangeRates::load(std::string filename) {
  auto file = std::ifstream(filename);

  if (!file.is_open()) {
    return false;
  }

  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);

    std::string input_currency;
    std::getline(ss, input_currency, ',');

    std::map<std::string, double> output_currencies;
    while (ss.good()) {
      std::string output_currency;
      std::string rate_str;
      std::getline(ss, output_currency, ',');
      std::getline(ss, rate_str, ',');
      double rate = std::stod(rate_str);
      output_currencies[output_currency] = rate;
    }

    this->rates[input_currency] = output_currencies;
  }

  return true;
}

void ExchangeRates::print() {
  for (const auto &input_currency : this->rates) {
    std::cout << input_currency.first << " => ";
    for (const auto &output_currency : input_currency.second) {
      std::cout << output_currency.first << " " << output_currency.second
                << ", ";
    }
    std::cout << std::endl;
  }
}