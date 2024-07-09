#include <iostream>
#include "validation.hpp"
#include "converter.hpp"

int main(int argc, char *argv[])
{

  Validator validator = Validator(argc, argv[2], argv[3]);

  if (!validator.is_argc_valid() || !validator.is_input_currency_valid() || !validator.is_output_currency_valid())
  {
    return -1;
  }

  Converter converter = Converter(std::stod(argv[1]), argv[2], argv[3]);

  std::cout << converter.get_input_amount() << " in " << argv[2] << " is " << converter.convert() << " in " << argv[3] << std::endl;

  return 0;
}