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
		std::cout << "regex size: " << regExp.size() << " outVIndex: "
				  << index.outVIndex << std::endl;
		std::cerr << "Index out of bounce [outter], will return 'Error'" 
				  << std::endl;
		return "Error";
	} else if(regExp[index.outVIndex].size() <= index.inVIndex){
		std::cout << "regex[x] size: " << regExp[index.outVIndex].size()
				  << " inVIndex: " << index.inVIndex << std::endl;
		std::cerr << "Index out of bounce [Inner], will return Error" << std::endl;
	}
	return regExp[index.outVIndex][index.inVIndex];
}


/*std::vector<std::string> regex::orSplit(){
	
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
}*/

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

	if(v.size() > 0){
		std::vector<std::string> tmp = regExp[0];
		for(viter vit = v.begin(); vit != v.end(); vit++){
			tmp.push_back(*vit);
		}
		regExp[0] = tmp;
		v.clear();
	}

	// For debugging purposes.
	std::cout << "regex size: " << regExp.size() << "\n";
	for(std::vector<std::vector<std::string> >::iterator it = regExp.begin(); it != regExp.end(); it++){
		std::cout << "size: " << (*it).size() << std::endl;
		for(viter vit = (*it).begin(); vit != (*it).end(); vit++){
			std::cout << "String: " << (*vit) << std::endl;
		}
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