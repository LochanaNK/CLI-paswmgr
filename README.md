<h1 align="center">
  <br>
  <br>
  CLI-based Password Manager
  <br>
</h1>

<h4 align="center">
A lightweight, terminal-based password manager built in C, featuring XOR encryption to safely store your credentials.
</h4>

<p align="center">
  <a href="https://img.shields.io/badge/C-Program-blue?style=for-the-badge&logo=c&logoColor=white"></a>
  <a href="https://img.shields.io/badge/Windows%20Ready-success?style=for-the-badge"></a>
  <a href="https://img.shields.io/badge/XOR%20Encryption-yellow?style=for-the-badge"></a>
</p>


---

## Key Features

* 📝 **Add Credentials** – Store site, username, and password.  
* 🔍 **View Credentials** – See all saved credentials with decrypted passwords.  
* ❌ **Remove Credentials** – Delete credentials by site name.  
* 🔐 **XOR-based Encryption** – Simple and safe for learning purposes.  
* 🎛️ **Interactive CLI Menu** – Easy-to-use terminal interface.  
* 💻 **Cross-platform Friendly** – Works on Windows and Linux.  

---

## How To Use

### Requirements

* GCC compiler (or any C compiler)  
* Windows Terminal / Command Prompt or Linux Terminal  

### Compile and Run

**Using Makefile (Recommended):**

```bash
make        # builds the program
make clean  # removes exe, object files, and vault.dat
```

**Manual compilation:**

```bash
gcc main.c storage.c crypto.c -o password_manager.exe
password_manager.exe
