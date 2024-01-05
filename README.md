<h1>Ferry Loading</h1>
This problem simulates the operation of a river ferry that transports cars between two river banks. The ferry has a fixed length and operates continuously between the banks, carrying cars back and forth. The goal is to determine the minimum number of times the ferry needs to cross the river to serve all waiting cars. The original problem is from Piotr Rudnicki.

<h2>Input & Output</h2>

- The input consists of multiple test cases. The first line of each test case contains two integers: 'l' (length of the ferry) and 'm' (number of cars). The following 'm' lines describe each car, specifying its length (in centimeters) and the bank at which it awaits the ferry ('left' or 'right').
- For each test case, the output should be a single line indicating the minimum number of times the ferry has to cross the river to serve all waiting cars.

```
Input:
2
10 4
380 left
720 right
134 left
175 right
15 6
340 left
650 left
110 right
80 left
130 right
270 right
```
```
Output:
4
5
```

<h2>Implementation</h2>

- The ferry has a length of 'l' meters and travels between two river banks. The ferry can only load cars that fit on its deck.
- Cars may arrive at either bank and need to be transported to the opposite bank. Cars wait in lines on both banks until the ferry arrives.
- The problem is solved by using a linked list as a queue data structure. Implement the ferry loading logic efficiently to minimize the number of river crossings. Unlike the typical array implementation, this solution utilizes a linked list to manage the queue of waiting cars.
