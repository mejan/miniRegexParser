#include "textContainer.h"

textContainer::textContainer():text(){}

textContainer::textContainer(std::string inText):text(){
	addText(inText);
}

textContainer::~textContainer(){}

void textContainer::addText(std::string inText){
	empStack();
	fillStack(inText);
}

void textContainer::addMoreText(std::string inText){
	std::string fromStack="";
	while(!text.empty()){
		fromStack += text.top();
		text.pop();
	}
	std::reverse(fromStack.begin(), fromStack.end());
	fromStack += inText;
	addText(fromStack);
}

void textContainer::addFileText(std::string file){
	std::ifstream in(file.c_str());
	if(in.is_open()){
		std::string fromFile="";
		std::string tmp;
		while(!in.eof()){
			tmp="";
			getline(in, tmp);
			fromFile += tmp;
		}
		addText(fromFile);
	} else{
		std::cerr << "Couldn't open file " << file << "." << std::endl;
	}
	in.close();
}

void textContainer::addMoreFileText(std::string file){
	std::ifstream in(file.c_str());
	if(in.is_open()){
		std::string fromFile="";
		std::string tmp;
		while(!in.eof()){
			tmp="";
			getline(in, tmp);
			fromFile += tmp;
		}
		addMoreText(fromFile);
	} else{
		std::cerr << "Couldn't open file " << file << "." << std::endl;
	}
	in.close();
}

bool textContainer::isInText(char c){
	while(!text.empty()){
		if(text.top() == c){
			text.pop();
			return 1;
		}
		text.pop();
	}
	return 0;
}

bool textContainer::isTopEquel(char c){
	if(text.top() == c){
		text.pop();
		return 1;
	}
	return 0;
}

bool textContainer::isEmpty(){
	return text.empty();
}

void textContainer::fillStack(std::string inText){
	for(riter rit = inText.rbegin(); rit != inText.rend(); rit++){
		text.push((*rit));
	}
}

void textContainer::empStack(){
	while(!text.empty()){
		text.pop();
	}
}