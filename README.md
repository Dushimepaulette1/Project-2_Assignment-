# C Programming Assignment: Memory, Pointers, and Structs

Hello! This is my submission for the C programming assignment. It includes three different projects that demonstrate how to use dynamic memory allocation, pointers, structs, unions, and function pointers.

**Developed by:** Dushime Paulette

**Student ID:** 22

---

## General Instructions

To test these programs, you will need a C compiler like `gcc` installed. Open your terminal, go to the folder where these files are saved, and use the commands provided under each project below.

---

## Project 1: Dynamic Student Record Engine

**File name:** `classifyPerformanceStatus.c`

### What it does:

This program acts like a teacher's digital grade book. It lets the user type in student IDs, names, and grades, and stores them in dynamically allocated memory. It uses a menu driven by an array of function pointers to manage the data.

### Features:

* **Add Students:** Lets the user input student details (safely handles names with spaces).
* **Display Students:** Prints all the saved records cleanly.
* **Sort Students:** Sorts the students in alphabetical order by their names using `strcmp`.
* **Calculate Average:** Adds up all the grades and finds the class average.
* **Find Top Student:** Finds and prints the student with the highest score.
* **Custom Analysis (Performance Classification):** Loops through the students and assigns them a letter grade (A, B, C, D, or F) based on their exact score.

### How to run it:

```bash
gcc classifyPerformanceStatus.c -o classifyPerformanceStatus
./classifyPerformanceStatus

```

---

## Project 2: Adaptive Text Intelligence Tool

**File name:** `calculateAverageWordLength.c`

### What it does:

This program takes a full paragraph of text typed by the user and analyzes the words inside it. It uses pointer traversal to jump through the text letter by letter to extract the words safely.

### Features:

* **Memory Tracking:** Prints the exact hexadecimal memory addresses where the text and the dictionary array are stored.
* **Count Words:** Tallies up the total number of words in the paragraph.
* **Longest Word:** Finds and prints the longest word the user typed.
* **Most Frequent Word:** Finds the word that was used the most times.
* **Custom Analysis (Average Word Length):** Does the math to find the average character length of all the words combined.

### How to run it:

```bash
gcc calculateAverageWordLength.c -o calculateAverageWordLength
./calculateAverageWordLength

```

---

## Project 3: Callback-Based Device Monitoring Simulator

**File name:** `executeDeviceCallback.c`

### What it does:

This program simulates a factory monitoring system. It generates 10 random sensor readings for three different devices: a thermometer, a barometer, and a battery. It uses a `union` to save memory because each device measures something different (Celsius, Pascals, or Volts).

### Features:

* **Simulates Readings:** Automatically creates 10 random sensor checks using dynamic memory allocation.
* **Standard Callbacks:** Uses function pointers to send the data to the correct monitor. It warns you if the temperature is too hot, the pressure is too high, or the battery is too low.
* **Custom Analysis (Diagnostic Maintenance):** A special callback function that runs every few cycles to check for specific dangers, like freezing conditions, pressure leaks, or battery overvoltage.

### How to run it:

```bash
gcc executeDeviceCallback.c -o executeDeviceCallback
./executeDeviceCallback

```
