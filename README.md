# Car Inventory Management System

This project is a simple Car Inventory Management System implemented in C++. It allows you to manage a list of cars, mark them as sold, and calculate total prices based on sales.

## Features

- **Car Class**: Represents a car with properties like model, year, price, and sold status.
- **File I/O**: Reads car details from a file (`cars.txt`) or creates default cars if the file is missing.
- **Sell Functionality**: Marks a car as sold and calculates total prices of sold cars.
- **Output**: Displays car details including model, year, price, and sold status.

## Files

- `main.cpp`: Contains the main logic for managing cars.
- `cars.txt`: Stores car details in a CSV format (`model,year,price,sold`).

## Usage

1. **Compile**: Compile the program using a C++ compiler (e.g., g++).
   ```bash
   g++ main.cpp -o car_inventory
