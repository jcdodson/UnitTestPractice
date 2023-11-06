#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}
bool Password::has_mixed_case(string phrase){
	bool flag = 0;
	bool lower = 0;
	bool upper = 0;
	int index = 0;

	while(index < phrase.length()){
		if(isupper(phrase[index])){
			upper = 1;
		}
		if(islower(phrase[index])){
			lower = 1;
		}
		index++;
	}
	if(lower==1 && upper==1){
		flag = true;
	}
		
	return flag;
}
