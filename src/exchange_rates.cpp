#include "exchange_rates.hpp"

#include <map>
#include <string>

double ExchangeRates::get_rate(std::string input, std::string output) {
  const auto rate = this->rates[input][output];
  return rate;
}

bool ExchangeRates::check_for_input_currency(std::string input_currency)
{
const auto rates = this -> rates;
bool is_input_currency_in_rates = rates.find(input_currency) != rates.end();

return is_input_currency_in_rates;

}

bool ExchangeRates::check_for_output_currency(std::string input_currency , std::string ouput_currency)
{
  
  bool is_output_currency_in_rates = this->rates[input_currency][ouput_currency] != 0;

  return is_output_currency_in_rates;
}


