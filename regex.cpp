#include "regex.h"

regex::regex():toRegex(),result(){}

regex::regex(parser token):toRegex(),result(){
	toRegex = token;

	std::cout << toRegex.getSize() << std::endl;
	for(int i = 0; i < toRegex.getSize(); i++){
		std::cout << getRegexStrings(i) << " " << i << std::endl;
	}
}

regex::~regex(){
	for(itsp it = result.begin(); it != result.end(); it++){
		delete (*it);
	}
}

void regex::addParser(parser token){
	toRegex = token;
}

std::string regex::continueOperation(int start, char toFind){
	int i = start;
	std::string tmp;
	while(toRegex.getExpressionChar(i) == toFind){
		tmp += toFind;
		i++;
	}
	return tmp;
}

std::string regex::getRegexStrings(int current){
	std::string resturnValue;
	if(toRegex.getToken(current) == LEFT_PAREN){
		std::cout << "( in regex" << std::endl;
	} else if(toRegex.getToken(current) == RIGHT_PAREN){
		std::cout << ") in regex" << std::endl;
	} else if(toRegex.getToken(current) == OR_OP){
		std::cout << "OR  in regex" << std::endl;
	} else if(toRegex.getToken(current) == CONTINUE_OP){
		std::cout << "con operation in regex" << std::endl;
	} else if(toRegex.getToken(current) == IDENT){
		std::cout << "IDent in regex" << std::endl;
	} else if(toRegex.getToken(current) == END){
		std::cout << "END in regex" << std::endl;
	} else{
		std::cout << "if this happen something is serigously wrong" << std::endl;
	}
	return "1";
}