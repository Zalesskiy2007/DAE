/* FILE NAME   : xml.h
 * PROGRAMMER  : MZ2
 * LAST UPDATE : 01.09.2023
 * PURPOSE     : dae compression project.
 *               xml header file.
 */

#ifndef __xml_h_
#define __xml_h_

#include "def.h"

#include "parser/parser.h"
#include "parser/scanner.h"
#include <string>
#include <iostream>

/* Project namespace */
namespace dae
{
  /* Xml class */
  class xml
  {
  private:
    scanner sc;
    parser ps;
    std::vector<std::string> tokens;
    std::vector<tag> Tags;
  public:

    /* Class constructor */
    xml()
    {
    }

    /* Class constructor */
    xml( std::string &in )
    {
      Load(in);
    }

    /* Class destructor */
    ~xml()
    {
    }

    BOOL Load( std::string &in )
    {
      if (!sc.Open(in))
        return FALSE;

      sc.Scan(tokens);

      ps.Open(tokens);
      ps.Parse(Tags);

      sc.Close();  

      return TRUE;
    }

    VOID Display( VOID )
    {
      for (INT i = 0; i < Tags.size(); i++)
        DisplayRec(Tags[i], 0);
    }
  private:
    VOID DisplayRec( tag &V, INT RecLevel )
    {
      std::string word;

      if (V.Tags.size() == 0)
      {
        word = "";
        for (INT i = 0; i < RecLevel * 4; i++)
          word += " ";
        std::cout << word << V.Name << '\n';

        return;
      }
      word = "";
      for (INT i = 0; i < RecLevel * 4; i++)
        word += " ";
      std::cout << word << V.Name << '\n';

      for (INT j = 0; j < V.Tags.size(); j++)
        DisplayRec(V.Tags[j], RecLevel + 1);
    }
  };  /* End of 'xml' class */
} /* end of 'dae' namespace */


#endif /* __xml_h_ */

/* END OF 'xml.h' FILE */
