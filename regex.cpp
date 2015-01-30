#include "regex.h"

regex::regex():findMatchIn(""),tokens(){}

regex::regex(std::string ex):findMatchIn(""),tokens(){
	tokens.addExpresstion(ex);
}

regex::regex(std::string fileName, std::string ex):findMatchIn(""),tokens(){
	addFile(fileName);
	tokens.addExpresstion(ex);
}

regex::~regex(){}

void regex::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << fileName << std::endl;
		exit(0);
	}
	std::string tmp;
	while(getline(in, tmp)){
		if(in.eof())
			break;

		findMatchIn += tmp;
		findMatchIn += "\n";
	}
}

void regex::addNewText(std::string matchingText){
	findMatchIn = matchingText;
}

void regex::addNewExpresion(std::string ex){

}

void regex::concat(std::string toFind){

}