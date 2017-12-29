# Comment:  This is the simplest of makefiles!

# Here is a template:
# [target]:  [dependencies]
# [tab] [command to execute]

# The thing to the left of the colon in the first line is what is created, 
# and the thing(s) to the right of the colon are what it depends on.  The second
# line is the action to create the target.  If the things it depends on 
# haven't changed since the target was last created, no need to do the action.

# make the hex file from the elf file
LoopBackSPI.hex:  LoopBackSPI.elf
	xc32-bin2hex LoopBackSPI.elf

# make the elf file from the object file (link); "-Wl" below is "-W ell" not "-W one"
LoopBackSPI.elf:  LoopBackSPI.o
	xc32-gcc -mprocessor=32MX795F512L -o LoopBackSPI.elf LoopBackSPI.c


# make the object file from the C source file (compile and assemble)
LoopBackSPI.o:  LoopBackSPI.c
	xc32-gcc -g -x c -c -mprocessor=32MX795F512L -o LoopBackSPI.o LoopBackSPI.c




# "make clean" throws away all previously made files to ensure make from scratch
clean:
	rm -f *.o *.elf *.hex