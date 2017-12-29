MAKE = make

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


