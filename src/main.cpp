#include "dae.h"

#include <chrono>

INT main( INT ArgC, CHAR **ArgV )
{
  std::vector<std::string> tokens;
  std::vector<dae::tag> Tags;

  dae::scanner sc;
  dae::parser ps;

  std::string in;

  std::cin >> in;

  sc.Open(in);
  sc.Scan(tokens);

  ps.Open(tokens);
  ps.Parse(Tags);

  for (auto &L : Tags)
  {
    std::cout << "TAG: \n";

    std::cout << "  Name: " << L.Name << '\n';

    for (auto &n : L.AttribsNames)
      std::cout << "  " << n << " = " << L.Attribs[n] << "\n";
  }
  sc.Close();
  return 0;
}