#include "dae.h"

#include <chrono>

INT main( INT ArgC, CHAR **ArgV )
{
  dae::xml xml;
  std::string in;

  std::cin >> in;

  xml.Load(in);
  xml.Display();
  return 0;
}