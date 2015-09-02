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
	index.outVIndex=0;
	/*index.rIndex=0;
	index.rTIndex=0;*/
}

token regex::getToken(){
	if(tokenList.size() <= index.tIndex){
		std::cerr << "Index out of bounce, will return END." << std::endl;
		return token::END;
	}

	token tmp = tokenList[index.tIndex];
	index.tIndex++;

	if(tmp == token::LPAR){
		index.outVIndex++;
		// index.rTIndex=0;
	} else if(tmp == token::RPAR){
		index.outVIndex--;
		// index.rTIndex=0;
	}

	return tmp;
}

std::string regex::getId(){
	/*if(regExp.size() <= index.rIndex){
		std::cerr << "Index out of bouce, will return last known." << std::endl;
		return regExp[0][regExp.size()-1];
	} else if(regExp[index.rIndex].size() <= index.rTIndex){
		std::cerr << "Index out of bounce (second), will return last." << std::endl;
		return regExp[index.rIndex][regExp[index.rIndex].size()-1];
	}
	index.rTIndex++;
	return regExp[index.rIndex][index.rTIndex];*/
	return "";
}


std::vector<std::string> regex::orSplit(){
	
	std::vector<std::string> forReturn;
	/*std::string tmpStr="";
	
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
	}*/

	return forReturn;
}

void regex::makeTokens(std::string ex){
	std::vector<std::string> v;
	std::string s="";

	for(iter it = ex.begin(); it != ex.end(); it ++){
		if(isalnum(*it)){
			s = (*it);

			if(it+1 != ex.end()){
				iter it2 = it+1;
				
				while(isalnum(*it2) && it2 != ex.end()){
					s+= (*it);
					it2++;
				}
				it = it2-1;
				tokenList.push_back(token::ID);
				v.push_back(s);
			}

		} else{
			token tmp = lookUp(*it);
			switch(tmp){
				case token::SYNER:
					std::cerr << "Syntax Error please check your expression: " 
							  << (*it) << std::endl;
					exit(0);
					break;

				case token::LPAR:
					// 'If' cuz '(' can be the first sign or after a other '(', 
					// then there is no meaning to push_back v.
					if(v.size() > 0) regExp.push_back(v);
					tokenList.push_back(token::LPAR);
					v.clear();
					index.outVIndex++;
					break;

				case token::RPAR:
					// 'If' cuz ')' can be directly after a other ')',
					// then there is no meaning to push_back v.
					if(v.size() > 0) regExp.push_back(v);
					tokenList.push_back(token::RPAR);
					v.clear();
					index.outVIndex--;
					break;

				default:
					tokenList.push_back(tmp);
					break;
			}
		}
	}

	if(v.size() > 0){
		regExp.push_back(v);
		v.clear();
	}

	if(!ex.size() == 0){
		tokenList.push_back(token::END);

		if(index.outVIndex > 0){
			std::cerr << "Syntax Error. You are missing one or more ')'" 
					  << "\nplease check your expression." << std::endl;
			exit(0);
		}

	} else{
		std::cerr << "No expression to process, program will shutdown." 
				  << std::endl;
		exit(0);
	}
	std::cout << "regex size: " << regExp.size() << "\n";
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