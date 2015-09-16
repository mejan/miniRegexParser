#include "parser.h"

int main(){
	std::string commande;
	std::cout << "Please enter your regular expression." << std::endl;
	std::cin >> commande;

	parser preformRegexParsing(commande);
	preformRegexParsing.addTextFile("tmp.txt");

	preformRegexParsing.parseExp();

	return 0;
}