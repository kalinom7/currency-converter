#include <iostream>

#include "converter.hpp"
#include "validation.hpp"

int main(int argc, char *argv[]) {
  ExchangeRates exchange_rates = ExchangeRates();

  Validator validator = Validator(exchange_rates, argc, argv[2], argv[3]);

  if (!validator.is_argc_valid() || !validator.is_input_currency_valid() ||
      !validator.is_output_currency_valid() ||
      !validator.are_currencies_different()) {
    return -1;
  }

  Converter converter =
      Converter(exchange_rates, std::stod(argv[1]), argv[2], argv[3]);

 
  std::cout << converter.get_input_amount() << " in " << argv[2] << " is "
            << converter.convert() << " in " << argv[3] << std::endl;

  return 0;
}