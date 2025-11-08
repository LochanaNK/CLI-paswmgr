🛡️ CLI Password Manager

Welcome to my CLI Password Manager! 🎉

A simple, lightweight, terminal-based password manager built in C, using XOR encryption to keep your credentials safe. Perfect for learning C, file handling, and basic encryption — and yes, it actually works! 😎

Features:

💠Add credentials (site, username, password)

💠View all stored credentials with decrypted passwords

💠Remove credentials by site

💠XOR-based encryption (safe, fun, and easy to understand)

💠Simple, interactive menu in the terminal

💠Works on Windows (and easily on Linux!)


Getting Started:

Requirements:

GCC compiler (or any C compiler)

Windows Terminal / Command Prompt or Linux Terminal


Compile and Run:

Option 1: Using Makefile (Recommended)


make        # builds the program
make clean  # removes exe, object files, and vault.dat

Option 2: Compile manually

gcc main.c storage.c crypto.c -o password_manager.exe
password_manager.exe

Using the Program:

💠Add Credential: Enter site, username, and password.

💠View Credentials: See all stored credentials decrypted safely.

💠Remove Credential: Delete a credential by specifying the site.

💠Exit: Close the program.

💠Pro tip: Passwords are XOR-encrypted in vault.dat, so they’re not stored in plain text. 🔐
