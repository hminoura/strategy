TARGET = ball

SRCS   = main.cpp App.cpp Timer.cpp Rand.cpp BallApp.cpp Ball.cpp MotionRefrection.cpp MotionBound.cpp MotionStop.cpp
OBJS   = $(SRCS:%.cpp=%.o)
## for macOS (SFML: brew)
#CXX    = clang++
#CXXFLAGS = -std=c++11 -Wc++11-extensions -g

## for Linux (SfLinux
CXX    = c++
CXXFLAGS = -std=c++11 -g
# LIBS     = -lsfml-graphics -lsfml-window -lsfml-system
LIBS	= `pkg-config --libs sfml-all`

all:$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o  $@ $^ $(LDFLAGS) $(LIBS)
	strip $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< 

.PHONY: clean run

clean:
	rm -f *.o *~ $(TARGET)

run: $(TARGET)
	./$(TARGET)

main.o: Timer.h BallApp.h
App.o: App.h
Timer.o: Timer.h
Rand.o: Rand.h
BallApp.o: BallApp.h Timer.h
Ball.o: Ball.h Rand.h BallApp.h
MotionRefrection.o: Motion.h MotionRefrection.h
MotionBound.o: Motion.h MotionBound.h
MotionStop.o: Motion.h MotionStop.h
