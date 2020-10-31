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

wherein % 26 here means "remainder when dividing by 26".
