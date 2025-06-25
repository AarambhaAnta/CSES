# CSES Problem Solutions Makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic
DEBUG_FLAGS = -g -DDEBUG

# Default target
.DEFAULT_GOAL := help

# Help target
help:
	@echo "CSES Problem Solutions Makefile"
	@echo "Available targets:"
	@echo "  compile FILE=<filename>  - Compile a specific C++ file"
	@echo "  debug FILE=<filename>    - Compile with debug flags"
	@echo "  run FILE=<filename>      - Compile and run a specific file"
	@echo "  clean                    - Remove all compiled files"
	@echo "  clean-logs              - Remove all log files"
	@echo "  clean-all               - Remove all compiled files, logs, and temp files"
	@echo ""
	@echo "Examples:"
	@echo "  make compile FILE=introductory_problems/weird_algorithm.cpp"
	@echo "  make run FILE=sorting_and_searching/distinct_numbers.cpp"
	@echo "  make clean"

# Compile a specific file
compile:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Please specify a file. Usage: make compile FILE=<filename>"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE)" ]; then \
		echo "Error: File $(FILE) not found"; \
		exit 1; \
	fi
	@echo "Compiling $(FILE)..."
	$(CXX) $(CXXFLAGS) -o $(basename $(FILE)) $(FILE)
	@echo "Compiled successfully: $(basename $(FILE))"

# Compile with debug flags
debug:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Please specify a file. Usage: make debug FILE=<filename>"; \
		exit 1; \
	fi
	@if [ ! -f "$(FILE)" ]; then \
		echo "Error: File $(FILE) not found"; \
		exit 1; \
	fi
	@echo "Compiling $(FILE) with debug flags..."
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $(basename $(FILE)) $(FILE)
	@echo "Debug build completed: $(basename $(FILE))"

# Compile and run
run:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Please specify a file. Usage: make run FILE=<filename>"; \
		exit 1; \
	fi
	@$(MAKE) compile FILE=$(FILE)
	@echo "Running $(basename $(FILE))..."
	@./$(basename $(FILE))

# Clean compiled files
clean:
	@echo "Cleaning compiled files..."
	@find . -type f \( \
		-name "*.out" -o \
		-name "*.exe" -o \
		-name "*.o" -o \
		-name "*.obj" -o \
		-name "*.bin" -o \
		-name "a.out" -o \
		-name "main" -o \
		-name "solution" -o \
		-name "temp" -o \
		-name "test" \
	\) -not -path "./.git/*" -delete 2>/dev/null || true
	@# Clean executable files without extensions (compiled from .cpp files)
	@find . -type f -perm +111 -not -name "*.cpp" -not -name "*.py" -not -name "*.java" -not -name "*.rs" -not -name "*.go" -not -name "*.js" -not -name "*.ts" -not -name "*.sh" -not -name "*.bat" -not -name "Makefile" -not -name "*.md" -not -name "*.txt" -not -name "*.json" -not -name "*.yml" -not -name "*.yaml" -not -name "*.xml" -not -name "*.in" -not -name "*.out" -not -path "./.git/*" -delete 2>/dev/null || true
	@echo "Compiled files cleaned successfully!"

# Clean log files
clean-logs:
	@echo "Cleaning log files..."
	@find . -type f \( \
		-name "*.log" -o \
		-name "*.tmp" -o \
		-name "*.temp" -o \
		-name "*.bak" -o \
		-name "*~" \
	\) -not -path "./.git/*" -delete 2>/dev/null || true
	@echo "Log files cleaned successfully!"

# Clean everything
clean-all: clean clean-logs
	@echo "Cleaning all temporary files..."
	@find . -type f \( \
		-name "*.ans" -o \
		-name "*.res" -o \
		-name "*.swp" -o \
		-name "*.swo" \
	\) -not -path "./.git/*" -delete 2>/dev/null || true
	@find . -name ".DS_Store" -delete 2>/dev/null || true
	@echo "All temporary files cleaned successfully!"

# Force clean (more aggressive)
force-clean:
	@echo "Force cleaning all compiled and temporary files..."
	@find . -type f \( \
		-name "*.out" -o \
		-name "*.exe" -o \
		-name "*.o" -o \
		-name "*.obj" -o \
		-name "*.bin" -o \
		-name "*.log" -o \
		-name "*.tmp" -o \
		-name "*.temp" -o \
		-name "*.bak" -o \
		-name "*.ans" -o \
		-name "*.res" -o \
		-name "*.swp" -o \
		-name "*.swo" -o \
		-name "*~" -o \
		-name "a.out" -o \
		-name "main" -o \
		-name "solution" -o \
		-name "temp" -o \
		-name "test" \
	\) -not -path "./.git/*" -delete
	@# Force clean executable files without extensions
	@find . -type f -perm +111 -not -name "*.cpp" -not -name "*.py" -not -name "*.java" -not -name "*.rs" -not -name "*.go" -not -name "*.js" -not -name "*.ts" -not -name "*.sh" -not -name "*.bat" -not -name "Makefile" -not -name "*.md" -not -name "*.txt" -not -name "*.json" -not -name "*.yml" -not -name "*.yaml" -not -name "*.xml" -not -name "*.in" -not -name "*.out" -not -path "./.git/*" -delete 2>/dev/null || true
	@find . -name ".DS_Store" -delete 2>/dev/null || true
	@echo "Force clean completed!"

.PHONY: help compile debug run clean clean-logs clean-all force-clean
