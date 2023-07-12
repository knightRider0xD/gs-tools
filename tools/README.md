# Tools

Contains programs and scripts that can be used in your autograders.

## Usage

1. Add dependencies to your `setup.sh` file:
  ```
  # Install node
  apt-get install -y nodejs
  
  # Make tools executable
  chmod +x /autograder/source/tools/*
  ```
2. Add this tools directory to your autograder files, alongside your `run_autograder` and `setup.sh`.
3. In your `run_autograder` script, make sure the added tools directory is in your `PATH`:  
  ```
  # Add Tools to PATH
  export PATH=/autograder/source/tools:$PATH
  ```
  (this command needs to be before any commands that use the tools)
