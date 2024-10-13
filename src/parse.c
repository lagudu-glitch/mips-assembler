#include "parse.h"


void
_parse (char* fname)
{
  // vars
  int lc = 0;
  char buff[MAX_LINE_LENGTH];

  // open the file
  FILE *fp  = fopen (fname, "r");
  FILE *fpc = fp;

  // check if we can open file
  if (fp == NULL)
  {
    printf ("Error: could not open file %s\n", fname);
    return;
  }


  // count the number of lines in the file
  while (fgets (buff, sizeof(buff), fpc))
  {
    lc++;
  }
  
  // print the number of lines
  printf ("Number of lines: %d\n", lc);

  // close the file
  fclose(fp);
}
