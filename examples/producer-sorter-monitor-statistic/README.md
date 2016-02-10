# Demo - Producer, Sorter, Monitor, Statistic
This is a very small and simplistic demo, created for the fabric attached memory emulation. The script `emulation_configure.bash` is able to set up, up to 4 fabric-machines, so you can assign each machine a specific role.

## Description
To show the use of fabric attached memory we have 4 roles:
- **Producer**: Produces an array of numbers
- **Sorter**: Sorts the array of numbers, created by the producer
- **Monitor**: Prints correspondent pairs of number arrays, created by the producer and sorted by the sorter
- **Statistic**: Prints the 3 most produced numbers produced by the producer

All roles run in an infinite loop with specific sleeping times (intentionally not the same).

## How to compile
To compile all binary files type: `make all`

To compile just one binary file, type: `make <TARGET>` where \<TARGET\> is either `producer`, `sorter`, `monitor` or `statistic`

You can find all binary files in the **bin/** folder.

After compiling simply deploy the correspondent binaries for a fabric machine via SSH.


## First start
Before you start to use the shared memory, initialize the *header* for the memory handling. The header is simply a struct in C to have some tracking of the number arrays and the progress of sorting. See the **lib/lib.h** file for further information.

To initialize the header execute `init_memory` on any fabric machine (this binary is created by compiling everything).

## Start
Start any of the binaries on a dedicated fabric machine and see what it does. You need root privileges to run the binaries.

Additionally you can abort some tasks or initialize the header of the memory to see what happens.

Enjoy!
