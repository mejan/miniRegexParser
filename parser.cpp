#include "parser.h"

parser::parser():text(),expression(),ans(),ansIndex(0),paranteses(0){}

parser::parser(std::string expr):text(),expression(expr),ans(),ansIndex(0),paranteses(0){}

parser::~parser(){}

void parser::expr(){
	token tmp = expression.getToken()
	switch(tmp){
		case token::ID:
			conOperation();
			break;
		case token::REP:
			repOperation();
			break;
		case token::OR:
			orOperation();
			break;
		case token::LPAR:
			parOperation();
			break;
		case token::RPAR:
			break;
		case token::END:
			break;
	}
}

bool parser::orOperation(){
	// leftExpr OR rightExpr
	return 0;
}

bool parser::parOperation(token tmpT){
	// (EXPR)
	return 0;
}

bool parser::conOperation(){
	// id
	return 0;
}

bool parser::repOperation(){
	// check the con from before and see if it continues.
	return 1;
}

bool parser::match(bool conOrNot){
	char tmp = expression.getExp();
	if(isalnum(tmp)){
		if(conOrNot){ //Check if the it's a concat.
			if(ans.size() == 0){ // if ans.size() is 0, then we need to search the whole text

			} else{ //else it has to be the next char.

			}
			return 0;
		} else{ // has to be repeat.

		}
	}
	return 0;
}