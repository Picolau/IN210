CXX = gcc

INCS = -I.  -I"." 
OBJS = $(SRC:.c=.o)
LDFLAGS = -lgcov --coverage
OPTION = -Wall -fexceptions -fprofile-arcs -ftest-coverage
SRC = ratp.c  main.c cmocka.c


all: $(OBJS)
	$(CXX) $(LDFLAGS) $(INCS) -o testAll $(OBJS)

exec : all
	testAll.exe
%.o: %.c
	$(CXX) $(OPTION) -c  $< -o $@ $(INCS)
	
clean:
	rm $(OBJS) 


mrproper: clean
	rm *.o
	rm testAll.exe
	rm result.xml