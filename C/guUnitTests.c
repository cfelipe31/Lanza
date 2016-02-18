
#include <stdio.h>

#include "guUnitTests.h"
#include "guFunctions.h"
#include "guTypes.h"
#include "guErrors.h"

#define OK	0

//BUGS: 

//If I create an unitialized pointer and pass it to a function 
// then run it in test_run, it wont detect its unitialized unless
// I explicitly define it as type *pointer = NULL


//-------------------------------------------------
// GuGetLanguageIndex()                        
//-------------------------------------------------

void GuGetLanguageIndex_01() 
{

     char *language = "portuguese";
    
    _it_should("Should return \"guPortuguese\" if input = \"portuguese\"", 
    	      (GuGetLanguageIndex(language) == guPortuguese));
}

void GuGetLanguageIndex_02() 
{

     char *language = "english";
    
    _it_should("Should return \"guEnglish\" if input = \"english\"", 
    	      (GuGetLanguageIndex(language) == guEnglish));
}

void GuGetLanguageIndex_03() 
{

     char *language = "polish";
    
    _it_should("Should return \"guEnglish\" if input = \"polish\"", 
    	      (GuGetLanguageIndex(language) == guEnglish));
}

void GuGetLanguageIndex_04() 
{

     char *language = NULL;
    
    _it_should("Should return \"guEnglish\" if input is a NULL pointer", 
    	      (GuGetLanguageIndex(language) == guEnglish));
}

//------------------------------------------------
// guCreateRandomString()                      
//------------------------------------------------

void GuCreateRandomString_01() 
{

     unsigned long stringLength = 5;
     char generatedString[10] ={0};
    
    _it_should("Should return \"guOk\" if all parameters are reasonable.", 
    	      (GuCreateRandomString (GU_VALID_PASSWORD_CHARACTERS, stringLength, generatedString) == guOk));

    printf(KCYN "    Length: %lu Generated string: <%s>\n" KNRM, stringLength, generatedString);

}

void GuCreateRandomString_02() 
{


     char *validChar = NULL;
     unsigned long stringLength = 5;
     char generatedString[10] ={0};
    
    _it_should("Should return \"guNullPointer\" if valid character list is unitialized.", 
    	      (GuCreateRandomString (validChar, stringLength, generatedString) == guNullPointer));

}

void GuCreateRandomString_03() 
{


     char *validChar = "abcde";
     unsigned long stringLength = 5;
     char *generatedString= NULL;

    _it_should("Should return \"guNullPointer\" if generetade string placeholder is unitialized", 
    	      (GuCreateRandomString (validChar, stringLength, generatedString) == guNullPointer));

}

void GuCreateRandomString_04() 
{


     char *validChar = "abcde";
     unsigned long stringLength = 0;
     char generatedString[10] = {0};
    
    _it_should("Should return \"guZeroValue\" if the length of the string is set to zero", 
    	      (GuCreateRandomString (validChar, stringLength, generatedString) == guZeroValue));

}


//------------------------------------------------
// GuEncodePasswordWithSpecificSalt()                      
//------------------------------------------------

void GuEncodePasswordWithSpecificSalt_01() 
{


     char *salt = "$5$1234567891234567";
     char *password = "123456";
     char encodedPassword[150] = {0};
    
    _it_should("Should return \"guOk\" if all parameters are reasonable", 
    	      (GuEncodePasswordWithSpecificSalt (password, salt, encodedPassword) == guOk));

    printf(KCYN "    Salt: <%s>  Password: <%s> Encoded password: <%s>\n" KNRM,salt, password, encodedPassword);

}


//------------------------------------------------
// GuEncodePasswordWithSpecificSalt()                      
//------------------------------------------------

void GuEncodePasswordWithSpecificAlgorithm_01() 
{

     char *password = "123456";
     char encodedPassword[150] = {0};

     guCryptAlgorithms algorithm = guSha256;
    
    _it_should("Should return \"guOk\" if all parameters are reasonable", 
    	      (GuEncodePasswordWithSpecificAlgorithm (password, algorithm, encodedPassword) == guOk));

    printf(KCYN "    Password: <%s> Encoded password: <%s>\n" KNRM, password, encodedPassword);

}


void GuEncodePasswordWithSpecificAlgorithm_02() 
{

     char *password = "123456";
     char encodedPassword[150] = {0};

     guCryptAlgorithms algorithm = (guCryptAlgorithms) 7;
    
    _it_should("Should return \"guInvalidCryptAlgorithm\" if the algorithm is not valid.", 
    	      (GuEncodePasswordWithSpecificAlgorithm (password, algorithm, encodedPassword) == guInvalidCryptAlgorithm));

    printf(KCYN "    Password: <%s> Encoded password: <%s>\n" KNRM, password, encodedPassword);

}



//------------------------------------------------
// Run all tests                      
//------------------------------------------------



void run_tests() 
{

  _test_start("GuGetLanguageIndex");
  _run_test(GuGetLanguageIndex_01);
  _run_test(GuGetLanguageIndex_02);
  _run_test(GuGetLanguageIndex_03);
  _run_test(GuGetLanguageIndex_04);

  _test_start("GuCreateRandomString");
  _run_test(GuCreateRandomString_01);
  _run_test(GuCreateRandomString_02);
  _run_test(GuCreateRandomString_03);    
  _run_test(GuCreateRandomString_04); 
  //TODO: Use string checker function for better tests

  _test_start("GuEncodePasswordWithSpecificSalt");
  _run_test(GuEncodePasswordWithSpecificSalt_01);

  _test_start("GuEncodePasswordWithSpecificAlgorithm");
  _run_test(GuEncodePasswordWithSpecificAlgorithm_01);
  _run_test(GuEncodePasswordWithSpecificAlgorithm_02);
}


int main(int argc, char **argv)
{        

  run_tests();

  _test_result();

  return OK;
}
