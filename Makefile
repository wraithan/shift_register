.PHONY: dotc build upload all clean

all: dotc build upload

dotc:
	dotc pre lib/test.cpp > src/sketch.cpp

build:
	ino build

upload:
	ino upload

clean:
	ino clean
	rm src/sketch.cpp