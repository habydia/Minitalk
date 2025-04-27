Minitalk is a project whose objective is to create a communication system between a server and a client, using only the SIGUSR1 and SIGUSR2 signals.
The client sends a string to the server, bit by bit, via these signals, and the server must reconstruct and display the message.

The project provides an introduction to:
UNIX signal handling
Low-level data transmission
The concepts of asynchronism and events
