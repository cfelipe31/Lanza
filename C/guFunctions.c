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

/*sprintf*/
#include <stdio.h>
/*srand, rand*/
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/*time*/
#include <time.h>
#include <unistd.h>

#include "guFunctions.h"

guErrorType 
guCheckEmail (char *validatedString, char *validChars,
              size_t minLength, size_t maxLength)
{
  unsigned stringIndex;
  unsigned specificChar;
  unsigned ampersandCount = 0;


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
      if (validChars[specificChar] == validatedString[stringIndex] || 
          validatedString[stringIndex] == '@')
        break;
    
    if (validChars[specificChar] != validatedString[stringIndex])
      return guInvalidString;
    
    if (validatedString[stringIndex] == '@')
      ampersandCount++;
  }

  if(ampersandCount > 1)
    return guTooManyAmpersands;

  return guOk;
}


guErrorType 
guCheckNickname (char *validatedString, char *validChars,
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
      if (validChars[specificChar] == validatedString[stringIndex] || 
          validChars[specificChar] == '.')
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

guErrorType 
guCheckStringField (char *validatedString, char *validChars,
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

guErrorType 
guCreateRandomString (char *validChar, unsigned long stringLength, char *generatedString)
{
  /*Checking passed Data*/
  if (!validChar)
    return guNullPointer;

  if (!stringLength)
    return guZeroValue;

  if (!generatedString)
    return guNullPointer;

  if (!strlen(validChar))
    return guZeroLength;

  srand( time(NULL) );

  /*Generating the string backwards*/
  generatedString[stringLength] = '\0';

  for (; stringLength > 0; stringLength--)
  {
    generatedString[stringLength-1] = validChar[rand()%( (unsigned)strlen(validChar))];
  }

  return guOk;
}

guErrorType guCreateNickname (char *name, char *firstNickname, char *secondNickname)
{

  char *auxName;
  char auxCompleteName[GU_MAX_NAME_LENGTH];
  char firstName[GU_MAX_NAME_LENGTH];
  char lastName[GU_MAX_NAME_LENGTH];
  char middleName[GU_MAX_NAME_LENGTH];


  if (!name)
    return guNullPointer;

  if (!firstNickname)
    return guNullPointer;

  if (!secondNickname)
    return guNullPointer;


  /*strtok operates on the parsed string*/
  strcpy(auxCompleteName, name);

  auxName = strtok(auxCompleteName, " ");
  strcpy(firstName, auxName);

  auxName = strtok(auxCompleteName, " ");

  if (!auxName)
    return guNoSurname;

  strcpy(lastName, auxName);

  strcpy(middleName, lastName);

  auxName = strtok(auxCompleteName, " ");

  if(!auxName)
  {
    sprintf(firstNickname, "%s%s", firstName, middleName);
    return guOk;
  }

  while(!(auxName = strtok(auxCompleteName, " ")))
  {
   strcpy(middleName, lastName);
   strcpy(lastName, auxName); 
  }

  sprintf(firstNickname, "%s%s", firstName, lastName);
  sprintf(secondNickname, "%s%s", firstName, middleName);

  return guOk;
}

guLanguageType
GuGetLanguageIndex(char * language)
{
  if(!language)
    return guNullPointer;

  if(strcmp(language, "portuguese") == 0)
  {
    return guPortuguese;
  }
  return guEnglish;
}


                                        
/* $RCSfile$ */
