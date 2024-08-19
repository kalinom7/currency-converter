#include "exchange_rates.hpp"

#include <map>
#include <string>

double ExchangeRates::get_rate(std::string input, std::string output) {
  const auto rate = this->rates[input][output];
  return rate;
}
