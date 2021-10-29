/*

1.
size of word is 16 - 2 bytes - unsigned short

2.
unsigned short int [8 general purpose registers (R0-R7), 
value of program counter (PC), the contents of the instruction 
regirster (IR)]

3.
unsigned short int array[10] - to hold the values of R0-R7
array[0] = R0, array[1] = R1 ...

4. 
char CC (condition code); (N,P,Z)

5. 
first 2 bytes is the starting address 
read the first 2 bytes from the file. 
let x - unsigned short variable for holding the starting address
first bytes -> bits 8-15 of x (1111111100000000 x = x | ff00; 
second bytes -> bits 0-7 of x (0000000011111111 x = x | 00ff)
(slides 85-98 how set/extrat values of variables)

6.
initially, R0-R7 -> 0, IR -> 0, CC -> "Z", PC -> starting address

7.
use unsigned short int M_array[] to store the machine code in the file,
each element of the array is each word consists of 2 bytes in LC3.
    a. M_array[0] = first instruction
       M_array[1] = second instruction...
       populate the M_array by reading the contents of the file into 
       the array, not inlcude the starting address
    b.later as executes the program, can obtain the instruction/value 
      stored in the memory form M_array

8. 
unsigned short int IR;
to "execute" an instruction, need to fetch the instruction from the 
M_array into the variable for IR. the address of the instruction
is given in PC.

9.
Determine the type of instruction in IR, need to check the [opcode]
of the instruction. --> check the value in bits 12-15 of the IR.
(slides 85-98 for finding out the value of the opcode of the 
instruction)

10.
use a [loop] to load each instruction into the IR. 
after loading an instruction into the IR, the value of PC should +1.
    a. understand the steps that a CPU takes when it executes an 
       instruction (first part of the course)
    b. First, the CPU check the opcode of the instruction - LD  (0x2)
        #yes 
        i. the LD inst load the contents of a memory location to a 
           register. the address of the memory location is obtained
           by PC + offset
        ii.the value of offset (slides 85-98 retrieve the offset) 
           stored in bits 0-8 of the instruction
        iii.find the value of address of the memory location -> find
            the index of the M_array's element that corresponds to 
            the memory location -> retrieve the value to be loaded to
            a register from that array element
        iv. the ID of the register that receives the value is stored
            in bits 9-11 of the instruction (i.e. IR) (slides 85-98
            retrieve the ID)
        v. the ID number is used as the index to find the element in
           the register array that corresponds to the register in 
           LD instruction
        vi.store the value retrieved from the memory to the register
        vii.according to the value loaded into the register in the LD 
            instruction then can set the value in the CC.
*/