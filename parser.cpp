#include "parser.h"

parser::parser():searchIn(""),tokens(),posInSearch(0),posInToken(0){}

parser::parser(std::string fileName):searchIn(""),tokens(),posInSearch(0),posInToken(0){
	addFile(fileName);
	tokens.addNewExprestion("");
}

parser::parser(std::string fileName, std::string ex):searchIn(""),tokens(ex),posInSearch(0),posInToken(0){
	addFile(fileName);
	// tokens.addExpresstion(ex);
}

parser::~parser(){}

void parser::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

	searchIn = "";

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << fileName << std::endl;
		exit(0);
	}

	posInSearch = 0;
	std::string tmp;
	while(getline(in, tmp)){
		searchIn += tmp;
		searchIn += "\n";
		if(in.eof())
			break;
	}
}

void parser::addNewText(std::string matchingText){
	searchIn = matchingText;
	posInSearch = 0;
}

void parser::addNewExpretion(std::string ex){
	tokens.addNewExprestion(ex);
}

void parser::expression(){
/*	bool match = concat();
	lex();
	if ( token = token::OR_OP){
		match |= concat(); 
	}*/
}

bool parser::concat(){
/*	lex();
	if ( token == token::ID){
		if(*search == id){
			bool result = concat();
			return true;
		}
		return false;
	}*/
}

bool parser::orOP(){

}

bool parser::parentes(){
/*	lex();
	bool match = expression();
	lex();
	assert( token == token::RIGHT_PAREN);
	if ( match )
		match += currentMatch;
	currentMatch;
	return match;*/
}

bool parser::repeat(){

}

bool parser::findMatch(std::string toFind){
/*	if(stackFound.size() != 0){
		std::string tmpStr = searchIn.substr(posInSearch, toFind.size());
		if(tmpStr == toFind){
			stackFound.push(tmpStr);
			posInSearch += toFind.size();
			return 1;
		}
	} else{
		size_t tmp = searchIn.find(toFind, posInSearch);
	
		if(tmp != std::string::npos){
			stackFound.push(searchIn.substr(tmp, toFind.size()));
			posInSearch = tmp + toFind.size(); //might have to make -1 on.
			return 1;
		} else if(tmp == std::string::npos){
			std::cout << "Wanted text can't be found in the text: " << toFind << std::endl
			<< "The text program is lookin in is: " << searchIn << std::endl;
			exit(0);
		}
	}
	return 0;*/
}