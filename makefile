CC = gcc
AR = ar
CFLAGS = -Wall -g

SRCS_LOOP = advancedClassificationLoop.c basicClassification.c
SRCS_REC = advancedClassificationRecursion.c basicClassification.c
OBJECTS_LOOP = $(SRCS_LOOP:.c=.o)
OBJECTS_REC = $(SRCS_REC:.c=.o)

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec


main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

# Create object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create static lib that contains all loop code
libclassloops.a: $(OBJECTS_LOOP)
	$(AR) -r -c -s $@ $(OBJECTS_LOOP)

# Create static lib that contains all recursive code
libclassrec.a: $(OBJECTS_REC)
	$(AR) -r -c -s $@ $(OBJECTS_REC)

# Build the dynamic library with recursive code function
libclassrec.so: $(OBJECTS_REC)
	$(CC) -shared -o $@ $(OBJECTS_REC)

# Build the dynamic library with loop code function
libclassloops.so: $(OBJECTS_LOOP)
	$(CC) -shared -o $@ $(OBJECTS_LOOP)

# Build the main program linked with the static library recursive
mains: main.o libclassrec.a
	$(CC) -o $@ $< libclassrec.a

# Build the main program linked with the dynamic library loop
maindloop: main.o 
	$(CC) -o $@ $< ./libclassloops.so

# Build the main program linked with the dynamic library recursive
maindrec: main.o 
	$(CC) -o $@ $< libclassrec.so

# Clean up compiled files
clean:
	rm -f *.o *.a *.so mains maindloop maindrec
