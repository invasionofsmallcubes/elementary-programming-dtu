# Let's crypt!

This time will do a little bit of cryptography.

## The context

The Caesar cipher is named after Julius Caesar, who, according to Suetonius, used it with a shift of three (A becoming D when encrypting, and D becoming A when decrypting) to protect messages of military significance. While Caesar's was the first recorded use of this scheme, other substitution ciphers are known to have been used earlier.

    "If he had anything confidential to say, he wrote it in cipher, that is, by so changing the order of the letters of the alphabet, that not a word could be made out. If anyone wishes to decipher these, and get at their meaning, he must substitute the fourth letter of the alphabet, namely D, for A, and so with the others."
    — Suetonius, Life of Julius Caesar 56

His nephew, Augustus, also used the cipher, but with a right shift of one, and it did not wrap around to the beginning of the alphabet:

    "Whenever he wrote in cipher, he wrote B for A, C for B, and the rest of the letters on the same principle, using AA for Z."
    — Suetonius, Life of Augustus 88

More info [here](https://en.wikipedia.org/wiki/Caesar_cipher)

## The assignment

To be clear, then, here’s how encrypting HELLO with a key of 1 yields IFMMP:

```
Letter:  H  E  L  L  O
Shift:   +1 +1 +1 +1 +1
Result:  I  F  M  M  P
```

More formally, Caesar’s algorithm (or cipher) encrypts messages by “rotating” each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), pi is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, ci, in the ciphertext, c, is computed as

`ci = (pi + k) % 26`

wherein % 26 here means "remainder when dividing by 26". There is for doing this is that the alphabet has 26 letters and when you use the remainder you can basically rotate.

### Rotation example - Launching a dice with C

For example if you want to simulate a dice in C what you can do is extracting a totally random number like 1450, and then use the reminder operation with 6 (the number of the faces of a commond dice, if you play Dungeons and Dragons you can have a dice with 20 faces and the procedure would be the same).

So:

- if we do 1447 % 6, the result will be 1.
- if we do 1449 % 6, the result will be 3.
- if we do 1450 % 6, the result will be 4.
- if we do 1451 % 6, the result will be 5.
- if we do 1452 % 6, the result will be 0.
- if we do 1451 % 6, the result will be 1.

As you can see we are *rotating* on the six faces mapped to the values 0, 1, 2, 3, 4 and 5.

So if we do `ci = (pi + k) % 26` it means that if we use an encryption key greater than 26, we will still have a result between 0 and 25, meaning we will stay in the boundaries of our alphabet.

## Acceptance criterias

These are the acceptance criteria that your code needs to pass to be successful:

### Acceptance Criteria 1

```
$ ./caesar
put key: 1
put plaintext:  HELLO
ciphertext is: IFMMP
```

### Acceptance Criteria 1

```
$ ./caesar
put key: 13
put plaintext: hello, world
ciphertext is: uryyb, jbeyq
```

Notice how spaces and characters that are not letters are ignored.

### Acceptance Criteria 3

```
$ ./caesar
put key: 13
plaintext:  be sure to drink your Ovaltine
ciphertext: or fher gb qevax lbhe Binygvar
```

Notice how upper case characters are kept in their uppercase format. (Remember how the ASCII table works? If not you can find on this repository some examples, but remember that **char** is actually an **int** and for normal letters, you can use the ASCII table mapping to do the `ci = (pi + k) % 26` )

### Acceptance Criteria 4

```
$ ./caesar
put key: -13
ERROR: you cannot use negative key
```
