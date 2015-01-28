#include "regex.h"

int main(){
	std::string file, commande;

	// first enter the file to do the regex in. After enter
	// the regex command.
	// std::cout << "Skriv in inläsnings filen" << std::endl;
	// std::cin >> file;
	std::cout << "Skriv in ditt regex uttryck" << std::endl;
	std::cin >> commande;
	// cin::cin >> file

	parser tokenTest(commande);
	// textContainer searchIn(file);

	// searchIn.printContent();

	if(!tokenTest.parse())
		return 1;

	for(int i = 0; i < tokenTest.getSize(); i++)
		std::cout << tokenTest.getToken(i) << std::endl;
		
	// regex testRegex(tokenTest, file);

	regex test("tmp.txt");

	return 0;
}