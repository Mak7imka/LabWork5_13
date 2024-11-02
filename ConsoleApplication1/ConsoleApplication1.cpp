#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

double calculate_y(int n, double x) {
    if (x <= 0) {
        double product = 1.0;
        for (int i = 0; i <= n - 1; ++i) {
            product *= (std::pow(i, 3) + i);
        }
        return product;
    }
    else {
        double sum = 0.0;
        for (int i = 0; i <= n - 1; ++i) {
            for (int j = 0; j <= n - 1; ++j) {
                if (i + j != 0) {  // Проверка на деление на ноль
                    sum += x / (i + j);
                }
            }
        }
        return sum;
    }
}

void calculate_and_display(int n, double a, double b, double h) {
    char saveToFile;
    std::cout << "Do you want to save the results to a file? (y - Yes, n - No): ";
    std::cin >> saveToFile;

    std::ofstream file;
    if (saveToFile == 'y' || saveToFile == 'Y') {
        file.open("results.txt");
        if (!file.is_open()) {
            std::cout << "Error opening file for writing." << std::endl;
            return;
        }
        file << std::setw(10) << "x" << std::setw(20) << "y" << std::endl;
    }

    std::cout << std::setw(10) << "x" << std::setw(20) << "y" << std::endl;

    for (double x = a; x <= b; x += h) {
        double y = calculate_y(n, x);
        std::cout << std::fixed << std::setprecision(4) << std::setw(10) << x << std::setw(20) << y << std::endl;

        if (file.is_open()) {
            file << std::fixed << std::setprecision(4) << std::setw(10) << x << std::setw(20) << y << std::endl;
        }
    }

    if (file.is_open()) {
        file.close();
        std::cout << "Results have been saved to 'results.txt'" << std::endl;
    }
}

int main() {
    int n;
    double a, b, h;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Enter the start of the interval (a): ";
    std::cin >> a;

    std::cout << "Enter the end of the interval (b): ";
    std::cin >> b;

    std::cout << "Enter the step (h): ";
    std::cin >> h;

    calculate_and_display(n, a, b, h);

    return 0;
}
