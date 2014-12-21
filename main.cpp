#include "regex.h"

int main(){
	std::string file, commande;

	// first enter the file to do the regex in. After enter
	// the regex command.
	// std::cout << "Skriv in inläsnings filen" << std::endl;
	// std::cin >> file;
	std::cout << "Skriv in ditt regex uttryck" << std::endl;
	std::cin >> commande;


	parser tokenTest(commande);
	// textContainer searchIn(file);

	// searchIn.printContent();

	if(!tokenTest.parse())
		return 1;
		
	regex testRegex(tokenTest);

	return 0;
}