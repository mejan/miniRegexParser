#include "parser.h"

int main(){
	std::string file, commande;

	// first enter the file to do the regex in. After enter
	// the regex command.
	// std::cout << "Skriv in inläsnings filen" << std::endl;
	// std::cin >> file;
	std::cout << "Skriv in ditt regex uttryck" << std::endl;
	std::cin >> commande;

	parser test("tmp.txt", commande); 

	return 0;
}