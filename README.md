# pushswap_by_an-wuyan



<img width="780" alt="Flowchart_pushswap" src="https://github.com/user-attachments/assets/7d36d4f7-e143-41b6-8066-6f20372cc1ed">




## Push Swap Visualizer Setup on macOS (M1/M2/M3)

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


More detail info_check_here

---
