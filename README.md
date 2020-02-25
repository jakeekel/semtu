# semtu
SEMTU (SEt of sMall and tricky Test Units) is a public benchmark that contains set of examples that make KLEE generate incorrect test cases result in sequential program and not relevant test cases result in multithreaded program. We provide seven examples. Following are the examples :
1. The imprecision of symbolic analysis in case of dynamic memory management.
2. The influence of shared variables on execution paths of multithreaded programs.
3. Data race.
4. Division by zero error.
5. Null pointer check error.
6. Out of bound access error.
7. Read of uninitialized error.

In order to check how many errors occured during the execution of the program, we created sample source code and executed it 10000 times. We display the result of the benchmark in table_result.txt
