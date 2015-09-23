#include "parser.h"

parser::parser():text(""),expression(),ans(),startPos(0),prevToken(token::SYNER){}

parser::parser(std::string expr):text(""),expression(expr),ans(),startPos(0),prevToken(token::SYNER){}

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
	// Will contiune to npos.
	/*while(1){
		expression.resetIndex();
		if(expr()){
			std::cout << "The match that was found:" << std::endl;
			ansPrint();
			return;
		}
	}*/

	if(!expr()){
		std::cout << "Match not found." << std::endl;
		return;
	} else{
		std::cout << "The match that was found:" << std::endl;
		ansPrint();
		return;
	}
}

bool parser::expr(){
	token tmpToken = expression.getToken();
	switch(tmpToken){
		case token::ID:
			if(!conOperation()){
				if(expression.getToken() == token::OR){
					if(!orOperation()){
						return false;
					}
				} else{
					return false;
				}
			}
			expr();
			break;
		case token::REP:
			if(prevToken != token::ID){
				std::cerr << "Syntax Error, * most have an concat before like: 'concat*'"
						  << std::endl;
				exit(0);
			}			
			repOperation();
			expr();
			break;
		case token::OR:
			if(!orOperation()){
				std::cout << "Syntax Error, not a concat before the '+' sign." << std::endl;
				return false;
			}
			expr();
			break;
		case token::LPAR:
			if(!parOperation()){
				return false;
			}
			// expr();
			break;
		case token::RPAR:
			prevToken = token::RPAR;
			tmpToken = expression.getToken();
			if(tmpToken == token::END){
				return true;
			} else if(tmpToken == token::ID){
				if(!conOperation()){
					if(expression.getToken() == token::OR){
						if(!orOperation()){
							return false;
						}
					} else{
						return false;
					}
				}
				expr();
				break;
			} else{
				return false;
			}
		case token::END:
			return true;
		case token::SYNER:
			std::cerr << "Syntax Error" << std::endl;
			return false;
	}
}

bool parser::orOperation(){
	token tmpToken = expression.getToken();
	
	if(tmpToken != token::ID){
		std::cerr << "Syntax Error, with or operation." << std::endl;
		exit(0);
	}
	std::string tmpStr = expression.getPrevId();

	if(tmpStr == "Error&"){
		std::cout << "Syntax Error, with or operation." << std::endl;
	}

	if(ans.size() > 0){
		if(prevToken == token::ID){
			if(ans[ans.size()-1] == tmpStr){
				prevToken = tmpToken;
				return true;
			}
		}else if(prevToken == token::REP){
			if(ans[ans.size()-2] == tmpStr){
				prevToken = tmpToken;
				return true;
			}
		}
	}
	prevToken = tmpToken;
	return conOperation();
}

bool parser::parOperation(){
	prevToken = token::LPAR;
	return expr();
}

bool parser::conOperation(){
	prevToken = token::ID;
	return match();
}

bool parser::repOperation(){
	prevToken = token::REP;
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