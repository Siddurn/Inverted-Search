proj.exe : main.o create_database.o display_database.o file_list.o insert.o save_database.o search.o update_database.o
	gcc -o proj.exe main.o create_database.o display_database.o file_list.o insert.o save_database.o search.o update_database.o
main.o : main.c
	gcc -c main.c
create_database.c :
	 gcc -c create_database.c
display_database.c :
	gcc -c display_database.c
file_list.c : 
	gcc -c file_list.c
insert.c: 
	gcc -c insert.c
save_database.c :
	gcc -c save_database.c
search.c : 
	gcc -c search.c
update_database.c :
	gcc -c update_database.c
clean:
	rm *.exe *.o
