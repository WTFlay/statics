# statics

Simple statistics calculator. Compute average, deviation and relative deviation.

## Build

```sh
$ make
```

## Run

The program reads only from the standard input. The first line is the total number of numbers and the other lines are the numbers.

```sh
$ ./gen_input.sh my_project_in_java/ "*.java" | ./statics

average: 139.277281
deviation: 166.873984
relative deviation: 1.198142
```

## Examples

The files in the data folder can be used as test files.

```sh
$ ./static < data/input0
average: 200.000000
deviation: 14.142136
relative deviation: 0.070711
```
