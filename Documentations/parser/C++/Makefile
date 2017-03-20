CC    ?= clang
CXX   ?= clang++

EXE = my_calc

CDEBUG = -g -Wall

CXXDEBUG = -g -Wall

CSTD = -std=c99
CXXSTD = -std=c++14

CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)


CPPOBJ = main calc_driver
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))

OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				 calc_parser.tab.cc calc_parser.tab.hh \
				 location.hh position.hh \
			    stack.hh calc_parser.output parser.o \
				 lexer.o calc_lexer.yy.cc $(EXE)\

.PHONY: all
all: calc

calc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)


parser: calc_parser.yy
	bison -d -v calc_parser.yy
	$(CXX) $(CXXFLAGS) -c -o parser.o calc_parser.tab.cc

lexer: calc_lexer.l
	flex --outfile=calc_lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c calc_lexer.yy.cc -o lexer.o

.PHONY: test
test:
	test/test0.pl

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)

