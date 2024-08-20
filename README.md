# Push_swap Project 🔄
The push_swap project at 42 School involves creating a sorting algorithm to arrange a stack of integers (positive and negative) with a limited set of operations. 📊

This project enhances our understanding of algorithm optimization, stack manipulation, and efficient problem-solving. 

## Features 📋
1. **Sorting Algorithm:** Develop and implement a custom sorting algorithm.
2. **Stack Operations:** Manipulate stacks using a predefined set of operations.
3. **Algorithm Optimization:** Ensure the algorithm is efficient and optimized for performance.

## Objectives 🎯
1. Master sorting algorithms and their optimization.
2. Improve stack manipulation skills.
3. Enhance problem-solving abilities in algorithmic contexts.

## Usage 📚
The push_swap program is executed with a list of integers as arguments. 
The program will sort the integers and print the most efficient and optimal sequence of operations needed to sort them, aiming to use as few operations as possible.

### Stack Operations 🔄
The push_swap project uses the following stack operations:

**Stack A Operations:**

**sa:** Swap 🔄 - Swap the top two elements of stack **A**.

**ra:** Rotate Up 🔼 - Rotate stack **A** up by one position.

**rra:** Reverse Rotate Down 🔽 - Reverse rotate stack **A** down by one position.


**Stack B Operations:**

**sb:** Swap 🔄 - Swap the top two elements of stack **B**.

**rb:** Rotate Up 🔼 - Rotate stack **B** up by one position.

**rrb:** Reverse Rotate Down 🔽 - Reverse rotate stack **B** down by one position.


**Combined Operations:**

**ss:** Swap Both 🔄🔄 - Swap the top two elements of **both stacks A and B**.

**rr:** Rotate Both Up 🔼🔼 - Rotate **both stacks A and B** up by one position.

**rrr:** Reverse Rotate Both Down 🔽🔽 - Reverse rotate **both stacks A and B** down by one position.


**Push Operations:**

**pa:** Push to A ⬆️ - Push the top element **from stack B to stack A**.
**pb:** Push to B ⬇️ - Push the top element **from stack A to stack B**.


**Tester Implementation:** A tester has been implemented to verify that the list is indeed sorted correctly. You can use it to check the validity of the sorting algorithm and ensure that the operations produce a correctly sorted stack. It will either print "OK" it the list is sorted, or "KO" if it is not properly sorted.

## Output 🖼️
Here is a screenshot showing the output of push_swap in action with a basic input:

![Capture d’écran 2024-08-20 202156](https://github.com/user-attachments/assets/419ec272-8ae8-4ba1-8e3a-d63044f24d83)
## Installation 🛠️
To explore the push_swap project:
git clone git@github.com:elodieiam/push_swap.git
