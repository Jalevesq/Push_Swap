# Push_Swap
Push_swap is a sorting algorithm project at 42 School that involves sorting a stack of integers using only two stacks and a set of predefined operations. The goal of this project is to sort a given stack of integers in ascending order with the lowest number of operations possible.
## Compiling
To compile the push_swap program, navigate to the root directory of the project and run `make`. This will compile the push_swap executable.

## Usage
The push_swap program takes a list of integers as arguments and outputs the list of operations needed to sort the stack in ascending order.

Usage: ./push_swap [list of integers]

Example: ./push_swap 4 67 3 87 23

## Operations
The operations that can be used are:

- `sa` swap the first two elements at the top of stack a
- `sb` swap the first two elements at the top of stack b
- `ss` do sa and sb at the same time
- `pa` take the first element from the top of stack b and put it at the top of stack a
- `pb` take the first element from the top of stack a and put it at the top of stack b
- `ra` rotate stack a (move the first element to the end of the stack)
- `rb` rotate stack b (move the first element to the end of the stack)
- `rr` do ra and rb at the same time
- `rra` reverse rotate stack a (move the last element to the top of the stack)
- `rrb` reverse rotate stack b (move the last element to the top of the stack)
- `rrr` do rra and rrb at the same time
Each operation should be followed by a new line character.

# Visualizer
You can find the visualizer I used [here](https://github.com/o-reo/push_swap_visualizer)
