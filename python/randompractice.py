import random
random.seed(5) #seed() is used to initialize the random number generator.
# If you provide a specific seed value,
# you will get the same sequence of random numbers every time you run the program.
# If you don't provide a seed value, 
# it will use the current system time to generate a different sequence of random numbers each time.

# random.random() is used to generate a random float number between 0.0 and 1.0.
print(random.random())
# random.randint(a, b) is used to generate a random integer N such that a <= N <= b.
print(random.randint(1, 10))
# random.choice() is used to select a random element from a non-empty sequence (like a list or a string).
print(random.choice(['apple', 'banana', 'cherry']))
# random.sample() is used to generate a list of unique random numbers from a specified range or sequence.
print(random.sample(range(1, 100), 5))
# random.randrange() generates a random number from the range [0, 100) with a step of 5 (i.e., 0, 5, 10, ..., 95).
print(random.randrange(start=0, stop=100, step=5))
#random.uniform(a, b) is used to generate a random float number between a and b (inclusive).[a, b]。
print(random.uniform(1.5, 3.5)) 

lst=[i for i in range(10)]
print(random.shuffle(lst)) 
#random.shuffle() is used to shuffle the elements of a list in place.
