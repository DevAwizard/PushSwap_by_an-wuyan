![cover-push_swap](https://github.com/user-attachments/assets/263ded18-813c-4747-8a1b-6ae762b5a101)


<div align="center">
<h1>Push swap Documentation</h1>
<img src="https://img.shields.io/badge/42-%23000000.svg?&style=for-the-badge&logo=42&logoColor=white" /> 
<img src="https://img.shields.io/badge/c-%23A8B9CC.svg?&style=for-the-badge&logo=c&logoColor=black" /> 
<img src="https://img.shields.io/badge/markdown-%23000000.svg?&style=for-the-badge&logo=markdown&logoColor=white" />
<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
</div>


### Table of Contents

1. [Introduction](#introduction)

2. [Objectives](#objectives)

3. [Usage](#usage)

   - [Example Usage](#example-usage)

4. [Stack Operations Explained](#stack-operations-explained)

5. [Program Workflow](#program-workflow)

6. [Code structure](#code-structure)

7. [Performance Testing](#performance-testing)

   - [Sorting Efficiency](#sorting-efficiency)

8. [Error Handling](#error-handling)

9. [Memory Management](#memory-management)

10. [Evaluation Checklist](#evaluation-checklist)

11. [Test_cases](#Test-cases)

12. [Push Swap Visualizer Setup on macOS (M1/M2/M3)](#push-swap-visualizer-setup-on-macos-m1m2m3)

13. [License](#license)


### 1. Introduction

The Push_swap project is a challenging algorithmic exercise that focuses on sorting data using a specific set of operations in the C programming language. The task is to write a program that sorts integers stored in a stack, using the minimum number of operations possible. 


This project is an excellent opportunity to deepen your understanding of sorting algorithms, data structures, and efficient code practices.

### 2. Objectives

The main objectives of this project are:

- **Algorithm Efficiency:** Implement an efficient sorting algorithm that uses the fewest possible operations.
- **Memory Management:** Properly manage memory allocations to avoid leaks and ensure that all allocated memory is freed.
- **Error Handling:** Create a robust program that gracefully handles all edge cases and errors, such as invalid input or memory issues.
- **Understanding Complexity:** Gain a solid understanding of algorithmic complexity, particularly with sorting operations.

### 3. Usage

The Push_swap program takes a series of integers as arguments and returns the sequence of operations required to sort them.

#### Example Usage

Run the following command to see Push_swap in action:

```bash
./push_swap 2 1 3 6 5 8
```

Expected Output:

```bash
sa
pb
pb
pb
sa
pa
pa
pa
```

### 4. Stack Operations Explained

#### Operation List

Each stack operation plays a crucial role in the sorting process. Below is a detailed explanation of each operation:

- **sa (swap a):** Swaps the top two elements of stack A.
- **sb (swap b):** Swaps the top two elements of stack B.
- **ss (swap both):** Swaps the top two elements of both stacks A and B.
- **pa (push a):** Pushes the top element from stack B to stack A.
- **pb (push b):** Pushes the top element from stack A to stack B.
- **ra (rotate a):** Shifts all elements of stack A up by one position.
- **rb (rotate b):** Shifts all elements of stack B up by one position.
- **rr (rotate both):** Performs `ra` and `rb` simultaneously.
- **rra (reverse rotate a):** Shifts all elements of stack A down by one position.
- **rrb (reverse rotate b):** Shifts all elements of stack B down by one position.
- **rrr (reverse rotate both):** Performs `rra` and `rrb` simultaneously.

### 5. My program visual Workflow

Below is a diagram that represents the pseudocodic approach of my Push_swap program. This flowchart illustrates the overall logic and steps involved in processing the inputs and sorting the stack:


![Flowchart](Flowchart_image/Flowchart_pushswap.png)

### 6. Code structure

```sh
pushswap/
├── srcs/                       # Source files of C code
│   ├── main.c                  # Entry point of the program
│   ├── check_arguments/        # Argument checking functionality
│   │   ├── single_argument.c       # Handles single argument case
│   │   ├── multiple_arguments.c    # Handles multiple arguments case
│   │   ├── edge_cases.c            # Handles edge cases for arguments
│   ├── errors/                # Error handling functionality
│   │   ├── ft_error_arguments.c    # Handles argument errors
│   │   ├── ft_error_parsing.c      # Handles parsing errors
│   ├── parsing_validation/    # Parsing and validation functionality
│   │   ├── process_arguments.c     # Processes and validates arguments
│   │   ├── convert_to_int.c        # Converts arguments to integers
│   │   ├── process_multi_argument_helper_functions.c  # Helper functions for multi-argument processing
│   ├── stacks/                # Stack operations and sorting algorithms
│   │   ├── pushswap.c             # Main logic for push-swap operations
│   │   ├── operations/            # Basic stack operations
│   │   │   ├── push.c                 # Push operation
│   │   │   ├── swap.c                 # Swap operation
│   │   │   ├── reverse.c              # Reverse operation
│   │   │   ├── rotate.c               # Rotate operation
│   │   ├── turk_algorithm/       # Turk algorithm for sorting
│   │   │   ├── find_min_max_value.c    # Finds minimum and maximum values
│   │   │   ├── sorting_small_stack.c   # Sorts small stacks
│   │   │   ├── utils.c                 # Utility functions for the algorithm
│   │   │   ├── sort_bigger.c           # Sorting larger stacks
│   │   │   ├── set_stacks.c            # Sets up the stacks for sorting
│   │   │   ├── sorting_loop.c          # Main sorting loop
│   │   │   ├── other_functions.c       # Additional functions for sorting
│   │   │   ├── calculate_move_cost.c   # Calculates the cost of moves
│   ├── free_memory/           # Memory management
│   │   ├── free_array.c           # Frees allocated arrays
│   │   ├── free_stacks.c          # Frees allocated stacks
│   ├── libft/                # Libft functions (external library)
│       ├── libft.a           # Compiled Libft library
├── obj/                      # Object files generated from the source files
└── Makefile                  # Makefile to compile the project
```

#### Key files

Here's a brief explanation of each file in your `pushswap` project:

##### `check_arguments/` - Argument Checking Functionality
- **`single_argument.c`**: Handles the case where the program is provided with a single argument. It ensures the argument is valid and ready for further processing.
- **`multiple_arguments.c`**: Manages the scenario where multiple arguments are provided. It checks the validity and prepares them for processing.
- **`edge_cases.c`**: Deals with special or unusual cases in argument handling, such as handling invalid formats or unexpected input.

##### `errors/` - Error Handling Functionality
- **`ft_error_arguments.c`**: Handles errors related to arguments, such as incorrect input or invalid numbers of arguments.
- **`ft_error_parsing.c`**: Manages errors that occur during the parsing of arguments, such as when converting strings to integers fails.

##### `parsing_validation/` - Parsing and Validation Functionality
- **`process_arguments.c`**: Processes and validates the input arguments to ensure they meet the program's requirements before further operations.
- **`convert_to_int.c`**: Converts input arguments from strings to integers, ensuring they are valid numbers.
- **`process_multi_argument_helper_functions.c`**: Contains helper functions that assist in processing and validating multiple arguments, breaking down complex tasks into manageable parts.

##### `stacks/` - Stack Operations and Sorting Algorithms
- **`pushswap.c`**: Implements the main logic for the push-swap operations, which is the core functionality of the program.
- **`operations/` - Basic Stack Operations**:
  - **`push.c`**: Implements the push operation, which adds elements to the stack.
  - **`swap.c`**: Implements the swap operation, which swaps the top two elements of the stack.
  - **`reverse.c`**: Implements the reverse operation, which reverses the stack's order.
  - **`rotate.c`**: Implements the rotate operation, which rotates the stack elements up or down.

##### `turk_algorithm/` - Turk Algorithm for Sorting
- **`find_min_max_value.c`**: Finds the minimum and maximum values in the stack, a crucial step for sorting.
- **`sorting_small_stack.c`**: Implements sorting logic for small stacks, using optimized techniques suitable for fewer elements.
- **`utils.c`**: Contains utility functions used by the Turk algorithm, providing support and common functionalities.
- **`sort_bigger.c`**: Implements sorting logic for larger stacks, managing more complex cases that require more operations.
- **`set_stacks.c`**: Sets up the initial state of the stacks before the sorting algorithm begins.
- **`sorting_loop.c`**: Contains the main sorting loop, driving the overall sorting process by iteratively applying the algorithm.
- **`other_functions.c`**: Includes additional functions that support the sorting process, providing extra capabilities or handling special cases.
- **`calculate_move_cost.c`**: Calculates the cost of each move, helping the algorithm decide the most efficient sorting path.

##### `free_memory/` - Memory Management
- **`free_array.c`**: Frees allocated memory for arrays, ensuring there are no memory leaks in the program.
- **`free_stacks.c`**: Frees allocated memory for stacks, cleaning up resources after they are no longer needed.

### 7. Performance Testing

#### Sorting Efficiency

To ensure your implementation is efficient, run performance tests with various inputs:

- **100 Numbers:** The stack should be sorted in less than 700 operations.
- **500 Numbers:** The stack should be sorted in less than 5500 operations.

These benchmarks help ensure that your sorting algorithm is optimized and efficient.

### 8. Error Handling

Your Push_swap program should handle errors gracefully. Some common errors include:

- **Non-numeric Input:** The program should display "Error" and exit.
- **Integer Overflow:** If any argument exceeds the integer range, the program should display "Error".
- **Duplicate Values:** If there are duplicates, the program should display "Error".

Handling these errors ensures the robustness of your program.

### 9. Memory Management

Memory management is critical in C programming. Your Push_swap program must:

**Avoid Memory Leaks**: All allocated memory should be freed before the program exits.

If there are no leaks it should look like this:

**No memory allocation**
```sh
HEAP SUMMARY:
==1925832==     in use at exit: 0 bytes in 0 blocks
==1925832==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==1925832== 
==1925832== All heap blocks were freed -- no leaks are possible
```

**Using memory allocation**

```sh
==2197287== HEAP SUMMARY:
==2197287==     in use at exit: 0 bytes in 0 blocks
==2197287==   total heap usage: 2 allocs, 2 frees, 28 bytes allocated
==2197287== 
==2197287== All heap blocks were freed -- no leaks are possible
```

- **Proper Allocation**: Memory should be allocated only when necessary, and freed promptly when no longer needed.

- **Tools**: You can use tools like **`Valgrind`** to check for memory leaks during testing.

### 10. Evaluation Checklist

During the evaluation of your Push_swap project, an executable called `checker_linux` will be used to verify the correctness of your program. The `checker_linux` executable will check whether the output produced by your program correctly sorts the numbers and stays within the permitted number of operations.

### Evaluation Steps:

1. **Permission Setup:**
   - Before using the `checker_linux` executable, ensure it has the proper execution permissions. You can do this by running:
   
     ```bash
     chmod +x checker_linux
     ```

2. **Execution Example:**
   - The following example shows how the evaluation will be performed:
   
     ```bash
     ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
     ```
     This command will output the number of operations your `push_swap` program used to sort the list.

   - Then, your program's output will be checked for correctness using:
   
     ```bash
     ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
     ```
     If the numbers are sorted correctly, the `checker_linux` program will return `OK`. If not, it will return `KO`.

#### Example Scenario:

- **Test Case:**
  - Given the input:
  
    ```bash
    ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
    ```
  - The expected output should be a reasonable number of operations (for example, `6` as in the scenario), which will then be verified for correctness using:
  
    ```bash
    ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
    ```

- **Expected Result:**
  - If the output is correct, the `checker_linux` will return:
  
    ```bash
    OK
    ```
  - If the output is incorrect or not sorted, it will return:
  
    ```bash
    KO
    ```

### 11. Test cases

Here's a list of all possible error cases for your Push_swap program that users might encounter when running `./push_swap input`:

#### Possible Error Cases

1. **Non-Numeric Input:**
   - **Example:** `./push_swap 1 2 three 4`
   - **Expected Behavior:** The program should detect the non-numeric value `"three"` and display `Error`.

2. **Duplicate Numbers:**
   - **Example:** `./push_swap 1 2 2 3`
   - **Expected Behavior:** The program should detect the duplicate `"2"` and display `Error`.

3. **Number Exceeding Integer Limits:**
   - **Example:** `./push_swap 1 2147483648 3`
   - **Expected Behavior:** The program should detect that `2147483648` exceeds `INT_MAX` and display `Error`.
   - **Example:** `./push_swap 1 -2147483649 3`
   - **Expected Behavior:** The program should detect that `-2147483649` is less than `INT_MIN` and display `Error`.

4. **Invalid Characters in Input:**
   - **Example:** `./push_swap 1 2a 3`
   - **Expected Behavior:** The program should detect the invalid character `"a"` in `"2a"` and display `Error`.

5. **Empty Input (No Arguments):**
   - **Example:** `./push_swap`
   - **Expected Behavior:** The program should not display anything and simply exit without error.

6. **Empty String as Input:**
   - **Example:** `./push_swap ""`
   - **Expected Behavior:** The program should detect the empty string and display `Error`.

7. **Only Spaces in Input:**
   - **Example:** `./push_swap " "`
   - **Expected Behavior:** The program should detect the invalid input consisting only of spaces and display `Error`.

8. **Too Many Spaces Between Numbers:**
   - **Example:** `./push_swap "1  2  3"`
   - **Expected Behavior:** The program should handle multiple spaces correctly or, if not supported, display `Error`.

9. **Leading or Trailing Spaces in Input:**
   - **Example:** `./push_swap " 1 2 3"`
   - **Example:** `./push_swap "1 2 3 "`
   - **Expected Behavior:** The program should either correctly handle the input by trimming spaces or display `Error`.

10. **Zero and Negative Numbers (Handled Correctly):**
    - **Example:** `./push_swap 0 -1 3`
    - **Expected Behavior:** The program should correctly process zeros and negative numbers without causing errors.

11. **Overflow and Underflow of Numbers (With Large Inputs):**
    - **Example:** `./push_swap 9223372036854775807`
    - **Expected Behavior:** The program should detect that `9223372036854775807` exceeds `INT_MAX` and display `Error`.
    - **Example:** `./push_swap -9223372036854775808`
    - **Expected Behavior:** The program should detect that `-9223372036854775808` is less than `INT_MIN` and display `Error`.

### 12. Push Swap Visualizer Setup on macOS (M1/M2/M3)

This guide will help you set up the Push Swap Visualizer for your Push Swap project on macOS with M1, M2, or M3 chips.

#### Prerequisites

Ensure you have the following tools and dependencies installed on your Mac:

1. **Homebrew**: A package manager for macOS.
   - **Install Homebrew**: 
     ```bash
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - **Verify Installation**:
     ```bash
     brew --version
     ```

2. **Xcode Command Line Tools**: Necessary for compiling software.
   - **Install Tools**: 
     ```bash
     xcode-select --install
     ```
   - If already installed, you will receive a notification.

#### Step 1: Install Required Packages Using Homebrew

Use Homebrew to install the following packages:

1. **CMake**: A build management tool.
   - **Install CMake**:
     ```bash
     brew install cmake
     ```
   - **Verify**:
     ```bash
     cmake --version
     ```

2. **GCC**: A compiler collection.
   - **Install GCC**:
     ```bash
     brew install gcc
     ```
   - **Verify**:
     ```bash
     gcc --version
     ```

3. **Freetype**: A font rendering library.
   - **Install Freetype**:
     ```bash
     brew install freetype
     ```

4. **SFML**: A multimedia library for graphics rendering.
   - **Install SFML**:
     ```bash
     brew install sfml
     ```

5. **Clang**: Included with Xcode Command Line Tools. Verify with:
   ```bash
   clang --version


#### Step 2: Clone the Push Swap Visualizer Repository

Clone the Push Swap Visualizer repository into your Push Swap project directory:

```bash
cd /path/to/your/push_swap_project_directory
git clone https://github.com/o-reo/push_swap_visualizer.git
```


### Step 3: Build the Visualizer

1. **Navigate to the Project Directory**:
   ```bash
   cd push_swap_visualizer

2. **Create and Enter the Build Directory:**

```bash

mkdir build
cd build
```

3. **Generate Build Files with CMake**:

```bash
cmake ..
```

4. **Compile the Visualizer**:

```bash
make
```


#### Step 4: Run the Visualizer

1. **Navigate to the bin Directory**:
```bash
cd bin
```

2. **Run the Visualizer:**

```bash
./visualizer
```
3. **Set Up and Test**:
Use the visualizer’s interface to input data, set paths, and control the sorting visualization.


#### Troubleshooting

- **Deprecation Warnings**: Warnings about deprecated OpenGL functions can be ignored, or silenced by defining `GL_SILENCE_DEPRECATION`.

- **Missing Binary**: If the visualizer binary is not created, try the following:
```bash
  rm -rf *
  cmake ..
  make
```

- **Dependencies Not Found**: Ensure all required packages are correctly installed via Homebrew.


### 13. License

This project is licensed under the MIT License. For more details, see the [LICENSE](LICENSE) file.

---
