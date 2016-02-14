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

#ifndef GU_FUNCTIONS_H 
#define GU_FUNCTIONS_H "@(#)guFunctions.h $Revision$"

#include <stddef.h>
#include "guTypes.h"
#include "guErrors.h"


guLanguageType 
GuGetLanguageIndex(char *);

guErrorType 
guCheckStringField(char *, char *, size_t, size_t);

guErrorType
guCheckNickname(char *, char *, size_t, size_t);

#endif /* #ifndef GU_FUNCTIONS_H */

/* $RCSfile$ */

