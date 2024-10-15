#include "parse.h"


void
_parse (char* fname)
{
  // vars
  int  lc, wc;
  char buff  [MAX_CHARS];
  char *line [MAX_WORDS];
  
  lc = 0;
  wc = 0;

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

  // read all the lines
  while (fgets(buff, sizeof(buff), fp))
  {
    // Tokenize and process line
    char *token = strtok(buff, " \t\n");
    while (token != NULL && wc < MAX_WORDS)
    {
      line [wc] = malloc (strlen (token) + 1);
      strcpy (line [wc], token);
      wc++;
      token = strtok (NULL, " \t\n");
    }

    printf ("Words in the line : \n");
    for (int i = 0; i < wc; i++)
    {
      printf ("%s\n", line[i]);
      free (line[i]);
    }
  }

  // print the number of lines
  printf ("Number of lines: %d\n", lc);

  // close the filegt
  fclose(fp);
}
