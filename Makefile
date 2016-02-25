PROGRAM_NAME = main
GCC = g++

build:
	$(GCC) *.cpp -o $(PROGRAM_NAME)

clean:
	rm *.gch

run:
	./$(PROGRAM_NAME) ${ARGS}
