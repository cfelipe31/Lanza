/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2015/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Marcelo Luiz Drumond Lanza
 *
 * $Author$
 * $Date$
 * $Log$
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "Libraries/mlcgi.h" 
#include "guUserInterface.h"
#include "guTypes.h"
#include "guFunctions.h"
#include "guConfig.h"


#define AMBIENTE_EXECUCAO_INVALIDO 	1
#define COMPRIMENTO_MAXIMO_LINGUA	20

int
main (int argc, char **argv)
{
  environmentType ambiente;
  char languageString [COMPRIMENTO_MAXIMO_LINGUA + 1];
  guLanguageType language;
  unsigned codigoRetorno;


  if (mlCgiInitialize (&ambiente))
    exit (ML_CGI_OK);

  if (ambiente == commandLine)
  {
    printf ("Este programa só pode ser executado via web\n");
    exit (AMBIENTE_EXECUCAO_INVALIDO);
  }

  mlCgiBeginHttpHeader ("text/html");
  mlCgiEndHttpHeader ();

  codigoRetorno = mlCgiGetFormStringNoNewLines ("guLanguage", 
                                                languageString, 
                                                COMPRIMENTO_MAXIMO_LINGUA);
  if (codigoRetorno != ML_CGI_OK)
  {
    printf ("Erro obtendo o valor do campo numero - Erro #%i\n", codigoRetorno);
    mlCgiFreeResources ();
    exit (ML_CGI_OK);
  }

  language = GuGetLanguageIndex(languageString);


  printf ("<html>\n");
  printf ("  <head>\n");
  printf ("    <title>\n");
  printf ("      %s\n",
                 GuGetWebUserInterfaceMessage(guWelcomeMessage,language));
  printf ("    </title>\n");
  printf ("  </head>\n");
  printf ("  <body bgcolor=\"white\">\n");
  printf ("    <h1 style=\"text-align: center;\">"
              "<span style=\"color: #cc99ff;\">GNUber</span></h1>\n");
  printf ("    <div style=\"text-align: center;float: center\">\n");
  printf ("      <embed src=\"./%s\" width=\"600\" height=\"400\">\n",
                 GuGetWebUserInterfaceMessage(guLicenseUrl,language));
  printf ("    <\div");
  printf ("  </body>\n");
  printf ("</html>\n");

  mlCgiFreeResources ();
  return ML_CGI_OK;
}

/* $RCSfile$ */
