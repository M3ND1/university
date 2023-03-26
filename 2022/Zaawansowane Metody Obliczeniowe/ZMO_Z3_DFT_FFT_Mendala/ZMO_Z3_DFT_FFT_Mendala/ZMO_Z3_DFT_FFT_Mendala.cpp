#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#define _USE_MATH_DEFINES
#include <math.h>

std::vector<std::complex<double>> DFT(const std::vector<double> &input_signal) {
    int N = input_signal.size();
    double real, imaginary;
    std::vector<std::complex<double>> x(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            real = cos(((2 * M_PI) / N) * i * j);
            imaginary = sin(((2 * M_PI) / N) * i * j);
            std::complex<double> temp(real, -imaginary);
            x[i] += input_signal[j] * temp;
        }
    }
    return x;
}
std::vector<std::complex<double>> IDFT(const std::vector<std::complex<double>> &dft) {
    int N = dft.size();
    double real, imaginary;
    std::vector<std::complex<double>> x(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            real = cos(((2 * M_PI) / N) * i * j);
            imaginary = sin(((2 * M_PI) / N) * i * j);
            std::complex<double> temp(real, imaginary);
            x[i] += dft[j] * temp;
        }
        x[i] /= N;
    }
    return x;
}
std::vector<std::complex<double>> FFT(const std::vector<double> &input_signal) {
    int N = input_signal.size();
    double real, imaginary;
    std::vector<std::complex<double>> x(N);
    if (N == 1) {
        x[0] = input_signal[0];
        return x;
    }
    std::vector<double> even(N / 2);
    std::vector<double> odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = input_signal[2 * i];
        odd[i] = input_signal[2 * i + 1];
    }
    std::vector<std::complex<double>> X_even = FFT(even);
    std::vector<std::complex<double>> X_odd = FFT(odd);
    for (int i = 0; i < N / 2; i++) {
        real = cos(((2 * M_PI) / N) * i);
        imaginary = sin(((2 * M_PI) / N) * i);
        std::complex<double> temp(real, -imaginary);
        x[i] = X_even[i] + (temp * X_odd[i]);
        x[i + N / 2] = X_even[i] - (temp * X_odd[i]);
    }
    return x;
}
std::vector<std::complex<double>> IFFT(const std::vector<std::complex<double>> &fft) {
    int N = fft.size();
    double real, imaginary;
    std::vector<std::complex<double>> x(N);
    if (N == 1) {
        x[0] = fft[0];
        return x;
    }

    std::vector<std::complex<double>> even(N / 2);
    std::vector<std::complex<double>> odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = fft[2 * i];
        odd[i] = fft[2 * i + 1];
    }
    std::vector<std::complex<double>> X_even = IFFT(even);
    std::vector<std::complex<double>> X_odd = IFFT(odd);
    for (int i = 0; i < N / 2; i++) {
        real = cos(((2 * M_PI) / N) * i);
        imaginary = sin(((2 * M_PI) / N) * i);
        std::complex<double> temp(real, imaginary);
        x[i] = (std::complex<double>(1.0/2.0) * (X_even[i] + (temp * X_odd[i])));
        x[i + N / 2] = (std::complex<double>(1.0 / 2.0) * (X_even[i] - (temp * X_odd[i])));
    }
    return x;
}

template <typename T>
void print_vector(std::vector<T>& v) {
    for (auto& i : v) {
        std::cout << i << "\n";
    }
    std::cout << "\n";
}
int main() {
    int one_two, N;
    std::cin >> one_two >> N;
    std::vector<double> signal(N);
    for (int i = 0; i < N; i++) {
        std::cin >> signal[i];
    }
    std::vector<std::complex<double>> dft = DFT(signal);
    std::vector<std::complex<double>> idft = IDFT(dft);
    std::vector<std::complex<double>> fft = FFT(signal);
    std::vector<std::complex<double>> ifft = IFFT(fft);
    std::vector<double> magnitudes;
    double m_max = 0.0;
    for (int i = 0; i < dft.size(); i++) {
        std::cout << abs(dft[i]) << "\n";
    }
    for (auto& i : fft) {
        double magnitude = std::sqrt(i.real() * i.real() + i.imag() * i.imag());
        if (magnitude >= m_max) {
            m_max = magnitude;
        }
        magnitudes.push_back(magnitude);
    }
    for (auto& i : signal) {
        std::cout << i << "\n";
    }
    print_vector(dft);
    print_vector(idft);
    print_vector(fft);
    print_vector(ifft);
    for (auto& i : magnitudes) {
        std::cout << i << "\n";
    }
    for (int i = 0; i < magnitudes.size(); i++) {
        if (abs(magnitudes[i]) > 0.0 && abs(magnitudes[i]) <= 1.5) {
            magnitudes[i] = 0.0;
            std::cout << abs(magnitudes[i]) << "\n";
        }
        else {
            std::cout << abs(magnitudes[i]) << "\n";
        }
    }

}