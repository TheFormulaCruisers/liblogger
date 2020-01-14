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

LOGGER_O = logger_test.o logger.o
LOGGER_BIN = logger_test

logger_build: $(LOGGER_O)
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -o bin/$(LOGGER_BIN) $(LOGGER_O) $(LIBS)

logger_test.o: tests/logger_test.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c tests/logger_test.c $(LIBS)

logger.o: src/logger.c
	$(CXX) $(CXXFLAGS) -mmcu=$(DEVICE) -DF_CPU=$(FCPU) -c src/logger.c $(LIBS)

clean:
	rm *.o