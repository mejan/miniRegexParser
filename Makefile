cpps = main.cpp textContainer.cpp parser.cpp
headers = textContainer.h parser.h
compile = g++ -std=c++11 -O3
out = regexParser

compRun: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)
	./$(out)

run: $(out)
	./$(out)

comp: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)