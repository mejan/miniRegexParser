#ifndef _REGEX_H_
#define _REGEX_H_

// #include "textContainer.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

enum token { END, IDENT, CONTINUE_OP, OR_OP, LEFT_PAREN, RIGHT_PAREN, SYN_ER };
typedef std::vector<token*>::iterator ittp;
typedef std::string::iterator its;

class regex{
	public:
		/*
		*defualt Constructor (only allocate empty 
		*textContainer and empty vector<enum>)
		*/
		regex();
		/*
		*Constructor (only allocate textContainer 
		*and empty vector<enum>)
		*
		*Argument: regex expression
		*add's it to textContainer
		*/
		regex(std::string ex);
		// Destructors
		~regex();
		
		//Takes new expression.
		void addExpresstion(std::string ex);
		//Gets all the tokens
		const std::vector<token*> getTokenList();
		//Get specific token
		const token getToken(size_t i);
		// Print Token type (only for testing).
		void printTokens();
		//parse the expresstion.
		bool parse();
		//Get expression char one at a time
		char getIdChar(size_t i);
		// Get the finish parsed ex size.
		size_t getSize();

	private:
		/*
		private functions
		*/
		//Look up if char is UNKNOWN.
		token lookup(char toLookUp);
		// add a token push back
		void addToken(token toAdd);

		/*
		Data members
		*/
		//Member for container of expression
		std::string inParse;
		//Pointer will be used to store tokens
		std::vector<token*> tokenList;
};
#endif /*_REGEX_H_*/