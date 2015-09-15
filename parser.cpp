#include "parser.h"

parser::parser():text(""),expression(),ans(),startPos(0){}

parser::parser(std::string expr):text(""),expression(expr),ans(),startPos(0){}

parser::~parser(){}

void parser::expr(){
	token tmp = expression.getToken();
	switch(tmp){
		case token::ID:
			conOperation();
			expr();
			break;
		case token::REP:
			repOperation();
			expr();
			break;
		case token::OR:
			orOperation();
			expr();
			break;
		case token::LPAR:
			parOperation(tmp);
			expr();
			break;
		case token::RPAR:
			expr();
			break;
		case token::END:
			return;
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
	
	// test code
	expr();
	std::cout << "From ans vector, size of ans:" << ans.size() << std::endl;
	for(viter vit = ans.begin(); vit != ans.end(); vit++){
		std::cout << *vit << std::endl;
	}
}

void parser::emptyText(){
	text = "";
}

bool parser::orOperation(){
	std::string tmpStr = expression.getPrivId();
	
	if(ans.size() > 0){
		if(ans[ans.size()-1] == tmpStr){
			return true;
		}
	}
	token tmp = expression.getToken();
	if(tmp == token::ID){
		return conOperation();
	} else{
		std::cerr << "Syntax error, or sign that missing id like: 'id+id'" << std::endl;
		exit(0);
	}
}

bool parser::parOperation(token tmpT){
	
	return false;
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
	std::cout << "id: " << tmpStr << std::endl;

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
	std::cout << "id: " << tmpStr << std::endl;

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