# Let's crypt stuff!

During this assignment, you will write a program for encrypting a string of text through these four steps.

## String normalization

Write a function for normalizing a string, this will do the following to the text:

- Removes all spaces
- Removes all special characters (only letters remain)
- Converts all lower-case letters to Upper-case
- Returns the resulting string

Examples:

- **Hello, World!** turns into **HELLOWORLD**
- **1..2..3..Hurray!** turns into **HURRAY**
- **{d,T,u,-,E}** turns into **DTUE**
- **02318** turns into an empty string

## String obfuscation

Write a function for obfuscating a normalized string, the function will do so by adding OB in front of any vowel (A, E, I, O, U, Y).

Examples:

- **HELLO** turns into **HOBELLOBO**
- **ANNA** turns into **OBANNOBA**
- **TIM** turns into **TOBIM**
- **EUOUAE** turns into **OBEOBUOBOOBUOBAOBE**

## Caesar's cypher

The Caesar Cipher is a primitive method of encryption, that shifts all letters of the text through the alphabet, the number of shifts being denoted by the key. We are using the English alphabet by default (a->z).

Examples:

- **HELLO** with key 2 turns into **JGNNQ**
- **CAESAR** with key 1 turns into **DBFTBS**
- **BOB** with key 7 turns into **IVI**
- **WXYZ** with key 2 turns into **YZAB** (notice that YZ, loops back to start and becomes AB)

## Split a string into code groups

Write a function for breaking a string into code groups, the function taking a string and a group size (integer) as inputs and returning the grouped string.
All groups must be filled, so if the last group is incomplete, the function should pad it with lower case x’s to ensure that all groups are of equal size.

Examples:

- **HELLOWORLD** with groups of 2 turns into **HE LL OW WO RL Dx**
- **DTUELEKTRO** with groups of 3 turns into **DTU ELE KTR Oxx**
- **RAMMSTEIN** with groups of 4 turn into **RAMM STEI Nxx**
- **BOB** with groups of 5 turn into **BOBxx**

## Combining everything

These four functions can now be combined into a single function, which:
• Normalizes an input string
• Obfuscates the normalized string
• Applies the Caesar cipher to the obfuscated string
• Splits the ciphered string into code groups and output the resulting string.
Thus, encrypting a piece of text.

This is a verbose example, outputting all steps of the encryption:

![alt text](image.png?raw=true)

## Bonus tasks (These are NOT mandatory)

- *Try creating a function for decrypting the encrypted text.
- *Try creating a function that can decrypt the encrypted text without knowing the Caesar key nor code group size.
- Modify the functions so that they also accept numbers.

* *Decryption can only reasonably expect to return the normalized text, since spaces, numbers and special characters have been deleted.*
