#include "textContainer.h"

textContainer::textContainer():inText(){}

textContainer::textContainer(std::string fileName):inText(){
	addFile(fileName);
}

textContainer::~textContainer(){}

void textContainer::printContent(){
	for(itcp it = inText.begin(); it != inText.end(); it++){
		std::cout << (*it) << ", ";
	}
}

void textContainer::pushBackChar(char& toAdd){
	inText.push_back(toAdd);
}

void textContainer::addString(std::string toCon){
	for(its it=toCon.begin(); it != toCon.end(); it++){
		if( !isspace((*it)) ){
			pushBackChar((*it));
		}
	}
}

void textContainer::addFile(std::string fileName){
	std::ifstream in(fileName.c_str());

	if(!in.is_open()){
		std::cout << "Couldn't open the file: " << fileName << std::endl;
		exit(0);
	}

	std::string tmp;

	while(!in.eof()){
		in >> tmp;
		addString(tmp);
	}
	in.close();
}

char textContainer::popFront(){
	char tmp = inText[0];
	inText.erase(inText.begin());
	return tmp;
}

char textContainer::getChar(int i){
	return inText[i];
}

size_t textContainer::getSize(){
	return inText.size();
}