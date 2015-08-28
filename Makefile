cpps = main.cpp parser.cpp regex.cpp textContainer.cpp
headers = parser.h regex.h textContainer.h
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
