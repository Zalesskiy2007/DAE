#include "dae.h"

#include <chrono>

INT main( INT ArgC, CHAR **ArgV )
{
  dae::xml xml;
  std::string in;
  std::cin >> in;

  auto st = std::chrono::high_resolution_clock::now();
  xml.Load(in);
  auto et = std::chrono::high_resolution_clock::now();

  std::cout << "TIME TO LOAD (MICROSECONDS): " << std::chrono::duration_cast<std::chrono::microseconds>(et - st).count() << "\n";

  std::vector<dae::tag *> t = xml.FindByAttribVal("name", "ANGLE");

  xml.Display();
  return 0;
}