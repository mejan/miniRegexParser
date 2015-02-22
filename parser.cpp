#include "parser.h"

parser::parser():searchIn(""),tokens(),posInSearch(0){}

parser::parser(std::string ex):searchIn(""),tokens(),posInSearch(0){
	tokens.addExpresstion(ex);
}

parser::parser(std::string fileName, std::string ex):searchIn(""),tokens(),posInSearch(0){
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

bool parser::findMatch(std::string toFind){
	if(stackFound.size() == 0){
		size_t tmp = searchIn.find(toFind, posInSearch);
	
		if(tmp != std::string::npos){
			stackFound.push(searchIn.substr(tmp, toFind.size()));
			std::cout << "To first value found: " << stackFound.top() << " to find value: "<< toFind << std::endl;
			posInSearch = tmp + toFind.size(); //might have to make -1 on.
			return 1;
		} else if(tmp == std::string::npos){
			std::cout << "Wanted text can't be found in the text: " << toFind << std::endl
			<< "Text program is lookin in is: " << searchIn << std::endl;
			exit(0);
		}
	} else{
		std::string tmpStr = searchIn.substr(posInSearch, toFind.size());
		if(tmpStr == toFind){
			std::cout << "To find value: " << toFind << " tmp string value: " << tmpStr << std::endl;
			stackFound.push(tmpStr);
			posInSearch += toFind.size();
			return 1;
		}
	}
	return 0;
}