---------------------------------------------------------------------------------------------------------------------------
Running the code:
1. Use 'make test' to compile and generate object file
2. Use 'make run' to run the program
3. Use 'make clean' to remove the executables

Brief description:
1. Main code acts like a testbench and calls the required functions based on message type.
2. 'update_motor' checks the message for correctness and calls the appropriate functions with the float values.
2. 'display_message' check the message for correctness and calls the 'LCD_display' function.

Possible improvements:
1. An extra parity-bit (even or odd) can be can be appended to the message to monitor its integrity.
2. Another solution is to perform Cyclic Redundancy Check. Although it increases our message size, it can be very useful
   in detecting possible corruption of data.
3. Changing packet array to packet structure with data elements will make it easy to operate with and document it.
 

