# Lab 3: Investigating Process Lifecycles and OS Interaction

**Module:** ST5003CMD Operating Systems, Security and Networks
**Author:** Shweta
**Environment:** Ubuntu 24.04 (WSL), GCC 13.3.0

This lab explores how C programs behave as processes managed by the Linux kernel:
querying process identity, controlling execution time, reading standard input, and
reporting success or failure to the shell through exit codes.

## Files

| File | Description |
|------|-------------|
| `task1_alive.c` | Long-running process that loops for 30 seconds using `sleep()` |
| `task2_identity.c` | Prints its own PID and its parent's PID using `getpid()` and `getppid()` |
| `task3_exit.c` | Returns exit code 0 for positive input and 1 for negative input |
| `task4_input.c` | Reads a name from standard input and prints a greeting |
| `task5_control.c` | Prints its PID, branches on user choice, and returns 0 or 1 |

## How to compile and run

```bash
gcc task1_alive.c -o task1
./task1 &            # run in the background
ps aux | grep task1  # monitor the running process
```

```bash
gcc task2_identity.c -o task2
./task2 &
ps -p <PID> -o pid,ppid,cmd
```

```bash
gcc task3_exit.c -o task3
./task3              # enter 5  -> Success
echo $?              # 0
./task3              # enter -5 -> Failure
echo $?              # 1
```

```bash
gcc task4_input.c -o task4
./task4              # enter your name
```

```bash
gcc task5_control.c -o task5
./task5              # enter 1 -> Continuing..., exit code 0
./task5              # enter 0 -> Exiting...,    exit code 1
echo $?
```

## Concepts covered

- **Process:** a program in execution, tracked by the kernel in its process table.
- **PID / PPID:** every process has a unique ID and records the ID of the process that created it.
- **sleep():** suspends the process for a number of seconds; the process stays in the sleeping state.
- **Background execution (&):** runs a process without blocking the shell.
- **Standard streams:** stdin for input (`scanf`), stdout for output (`printf`).
- **Exit codes:** the value returned from `main()` is the exit status; 0 means success, non-zero means failure, and it is read with `echo $?`.

## Report

The full lab report, with flow diagrams and screenshots of all verification steps, is included in this repository.
