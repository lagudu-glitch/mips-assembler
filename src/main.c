#include "parse.h"

int
main (int argc, char* argv[])
{
  // check if there are enough args
  if (argc != 3)
  {
    printf ("Error: not enough args\n");
    return EXIT_FAILURE;
  }

  _parse (argv[1]); 
 return EXIT_SUCCESS; 
}
