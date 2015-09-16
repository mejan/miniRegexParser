cpps = main.cpp parser.cpp regex.cpp
headers = parser.h regex.h
compile = g++ -std=c++11 -O3
out = regexParser

compRunDel: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)
	./$(out)
	rm $(out)
run: $(out)
	./$(out)

comp: $(cpps) $(headers)
	$(compile) $(cpps) -o $(out)