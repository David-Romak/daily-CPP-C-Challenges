# Flowing Words

## Problem Description

If a sentence flows, the first letter of each word will be the same as the last letter of the previous word.

## Task

Write a program that takes in a string that contains a sentence and checks if the first letter of each word is the same as the last letter of the previous word. If the condition is met, output `true`; if not, output `false`.

**Note:** Casing does not matter.

## Input Format

A string containing a sentence of words.

## Output Format

A string: `true` or `false`.

## Example

**Input:**

```
this string gets stuck
```

**Output:**

```
true
```

## Explanation

- "this" → 's' is the last letter
- "string" → starts with 's' ✓
- "string" → 'g' is the last letter
- "gets" → starts with 'g' ✓
- "gets" → 's' is the last letter
- "stuck" → starts with 's' ✓

All conditions are met, so the output is `true`.
