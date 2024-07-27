## Overview

The CSV Quote Processor is a C++ application designed to parse and process historical financial data from CSV files. The application handles quotes, prices, and other financial metrics, integrating with custom strategies and venues to validate and manage financial orders.

## Features

- **CSV Parsing:** Handles quoted fields and commas within fields.
- **Price Correction:** Removes commas and converts price strings to numeric values.
- **Order Processing:** Integrates with custom order strategies and venues.
- **Reverse Processing:** Processes data from bottom to top, as the most recent entries are at the top.

## Dependencies

- **C++ Standard Library:** The project uses standard C++ libraries such as `<iostream>`, `<fstream>`, `<sstream>`, and `<vector>`.
- **Custom Libraries:** Includes custom header files such as `OrderStrategy033.h`, `QuoteEvent.h`, `OrderVectors.h`, `SimplePrice.h`, and `Venue.h`.
- **CSV Parsing Library:** Uses a custom or third-party CSV parsing library. Ensure you have the necessary library files or include paths.

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/csv-quote-processor.git
   cd csv-quote-processor
   ```

2. **Build the Project:**

   Ensure you have a C++ compiler installed (e.g., `g++`).

   ```bash
   g++ -o csv_quote_processor main.cpp
   ```

   Replace `main.cpp` with the name of your source file if it's different.

3. **Include Dependencies:**

   Ensure the custom header files and any CSV parsing library files are in the correct paths. Adjust the `#include` directives in your source files if necessary.

## Usage

1. **Prepare a CSV File:**

   Ensure your CSV file is formatted correctly with columns for date, price, open, high, low, volume, and change percent. Place this file in the project directory.

2. **Run the Application:**

   ```bash
   ./csv_quote_processor
   ```

   By default, the application will process the file named `XAU_USD_Historical_Data.csv`. To use a different file, modify the `filePath` variable in the `main` function of `main.cpp`.

3. **View Output:**

   The application will print the processed data to the console, including any debug information and validation results.

## Customization

- **Adjust File Path:** Modify the `filePath` variable in the `main` function to point to your CSV file.
- **CSV Parsing Logic:** Update the `parseCSVLine` function to handle different CSV formats if needed.
- **Order Strategy and Venue:** Customize `OrderStrategy033` and `Venue` according to your specific financial processing needs.

## Troubleshooting

- **File Not Found:** Ensure the CSV file path is correct and the file is in the specified location.
- **Parsing Errors:** Check the format of your CSV file and ensure it matches the expected structure.

## Contributing

Feel free to open issues or submit pull requests if you have suggestions or improvements for the project.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For questions or feedback, contact [ameymanuel@gmail.com].
