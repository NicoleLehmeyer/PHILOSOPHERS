# PHILOSOPHERS

<p>
  <b><a href="https://github.com/NicoleLehmeyer/PHILOSOPHERS/blob/main/subject/PHILOSOPHERS_SUBJECT.pdf">'philosophers'</a> is a 42 project which involves the creation of a program which tackles the 'Philosophers' problem, requiring the use of concurrent programming by threading processes and utilising mutexes.</b>
    
<br><br>
  <b>philosophers Grade: 100%</b>
  <br>
  <br>
  <br>
  <b>The Philosophers Problem:</b><br>
  - One or more philosophers sit at a found table. They each bring one fork to the table, which they will use, with another fork shared with an adjacent philosopher (one fork in each hand - left & right), to eat one big bowl of spaghetti in the centre of the table. (Maybe you only need one fork to eat spaghetti, but these philosophers are special and need two. If that idea still doesn't sit well with you, maybe imagine that the forks are chopsticks... These philosophers must have two to eat!<br>
  - When a philosopher has finished eating, they place both forks on the table. They alternatively <b>eat, sleep, then think</b>. They can only do one task at a time.<br>
  - The philosophers can starve to death if they haven't eaten for a specified period of time...<br><br>

  <b>Program Arguments:</b><br>
  - <code>number_of_philosophers</code>: Number of philosophers (also number of forks)<br>
  - <code>time_to_die</code>(in milliseconds): If a philosopher hasn't started eating <code>time_to_die</code> ms since the beginning of their last meal/beginning of simulation, they die!<br>
  - <code>time_to_eat</code>(in milliseconds): Time it takes for a philosopher to eat a meal (with two forks)<br>
  - <code>time_to_sleep</code>(in milliseconds): Time it takes for a philosopher to sleep, after eating<br>
  - <code>number_of_times_each_philosopher_must_eat</code>(optional arg): Min times each philosopher must eat to end the simulation. Otherwise, the sim will either stop when a philosopher dies, or run infinitely if the conditions allow.<br><br>
  
  <b>The Program:</b><br>
  - Each philosopher is named by number, from <code>1</code>, to <code>number_of_philosophers</code><br>
  - Philosopher <code>1</code> sits next to philosopher <code>number of philosophers</code>. Other philosophers, <code>N</code> sit next to philosopher <code>N - 1</code> and <code>N + 1</code><br>
  - The program output must be a log of philosopher events, formatted as <code>timestamp_in_ms X event</code>, where <code>X</code> is the philosopher name<br>
  - The messages must not be jumbled or mixed, and the message announcing that a philosopher has died must display no more than 10ms after death.<br>
  - Each <b>philosopher</b> should be a <b>thread</b>, and each <b>fork</b> should be a <b>mutex</b><br><br>

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
  You may also specify number of integers to test with and how many times you wish to test: <code>./push_swap_tester.sh <no. of integers> -r <no. of tests run></code><br>
  ie. <code>./push_swap_tester.sh 100 -r 200</code> (run program with 100 integers, 200 times)<br>
  <br>
  <br>
</p>

---
<p align="center">
Made by NicoleLehmeyer: nlehmeye@student.42adel.org.au | LinkedIn: <a href="https://www.linkedin.com/in/nicole-lehmeyer/">nicole-lehmeyer</a> | Discord: <a href="https://discordapp.com/users/1107446949344448543/">nicole.lehmeyer</a>
</p>
