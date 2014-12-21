#ifndef _PARSER_H_
#define _PARSER_H_

#include "textContainer.h"

enum token { END, IDENT, CONTINUE_OP, OR_OP, LEFT_PAREN, RIGHT_PAREN, SYN_ER };
typedef std::vector<token*>::iterator ittp;

class parser{
	public:
		/*
		*defualt Constructor (only allocate empty 
		*textContainer and empty vector<enum>)
		*/
		parser();
		/*
		*Constructor (only allocate textContainer 
		*and empty vector<enum>)
		*
		*Argument: regex expression
		*add's it to textContainer
		*/
		parser(std::string ex);
		// Destructors
		~parser();
		
		//Takes new expression.
		void addExpresstion(std::string ex);
		//Gets all the tokens
		const std::vector<token*> getTokenList();
		//Get specific token
		const token getToken(int i);
		// Print Token type (only for testing).
		void printTokens();
		//parse the expresstion.
		bool parse();
		//Get expression char one at a time
		char getExpressionChar(int i);
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
		textContainer inParse;
		//Pointer will be used to store tokens
		std::vector<token*> tokenList;
};
#endif /*_PARSER_H_*/