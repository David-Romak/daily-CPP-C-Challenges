# Keyboard Symbol Cleanup

## 📝 Problem Statement

Your keyboard has a frustrating bug: it randomly inserts symbols into your text while you're typing! You need to clean up the corrupted text by removing all unwanted symbols, leaving only alphanumeric characters (letters and numbers) and spaces to maintain word separation.

## 🎯 Objective

Write a function that takes a corrupted string containing random symbols and returns a cleaned string containing only:

- **Letters** (both uppercase A-Z and lowercase a-z)
- **Numbers** (0-9)
- **Spaces** (to preserve word boundaries)

All other characters (symbols, punctuation, special characters) must be removed.

## 📥 Input Format

A single string `text` where `1 ≤ length ≤ 1000` that may contain:

- English letters (uppercase and lowercase)
- Digits (0-9)
- Spaces
- Various symbols: `! @ # $ % ^ & * ( ) _ + - = [ ] { } | \ ; : ' " , . < > / ? ~`

> **Note:** The input may contain any ASCII character except control characters.

## 📤 Output Format

A cleaned string containing only alphanumeric characters and spaces.

## 🧪 Examples

### Example 1

**Input:**

```
#l$e%ts go @an#d@@ g***et #l#unch$$$
```

**Output:**

```
lets go and get lunch
```

**Explanation:**

- `#l$e%ts` → `lets` (removed `#`, `$`, `%`)
- `go` remains `go` (no symbols)
- `@an#d@@` → `and` (removed `@`, `#`, `@`, `@`)
- `g***et` → `get` (removed `*`, `*`, `*`)
- `#l#unch$$$` → `lunch` (removed `#`, `#`, `$`, `$`, `$`)

### Example 2

**Input:**

```
H3ll0 W0rld! Th1s is @ t3st.
```

**Output:**

```
H3ll0 W0rld Th1s is t3st
```

**Explanation:**

- `H3ll0` remains `H3ll0` (alphanumeric)
- `W0rld!` → `W0rld` (removed `!`)
- `Th1s` remains `Th1s`
- `is` remains `is`
- `@` → removed completely
- `t3st.` → `t3st` (removed `.`)

### Example 3

**Input:**

```
C0d3_Ch@ll3ng3 #2024
```

**Output:**

```
C0d3Chll3ng3 2024
```

**Explanation:**

- `C0d3_Ch@ll3ng3` → `C0d3Chll3ng3` (removed `_` and `@`)
- `#2024` → `2024` (removed `#`)

🔍 Constraints

    String length: 1 ≤ n ≤ 1000

    Character set: Standard ASCII (32-126)

    Time complexity: O(n) expected

    Space complexity: O(n) expected (for new string creation)
