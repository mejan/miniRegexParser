#include "parser.h"

parser::parser():text(),expression(),ans(),ansIndex(0){}

parser::~parser(){}

void parser::expr(){
	switch(expression.getToken()){
		case token::IDENT:
			conOperation();
			break;
		case token::CONTINUE_OP:
			repOperation();
			break;
	}
}

bool parser::orOperation(){
	// leftExpr OR rightExpr
	return 0;
}

bool parser::parOperation(){
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