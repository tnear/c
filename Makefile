.PHONY: all clean

# Build through Python file (for now)
all:
	./build.py

# Remove object files and crash dumps
clean:
	rm -f *.o
	rm -f *.o.core
