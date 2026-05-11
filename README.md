# Targilon-5
targilon 5 for advanced programming course

https://github.com/orLevinson/Targilon-5

3. firstly the program creates a new Foo object with a bar value of 0 at the beginning. then, it creates 2 new threads and gives each thread an objective to use the baz method of the Foo object 10000 times each(using an anonymous function). then the main thread is instructed to wait to both the two created threads to fininsh before printing the finished bar value of the Foo instance.
The program didn't compile though, because join throws a checked exception, thus we need to handle it using a try catch value.(I changed the code to include a try catch, and now the code works an outputs a random value below 20K, because of race condition when both the threads try to modify the value of bar, which is a shared memory, at the same time)

4. it seems like the keyword synchronized provides mutex for code blocks - in our case, a public method - in java. when implementing the synchronized keyword on our baz method, we eliminated the race condition that occured with 2 threads trying to modify the value of bar simultaniously.

5. it did the same thing as in assignment 4, but this time instead of locking the entire method, we locked only the memory modifying part - the bar++ line, thus achieving the same goal and the same result.

6. it looks like we are creating 10 threads and trying to run baz method for 10M times in each thread. the output isn't 100M because of race condition for trying to modify shared memory between the threads(the value of bar), and in the end the program prints the value of bar and the time that it took the program to calculate it.

7. now we used the synchronized keyword to lock the memory modifying part of baz method that all of the threads use simultaniously, and effectively eliminated the race condition that occured - at the cost of the time that it took the system to lock and unlock the code blocks between the context switches. now when the program prints at the end the value of bar and the time it took to calculate it, as expected, the value of bar is exactly 100M(because there were no race condtions), but it took longer time to calculate in relation to the time it took to calculate it in the sixth assignment.