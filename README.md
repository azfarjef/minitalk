# Minitalk

This project is a small data exchange program that uses UNIX signals for communication between a client and a server. The program allows the client to send a string to the server, which then displays the string on its standard output.

## Usage

1. Compile the source files using Makefile:
```bash
make
```
2. Start the server:
```bash
./server
```
The server will print its PID after starting.

3. In another terminal, start the client with the server's PID and the string to send:
```bash
./client [SERVER_PID] "Hello, world!"
```

4. The server will receive the string and display it on its standard output. In the bonus feature, the client will also receive an acknowledgement signal from the server.


## Implementation Details

The minitalk program uses UNIX signals to communicate between the client and server. When the client sends a string to the server, it converts the string to a bitstream of 0's and 1's and sends the bitstream one bit at a time using SIGUSR1 and SIGUSR2 signals. The server listens for these signals and reconstructs the bitstream to obtain the original string.

For the bonus feature of acknowledging every message received, the server sends a signal back to the client using the same signal that the client used to send the message (i.e. SIGUSR1 or SIGUSR2).

## Credit
This project was completed as part of the curriculum of the Ecole 42 program. The instructions for the project were provided by the school.
