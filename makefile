# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -pthread
LDFLAGS = -lz

# Source and header files
SRCS = block.cpp fakeMiner.cpp global.cpp main.cpp miner.cpp server.cpp
HDRS = block.h fakeMiner.h global.h miner.h server.h

# Output executable
TARGET = cryptocurrency_mining_linux_thread_proje

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET) *.o

