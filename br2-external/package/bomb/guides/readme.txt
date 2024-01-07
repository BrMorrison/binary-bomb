Welcome to the binary bomb game!

This is a game about using reverse engineering to defuse a "bomb" running in
a virtual machine. When executed, the bomb will prompt you for passwords and
your goal is to use gdb to determine the right passwords and prevent the bomb
from exploding.


Prerequisites
=============

In order to play the game, you will need the following programs installed on
your computer.

- qemu-system-arm
- gdb-arm (or gdb-multiarch)


Starting the Virtual Machine
============================

To start the vm, simply run

`./run_script.sh`

This will take you to a bash shell where you can work. Note that when you start
the VM, you should see a message talking about a "char dev" like 
`char device redirected to /dev/pts/5 (label gdb)`. Keep track of this, you'll
need that info later when starting gdb.


Running the Bomb
================

The bomb program lives in /usr/bin/bomb and optionally takes the path to a text
file with passwords as an argument. It can be run as

`bomb [password_file]`

When a password file is provided, the program will read passwords from the file
until it reaches the end and then it will switch back to using standard input
to get passwords from the user.


Debugging the Bomb
==================

To debug the bomb program, you'll need to use gdbserver connected to the 
/dev/ttyS0 serial port in the virtual machine. This can be accomplished with

`gdbserver /dev/ttyS0 /usr/bin/bomb [password_file]`

From there, on your host machine you'll need to run

`gdb-multiarch bomb`

Then inside of gdb you'll need to connect to the device that the virtual machine
specified when it started up. In my case, I would use /dev/pts/5

`(gdb) target extended-remote /dev/pts/5`

At this point, everything should be connected and the program should start
running if you type `c` at the gdb command prompt.


Remote GDB Notes
================

Using remote gdb can be a bit weird, so here are some notes on starting and
stopping the program.

If the program terminates, you should be able to restart it by running

`(gdb) r [arguments]`

at the gdb prompt, where `[arguments]` is an optional list of arguments for the
program.

If you want gdbserver to stop running in the VM, you can stop it by running

`(gdb) monitor exit`

from the gdb command prompt. Though you may need to re-run the
`target extened-remote` command from gdb if you restart the gdbserver.

