
objects = main.o mclass.o mvirtual.o mbit.o mcore.o 

Exe : $(objects) 
	g++ -g -o Exe $(objects) 

main.o : main.cpp mclass.h mvirtual.h mcore.h mtest.h
	g++ -g -c main.cpp

mclass.o : mclass.cpp mclass.h
	g++ -g -c mclass.cpp

mvirtual.o : mvirtual.cpp mvirtual.h
	g++ -g -c mvirtual.cpp

mbit.o : mbit.cpp mbit.h 
	g++ -g -c mbit.cpp		

mcore.o : mcore.cpp mcore.h 
	g++ -g -c mcore.cpp		

.PHONY : clean
clean : 
	rm Exe $(objects) 

