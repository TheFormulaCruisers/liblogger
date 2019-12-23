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

LOGGER_O = logger_tests.o logger.o
LOGGER_BIN = logger_tests

logger_build: $(LOGGER_O)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(LOGGER_BIN) $(LOGGER_O)

logger_tests.o: tests/logger_tests.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c tests/logger_tests.c $(LIBS)

logger.o: src/logger.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/logger.c $(LIBS)

clean:
	rm *.o