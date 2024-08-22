# PHILOSOPHERS

<p>
  <b><a href="https://github.com/NicoleLehmeyer/PHILOSOPHERS/blob/main/subject/PHILOSOPHERS_SUBJECT.pdf">'philosophers'</a> is a 42 project which involves the creation of a project which tackles the 'Philosophers' problem, requiring the use of concurrent programming by threading processes and utilising mutexes.
    
<br><br>
  <b>philosophers Grade: 100%</b>
  <br>
  <br>
  <br>
  <b>The Philosophers Problem:</b><br><br>
  - One or more philosophers sit at a found table. They each bring one fork to the table, which they will use, with another fork shared with an adjacent philosopher (one fork in each hand - left & right), to eat one big bowl of spaghetti in the centre of the table. (Maybe you only need one fork to eat spaghetti, but these philosophers are special and need two. If that idea still doesn't sit well with you, maybe imagine that the forks are chopsticks... These philosophers must have two to eat!<br>
  - When a philosopher has finished eating, they place both forks on the table. They alternatively <b>eat, sleep, then think</b>. They can only do one task at a time.<br>
  - The philosophers can starve to death if they haven't eaten for a specified period of time...<br><br>

  <b>Program Arguments:</b><br>
  - <code>number_of_philosophers</code>: Number of philosophers (also number of forks)<br>
  - <code>time_to_die</code>(in milliseconds): If a philosopher hasn't started eating <code>time_to_die</code> ms since the beginning of their last meal/beginning of simulation, they die!<br>
  - <code>time_to_eat</code>(in milliseconds): Time it takes for a philosopher to eat a meal (with two forks)<br>
  - <code>time_to_sleep</code>(in milliseconds): Time it takes for a philosopher to sleep, after eating<br>
  - <code>number_of_times_each_philosopher_must_eat</code>(optional arg): Min times each philosopher must eat to end the simulation. Otherwise, the sim will either stop when a philosopher dies, or run infinitely if the conditions allow.<br>

  <b>The Program:</b><br><br>
  - Each philosopher is named by number, from '1', to <code>number_of_philosophers</code><br>
  - Philosopher '1' sits next to philosopher 'number of philosophers'. Other philosophers, 'N' sit next to philosopher 'N - 1' and 'N + 1.'<br>
  - The program output must be a log of philosopher events, formatted as <code>timestamp_in_ms X event</code>, where X is the philosopher name<br>
  - The messages must not be jumbled or mixed, and the message announcing that a philosopher has died must display no more than 10ms after death.<br><br>


  
  The program must sort a list of integers in ascending order, using the allowed 'operations' to organise the integers across two stacks, <b>'stack a'</b> and <b>'stack b'</b>.<br><br>
  The integers to be sorted must be firstly placed in 'stack a', with the first argument at the top of the stack. 'stack b' begins empty.<br><br>
  <b>The sort is to be completed within the maximum number of operations:</b><br>
  - Sort 3 values in <= 3 operations<br>
  - Sort 5 values in <= 12 operations<br>
  - Sort 100 values in <= 700 operations (for 100% project validation)<br>
  - Sort 500 values in <= 5500 operations (for 100% project validation)<br><br>

  <br>
  List of operations executed must display in the standard output, each seperated by a newline character.<br><br>
  Use of <a href="https://github.com/NicoleLehmeyer/LIBFT">libft</a> is permitted.<br><br>
  No global variables permitted.<br><br>
  Program must be written in C, and <a href="https://github.com/NicoleLehmeyer/LIBFT/blob/main/subject/norme.pdf">Norminette</a> (42 organisational syntax) compliant, without seg fault/bus error/double free etc.
  <br>
  <br>
  <br>
  <b>Philosophers Method:</b><br>
  1.  Process arguments: Return error if argument format is incorrect (ie. non-number, non-sign characters) or duplicates are present, handle '+' and '-', and handle if args are written in "", ie. "20 -3 80".<br>
  2.  Initialise stacks & fill 'stack a'<br>
  3.  PUSH SWAP SORT: (a) small sorts for 2 & 3 integers. (b) big sort (as written below) for > 3 integers<br>
  4.  Free stacks<br>
  <br>
  <b>Big Sort Method:</b><br>
  1.  Push all but 3 integers to 'stack b'<br>
  2.  Small sort on 'stack a' to create an ascending order<br>
  3.  For each integer in 'stack b', assign: (1) target position - position in 'stack a' with value of next lowest value, (2) cost - lowest number of moves to get 'stack b' integer to its target position in 'stack a'.<br>
  4.  Execute the sequence of operations for the 'stack b' integer with the 'cheapest' move number to get to its target position.<br>
  5.  Repeat until there are no values in 'stack b', then ra/rra (dependent on if smallest int is in top or bottom half of the stack) until the smallest value is at the top of the stack.<br>
  <br>
  <br>
</p>

## Run Program:
<p>
  <b>Create executables:</b> <code>make</code><br>
  <br>
  <b>Run program:</b> <code>ARG="<integers seperated by ' ' character>; ./push_swap $ARG</code><br>
  ie.: <code>ARG=""54 32 0 67 88 -1234 51 567"; ./push_swap $ARG</code><br>
  <br>
  <b>Run program with checker:</b> <code>ARG="<integers seperated by ' ' character>"; ./push_swap $ARG | ./checker_mac $ARG</code><br>
  ie. <code>ARG="54 32 0 67 88 -1234 51 567"; ./push_swap $ARG | ./checker_mac $ARG</code><br>
  <br>
  <b>My friend Nate created a fantastic push_swap checker, which can be used on my program with:</b> <code>./push_swap_tester.sh</code><br>
  <b>Check out Nate's github <a href="https://github.com/redback0">here</a>.</b><br>
  <br>
  You may also specify number of integers to test with and how many times you wish to test: <code>./push_swap_tester.sh <no. of integers> -r <no. of tests run></code><br>
  ie. <code>./push_swap_tester.sh 100 -r 200</code> (run program with 100 integers, 200 times)<br>
  <br>
  <b>**Ensure to <code>chmod 777</code> 'checker_Mac' and 'push_swap_tester.sh'**</b><br>
  <br>
  <br>
</p>

---
<p align="center">
Made by NicoleLehmeyer: nlehmeye@student.42adel.org.au | LinkedIn: <a href="https://www.linkedin.com/in/nicole-lehmeyer/">nicole-lehmeyer</a> | Discord: <a href="https://discordapp.com/users/1107446949344448543/">nicole.lehmeyer</a>
</p>
