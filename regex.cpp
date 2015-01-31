#include "regex.h"

regex::regex():inParse(),tokenList(){}

regex::regex(std::string ex):inParse(),tokenList(){
	// Add string to container.
	inParse.addString(ex);
	if(!parse())
		exit(0);
}

regex::~regex(){
	for(ittp it = tokenList.begin(); it != tokenList.end(); it++){
		delete (*it);
	}
}

void regex::addExpresstion(std::string ex){
	inParse.addString(ex);
	if(!parse())
		exit(0);
}

const std::vector<token*> regex::getTokenList(){
	return tokenList;
}

const token regex::getToken(int i){
	return (*tokenList[i]);
}

void regex::printTokens(){
	if(tokenList.size() > 0){
		for(ittp it = tokenList.begin(); it != tokenList.end(); it++){
			switch( (*(*it)) ){
				case IDENT:
					std::cout << "id" << std::endl;
					break;
				case END:
					std::cout << "end" << std::endl;
					break;
				case CONTINUE_OP:
					std::cout << "con op" << std::endl;
					break;
				case OR_OP:
					std::cout << "or op" << std::endl;
					break;
				case LEFT_PAREN:
					std::cout << "left par" << std::endl;
					break;
				case RIGHT_PAREN:
					std::cout << "right par" << std::endl;
					break;
				case SYN_ER:
					std::cout << "syn error" << std::endl;
					break;
			}
		}
	}
}

bool regex::parse(){
	for(size_t i = 0; i < inParse.getSize(); i++){

		if(isalpha(inParse.getChar(i)) || isdigit(inParse.getChar(i))){
			addToken(IDENT);


			for(size_t j = i+1; j < inParse.getSize(); j++){
				if( !(isalpha(inParse.getChar(j)) || isdigit(inParse.getChar(j))) ){
					break;
				}
				else{
					addToken(IDENT);
				}
			}

		} else{
			token tmp = lookup(inParse.getChar(i));
			if(tmp == SYN_ER){
				return 0;
			}

			addToken(tmp);
		}
	}
	addToken(END);
	inParse.makeEmpty();
	return 1;
}

char regex::getIdChar(int i){
	return inParse.getChar(i);
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