# Trie-Based Dictionary ADT

This project implements a **dictionary Abstract Data Type (ADT)** using a **trie** data structure. The dictionary allows mapping strings to integers, retrieving values, and printing the contents in alphabetical order. It also includes a Makefile for building and cleaning the project.

## Features

1. **Trie-Based Implementation**:
   - The dictionary is implemented using a trie data structure (`Trie`).
   - Supports efficient insertion, retrieval, and traversal of strings.

2. **Dictionary Operations**:
   - **`make_dict()`**: Creates an empty dictionary.
   - **`free_dict(Dict dict)`**: Frees the memory allocated to the dictionary.
   - **`get(Dict dict, const char *key)`**: Retrieves the value associated with a string key.
   - **`set(Dict dict, const char *key, int value)`**: Sets the value for a string key.
   - **`print_dict(Dict dict)`**: Prints all keys and their associated values in alphabetical order.

3. **Alphabetical Printing**:
   - Utilizes recursive traversal of the trie to print keys in lexicographical order.

4. **Makefile**:
   - Automates the build process.
   - Supports compiling the source files and cleaning up build artifacts.

## File Structure

```
project-directory/
├── dict_adt.h 
├── dict.h           # Header file defining the dictionary ADT interface
├── dict.c           # Implementation of the dictionary functions
├── main.c            # Sample test program
├── Makefile         # Makefile for building and cleaning
├── input.txt        # Sample input file
```

## Function Descriptions

### Header File: `dict.h`
- Defines the `Dict` type and operations.

#### Functions:
1. **`make_dict()`**:
   - Creates and returns an empty dictionary.
2. **`free_dict(Dict dict)`**:
   - Frees all memory allocated for the dictionary, including keys.
3. **`get(Dict dict, const char *key)`**:
   - Returns a pointer to the integer value associated with the key. Returns `NULL` if the key does not exist.
4. **`set(Dict dict, const char *key, int value)`**:
   - Sets the value for the key. If the key already exists, its value is updated.
   - Returns `1` on success, `0` otherwise.
5. **`print_dict(Dict dict)`**:
   - Prints all key-value pairs in alphabetical order.

### Trie Structure
- Defined as:
  ```c
  typedef struct trie {
      struct trie *next[26];
      int isEnd;
  } Trie;
  ```
- Supports efficient storage and traversal of strings composed of lowercase English letters.

## Sample Input and Output

### Input File: `input.txt`
```
1
abc
2
def
3
abc
0
```

### Execution
Run the program with the input file to:
- Insert keys and values.
- Update existing values.
- Print the dictionary contents in alphabetical order.

### Output
```
abc:3
def:2
```

## Building and Running

### Requirements
- GCC compiler

### Build
Use the provided Makefile:
```bash
make
```
This will compile the source files and produce the executable `hw2`.

### Run
Execute the program:
```bash
./main < input.txt
```

### Clean
Remove build artifacts:
```bash
make clean
```

## Notes
- The `print_dict()` function ensures that keys are printed in lexicographical order using trie traversal.
- The trie data structure limits keys to lowercase English letters (`a-z`).

## Contributions
Contributions to improve or extend the functionality of this project are welcome! Fork the repository, create a new branch, and submit a pull request.

## License
This project is open-source and available under the MIT License.

