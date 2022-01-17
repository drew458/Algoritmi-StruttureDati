FILTER  := 
SOURCES := $(filter-out $(FILTER),$(wildcard */*.c),$(wildcard */*/*.c) )
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))
TARGETS := $(patsubst %.o, %  , $(OBJECTS) )
LDLIBS  := 
CFLAGS := -Wall -O3
CC := gcc

all: $(TARGETS)

clean:
	-rm $(TARGETS)

.PHONY: clean

.PRECIOUS: %.o