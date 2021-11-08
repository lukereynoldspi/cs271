// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm
// Name: Luke Reynolds
// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.
@R1
D=M

@R2 //sum of R0 * R1
M=0

@i //inc for R1
M=D

(LOOP)

//checks if i is 0, ends program
@i
D=M
@END
D;JEQ //greater than or less than 0

@R0 
D=M //puts value of R0 in register

@R2
M=M+D //adds value to R2

@i
M=M-1 //decrement R1 or @i in this case

@LOOP
0;JMP //next iteration of loop
(END)