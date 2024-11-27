**Comprehensive Scientific Calculator in C Framework**


Nikhil Patel 


**Purpose**


I created a Reverse Polish Notation (RPN) scientific calculator that performs basic and advanced mathematical operations using C programming. This program takes user inputs, such as numbers and mathematical operators, and calculates results in a stack-based environment. It uses function pointers, stack-based ADTs, and mathematical approximations for trigonometric functions. The program ensures accurate results by handling edge cases and normalizing inputs, making it robust and efficient.

**Testing**


To test my program, I first compared my implementation against a working version provided for reference. This allowed me to understand the expected functionality and ensured that my program behaved correctly. I conducted manual tests using various RPN inputs to verify the accuracy of both basic and advanced mathematical operations.
For trigonometric functions, I focused on testing values within the domain 000 to 2π2\pi2π, since these functions are periodic. I also tested edge cases, including extremely large inputs, negative inputs, and invalid formats, to ensure my error handling worked as intended. Additional tests checked how the program handled special cases like dividing by zero, stack underflows, and unsupported operations. By testing inputs of varying sizes and types, I confirmed that my program could handle a wide range of scenarios without crashing or producing incorrect results.

**How to Use the Program**


This calculator uses a stack-based system with Reverse Polish Notation (RPN) to perform calculations. To use the program, compile it with the command:
bash
Copy code
make all

Then, run the program with:
bash
Copy code
./calc

Once running, the program prompts you to input numbers and mathematical operators in RPN format. For example, entering 3 2 + calculates 3+23 + 23+2 and returns 5. You can chain operations like 3 2 4 + + to calculate 3+(2+4)3 + (2 + 4)3+(2+4), which results in 9. Supported operations include addition (+), subtraction (-), multiplication (*), division (/), and trigonometric functions (sin, cos, tan). The program also handles absolute values, square roots, and other basic functions.
If invalid input is entered, the program prints an error message and continues running. It remains active until you exit with an EOF signal (Ctrl+D).

**Program Design**


When designing the program, I structured it around a stack-based Abstract Data Type (ADT) to manage operands and operators. The stack is implemented as an array, and I wrote functions to push, pop, and peek at elements. These stack operations are essential for handling RPN input and ensuring the program executes calculations in the correct order.
For the mathematical functions, I implemented basic operations like addition, subtraction, multiplication, and division in separate functions. Advanced functions, such as sine, cosine, and tangent, are computed using the Maclaurin series approximation. I ensured that input values for these functions were normalized to the domain 000 to 2π2\pi2π to maintain accuracy and consistency.
The main function ties everything together. It uses an infinite loop to read user input with fgets, then tokenizes the input using strtok_r to separate numbers and operators. Depending on the token, the program performs operations, pushes numbers to the stack, or prints an error message for invalid input. I used function pointers to dynamically link operations to their corresponding functions, which made the program flexible and modular.
Error handling is a critical part of the program. For example, the program detects stack underflows, invalid operations, and malformed input, printing appropriate error messages without crashing. This design ensures the program is reliable and easy to debug or extend in the future.

**Pseudocode**


Here’s a breakdown of how I structured my program:
Main Function:
Continuously prompt the user for input.
Use fgets to read input and strtok_r to parse it into tokens.
For each token:
If it’s a number, push it onto the stack.
If it’s an operator, call the corresponding function.
If it’s invalid, print an error message.
Print the stack after each valid operation.
Mathematical Functions:
Implement basic operations (+, -, *, /) as simple functions.
Use the Maclaurin series to approximate trigonometric functions (sin, cos, tan), ensuring inputs are normalized to the range 000 to 2π2\pi2π.
Handle special cases, like dividing by zero or invalid trigonometric inputs, gracefully.
Stack Operations:
Implement stack_push to add an element to the stack and stack_pop to remove and return the top element.
Use stack_peek to view the top element without modifying the stack.
Implement stack_clear to reset the stack.

**Results**


The program successfully calculates results for a wide range of inputs and operations. For trigonometric functions, I plotted the difference between my results and the built-in math.h library functions. The results showed that my approximations were accurate within the given epsilon value. Edge cases like large inputs, negative inputs, and invalid formats were handled correctly, with appropriate error messages displayed.
Overall, the program performs as expected and demonstrates my understanding of C programming concepts like stack ADTs, function pointers, and numerical approximations. The modular design makes it easy to maintain and extend, and the robust error handling ensures reliability.

