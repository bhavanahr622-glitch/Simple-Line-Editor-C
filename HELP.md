# HELP - Simple Line Editor

## Description

This is a simple command-line line editor developed in C.
It allows the user to insert, delete, display, save, and load
lines of a text document.

## Menu Options

### 1. Insert

Adds a new line at the specified line number.

The existing lines are shifted down.

Example:

    Enter choice: 1
    Enter line number: 2
    Enter text: C Programming

If the document contains:

    1. Hello
    2. World

After insertion:

    1. Hello
    2. C Programming
    3. World


### 2. Delete

Deletes the line at the specified line number.

The lines below it are shifted up.

Example:

    Enter choice: 2
    Enter line number: 2

If the document contains:

    1. Hello
    2. C Programming
    3. World

After deletion:

    1. Hello
    2. World


### 3. Display

Displays all lines currently stored in the document along
with their line numbers.

Example:

    Enter choice: 3

Output:

    1. Hello
    2. World


### 4. Save

Saves the current document into a text file.

Example:

    Enter choice: 4
    Enter filename: document.txt

The current lines are written to `document.txt`.


### 5. Load

Loads the contents of a previously saved text file into
the editor.

Example:

    Enter choice: 5
    Enter filename: document.txt

The contents of `document.txt` are loaded into the editor.


### 6. Exit

Exits the line editor and releases the allocated memory.

Example:

    Enter choice: 6

Output:

    Exiting...


## Invalid Input

The editor checks for invalid line numbers.

Example:

    Enter choice: 2
    Enter line number: 10

Output:

    Invalid line number.

If there are no lines in the document and a delete operation
is attempted, the editor displays:

    Document is empty.


## Data Structure

The editor uses a dynamic array of strings.

Each line is stored separately in dynamically allocated memory.
The dynamic array allows the document to grow when more lines
are inserted.

## Features Implemented

- Insert a line
- Delete a line
- Display the document
- Save the document to a file
- Load the document from a file
- Invalid line number checking
- Dynamic memory allocation