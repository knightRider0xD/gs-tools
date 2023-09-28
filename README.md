# gs-tools

Gradescope Autograder Tools and Scripts

---

## Repository Moved

To better enable continued work on these Gradescope Tools, active development is moving to [knightRider0xD/gs-tools](https://github.com/knightRider0xD/gs-tools).

These tools will remain open source.

---

This repository contains tools and scripts for Gradescope autograders.  
The following tools are currently included:

- **libs/GradescopeResult.hpp** A C++ library for generating a Gradescope test result
- **tools/generate_results** Combines multiple test results to generate correctly formatted content for results.json
- **tools/merge_results** Combines multiple test results into a single test result
- **tools/cap_part_results** For groups of tests with a maximum score for that group, offsets the total score to not exceed the maximum
- **tools/extract_nbgrader_results** Extracts results from a graded NBGrader .ipynb notebook. See releases for an integrated example.
- **tools/apply_late_policy** Adjusts final mark of late submissions according to a late policy.
- **tools/append_output** Appends additional text to the body of test result. Useful if the score and output are collected separately.

These tools are mainly written using Node.js due to its native JSON support.  
More tools on their way!
