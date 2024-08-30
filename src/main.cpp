#include <iostream>

#include "converter.hpp"
#include "validation.hpp"

int main(int argc, char *argv[]) {
  ExchangeRates exchange_rates = ExchangeRates();

  Validator validator = Validator(exchange_rates);

  if (!validator.is_argc_valid(argc) || !validator.is_input_currency_valid(argv[2]) ||
      !validator.is_output_currency_valid(argv[2],argv[3]) ) 
  {
    return -1;
  }

  Converter converter =
      Converter(exchange_rates, std::stod(argv[1]), argv[2], argv[3]);

 
  std::cout << converter.get_input_amount() << " in " << argv[2] << " is "
            << converter.convert() << " in " << argv[3] << std::endl;

  return 0;
}