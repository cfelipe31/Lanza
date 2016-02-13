/*
 *Universidade Federal do Rio de Janeiro
 *Escola Politecnica
 *Departamento de Eletronica e de Computacao
 *Prof. Marcelo Luiz Drumond Lanza
 *EEL 270 - Computacao II - Turma 2015/2
 *       
 *$Author$
 *$Date$
 *$Log$
 */

#include "guTypes.h"
#include "guFunctions.h"
#include <string.h>

guLanguageType
GuGetLanguageIndex(char * language)
{

  if(strcmp(language, "portuguese") == 0)
  {
    return guPortuguese;
  }

  
  return guEnglish;
 
}
                                        
/* $RCSfile$ */
