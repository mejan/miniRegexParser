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
	index.inVIndex=-1;
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
		index.inVIndex=-1;
	} else if(tmp == token::RPAR){
		index.outVIndex--;
		index.inVIndex=-1;
	} else if(tmp == token::ID){
		index.inVIndex++;
	}

	return tmp;
}

std::string regex::getId(){
	if(regExp.size() <= index.outVIndex){
		std::cerr << "Index out of bounce [outer], will return 'Error'" 
				  << std::endl;
		return "Error";
	} else if(regExp[index.outVIndex].size() <= index.inVIndex){
		std::cerr << "Index out of bounce [inner], will return Error" 
				  << std::endl;
		return "Error";
	}
	return regExp[index.outVIndex][index.inVIndex];
}


std::string regex::getPrivId(){
	if(regExp.size() <= index.outVIndex){
		std::cout << "Index out of bounce [outer], will return 'Error'"
				  << std::endl;
		return "Error";
	} else if(regExp[index.outVIndex].size() <= (index.inVIndex-1)){
		std::cout << "Index out of bounce [inner], will return Error"
				  << std::endl;
		return "Error";
	}
	return regExp[index.outVIndex][index.inVIndex-1];
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
					s += (*it2);
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
					regExp.push_back(v);
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

	// if last thing in the expression
	// then it needs to get into regExp
	// and that is what this code does.
	if(v.size() > 0){
		std::vector<std::string> tmp;
		if(regExp.size() > 0){
			tmp = regExp[0];
			regExp[0].clear();
		}
		for(viter vit = v.begin(); vit != v.end(); vit++){
			tmp.push_back(*vit);
		} 
		regExp.push_back(tmp);
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