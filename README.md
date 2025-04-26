# Mutual Exclusion Algorithms
## Overview
This repository contains classic **mutual exclusion algorithms** implemented in **C** to manage concurrent access to shared resources.  
It demonstrates various synchronization techniques essential for building reliable multi-threaded applications.

## Included Algorithms
| Algorithm                         | Description                                       |
|-----------------------------------|---------------------------------------------------|
| Race Condition Example            | Demonstrates unsafe access to shared resources.   |
| Dekker's Algorithm (Deadlock-Prone) | Early solution to mutual exclusion (with issues). |
| Peterson's Algorithm              | Correct two-process mutual exclusion algorithm.   |
| Improved Peterson's Algorithm     | Optimized version of Peterson's algorithm.         |
| Flag-Based Mutex                  | Simple mutex using flags.                         |
| Strict Alternation Mutex          | Alternating access to critical section.           |

## Why Mutual Exclusion?
When multiple processes or threads attempt to access shared resources at the same time without coordination, it can cause **race conditions**, **deadlocks**, and **data inconsistency**.  
These classical algorithms provide fundamental solutions to ensure that only one process accesses the critical section at a time.
## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/chouaibcher/mutual-exclusion-algorithms.git
   cd mutual-exclusion-algorithms
   ```
2. Compile and run an algorithm (for example, Peterson's Algorithm):
   ```bash
   gcc peterson_algorithm.c -o peterson
   ./peterson
   ```

## Performance Comparison
Each algorithm has different characteristics in terms of fairness, performance, and complexity:

- **Race Condition**: Fast but incorrect (included for demonstration only)
- **Dekker's Algorithm**: First correct solution but complex
- **Peterson's Algorithm**: Elegant two-process solution with good fairness
- **Flag-Based Mutex**: Simple implementation but potential for starvation
- **Strict Alternation**: Guarantees fairness but unnecessary blocking

## Technologies Used
- C Programming Language
- POSIX Threads (if applicable)
- Standard Synchronization Techniques

## Requirements
- GCC compiler
- POSIX threads library (pthread)
- Linux/Unix environment

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

