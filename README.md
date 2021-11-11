# 20-bit-RISC-processor-ISA

Design a simple 20 bit RISC processor ISA that is able to run the following code. Translate the following high level code into
assembly code based on your ISA. Then write an assembler (in any high level language) that can accept an assembly code (as a
text file) as an input and output a machine code (as a text file). Also, build a control unit on Logisim that is able to produce the
required control signals to execute the following code.
int main()
{
 int y;
 y = multiplyNumbers(2,3); /*Returns product of 2 and 3*/
}
int multiplyNumbers(int a, int b)
{
 int i;
 int product = 0;
 for (i = 0; i != b; i = i + 1)
 {
 product = product + a
 }
 return product;
}
