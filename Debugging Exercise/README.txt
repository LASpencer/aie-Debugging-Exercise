DebuggingExercise by Marc Chee (2016)
Modified by L. Andrew Spencer (2017)

In this program a group of marines fights a group of zerglings until one side is defeated.


I. Use
-------



II. Design
-----------

See bugs.txt for list of bugs resolved.

As originally written, the program would run though the fight and end. This isn't particularly 
useful as the user won't have time to read what's happening. So, I had it wait for the user to 
press a key after both teams have attacked, and at the end of the program.

I also moved the code for making attacks and printing messages to the Marine and Zergling 
classes, as a method. This will make it easier to change their behaviour later, or create 
subclasses with their own behaviour.

I replaced the marineAlive and zerglingAlive functions with a template function teamAlive.
This makes it easier to modify the code later, as changes only have to be made once 
instead of in two different functions.

Finally I changed the for loops to both use iterators. This makes the code more consistent. It 
also means that if a different container is used instead of a vector, as long as it implements 
iterators most of the code can be reused.