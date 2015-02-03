#include "parser.h"

parser::parser():searchIn(""),tokens(){
	startSearch = searchIn.begin();
}

parser::parser(std::string ex):searchIn(""),tokens(){
	tokens.addExpresstion(ex);
	startSearch = searchIn.begin();
}

parser::parser(std::string fileName, std::string ex):searchIn(""),tokens(){
	addFile(fileName);
	tokens.addExpresstion(ex);
}

parser::~parser(){}

void parser::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

	searchIn = "";

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << fileName << std::endl;
		exit(0);
	}
	std::string tmp;
	while(getline(in, tmp)){
		if(in.eof())
			break;

		searchIn += tmp;
		searchIn += "\n";
	}
	startSearch = searchIn.begin();
}

void parser::addNewText(std::string matchingText){
	searchIn = matchingText;
}

void parser::addNewExpretion(std::string ex){
	tokens.addExpresstion(ex);
}

void parser::exprestion(){

}

bool parser::concat(size_t i){
	if(tokens.getToken(i) == IDENT){

	} 
}

bool parser::parentes(){

}

bool parser::repeat(){
	
}

void findMatch(std::string toFind){
	
}