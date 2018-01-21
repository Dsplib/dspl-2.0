MAKE = make

LIB_PATH = linux64


all:
	$(MAKE) -f Makefile.dspl 
	$(MAKE) -f Makefile.plot 
	$(MAKE) -f Makefile.test 
	$(MAKE) -f Makefile.verif 
	cp lib/dspl/bin/libdspl.a release/lib/$(LIB_PATH)/libdspl.a
	cp lib/plot/bin/libplot.a release/lib/$(LIB_PATH)/libplot.a
	cp lib/extlibs/$(LIB_PATH)/libfftw3.a release/lib/$(LIB_PATH)/libfftw3.a
	cp include/dspl.h release/include/dspl.h
	cp include/plot.h release/include/plot.h
	cp include/common.h release/include/common.h

clean:
	$(MAKE) -f Makefile.dspl clean
	$(MAKE) -f Makefile.plot clean
	$(MAKE) -f Makefile.test clean 
	$(MAKE) -f Makefile.verif clean


