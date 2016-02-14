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

#include <string.h>
#include <stddef.h>

#include "guTypes.h"
#include "guFunctions.h"



guErrorType guCheckNickname (char *validatedString, char *validChars,
                             size_t minLength, size_t maxLength)
{
  unsigned stringIndex;
  unsigned specificChar;
  unsigned dotCount = 0;


  /*Checking passed Data*/
  if (!validChars)
    return guNullPointer;

  if (!validatedString)
    return guNullPointer;

  if (!minLength)
    return guZeroValue;

  if (maxLength < minLength)
    return guMaxMinInvalid;

  /*Verifying length*/
  if (strlen(validatedString) < minLength)
    return guSmallString;

  if (strlen(validatedString) > maxLength)
    return guBigString;

  /*Now looking for invalid chars in the string*/
  for (stringIndex = 0; stringIndex < strlen(validatedString); stringIndex++)
  {
    for (specificChar = 0; specificChar < strlen(validChars); specificChar++)
      if (validChars[specificChar] == validatedString[stringIndex])
        break;
    
    if (validChars[specificChar] != validatedString[stringIndex])
      return guInvalidString;
    
    if (validatedString[stringIndex] == '.')
      dotCount++;
  }

  if(dotCount > 1)
    return guTooManyDots;

  return guOk;
}


guErrorType guCheckStringField (char *validatedString, char *validChars,
                                size_t minLength, size_t maxLength)
{
  unsigned stringIndex;
  unsigned specificChar;
  

  /*Checking passed Data*/
  if (!validChars)
    return guNullPointer;
  
  if (!validatedString)
    return guNullPointer;
  
  if (!minLength)
    return guZeroValue;
  
  if (maxLength < minLength)
    return guMaxMinInvalid;
  
  /*Verifying length*/
  if (strlen(validatedString) < minLength)
    return guSmallString;
   
  if (strlen(validatedString) > maxLength)
    return guBigString;
  
  /*Now looking for invalid chars in the string*/
  for (stringIndex = 0; stringIndex < strlen(validatedString); stringIndex++)
  {
    for (specificChar = 0; specificChar < strlen(validChars); specificChar++)
      if (validChars[specificChar] == validatedString[stringIndex])
        break;
    if (validChars[specificChar] != validatedString[stringIndex])
      return guInvalidString;
  }
  
  return guOk;
}


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
