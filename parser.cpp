#include "parser.h"

parser::parser():text(""),expression(),ans(),startPos(0){}

parser::parser(std::string expr):text(""),expression(expr),ans(),startPos(0){}

parser::~parser(){}

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

void parser::parseExp(){
	if(!expr()){
		std::cout << "Match not found." << std::endl;
		return;
	} else{
		std::cout << "The match that was found:" << std::endl;
		ansPrint();
		break;
	}
}

bool parser::expr(){
	token tmp = expression.getToken();
	switch(tmp){
		case token::ID:
			if(!conOperation())
				if(expression.getToken() == token::OR){
					if(!orOperation()){
						return false;
					}
				} else{
					return false;
				}
			expr();
			break;
		case token::REP:
			repOperation();
			expr();
			break;
		case token::OR:
			if(!orOperation()){
				return false;
			}
			expr();
			break;
		case token::LPAR:
			if(!parOperation(tmp)){
				return false;
			}
			expr();
			break;
		case token::RPAR:
			expr();
			break;
		case token::END:
			return true;
	}
}

bool parser::orOperation(){
	token tmp = expression.getToken();

	if(tmp != token::ID){
		std::cerr << "Syntax error" << std::endl;
		exit(0);
	}
	std::string tmpStr = expression.getPrivId();

	if(tmpStr == "Error"){
		std::cout << "Syntax error" << std::endl;
	}

	if(ans.size() > 0){

		if(ans[ans.size()-1] == tmpStr){
			return true;
		}
	}
	
	return conOperation();
}

bool parser::parOperation(token tmpT){
	bool tmp = false;
	if(tmpT == token::LPAR){
		tmp = expr();
	} else if(tmpT == token::RPAR){
		std::cout << "parOperation: " << tmp << std::endl;
		return tmp;
	} else{
		std::cerr << "Something gone wrong in the application." << std::endl;
		return false;
	}
}

bool parser::conOperation(){
	return match();
}

bool parser::repOperation(){
	repMatch();
	return true; // will always return true.
}

bool parser::match(){
	if(ans.empty()){ // if ans.empty(), then we need to search the whole text.
		return fistMatch();
	} else{ //else it has to be the next char + tmpStr size.
		return nxtMatch();
	}
}

bool parser::fistMatch(){
	std::string tmpStr = expression.getId();

	size_t tmpPos = text.find(tmpStr);

	if(tmpPos != std::string::npos){
		std::string tmpStr2 = text.substr(tmpPos,tmpStr.size());
		ans.push_back(tmpStr2);
		// Change start pos for next search.
		startPos = tmpPos+tmpStr.size();

		return true;

	}
	return false;
}

bool parser::nxtMatch(){
	std::string tmpStr = expression.getId();

	std::string tmpStr2 = text.substr(startPos, tmpStr.size());

	if(tmpStr2 == tmpStr){
		ans.push_back(tmpStr);
		startPos = startPos+tmpStr.size();

		return true;
	}
	return false;
}

void parser::repMatch(){
	std::string tmpStr = "";
	while(ans[ans.size()-1][ans[ans.size()-1].size()-1] == text[startPos]){
		
		if(!(startPos < text.size())){
			break;
		}
		tmpStr += ans[ans.size()-1][ans[ans.size()-1].size()-1];
		startPos = startPos+1;
	}

	if(tmpStr.size() != 0){
		ans.push_back(tmpStr);
	}
}

void parser::ansPrint(){
	for(viter vit = ans.begin(); vit != ans.end(); vit++){
		std::cout << *vit;
	}
	std::cout << std::endl;
}