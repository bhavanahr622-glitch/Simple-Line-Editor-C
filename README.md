# Build a Simple Line Editor in C

## TEAM MEMBERS
01. Amruta Sullibhavi
02. Bhavana H R
03. Bhoomika J E

## Project Description

This project is a simple command-line line editor developed in C.

It allows users to create, view, modify, save, and load a text document
through a menu-based interface.

## Data Structure Used

The project makes use of concept of dynamic array of strings.

```c
typedef struct
{
    char **lines;
    int count;
    int capacity;
} Document;
