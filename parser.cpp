#include "parser.h"

parser::parser(){
	inParse = new textContainer;
	tokenList = new std::vector<token>;
}

parser::parser(std::string ex){
	inParse = new textContainer;
	tokenList = new std::vector<token>;
	// Add string to container.
	inParse->addString(ex);
}

parser::~parser(){
	delete inParse;
	delete tokenList;
}

void parser::addExpresstion(std::string ex){
	// Add string to container.
	inParse->addString(ex);
}

const std::vector<token> parser::getTokenList(){
	return (*tokenList);
}

const token parser::getToken(int& i){
	return tokenList->at(i);
}

void parser::printTokens(){
	if(tokenList->size() > 0){
		for(itt it = tokenList->begin(); it != tokenList->end(); it++){
			switch( (*it) ){
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

token parser::lookup(char toLookUp){
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
bool parser::parse(){
	for(size_t i = 0; i < inParse->getSize(); i++){

		if(isalpha(inParse->getChar(i)) || isdigit(inParse->getChar(i))){
			tokenList->push_back(IDENT);

			for(size_t j = i+1; j < inParse->getSize(); j++){
				if( !(isalpha(inParse->getChar(j)) || isdigit(inParse->getChar(j))) ){
					break;
				}
				else{
					tokenList->push_back(IDENT);
				}
			}

		} else if(lookup(inParse->getChar(i)) == SYN_ER){
			std::cout << std::endl;
			return 0;
		} else{
			tokenList->push_back(lookup(inParse->getChar(i)));
		}
	}
	return 1;
}