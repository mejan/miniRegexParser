#include "regex.h"

regex::regex():inRegex(),tokenList(){}

regex::regex(std::string ex):inRegex(ex),tokenList(){
	// Add string to container.
	if(!makeRegex())
		exit(0);
}

regex::~regex(){
	for(ittp it = tokenList.begin(); it != tokenList.end(); it++){
		delete (*it);
	}
}

void regex::addExpresstion(std::string ex){
	inRegex = ex;
	if(!makeRegex())
		exit(0);
}

const std::vector<token*> regex::getTokenList(){
	return tokenList;
}

const token regex::getToken(size_t i){
	return (*tokenList[i]);
}

void regex::printTokens(){
	if(tokenList.size() > 0){
		size_t i = 0;
		for(ittp it = tokenList.begin(); it != tokenList.end(); it++, i++){
			switch( (*(*it)) ){
				case IDENT:
					std::cout << "id: " << getIdChar(i) <<std::endl;
					break;
				case END:
					std::cout << "end: " << getIdChar(i) << std::endl;
					break;
				case CONTINUE_OP:
					std::cout << "con op: " << getIdChar(i) << std::endl;
					break;
				case OR_OP:
					std::cout << "or op: " << getIdChar(i) << std::endl;
					break;
				case LEFT_PAREN:
					std::cout << "left par: " << getIdChar(i) << std::endl;
					break;
				case RIGHT_PAREN:
					std::cout << "right par: " << getIdChar(i) << std::endl;
					break;
				case SYN_ER:
					std::cout << "syn error: " << getIdChar(i) << std::endl;
					break;
			}
		}
	}
}

bool regex::makeRegex(){
	for(its it = inRegex.begin(); it != inRegex.end(); it++){

		if(isalpha(*it) || isdigit(*it)){
			for(its it2 = it+1; it2 != inRegex.end(); it2++){
				if( !(isalpha(*it2) || isdigit(*it2)) ){
					break;
				}
			}

			addToken(IDENT);

		} else{
			token tmp = lookup(*it);
			if(tmp == SYN_ER){
				return 0;
			}

			addToken(tmp);
		}
	}
	if(!inRegex.size() == 0)
		addToken(END);
	printTokens();
	return 1;
}

char regex::getIdChar(size_t i){
	return inRegex[i];
}

size_t regex::getSize(){
	return tokenList.size();
}

token regex::lookup(char toLookUp){
	switch (toLookUp){
		case '(':
			return LEFT_PAREN;
		case ')':
			return RIGHT_PAREN;
		case '+':
			return OR_OP;
		case '*':
			return CONTINUE_OP;
		default:
			std::cout << "Syntax error! see: " << toLookUp << std::endl;
			return SYN_ER;
	}
}

void regex::addToken(token toAdd){
	tokenList.push_back(new token);
	(*tokenList[tokenList.size()-1]) = toAdd;
}