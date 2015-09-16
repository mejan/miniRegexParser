#include "parser.h"

int main(){
	std::string commande;
	std::cout << "Please enter your regular expression." << std::endl;
	std::cin >> commande;

	parser test(commande);
	test.addTextFile("tmp.txt");

	test.parseExp();

	return 0;
}