main: main.o print_str.o get_name.o
	gcc main.o print_str.o get_name.o -o main
main.o: main.c get_name.h print_str.h
	gcc -c main.c
print_str.o: print_str.c
	gcc -c print_str.c
get_name.o: get_name.c
	gcc -c get_name.c
