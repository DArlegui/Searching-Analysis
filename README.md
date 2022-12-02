# Program 14 Searching-Analysis

This program will analyze the efficiency of these search algorithms:
- Procedural sequential search (procedural means non-recursive)
- Procedural binary search
- Recursive sequential search
- Recursive binary search
- Hashing search

Let n represent the number of values in our search container (i.e. the values vector).

We'll conduct 13 grand-simulations for each algorithm using varying container sizes. We'll start with 2, and then successively double the container size with each iteration of the loop, up to a maximum of 8192. This means that for size, say, n = 8, we'll have 8 elements in our vector. We'll then evaluate how efficient the search algorithm is with 8 elements by actually searching for a term that we know will be in the vector. We'll count the number of key exchanges that it took to find that element.

For the procedural sequential search, we'll do 13 grand-simulations for n = 2, n = 4, ... , n = 8192. We'll then do 13 grand-simulations for procedural binary search, and so forth.

For each of these gradually-increasing container sizes, we'll do these tasks:
- create a vector to hold values
- run 1000 simulations. Each simulation:
  - pushes "n" number of random values (say 100-10,000) into the vector
  - randomly selects one of those vector elements as the search term (thereby guaranteeing the search will be successful)
  - then searches for that element in the vector using the right algorithm
  - the number of key comparisons are returned from the function, and stored in a convenient container

Then calculate the average number of key comparisons for that run of 1000 simulations.

From there, derive the efficiency: if there were 1000 simulations on container size n = 512, and on average it took 400 key comparisons, we divide the average by the container size to get the efficiency, 400/512 = 0.78.

![image](https://user-images.githubusercontent.com/79351401/205207512-a5bb81da-369a-458d-a16d-c200448098b7.png)
