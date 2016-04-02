INCDIR = -I$(HOME)/wpilib/cpp/current/include
CPPFLAGS += -g -Wall -W $(INCDIR) -std=c++14 -shared -Wl,-soname,libeventrobot.so.1.0.1 -lc -fPIC
LFLAGS = -L$(HOME)/wpilib/cpp/current/lib -lwpi
CXX = arm-frc-linux-gnueabi-g++

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
OBJECTS = $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))

all: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) $(LFLAGS)
clean: 
	#@for dir in .; do find $$dir -name \*.o -exec $(RMCOMMAND) {} \; ; done
	$(RMCOMMAND) ./*.o
	$(RMCOMMAND) ./*.out

