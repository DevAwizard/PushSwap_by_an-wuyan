# pushswap_by_an-wuyan

## Table of Contents

1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Setup and Installation](#setup-and-installation)
   - [Cloning the Repository](#cloning-the-repository)
   - [Compiling the Program](#compiling-the-program)
4. [Usage](#usage)
   - [Example Usage](#example-usage)
   - [Supported Operations](#supported-operations)
5. [Program Workflow](#program-workflow)
   - [Flowchart Overview](#flowchart-overview)
   - [Argument Handling](#argument-handling)
   - [Stack Size Check](#stack-size-check)
   - [Sorting Algorithm](#sorting-algorithm)
6. [Stack Operations Explained](#stack-operations-explained)
   - [Operation List](#operation-list)
7. [Performance Testing](#performance-testing)
   - [Sorting Efficiency](#sorting-efficiency)
8. [Error Handling](#error-handling)
9. [Memory Management](#memory-management)ju
10. [Evaluation Checklist](#evaluation-checklist)
11. [Test_cases](#Test-cases)
12. [Push Swap Visualizer Setup on macOS (M1/M2/M3)](#push-swap-visualizer-setup-on-macos-m1m2m3)
13. [License](#license)

---

## 1. Introduction

The Push_swap project is a challenging algorithmic exercise that focuses on sorting data using a specific set of operations in the C programming language. The task is to write a program that sorts integers stored in a stack, using the minimum number of operations possible. 


This project is an excellent opportunity to deepen your understanding of sorting algorithms, data structures, and efficient code practices.

## 2. Objectives

The main objectives of this project are:

- **Algorithm Efficiency:** Implement an efficient sorting algorithm that uses the fewest possible operations.
- **Memory Management:** Properly manage memory allocations to avoid leaks and ensure that all allocated memory is freed.
- **Error Handling:** Create a robust program that gracefully handles all edge cases and errors, such as invalid input or memory issues.
- **Understanding Complexity:** Gain a solid understanding of algorithmic complexity, particularly with sorting operations.

## 3. Setup and Installation

### Cloning the Repository

To start using the Push_swap project, first clone the repository from GitHub:

```bash
git clone https://github.com/yourusername/push_swap.git
```

### Compiling the Program

After cloning the repository, navigate to the project directory and compile the program using the provided Makefile:

```bash
cd push_swap
make
```

This will generate the `push_swap` executable, ready for use.

## 4. Usage

The Push_swap program takes a series of integers as arguments and returns the sequence of operations required to sort them.

### Example Usage

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

### Supported Operations

The program supports the following stack operations:

- **sa:** Swap the first two elements at the top of stack A.
- **sb:** Swap the first two elements at the top of stack B.
- **ss:** Swap the first two elements of both stacks A and B simultaneously.
- **pa:** Push the top element from stack B to stack A.
- **pb:** Push the top element from stack A to stack B.
- **ra:** Rotate all elements of stack A up by one. The first element becomes the last one.
- **rb:** Rotate all elements of stack B up by one. The first element becomes the last one.
- **rr:** Perform `ra` and `rb` simultaneously.
- **rra:** Reverse rotate all elements of stack A. The last element becomes the first one.
- **rrb:** Reverse rotate all elements of stack B. The last element becomes the first one.
- **rrr:** Perform `rra` and `rrb` simultaneously.

## 5. My program visual Workflow

Below is a diagram that represents the pseudocodic approach of the Push_swap program. This flowchart illustrates the overall logic and steps involved in processing the inputs and sorting the stack:


![Flowchart](Flowchart_image/Flowchart_pushswap.png)


## 6. Stack Operations Explained

### Operation List

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

## 7. Performance Testing

### Sorting Efficiency

To ensure your implementation is efficient, run performance tests with various inputs:

- **100 Numbers:** The stack should be sorted in less than 700 operations.
- **500 Numbers:** The stack should be sorted in less than 5500 operations.

These benchmarks help ensure that your sorting algorithm is optimized and efficient.

## 8. Error Handling

Your Push_swap program should handle errors gracefully. Some common errors include:

- **Non-numeric Input:** The program should display "Error" and exit.
- **Integer Overflow:** If any argument exceeds the integer range, the program should display "Error".
- **Duplicate Values:** If there are duplicates, the program should display "Error".

Handling these errors ensures the robustness of your program.

## 9. Memory Management

Memory management is critical in C programming. Your Push_swap program must:

Avoid Memory Leaks: All allocated memory should be freed before the program exits.

If there are no leaks it should look like this:


Proper Allocation: Memory should be allocated only when necessary, and freed promptly when no longer needed.
Tools: You can use tools like Valgrind to check for memory leaks during testing.
Here is a section for your README file that details the evaluation checklist:

---

## 10. Evaluation Checklist

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

### Example Scenario:

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

## 11. Test cases

Here's a list of all possible error cases for your Push_swap program that users might encounter when running `./push_swap input`:

### Possible Error Cases

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

## 12. Push Swap Visualizer Setup on macOS (M1/M2/M3)

This guide will help you set up the Push Swap Visualizer for your Push Swap project on macOS with M1, M2, or M3 chips.

### Prerequisites

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

### Step 1: Install Required Packages Using Homebrew

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


### Step 2: Clone the Push Swap Visualizer Repository

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


### Step 4: Run the Visualizer

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


### Troubleshooting

- **Deprecation Warnings**: Warnings about deprecated OpenGL functions can be ignored, or silenced by defining `GL_SILENCE_DEPRECATION`.

- **Missing Binary**: If the visualizer binary is not created, try the following:
```bash
  rm -rf *
  cmake ..
  make
```

- **Dependencies Not Found**: Ensure all required packages are correctly installed via Homebrew.


### Additional Notes

- Ensure that your `push_swap` program is executable:
  ```bash
  chmod +x /path/to/push_swap

- Configure the visualizer's interface to point to your push_swap executable and test with different inputs.

## 13. License

This project is licensed under the MIT License. For more details, see the [LICENSE](LICENSE) file.

---
