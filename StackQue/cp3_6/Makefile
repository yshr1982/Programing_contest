CXX = g++
TARGET = main
CXXFLAGS = -Wall -O2 -pipe
SRCS = main.cpp ../stack.cpp
OBJS := $(SRCS:.cpp=.o) #SRCSの各ファイルのサフィックスの.cppを.oに変換

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)