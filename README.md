# BSQ

BSQ (Biggest SQuare) is a command-line program that identifies the largest possible square in a grid defined by . (holes) and o (walls). The program can accept an input grid or generate one based on a specified string and dimensions, then displays the grid with the largest square marked by x.
Features

    Find Largest Square: Given a grid with holes (.) and walls (o), the program identifies the largest square composed entirely of holes.
    Grid Generation: Can generate a custom grid based on a user-specified string and size.
    Results Display: Prints the modified grid with the largest square highlighted using x.

## Usage
### Input Format

The grid should be represented as an x * y matrix where:

    . represents a hole.
    o represents a wall.

For example:
```
....o
.....
..o..
.....
```

### Example Run

Given an input grid like the one above, BSQ will find the largest square area filled only with . and mark it with x.
Output Example

For the grid:
```
....o
.....
..o..
.....
```

BSQ would output:

```
xx..o
xx...
..o..
.....
````

(First biggest square found)

## Generating a Grid

You can also provide BSQ with a string and a size to generate a grid automatically.

Example command:

```bash
$ ./bsq size "pattern_string"
```

Where:

    pattern_string is a string defining the pattern (e.g., ..o).
    size is the integer representing grid dimensions.

## Installation

Clone the repository and compile the code using make:

```bash
git clone https://github.com/username/bsq
cd bsq
make
```

This will produce an executable called bsq.
Running the Program

To find the largest square in an input grid:

```bash
$ ./bsq <path_to_grid_file>
```

To generate and analyze a grid based on a pattern and size:

```bash
$ ./bsq size "pattern_string"
```
