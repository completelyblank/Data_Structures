#include <iostream>
#include <cstring>
using namespace std;

#define BASE 10

void rabinKarpSearch(char pattern[], char text[], int prime) 
{
  int patternLength = strlen(pattern);
  int textLength = strlen(text);
  int i, j;
  int patternHash = 0;
  int textHash = 0;
  int baseRaised = 1;

  for (i = 0; i < patternLength - 1; i++) 
  {
    baseRaised = (baseRaised * BASE) % prime;	//hashing formula
  }

  for (i = 0; i < patternLength; i++) 
  {
    patternHash = (BASE * patternHash + pattern[i]) % prime; //pattern's hashing
    textHash = (BASE * textHash + text[i]) % prime; //the input text's hashing 
  }

  for (i = 0; i <= textLength - patternLength; i++) 
  {
    if (patternHash == textHash) //meaning that the text can be in the pattern //possiblity still remains it can be an anagram or something
	{
      for (j = 0; j < patternLength; j++) 
	  {
        if (text[i + j] != pattern[j]) //now do linear search
		{
          break;	
        }
      }

      if (j == patternLength) //pattern found as text went through pattern 
	  {
        cout << "Pattern found at position: " << i + 1 << endl;	
      }
    }

    if (i < textLength - patternLength) 
	{
      textHash = (BASE * (textHash - text[i] * baseRaised) + text[i + patternLength]) % prime; //new hashing done //keeps in range of pattern and prime

      if (textHash < 0) 
	  {
        textHash = (textHash + prime);	//so not in negative
      }
    }
  }
}

int main() 
{
  char text[] = "ABCCDDAEFG";
  char pattern[] = "EFG";
  int prime = 13;
  rabinKarpSearch(pattern, text, prime);
}

