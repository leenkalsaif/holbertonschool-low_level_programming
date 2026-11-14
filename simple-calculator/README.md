# Simple Calculator

A small command-line calculator written in C.

## Usage
1
cat README.md
0


cat README.md

## Features

- Displays a menu
- Quit with option `0`
- Menu loops until the user quits
- Invalid choices print `Invalid choice`
- Addition (option `1`): prompts for `A` and `B`, prints `Result: <value>`
- Subtraction (option `2`): prints `A - B`
- Multiplication (option `3`): prints `A * B`
- Division (option `4`): prints `A / B`. If `B` is `0`, prints `Error: division by zero`

## Number type

The calculator uses decimal numbers (`double`) for every operation, so inputs like `2.5` are accepted and `10 / 4` gives `2.5`. Results are printed with up to 10 significant digits and no trailing zeros (`35`, not `35.000000`).
