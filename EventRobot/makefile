INCDIR = -I$(HOME)/wpilib/cpp/current/include
CPPFLAGS += -g -Wall -W $(INCDIR) -std=c++14 -fPIC -c ./*.cpp
LFLAGS = -L$(HOME)/wpilib/cpp/current/lib -lwpi
CXX = arm-frc-linux-gnueabi-g++
AR = ar
ARFLAGS = rvs libeventrobot.a
RMCOMMAND = rm -f

SOURCES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
OBJECTS = $(patsubst src/%.cpp,src/%.o,$(wildcard src/*.cpp))

all: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) $(LFLAGS)
	$(AR) $(ARFLAGS) ./*.o
clean: 
	@for dir in .; do find $$dir -name \*.o -exec $(RMCOMMAND) {} \; ; done
	$(RMCOMMAND) ./*.o
	$(RMCOMMAND) ./*.out

