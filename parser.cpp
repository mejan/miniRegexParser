#include "parser.h"

parser::parser():searchIn(""),tokens(),searchPos(0),tokenListPos(0){}

parser::parser(std::string fileName):searchIn(""),tokens(),searchPos(0),tokenListPos(0){
	addFile(fileName);
}

parser::parser(std::string fileName, std::string ex):searchIn(""),tokens(ex),searchPos(0),tokenListPos(0){
	addFile(fileName);
	expression();
	tokens.printTokensAndText();
}

parser::~parser(){}

void parser::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

	searchIn = "";

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << fileName << std::endl;
		exit(0);
	}

	searchPos = 0;
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
	searchPos = 0;
}

void parser::addNewExpretion(std::string ex){
	tokens.addNewExprestion(ex);
	tokenListPos = 0;

}

void parser::expression(){
	/*if(tokenListPos == 0 || tokens.getToken(tokenListPos) == IDENT){
		switch(tokens.getToken(tokenListPos+1)){
			case IDENT:
				break;
			case CONTINUE_OP:
				break;
			case OR_OP:
				break;
			case LEFT_PAREN:
				break;
			case RIGHT_PAREN:
				break;
			case END:
				break;
			default:
				break;
		}
	}*/
	switch(tokens.getToken(tokenListPos)){
		case IDENT:
			if(tokens.getToken(tokenListPos+1) == CONTINUE_OP){
				repeat();
				tokenListPos++;
			} else if(tokens.getToken(tokenListPos+1) == OR_OP){
				orOP();
				tokenListPos++; // Very likely that I've to change later.
			} else{
				concat();	
			}
			tokenListPos++;
			expression();
			break;
		case LEFT_PAREN:
			parentes();
			tokenListPos++;
			expression();
			break;
		case RIGHT_PAREN:
			if(tokens.getToken(tokenListPos+1) == CONTINUE_OP){
				parentes();
				repeat();
				tokenListPos++;
			} else{
				parentes();
			}
			tokenListPos++;
			expression();
			break;
		case END:
			std::cerr << "oklart vad som ska göras just nu." << std::endl;
			break;
		default:
			std::cerr << "Något är oklart har hänt måste kolla upp!" << std::endl;
			return;
	}
}

bool parser::concat(){
	std::cout << "Concat" << std::endl;
	return true;
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
	std::cout << "or" << std::endl;
	return true;
}

bool parser::parentes(){
	if(tokens.getToken(tokenListPos) == LEFT_PAREN)
		std::cout << "left parantes" << std::endl;
	else if(tokens.getToken(tokenListPos) == RIGHT_PAREN)
		std::cout << "Right parantes" << std::endl;
	return 0;
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
	std::cout << "repeat" << std::endl;
	return 1;
}

bool parser::findMatch(char toMatch){

/*	if(stackFound.size() != 0){
		std::string tmpStr = searchIn.substr(searchPos, toFind.size());
		if(tmpStr == toFind){
			stackFound.push(tmpStr);
			searchPos += toFind.size();
			return 1;
		}
	} else{
		size_t tmp = searchIn.find(toFind, searchPos);
	
		if(tmp != std::string::npos){
			stackFound.push(searchIn.substr(tmp, toFind.size()));
			searchPos = tmp + toFind.size(); //might have to make -1 on.
			return 1;
		} else if(tmp == std::string::npos){
			std::cout << "Wanted text can't be found in the text: " << toFind << std::endl
			<< "The text program is lookin in is: " << searchIn << std::endl;
			exit(0);
		}
	}
	return 0;*/
}