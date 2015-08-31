#ifndef _REGEX_H_
#define _REGEX_H_


#include <vector>
#include <iostream>
#include <string>
#include <cctype>


enum token { END, IDENT, CONTINUE_OP, OR_OP, LEFT_PAREN, RIGHT_PAREN, SYN_ER };
// I use a pointer just for practise,
// works fine without pointer just find.
typedef std::vector<token*>::iterator tokenIt;

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
		/*
		*Destructor deletes all allocated memory.
		*/
		~regex();
		/*
		*Deletes the old token list and add new expression
		*and create new token list for it.
		*/
		void addNewExprestion(std::string ex);
		/*
		* returns the expression for a specifik position
		* position is the same as a token position.
		*/
		char getTokenCode();
		/*
		*Returns a token in a serten index in tokenlist
		*attribute i is the index that will be returned.
		*/
		const token getToken();
		/*
		*returns the size of the token list.
		*/
		size_t getSize();
		/*
		*prints the current tokens and there expression.
		*/
		void printTokensAndText();
		/*
		*Reset index to 0.
		*/
		void restart();

	private:
		// make tokens out of the a expression
		bool makeToken(std::string ex);
		// look up the token type.
		token lookup(char toLookUp);
		// add token to the tokenList.
		void addToken(token toAdd);
		// delete allocated token memory and erase all pointers in the vector.
		void emptyToken();
		
		/*
		*Members for data storeage.
		*/
		// store expression to specifik token
		std::vector<char> textRegex;
		// store the tokens.
		// I use a pointer just for practise,
		// works fine without pointer just find.
		std::vector<token*> tokenList;
		// keep track on token that's been seen.
		size_t index;
};

#endif /*_REGEX_H_*/