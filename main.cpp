#include "parser.h"

int main(){
	std::string file, commande;

	// first enter the file to do the regex in. After enter
	// the regex command.
	// std::cout << "Skriv in inläsnings filen" << std::endl;
	// std::cin >> file;
	std::cout << "Skriv in ditt regex uttryck" << std::endl;
	std::cin >> commande;

	parser test(commande); 
	test.addFile("tmp.txt");
	if(test.findMatch("Sa"))
		std::cout << "found 1" << std::endl;

	if(test.findMatch("Den"))
		std::cout << "found 2" << std::endl;

	if(test.findMatch("Stora"))
		std::cout << "found 3" << std::endl;

	if(test.findMatch("Kuk"))
		std::cout << "found 4" << std::endl;
	
	return 0;
}