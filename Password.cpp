#include "Password.h"
#include <string>

using std::string;
using std::vector;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
Password::Password(){
	pass_history.push_back("ChicoCA-95929");
}

int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}
/*
bool Password::has_mixed_case(string phrase){
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
		
	return (upper && lower);
}
*/
/*
bool Password::has_mixed_case(string pass){
  bool lower = false;
  bool upper = false;
  for(int i = 0; i < pass.size(); i++){
    if( pass[i] >= 'A' && pass[i] <= 'Z' ){
      upper = true;
    }
    else if( pass[i] < 'z'){
      lower = true;
    }
  }
  return upper && lower;
}
*/
bool Password::has_mixed_case(string phrase) {
  int index = 0;
  bool uppercheck = false;
  bool lowercheck = false;

  while( index < phrase.length()){
    if (isupper(phrase[index])) {
      uppercheck = true;
    }
    if (islower(phrase[index])) {
      lowercheck = true;
    }
    index++;
  }

  if(uppercheck == true && lowercheck == true) {
    return true;
  } else {
    return false;
  }
 }

void Password::set(string phrase){
	
	bool flag = true;

	if(phrase.length() < 8){
		flag = false;
	}
	
	if(count_leading_characters(phrase) > 3){
		flag = false;
	}

	if(!has_mixed_case(phrase)){
		flag = false;
	}

	for(int i = 0; i < pass_history.size()-1; i++){
		if(phrase == pass_history[i]){
			flag = false;
		}
	}
	
	if(flag){
		pass_history.push_back(phrase);
	}
}

bool Password::authenticate(string phrase){
	return (phrase == pass_history[pass_history.size()-1]);
}


