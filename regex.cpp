#include "regex.h"

regex::regex():findMatchIn(""){}

regex::regex(std::string fileName):findMatchIn(""){
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
	for(its it = findMatchIn.begin(); it != findMatchIn.end(); it++)
		std::cout << *it;
}

regex::~regex(){
}

void regex::getMatch(std::string toFind){

}