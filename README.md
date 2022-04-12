This assignment has not been marked. This README.md will be updated when the marks are released.

# SENG1120-Assign1
Assignment 1: Linked Lists [C++]

## INTRODUCTION
You are required to build the infrastructure to manipulate data related to student scores. Your client further specifies that you are to create a class named *LinkedList* to store the students’ information. The *LinkedList* will store each name of the student and their score in a *Node* of the list, using the provided class *Student*.

## ASSIGNMENT TASK
You are required to use a doubly linked list, as discussed in lectures, to create your own implementation of the *LinkedList* class. It will use instances of *Node* to store instances of *value_type* (in this assignment, each *Node* will be used to store an instance of the provided *Student* type).
The *LinkedList* class will be used by a main program, to be supplied to you, as well as a *makefile*. You will need to design *LinkedList* and *Node* in a way that it communicates seamlessly with the provided main program and *Student* class, compiles with the provided *makefile*, and matches the exact expected output.
Please refer to the Lecture Slides for guidance on how to properly implement both classes.

## EXPECTED COMPILING OUTPUT
```
CES236-7DXQJX2+Alex@CES236-7DXQJX2 /home/Assign1-S1-2022
$ make clean
rm -rf *.o core

CES236-7DXQJX2+Alex@CES236-7DXQJX2 /home/Assign1-S1-2022
$ make
g++ -c -Wall -c LinkedListDemo.cpp
g++ -c -Wall -c LinkedList.cpp
g++ -c -Wall -c Node.cpp
g++ -c -Wall -c Student.cpp
g++ LinkedListDemo.o LinkedList.o Node.o Student.o -o assignment1

CES236-7DXQJX2+Alex@CES236-7DXQJX2 /home/Assign1-S1-2022
$ ./assignment1.exe
Start lists:
List 1: (Alex,45) (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31)
List 2: (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
Concatenating the two lists onto list '1':
List 1: (Alex,45) (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31) (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
List 2: (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
Removing student 'Alex' from list '1':
List 1: (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31) (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
List 2: (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
Removing student 'John' from list '2':
List 1: (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31) (Michelle,12) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85) (Michelle,90)
List 2: (Michelle,12) (Carol,27) (Tim,20) (Tony,60) (Chris,85) (Michelle,90)
Removing all ocurrences of 'Michelle' from both lists:
List 1: (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85)
List 2: (Carol,27) (Tim,20) (Tony,60) (Chris,85)
Removing student 'Fred' from list '2':
List 1: (Peter,10) (John,32) (Mary,95) (Karen,70) (Carol,31) (Carol,27) (Tim,20) (John,75) (Tony,60) (Chris,85)
List 2: (Carol,27) (Tim,20) (Tony,60) (Chris,85)
Statistics of list '1': (10 / 50.5 / 95)
Statistics of list '2': (20 / 48 / 85)
Number of students named 'Carol': 3
The program has finished.
```
