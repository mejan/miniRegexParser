#include "parser.h"

parser::parser():text(""),expression(),ans(),ansIndex(0),startPos(0){}

parser::parser(std::string expr):text(""),expression(expr),ans(),ansIndex(0),startPos(0){
	// test code for the regex.
	std::string tmp ="";
	std::cout << std::endl << std::endl << "parser Print: " << std::endl;
	for(int i = 0; i < 14; i++){
		switch(expression.getToken()){
			case token::ID:
				tmp = "ID";
				break;
			case token::REP:
				tmp = "REP";
				break;
			case token::OR:
				tmp = "OR";
				break;
			case token::LPAR:
				tmp ="LPAR";
				break;
			case token::RPAR:
				tmp ="RPAR";
				break;
			case token::END:
				tmp = "END";
				break;
		}
		std::cout << "The Token: " << tmp;
		if(tmp == "ID"){
			std::cout << " And the ID " << expression.getId();
		}
		std::cout << std::endl;
	} //End of test code.
}

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
	startPos = 0;
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
	return 1; // will always return true.
}

bool parser::match(bool conOrNot){
	std::string tmpStr = expression.getId();

	if(conOrNot){ //Check if the it's a concat.

		if(ans.empty()){ // if ans.size() is 0, then we need to search the whole text
			size_t tmpPos = text.find(tmpStr);

			if(tmpPos != std::string::npos){
				std::string tmpStr2 = text.substr(tmpPos,tmpStr.size());
				ans.push_back(tmpStr2);
				// Change start pos for next search.
				startPos = tmpPos+tmpStr.size();
				std::cout << "klar" << std::endl;

			}

		} else{ //else it has to be the next char + tmpStr size.
			std::cout << "kommer vi in?" << std::endl;
			std::string tmpStr2 = text.substr(startPos, tmpStr.size());
			std::cout << "substr: " << tmpStr2 
					  << " sökt: "<< tmpStr << std::endl;
			if(tmpStr2 == tmpStr){
				ans.push_back(tmpStr);
				startPos = startPos+tmpStr.size();
				for(size_t testSkit = startPos; testSkit<text.size(); testSkit++){
					std::cout << "$: " << text[testSkit] <<std::endl;
				}
			}
		}

	} else{ // has to be repeat.

	}
	return 0;

}