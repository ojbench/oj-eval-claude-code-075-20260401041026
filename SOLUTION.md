# Solution Summary for Problem 075 - str

## Problem Description
Implement a C++ string class `str` with the following features:
- Default constructor (empty string)
- Constructors from char and char*
- Copy constructor and assignment operators
- Array subscript operator for character access
- `len()` method to get string length
- `join()` method to concatenate strings with a separator
- `slice()` method to extract substring
- Proper memory management (no leaks)

## Implementation Details

### File Structure
- `src.hpp` - Main implementation file (required name by OJ)
- `test.cpp` - Local testing program
- `CMakeLists.txt` - Build configuration
- `.gitignore` - Git ignore rules
- `submit_code.py` - Helper script for direct code submission

### Key Implementation Points

1. **Memory Management**:
   - Used dynamic allocation with `new[]` and proper cleanup with `delete[]`
   - Ensured no memory leaks by implementing proper destructor
   - Handled self-assignment in copy assignment operator

2. **Constructor from char*** :
   - Used rvalue reference `const char *&&` as specified in the problem
   - Null pointer checks to avoid crashes

3. **Join Function**:
   - Efficiently concatenates vector of strings with separator
   - Handles empty vectors and single elements correctly
   - Pre-calculates total length to avoid multiple allocations

4. **Slice Function**:
   - Extracts substring from [l, r) range
   - Boundary checking to handle edge cases
   - Returns empty string for invalid ranges

## Submission Results

### Attempts Summary
- **Attempt 1**: Compile Error - Used git submission with filename `str.hpp` (wrong)
- **Attempt 2**: Compile Error - Used git submission with filename `src.hpp` (OJ git submission not working as expected)
- **Attempt 3**: **ACCEPTED** - Direct code submission with C++ language, score 100/100

### Key Learning
The OJ system for this problem expects **direct code submission** (language: cpp) with the code content, NOT git repository submission. The git submission method was placing the URL as code content instead of cloning the repository.

## Test Results
```
Runtime: 610 ms
Memory: 47.5 MB
Score: 100/100 (ACCEPTED)
```

## Usage

### Local Testing
```bash
cmake .
make
./code
```

### Direct Code Submission
```bash
python3 submit_code.py 1059 src.hpp cpp
```

## Conclusion
Successfully implemented a complete string class with all required features, proper memory management, and achieved perfect score on the OJ system.
