cpps = main.cpp textContainer.cpp parser.cpp regex.cpp
headers = textContainer.h parser.h regex.h
compile = g++ -std=c++11 -O3
out = regexParser

compRun: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)
	#./$(out)
	cat test.txt | ./$(out)

run: $(out)
	#./$(out)
	cat test.txt | ./$(out)

comp: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)
