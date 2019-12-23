#
# Parameters
#===========

CXX         = avr-gcc
CXXFLAGS    = -Wall
LIBS        = -Iinc
DEVICE		= at90can128
FCPU		= 16000000

#
# Make
#===========

LIB_O = logger_tests.o logger.o
LIB_BIN = logger_tests
LIB_TEST = logger_tests
LIB_C = logger

logger_build: $(LIB_O)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(LIB_BIN) $(LIB_O)

logger_tests.o: tests/$(LIB_TEST).c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c tests/$(LIB_TEST).c $(LIBS)

logger.o: src/$(LIB_C).c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/$(LIB_C).c $(LIBS)

clean:
	rm *.o