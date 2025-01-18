# Calendar Application Documentation

This documentation provides a comprehensive overview of a simple calendar application implemented in C++. The application allows users to view the entire year's calendar or a specific month's calendar based on user input. 

## Overview

The program prompts the user to choose between viewing a complete year's calendar or just a specific month's calendar. It then calculates the days of each month, accounts for leap years, and displays the calendar in a formatted manner.

## Code Structure

The code is organized into several key components, including function definitions and global variables. Below, we will detail the methods, variables, and overall functionality of the code.

### Global Variables

- `vector<string> month`: A vector containing the names of the months from January to December.
- `vector<string> week`: A vector containing the abbreviated names of the weekdays from Monday to Sunday.

### Functions

1. **`void clearOutputConsole()`**
   - **Description**: Clears the console output. It uses the `system` command to execute either `cls` (for Windows) or `clear` (for Unix/Linux) based on the operating system.
   - **Usage**: Called at the beginning of the `main` function and before displaying each month's calendar.

2. **`void calander(int year, int month_num)`**
   - **Description**: Calculates the total number of days that have passed since January 1, 1945, to determine the starting day of the specified month. It also checks for leap years to adjust the day count for February.
   - **Parameters**:
     - `int year`: The year for which the calendar is being calculated.
     - `int month_num`: The month number (1 for January, 2 for February, ..., 12 for December).
   - **Functionality**:
     - Initializes a vector for the number of days in each month.
     - Calculates the total number of days from 1945 to the previous year.
     - Adjusts February's days for leap years.
     - Calls `showcalander` to display the formatted calendar.

3. **`void showcalander(int year, int month_num, int total_days, vector<int> &days)`**
   - **Description**: Displays the calendar for the specified month and year in a structured format.
   - **Parameters**:
     - `int year`: The year for the calendar display.
     - `int month_num`: The month number to display.
     - `int total_days`: The total number of days calculated to determine the starting day of the month.
     - `vector<int> &days`: A reference to the vector containing the number of days in each month.
   - **Functionality**:
     - Clears the console before displaying the calendar.
     - Prints the month and year at the top.
     - Displays the weekday names in a formatted manner.
     - Prints the days of the month, adjusting for the starting position based on the total days calculated.
     - Correctly formats the output to ensure each day is represented with proper spacing.

### `main` Function

- **Description**: The entry point of the program. It handles user input and orchestrates the flow of the application.
- **Functionality**:
  - Calls `clearOutputConsole` to clean the console.
  - Prompts the user for an option: either to view the whole year or a specific month.
  - Validates the user's choice and prompts for further input (the year and, if applicable, the month).
  - Calls `calander` to perform the necessary calculations and display the calendar based on user input.

### Error Handling

The program validates user input for the choice of viewing a calendar and the year. It checks if the year is less than 1945 and prompts the user to enter a valid year.

### Example Usage

When the program is executed, the user will see output similar to:

```
Enter Choice : 
1. View Whole Year Calendar 
2. View Month Calendar 
```

Upon entering `1` or `2`, the user will follow prompts to enter the year and, if applicable, the month. The program will then display the requested calendar.

### Conclusion

This calendar application serves as a basic example of how to calculate and display calendars in C++. It demonstrates the handling of user input, the use of vectors for data storage, and formatted console output. The inclusion of leap year logic and error handling enhances the application's robustness.