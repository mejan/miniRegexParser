#include "parser.h"

parser::parser():searchIn(""),tokens(){}

parser::parser(std::string ex):searchIn(""),tokens(){
	tokens.addExpresstion(ex);
}

parser::parser(std::string fileName, std::string ex):searchIn(""),tokens(){
	addFile(fileName);
	tokens.addExpresstion(ex);
}

parser::~parser(){}

void parser::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

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
}

void parser::addNewText(std::string matchingText){
	searchIn = matchingText;
}

void parser::addNewExpretion(std::string ex){
	tokens.addExpresstion(ex);
}

void parser::exprestion(){

}

bool parser::concat(){
	
}

bool parser::parentes(){

}

bool parser::repeat(){
	
}