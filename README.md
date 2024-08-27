# PHILOSOPHERS

<p>
  <b><a href="https://github.com/NicoleLehmeyer/PHILOSOPHERS/blob/main/subject/PHILOSOPHERS_SUBJECT.pdf">'philosophers'</a> is a 42 project which involves the creation of a program which tackles the 'Philosophers' problem, requiring the use of concurrent programming by threading processes and utilising mutexes.</b>
    
<br><br>
  <b>philosophers Grade: 100%</b>
  <br>
  <br>
  <br>
  <b>The Philosophers Problem:</b><br>
  - One or more philosophers sit at a round table. To eat the big bowl of spaghetti in the middle of the table, they need two forks - the one they brought to the table, and another fork shared with an adjacent philosopher (one fork in each hand - left & right), to eat one big bowl of spaghetti in the centre of the table. (Maybe YOU only need one fork to eat spaghetti, but these philosophers are special and need two. If that idea still doesn't sit well with you, maybe imagine that the forks are chopsticks... These philosophers must have two to eat!)<br>
  - When a philosopher has finished eating, they place both forks on the table. They alternatively <b>eat, sleep, then think</b>. They can only do one task at a time.<br>
  - The philosophers can starve to death if they haven't eaten for a specified period of time...<br><br>

  <b>Program Arguments:</b><br>
  - <code><b>number_of_philosophers</b></code>: Number of philosophers (also number of forks)<br>
  - <code><b>time_to_die</code>(in milliseconds)</b>: If a philosopher hasn't started eating <code>time_to_die</code> ms since the beginning of their last meal/beginning of simulation, they die!<br>
  - <code><b>time_to_eat</code>(in milliseconds)</b>: Time it takes for a philosopher to eat a meal (with two forks)<br>
  - <code><b>time_to_sleep</code>(in milliseconds)</b>: Time it takes for a philosopher to sleep, after eating<br>
  - <code><b>number_of_times_each_philosopher_must_eat</code>(optional arg)</b>: Minimum times each philosopher must eat to end the simulation. Otherwise, the sim will either stop when a philosopher dies, or run infinitely if the conditions allow.<br><br>
  
  <b>The Program:</b><br>
  - Each philosopher is named by number, from <code>1</code>, to <code>number_of_philosophers</code><br>
  - Philosopher <code>1</code> sits next to philosopher <code>number_of_philosophers</code>. Other philosophers, <code>N</code> sit next to philosopher <code>N - 1</code> and <code>N + 1</code><br>
  - The program <b>output must be a log of philosopher events</b>, formatted as <code>timestamp_in_ms X event</code>, where <code>X</code> is the philosopher name<br>
  - The messages must not be jumbled or mixed, and the message announcing that a philosopher has died must display no more than 10ms after death.<br>
  - Each <b>philosopher should be a thread</b>, and each <b>fork should be a mutex</b><br><br>

  Use of <a href="https://github.com/NicoleLehmeyer/LIBFT">libft</a> is permitted.<br><br>
  Use a non-relinking Makefile, compiling with <code>cc</code> and flags: <code>-Wall</code>, <code>-Wextra</code> and <code>-Werror</code>
  No global variables permitted.<br><br>
  Program must be written in C, and <a href="https://github.com/NicoleLehmeyer/LIBFT/blob/main/subject/norme.pdf">Norminette</a> (42 organisational syntax) compliant, without seg fault/bus error/double free etc.
  <br>
  <br>
  <br>
  <b>My Program Method:</b><br>
  1.  Check argument input (argv must be 5 or 6, and all arguments must be numbers/digits).<br>
  2.  Initialise philosopher and fork array, and assign struct variables. Assign forks to each philosopher's left and right.<br>
  3.  If there is one philosopher, it grabs a fork then dies.<br>
  4.  If there are multiple philosophers, odd philosophers wait 50 ms until they begin the routine of events (prevent race condition).<br>
  5.  Mutex on message printing to prevent jumbled messages.<br>
  6.  In the meantime, endsim() runs two threads to continually check if any philosophers have died, or if all have eaten the minimum number of times.
  7.  In event of error or end of sim, all existing threads are joined, mutexes destroyed and memory freed.<br>
  <br>
  <br>
</p>

## Run Program:
<p>
  <b>Create executables:</b> <code>make</code><br>
  <br>
  <b>Run program:</b> <code>./philo *time_to_die* *time_to_eat* *time_to_sleep* *OPTIONAL:minimum_times_each_philo_must_eat*</code><br>
  ie.: <code>./philo 2 100 100 100</code> (philosopher should die)<br> 
  ie.: <code>./philo 1 800 200 200</code> (philosopher will not eat and should die)<br> 
  ie.: <code>./philo 5 800 200 200</code> (no philosopher should die)<br>
  ie.: <code>./philo 5 800 200 200 7</code> (no philosopher should die, sim should end after each philosopher has eaten 7 times)<br>
  ie.: <code>./philo 4 410 200 200</code> (no philosopher should die)<br>
  ie.: <code>./philo 4 310 200 100</code> (philosopher should die)<br>
  - Do not test with more than 200 philosophers<br>
  - Do not test with <code>time_to_die</code> or <code>time_to_sleep</code> set to values lower than 60 ms.<br>
  <br>
  <br>
  <br>
</p>

---
<p align="center">
Made by NicoleLehmeyer: nlehmeye@student.42adel.org.au | LinkedIn: <a href="https://www.linkedin.com/in/nicole-lehmeyer/">nicole-lehmeyer</a> | Discord: <a href="https://discordapp.com/users/1107446949344448543/">nicole.lehmeyer</a>
</p>
