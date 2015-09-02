#include "regex.h"


regex::regex():tokenList(),regExp(){
	setIndex();
}

regex::regex(std::string ex):tokenList(),regExp(){
	setIndex();
	makeTokens(ex);
}

regex::~regex(){}

void regex::setIndex(){
	index.tIndex=0;
	index.rIndex=0;
	index.rTIndex=0;
}

token regex::getToken(){
	if(tokenList.size() <= index.tIndex){
		std::cerr << "Index out of bounce, will return END." << std::endl;
		return token::END;
	}

	token tmp = tokenList[index.tIndex];
	index.tIndex++;

	if(tmp == token::LPAR){
		index.rIndex++;
		index.rTIndex=0;
	} else if(tmp == token::RPAR){
		index.rIndex--;
		index.rTIndex=0;
	}

	return tmp;
}

char regex::getExp(){
	if(regExp.size() <= index.rIndex){
		std::cerr << "Index out of bouce, will return last known." << std::endl;
		return regExp[0];
	} else if(regExp[index.rIndex].size() <= index.rTIndex){
		std::cerr << "Index out of bounce (second), will return last." << std::endl;
		return regExp[index.rIndex][regExp[index.rIndex].size()-1];
	}
	index.rTIndex++;
	return regExp[index.rIndex][index.rTIndex];
}


std::vector<std::string> regex::orSplit(){
	
	std::vector<std::string> forReturn;
	std::string tmpStr="";
	
	for(iter sit = regExp[index.rIndex].begin(); sit != regExp[index.rIndex].end(); sit++){
		if(!isalnum(*sit)){
			forReturn.push_back(tmpStr);
			tmpStr = "";
		} else{
			tmpStr += (*sit);
		}
	}

	if(tmpStr.size() > 0){
		forReturn.push_back(tmpStr);
	}

	return forReturn;
}

void regex::makeTokens(std::string ex){
	
	std::string tmpStr = "";
	regExp.push_back(tmpStr);

	for(iter it = ex.begin(); it != ex.end(); it++){
		
		tmpStr = (*it);
		
		if(isalnum(*it)){
			regExp[index.rIndex] += (*it);

			if(it+1 != ex.end()){
				iter it2 = it+1;
				
				while(isalnum(*it2) && it2 != ex.end()){
					regExp[index.rIndex] += (*it2);
					it2++;
				}
				it = it2-1;

			}
			tokenList.push_back(token::ID);

		} else{
			token tmp = lookUp(*it);

			if(tmp == token::SYNER){
				std::cerr << "Syntax Error please check your expression: " << (tmpStr) << std::endl;
				exit(0);
			} else if(tmp == token::LPAR){
				tokenList.push_back(token::LPAR);
				regExp.push_back(tmpStr);
				index.rIndex++;
			} else if(tmp == token::RPAR){
				tokenList.push_back(token::RPAR);
				regExp[index.rIndex] += (tmpStr);
				index.rIndex--;
			} else{
				tokenList.push_back(tmp);
				regExp[index.rIndex] += (tmpStr);
			}

		}
	}

	if(!ex.size() == 0){
		tokenList.push_back(token::END);

		if(index.rIndex > 0){
			std::cout << "rIndex: " << index.rIndex << std::endl;
			std::cerr << "Syntax Error. You are missing one or more ')'" 
					  << "\nplease check your expression." << std::endl;
			exit(0);
		}
	} else{
		std::cerr << "No expression to process, program will shutdown. " << std::endl;
		exit(0);
	}
}

token regex::lookUp(char toCheck){
	switch(toCheck){
		case '(':
			return token::LPAR;
		case ')':
			return token::RPAR;
		case '*':
			return token::REP;
		case '+':
			return token::OR;
		default:
			return token::SYNER;
	}
}