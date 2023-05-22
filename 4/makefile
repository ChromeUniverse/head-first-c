encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

message_hider.o: message_hider.c encrypt.h
	gcc -c message_hider.c 

message_hider: encrypt.o message_hider.o
	gcc encrypt.o message_hider.o -o message_hider

file_hider.o: file_hider.c encrypt.h
	gcc -c file_hider.c

file_hider: encrypt.o file_hider.o
	gcc encrypt.o file_hider.o -o file_hider