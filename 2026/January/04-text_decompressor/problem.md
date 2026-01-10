Text Decompressor

Problem

You are given a compressed string where each symbol is followed by a non-negative integer indicating how many times that symbol should appear in the decompressed output. Symbols are any non-digit printable characters (letters, punctuation, symbols). Digits in the input belong to counts and are not used as symbols.

Parse the string and expand each symbol by repeating it the specified number of times. If a count is zero, the symbol does not appear in the output.

Input

A single line containing the compressed string. The string contains alternating symbols (non-digit characters) and counts (one or more digits). There are no spaces.

Output

A single line with the decompressed text.

Notes / Constraints

- Counts may be multiple digits (for example, `x12` means `x` repeated 12 times).
- A count of `0` means the symbol is omitted.
- You may assume the input is well-formed (every symbol is followed by at least one digit) and the total decompressed length fits in memory.

Examples

- Input: `a2b3`
  Output: `aabbb`
- Input: `k2&4b1`
  Output: `kk&&&&b`
- Input: `x12`
  Output: `xxxxxxxxxxxx`
- Input: `z0`
  Output: ``

Task

Write a program that reads the compressed string from standard input and prints the decompressed string to standard output.
