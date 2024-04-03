## Interaction of processes
1. Develop and debug a program representing the parent process and performing the following functions:
    1. Creating an anonymous channel;
    2. Creating (launching) a descendant process whose standard input stream is redirected to the input stream of an anonymous channel;
    3. Transmitting a data stream through a channel to a descendant process.
2. Develop and debug a program representing a descendant process and performing the following functions:
    1. Receiving data from the parent process via the standard input stream
    2. Formatted output of the received data to the standard output stream
3. Check the operation of the data transmission channel when organizing interaction between the parent process and the child process for two options:
    1. Use the developed program as a descendant process
    2. Use the standard Windows utility as a descendant process
