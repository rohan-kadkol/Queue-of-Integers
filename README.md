# Integer Queue

Basic implementation of an int queue.

## How to run the code (on Linux/Mac, use GitBash for Windows)

To compile the code
```
gcc -o ./executables/queue queue.c
```

To run the code
```
./executables/queue
```

## Cases

* To enqueue an int of value x, ```ENQUEUE x```

* To dequeue from the queue, ```DEQUEUE <dummy int>```. 

* To exit, ```EXIT <dummy int>```.

The dummy variable can be any int value. This is because the code expects a string and an int at all times. An example of a dummy int is ```-1```.

## Sample Output

```
$ ./executables/queue
ENQUEUE 5
5 
ENQUEUE 18
5 18 
ENQUEUE 9
5 18 9 
ENQUEUE 45
5 18 9 45 
ENQUEUE 1
5 18 9 45 1 
ENQUEUE 2
5 18 9 45 1 2 
DEQUEUE -1
18 9 45 1 2 
DEQUEUE -1
9 45 1 2 
DEQUEUE -1
45 1 2 
DEQUEUE -1
1 2 
DEQUEUE -1
2 
DEQUEUE -1

EXIT -1
```