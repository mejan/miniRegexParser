#include "regex.h"


regex::regex():tokenList(),regExp(){
	resetIndex();
}

regex::regex(std::string ex):tokenList(),regExp(){
	resetIndex();
	makeTokens(ex);
}

regex::~regex(){}

void regex::resetIndex(){
	index.tIndex=0;
	index.outVIndex=0;
	index.inVIndex=-1;
	prevIn = 0;
}

token regex::getToken(){
	if(tokenList.size() <= index.tIndex){
		std::cerr << "Index out of bounce, will return SYNER." << std::endl;
		return token::SYNER;
	}

	token tmp = tokenList[index.tIndex];
	index.tIndex++;

	if(tmp == token::LPAR){
		index.outVIndex++;
		prevIn = index.inVIndex;
		index.inVIndex=-1;
	} else if(tmp == token::RPAR){
		index.outVIndex--;
		index.inVIndex=prevIn;
	} else if(tmp == token::ID){
		index.inVIndex++;
	}

	return tmp;
}

std::string regex::getId(){
	if(regExp.size() <= index.outVIndex){
		std::cerr << "Index out of bounce [outer], will return 'Error'" 
				  << std::endl;
		return "Error&";
	} else if(regExp[index.outVIndex].size() <= index.inVIndex){
		std::cerr << "Index out of bounce [inner], will return Error" 
				  << std::endl;

		return "Error&";
	}
	return regExp[index.outVIndex][index.inVIndex];
}


std::string regex::getPrevId(){
	if(regExp.size() <= index.outVIndex){
		std::cout << "Index out of bounce [outer], will return 'Error'"
				  << std::endl;
		return "Error&";
	} else if(regExp[index.outVIndex].size() <= (index.inVIndex-1)){
		std::cout << "Index out of bounce [inner], will return Error"
				  << std::endl;
		return "Error&";
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
			}
			tokenList.push_back(token::ID);
			v.push_back(s);

		} else{
			token tmpToken = lookUp(*it);
			switch(tmpToken){
				case token::SYNER:
					std::cerr << "Syntax Error please check your expression: " 
							  << (*it) << std::endl;
					exit(0);

				case token::LPAR:
					regExp.push_back(v);
					tokenList.push_back(token::LPAR);
					v.clear();
					index.outVIndex++;
					break;

				case token::RPAR:
					if(v.size() > 0){
						regExp.push_back(v);
					} else{
						std::cerr << "Syntax Error, brackets without "
								  << "any concat within them." << std::endl;
						exit(0);
					}
					tokenList.push_back(token::RPAR);
					v.clear();
					index.outVIndex--;
					break;

				default:
					tokenList.push_back(tmpToken);
					break;
			}
		}
	}



	/*
	If the last read token is an ID
	then it need's to be put in the regExp
	vector witch is what we do here.
	*/
	if(v.size() > 0){
		std::vector<std::string> tmpVec;
		if(regExp.size() > 0){
			tmpVec = regExp[0];
			regExp[0].clear();
		}
		
		for(viter vit = v.begin(); vit != v.end(); vit++){
			tmpVec.push_back(*vit);
		}
		v.clear();

		if(regExp.size() > 0){
			regExp[0] = tmpVec;
		} else{
			regExp.push_back(tmpVec);
		}
	}

	/* Some syntax checkes and see if the exprsion has something in it. */
	if(!ex.size() == 0){

		if(index.outVIndex > 0){
			std::cerr << "Syntax Error. You are missing one or more ')'" 
					  << "\nplease check your expression." << std::endl;
			exit(0);
		}
	} else{
		std::cerr << "No expression to process, the program will shutdown." 
				  << std::endl;
		exit(0);
	}

	tokenList.push_back(token::END);
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

void regex::printTokenList(){
	typedef std::vector<token>::iterator titer;
	for(titer it = tokenList.begin(); it != tokenList.end(); it++){
		switch(*it){
			case token::ID:
				std::cout << "ID" << std::endl;
				break;
			case token::REP:
				std::cout << "REP" << std::endl;
				break;
			case token::OR:
				std::cout << "OR" << std::endl;
				break;
			case token::LPAR:
				std::cout << "LPAR" << std::endl;
				break;
			case token::RPAR:
				std::cout << "RPAR" << std::endl;
				break;
			case token::SYNER:
				std::cout << "SYNER" << std::endl;
				break;
			case token::END:
				std::cout << "END" << std::endl;
				break;
		}
	}
}

void regex::printRegExp(){
	std::cout << "Printing regExp" << std::endl;
	for(size_t i = 0; i < regExp.size(); i++){
		for(viter vit = regExp[i].begin(); vit != regExp[i].end(); vit++){
			std::cout << (*vit) << " Depht in vector: " << i << std::endl;
		}
	}
}