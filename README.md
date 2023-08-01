# Data_Encryption_and_Decryption
To use this program, the user can choose between encryption and decryption operations, provide the message to be encrypted or decrypted, and the encryption/decryption key (a number between 0 and 9).

## Overview

•	The program allows the user to encrypt and decrypt messages using the Caesar cipher technique.
•	The Caesar cipher is a simple substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet.
•	The user can choose between encryption and decryption operations.
•	For encryption, the user provides the message to be encrypted and the encryption key (a number between 0 and 9).
•	For decryption, the user provides the decryption key, which must be the same as the key used for encryption.

## Functions:

1. ### “encrypt” Function:
o	Accepts a message and an encryption key as input.
o	Encrypts the message using the Caesar cipher technique.
o	Shifts each character in the message based on the key value.

2. ### “decrypt” Function:
o	Used to decrypt a previously encrypted message.
o	Calls the `encrypt` function with a negative key to perform decryption.

3. ### “main” Function:
o	The entry point of the program.
o	Interacts with the user to perform encryption or decryption based on their input.
o	Handles input and output file operations.



## Encryption Process:

1. ### User Interaction:
o	The user is prompted to choose between encryption and decryption (E/D).

2. ### Encryption:
o	If encryption is chosen:
o	The user enters the message to be encrypted.
o	The user provides the encryption key (a number between 0 and 9).
o	The program encrypts the message using the `encrypt` function.
o	The encrypted message is saved in the "encrypted_message.txt" file.
o	The encryption key is saved in the "encryption_key.txt" file.

## Decryption Process:

1. ### User Interaction:
o	If decryption is chosen:
o	The user is asked to provide the decryption key (the same key used for encryption).

2. ### Decryption:
o	The program reads the original encryption key from the "encryption_key.txt" file.
o	If the user-provided key matches the original key, decryption proceeds.
o	The program reads the encrypted message from the "encrypted_message.txt" file.
o	The program decrypts the message using the `decrypt` function.
o	The decrypted message is saved in the "decrypted_message.txt" file.


## Error Handling:

1. ### Invalid Input:
o	The program checks for invalid user inputs, such as choosing an unsupported action or providing an invalid encryption/decryption key.
o	If an invalid input is detected, the program displays an appropriate error message.
2. ### Data Integrity:
o	To ensure data integrity during decryption, the program checks whether the user-provided decryption key matches the original encryption key.
o	If they do not match, the program displays an error message and aborts the decryption process.


## Conclusion:
o	The C program provides a basic implementation of data encryption and decryption using the Caesar cipher technique.
o	It allows users to encrypt and decrypt messages, stores the encrypted content and encryption key in separate files, and ensures data integrity during decryption.
o	With possible future enhancements and improvements, this program can serve as a foundation for building more secure and user-friendly encryption/decryption applications.
