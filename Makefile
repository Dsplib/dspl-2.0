



ifeq ($(OS),Windows_NT)
    MAKE = mingw32-make  
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        MAKE = make       
    endif
endif





all:
	$(MAKE) -f Makefile.dspl 
	$(MAKE) -f Makefile.plot 
	$(MAKE) -f Makefile.test 
	$(MAKE) -f Makefile.verif 

clean:
	$(MAKE) -f Makefile.dspl clean
	$(MAKE) -f Makefile.plot clean
	$(MAKE) -f Makefile.test clean 
	$(MAKE) -f Makefile.verif clean


