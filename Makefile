BIN=./bin

datasender: datasender-build
	$(BIN)/datasender -I 2

datasender-build: bindir
	gcc datasender.c -o $(BIN)/datasender

getoptmin: getoptmin-build
	$(BIN)/getoptmin

getoptmin-build: bindir
	gcc getoptmin.c -o $(BIN)/getoptmin

bindir:
	test -d bin || mkdir $(BIN)

clean:
	find . -name 'bin' -type d -exec rm -rf {} +
