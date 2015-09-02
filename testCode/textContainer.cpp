#include "textContainer.h"

textContainer::textContainer():text(""),currentPos(text.begin()),stopPos(text.end()){}

textContainer::textContainer(std::string inText):text(inText),currentPos(text.begin()),stopPos(text.end()){}

textContainer::~textContainer(){}

void textContainer::addText(std::string inText){
	text = inText;
}

void textContainer::addMoreText(std::string inText){
	text += inText;
}

void textContainer::addFileText(std::string file){
	addFromFile(file, 1);
}

void textContainer::addMoreFileText(std::string file){
	addFromFile(file, 0);
}

void textContainer::addFromFile(std::string file, bool removeOLd){
	std::ifstream in(file.c_str());

	if(!in.is_open()){
		std::cerr << "Couldn't open the file: " << file
			  << " please check the file name." << std::endl;
	}

	std::string tmpStr="";

	if(removeOLd){
		getline(in, tmpStr);
		addText(tmpStr);
	}
	
	while(!in.eof()){
		getline(in, tmpStr);
		addMoreText(tmpStr);
	}
	in.close();
}