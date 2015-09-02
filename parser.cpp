#include "parser.h"

parser::parser():text(""),expression(),ans(),ansIndex(0),startPos(text.begin()){}

parser::parser(std::string expr):text(""),expression(expr),ans(),ansIndex(0),startPos(text.begin()){}

parser::~parser(){}

void parser::expr(){
	token tmp = expression.getToken();
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
			parOperation(tmp);
			break;
		case token::RPAR:
			break;
		case token::END:
			break;
	}
}

void parser::addText(std::string inText){
	text += inText;
	startPos = text.begin();
}

void parser::addTextFile(std::string filename){
	std::ifstream in(filename.c_str());

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << filename
				  << " please check the file name." << std::endl;
	}

	std::string tmpStr="";
	
	while(!in.eof()){
		getline(in, tmpStr);
		addText(tmpStr);
	}
	in.close();
}

void parser::emptyText(){
	text = "";
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
	/*std::string tmp = expression.getExp();
	iter it;
	if(isalnum(tmp)){
		if(conOrNot){ //Check if the it's a concat.
			if(ans.size() == 0){ // if ans.size() is 0, then we need to search the whole text

			} else{ //else it has to be the next char.

			}
		} else{ // has to be repeat.

		}*/
	return 0;

}