#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

// Function to clear input buffer
void clear_input_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get valid numeric input
double get_number(const string& prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cout << "Invalid input. Please enter a number: ";
        clear_input_buffer();
    }
    return num;
}

// Division with zero-check
double division(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return a / b;
}

// Renamed to avoid conflict with std::modulus
int compute_modulus(int a, int b) {
    if (b == 0) {
        throw runtime_error("Modulus by zero is not allowed.");
    }
    return a % b;
}

// Menu display
void print_menu() {
    cout << "\n\n---------------------------------" << endl;
    cout << "Welcome to Simple Calculator" << endl;
    cout << "\nChoose one of the following options:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Power" << endl;
    cout << "7. Exit" << endl;
    cout << "Now, enter your choice (1-7): ";
}

int main() {
    int choice;
    double first, second, result;

    while (true) {
        print_menu();
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cout << "Invalid menu choice. Please enter a number between 1 and 7: ";
            clear_input_buffer();
        }

        if (choice == 7) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        first = get_number("Please enter the first number: ");
        second = get_number("Now, enter the second number: ");

        try {
            switch (choice) {
                case 1: // Add
                    result = first + second;
                    break;
                case 2: // Subtract
                    result = first - second;
                    break;
                case 3: // Multiply
                    result = first * second;
                    break;
                case 4: // Divide
                    result = division(first, second);
                    break;
                case 5: // Modulus
                    if (fmod(first, 1.0) != 0 || fmod(second, 1.0) != 0) {
                        throw runtime_error("Modulus requires integer inputs.");
                    }
                    result = compute_modulus(static_cast<int>(first), static_cast<int>(second));
                    break;
                case 6: // Power
                    result = pow(first, second);
                    break;
            }

            cout << "\nResult of operation is: " << fixed << setprecision(2) << result << endl;
        } catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            clear_input_buffer();
            continue;
        }
    }

    return 0;
}
