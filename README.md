# Caesar-Cipher
A command-line program written in C that encrypts text using the [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher), a classic substitution cipher that shifts each letter of the alphabet by a fixed number of positions.

Built using the CS50 library as part of the CS50x course (Problem Set 2).

## How It Works

Given a non-negative integer key `k` and a plaintext message, each alphabetic character is shifted forward by `k` positions in the alphabet, wrapping around from `z` back to `a`:

```
c_i = (p_i + k) % 26
```

where `p_i` is the position of the plaintext letter in the alphabet (A/a = 0, ..., Z/z = 25) and `c_i` is the position of the resulting ciphertext letter.

- Uppercase letters stay uppercase.
- Lowercase letters stay lowercase.
- Non-alphabetic characters (spaces, digits, punctuation) are left unchanged.

## Requirements

- A C compiler (e.g. `clang` or `gcc`)
- The [CS50 library](https://github.com/cs50/libcs50) (`cs50.h`)

## Compilation

```
make caesar
```

or manually:

```
clang -o caesar caesar.c -lcs50
```

## Usage

```
./caesar key
```

`key` must be a non-negative integer, passed as a single command-line argument.

### Example

```
$ ./caesar 1
plaintext:  HELLO
ciphertext: IFMMP
```

```
$ ./caesar 13
plaintext:  Hello, world!
ciphertext: Uryyb, jbeyq!
```

```
$ ./caesar 12
plaintext:  be sure to drink your Ovaltine
ciphertext: nq emdq ba pduwz kagd Ahmxfuzq
```

## Error Handling

If the program is run with no key, more than one argument, or a key that contains non-digit characters, it prints a usage message and exits with status code `1`:

```
$ ./caesar
Usage ./caesar key

$ ./caesar 1 2
Usage ./caesar key

$ ./caesar abc
Usage ./caesar key
```

## Code Overview

1. **Validate input:** checks that exactly one argument was given and that every character in it is a digit (`isdigit`).
2. **Convert key:** turns the argument into an integer with `atoi`.
3. **Prompt for plaintext:** uses `get_string` from the CS50 library.
4. **Encrypt:** loops through each character, shifts letters using the formula above while preserving case, and prints other characters as-is.

## Known Limitations

- Very large keys may overflow `int` when converted with `atoi`.
- Only the 26 letters of the English alphabet are shifted; accented or non-ASCII letters are not handled.

## Author

Add your name here.
