#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>

double ellipk(double x) {
    double m = 1 - x * x;
    double a = 1.38629436112;
    double b = 0.09666344259;
    double c = 0.03590092383;
    double d = 0.03742563713;
    double e = 0.01451196212;
    double f = 0.00277125703;
    double g = 0.00040410775;
    double h = 0.00001746728;
    double i = 0.00000018586;
    double j = 0.00000000469;
    double k = 0.00000000001;
    return a + m * (b + m * (c + m * (d + m * (e + m * (f + m * (g + m * (h + m * (i + m * (j + m * k)))))))));
}

double calculate_period(double phi0, double l, double g) {
    double T = 4 * std::sqrt(l / g) * ellipk(std::sin(phi0 / 2) ^2);
    return T;
}

std::vector<std::pair<double, std::vector<std::pair<double, double>>>> save_data(std::vector<double> l_values, std::vector<double> phi0_values, double g) {
    std::vector<std::pair<double, std::vector<std::pair<double, double>>>> data;
    for (int i = 0; i < l_values.size(); i++) {
        double l = l_values[i];
        std::vector<std::pair<double, double>> l_data;
        for (int j = 0; j < phi0_values.size(); j++) {
            double phi0 = phi0_values[j];
            double T = calculate_period(phi0, l, g);
            l_data.push_back(std::make_pair(phi0, T));
        }
        data.push_back(std::make_pair(l, l_data));
    }
    return data;
}

void plot_data(std::vector<std::pair<double, std::vector<std::pair<double, double>>>> data) {
    for (int i = 0; i < data.size(); i++) {
        double l = data[i].first;
        std::vector<std::pair<double, double>> l_data = data[i].second;
        std::vector<double> phi0_values;
        std::vector<double> T_values;
        for (int j = 0; j < l_data.size(); j++) {
            phi0_values.push_back(l_data[j].first);
            T_values.push_back(l_data[j].second);
        }
        // Plot the data using a plotting library (fix gnuplot Qt in terminal)
    }
}

void calculate_and_save_data(double a, double b, std::vector<double> l_values, double g) {
    std::vector<double> phi0_values;
    for (double phi0 = a; phi0 <= b; phi0 += (b - a) / 1000) {
        phi0_values.push_back(phi0);
    }
    std::vector<std::pair<double, std::vector<std::pair<double, double>>>> data = save_data(l_values, phi0_values, g);
    
    if (!data.empty()) {
        plot_data(data);
        
        for (int i = 0; i < data.size(); i++) {
            double l = data[i].first;
            std::vector<std::pair<double, double>> l_data = data[i].second;
            std::ofstream file(std::to_string(i+1) + ".txt");
            file << "#l = " << l << std::endl;
            for (int j = 0; j < l_data.size(); j++) {
                double phi0 = l_data[j].first;
                double T = l_data[j].second;
                file << phi0 << "\t" << T << std::endl;
            }
            file.close();
        }
    }
}

int main() {
    double a_min = -M_PI / 2;
    double a_max = M_PI / 2;
    double b_min = 0.0;
    double b_max = M_PI / 2;

    double a;
    std::cout << "Enter the lower bound for phi0 (hit Enter for " << a_min << "): ";
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        a = a_min;
    } else {
        while (true) {
            try {
                a = std::stod(input);
                if (a < a_min || a > a_max) {
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument) {
                std::cout << "Invalid value entered." << std::endl;
                std::cout << "Enter the lower bound for phi0 (" << a_min << "): ";
                std::getline(std::cin, input);
            }
        }
    }

    double b;
    std::cout << "Enter the upper bound for phi0 (hit Enter for " << b_max << "): ";
    std::getline(std::cin, input);
    if (input.empty()) {
        b = b_max;
    } else {
        while (true) {
            try {
                b = std::stod(input);
                if (b < b_min || b > b_max || a > b) {
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument) {
                std::cout << "Invalid value entered." << std::endl;
                std::cout << "Enter the upper bound for phi0 (" << b_max << "): ";
                std::getline(std::cin, input);
            }
        }
    }

    int num_l;
    std::cout << "Enter the number of l values: ";
    std::getline(std::cin, input);
    while (true) {
        try {
            num_l = std::stoi(input);
            if (num_l <= 0) {
                throw std::invalid_argument("");
            }
            break;
        } catch (std::invalid_argument) {
            std::cout << "Invalid value entered." << std::endl;
            std::cout << "Enter the number of l values: ";
            std::getline(std::cin, input);
        }
    }

    std::vector<double> l_values;
    while (l_values.size() < num_l) {
        double l;
        std::cout << "Enter l value " << l_values.size() + 1 << ": ";
        std::getline(std::cin, input);
        while (true) {
            try {
                l = std::stod(input);
                if (l <= 0) {
                    throw std::invalid_argument("");
                }
                break;
            } catch (std::invalid_argument) {
                std::cout << "Invalid value entered." << std::endl;
                std::cout << "Enter l value " << l_values.size() + 1 << ": ";
                std::getline(std::cin, input);
            }
        }
        if (std::find(l_values.begin(), l_values.end(), l) == l_values.end()) {
            l_values.push_back(l);
        } else {
            std::cout << "Ignoring repeat " << l << std::endl;
        }
        std::cout << "l values are: ";
        for (int i = 0; i < l_values.size(); i++) {
            std::cout << l_values[i] << " ";
        }
        std::cout << std::endl;
    }

    calculate_and_save_data(a, b, l_values, 9.8);

    return 0;
}
