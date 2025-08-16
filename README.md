# Shell Box

A cross-platform utility suite for Mac, Windows, and Linux, combining Bash/shell scripts and C programs. Shell Box provides data management, system insights, and other helpful tools for command-line users.

## Structure
- `bin/`: Compiled C binaries
- `scripts/`: Bash/shell scripts
- `src/`: C source code

## Getting Started
- Use the Makefile to build C programs in `src/`.
- Run scripts from `scripts/` for quick utilities.

### Setup PATH (Optional)
To run executables directly without `make`:

**Windows:**
```cmd
setup.bat
```

**WSL/Linux:**
```bash
chmod +x setup.sh
./setup.sh
```

## Extending
Add new scripts or C programs to the respective folders. Update the Makefile as needed.
