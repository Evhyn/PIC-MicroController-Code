# Comment:  This is the simplest of makefiles!

# Here is a template:
# [target]:  [dependencies]
# [tab] [command to execute]

# The thing to the left of the colon in the first line is what is created, 
# and the thing(s) to the right of the colon are what it depends on.  The second
# line is the action to create the target.  If the things it depends on 
# haven't changed since the target was last created, no need to do the action.

# make the hex file from the elf file
AmbientLightSensor.hex:  AmbientLightSensor.elf
	xc32-bin2hex AmbientLightSensor.elf

# make the elf file from the object file (link); "-Wl" below is "-W ell" not "-W one"
AmbientLightSensor.elf:  AmbientLightSensor.o
	xc32-gcc -mprocessor=32MX795F512L -o AmbientLightSensor.elf AmbientLightSensor.c


# make the object file from the C source file (compile and assemble)
AmbientLightSensor.o:  AmbientLightSensor.c
	xc32-gcc -g -x c -c -mprocessor=32MX795F512L -o AmbientLightSensor.o AmbientLightSensor.c




# "make clean" throws away all previously made files to ensure make from scratch
clean:
	rm -f *.o *.elf *.hex