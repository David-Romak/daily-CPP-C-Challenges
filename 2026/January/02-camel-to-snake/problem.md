# Camel Case to Snake Case Converter

## Problem Statement

Your company is refactoring its codebase and converting all naming conventions from **camelCase** to **snake_case**.

The conversion rule is straightforward:

- The first letter remains lowercase (without underscore)
- Every subsequent capital letter is replaced with an underscore followed by its lowercase equivalent

**Example:** `SomeName` → `some_name`

## Task

Write a program that converts a string from camelCase to snake_case.

## Input Format

A single string written in camelCase.

## Output Format

The converted string in snake_case.

## Examples

### Example 1

**Input:** `camelCasing`  
**Output:** `camel_casing`

### Example 2

**Input:** `myVariableName`  
**Output:** `my_variable_name`

### Example 3

**Input:** `HTTPSConnection`  
**Output:** `h_t_t_p_s_connection`
