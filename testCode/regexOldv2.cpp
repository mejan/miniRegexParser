#include "regex.h"

regex::regex():tokenList(),textRegex(),index(0){}

regex::regex(std::string ex):tokenList(),textRegex(),index(0){
	if(!makeToken(ex)){
		std::cerr << "Syntax error, else expression is missing." << std::endl;
		exit(0);
	}
}

regex::~regex(){
	// clear the tokenList.
	emptyToken();
}

void regex::addNewExprestion(std::string ex){
	// clear the tokenList
	emptyToken();
	if(!makeToken(ex))
		exit(0);
}

char regex::getTokenCode(){
	if(index < textRegex.size()){
		return textRegex[index];
	}

	std::cout << "Out of bounce!(expression)" << std::endl;
	return 'E';
}

const token regex::getToken(){
	if(index < tokenList.size()){
		return (*tokenList[index]);
		index++;
	}

	std::cerr << "Out of bounce!(Token list)" << std::endl;
	return SYN_ER;
}

size_t regex::getSize(){
	return tokenList.size();
}

void regex::printTokensAndText(){
	for(tokenIt it = tokenList.begin(); it != tokenList.end(); it++){
		switch( (*(*it)) ){
			case IDENT:
				std::cout << "id: " << getTokenCode() <<std::endl;
				break;
			case END:
				std::cout << "end: This is where we die!" << std::endl;
				break;
			case CONTINUE_OP:
				std::cout << "con op: " << getTokenCode() << std::endl;
				break;
			case OR_OP:
				std::cout << "or op: " << getTokenCode() << std::endl;
				break;
			case LEFT_PAREN:
				std::cout << "left par: " << getTokenCode() << std::endl;
				break;
			case RIGHT_PAREN:
				std::cout << "right par: " << getTokenCode() << std::endl;
				break;
			case SYN_ER:
				std::cout << "syn error: " << getTokenCode() << std::endl;
				break;
		}
	}
}

void regex::restart(){
	index=0;
}

bool regex::makeToken(std::string ex){
	for(size_t i = 0; i < ex.size(); i++){
		if(isalnum(ex[i])){
			textRegex.push_back(ex[i]);
			addToken(IDENT);
		} else{
			token tmp = lookup(ex[i]);
			if(tmp == SYN_ER){
				return 0;	
			}
			textRegex.push_back(ex[i]);
			addToken(tmp);
		}
	}

	// This 'if' is to prevent a token list with only the token end.
	if(!ex.size() == 0){
		addToken(END);
	} else{
		return 0;
	}
	return 1;
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
			std::cerr << "Syntax error! see: " << toLookUp << std::endl;
			return SYN_ER;
	}
}

void regex::addToken(token toAdd){
	// allocate new token for vector.
	tokenList.push_back(new token);
	// set value to the new allocated token.
	(*tokenList[tokenList.size()-1]) = toAdd;
}

void regex::emptyToken(){
	// deletes allocated memory.
	for(tokenIt it = tokenList.begin(); it != tokenList.end(); it++){
		delete (*it);
	}
	// erase pointers in the vector.
	tokenList.erase(tokenList.begin(), tokenList.end());
}