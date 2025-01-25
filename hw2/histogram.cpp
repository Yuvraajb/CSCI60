// Implementation starter file for CSCI 60 Homework 2; due Thursday 01/23/25
// Comment functions below; list any collaborators and write your name here

#include "histogram.h"

/* TODO: implement the functions declared in histogram.h here */
Histogram::Histogram() {
    for (size_t i = 0; i <= MAX; ++i) {
        counts[i] = 0;
    }
}

// Constructor to read histogram data from a file
Histogram::Histogram(string filename) {
    for (size_t i = 0; i <= MAX; ++i) {
        counts[i] = 0;
    }

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return; 
    }

    int value;
    while (file >> value) {
        if (value >= 0 && value <= MAX) {
            counts[value]++;
        }
    }

    file.close();
}

// Return total counts across all values
size_t Histogram::size() const {
    size_t total = 0;
    for (size_t i = 0; i <= MAX; ++i) {
        total += counts[i];
    }
    return total;
}

// Return the smallest value with a positive count
size_t Histogram::min() const {
    for (size_t i = 0; i <= MAX; ++i) {
        if (counts[i] > 0) {
            return i;
        }
    }
    return 0; 
}

// Return the largest value with a positive count
size_t Histogram::max() const {
    for (size_t i = MAX; i >= 0; --i) {
        if (counts[i] > 0) {
            return i;
        }
    }
    return 0; 
}

// Return the mode (value with the highest count)
size_t Histogram::mode() const {
    size_t maxCount = 0;
    size_t modeValue = 0;

    for (size_t i = 0; i <= MAX; ++i) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            modeValue = i;
        }
    }

    return modeValue;
}

// Return the median (average of middle value(s))
size_t Histogram::median() const {
    size_t total = size();
    size_t cumulative = 0;
    size_t mid1 = 0, mid2 = 0;

    for (size_t i = 0; i <= MAX; ++i) {
        cumulative += counts[i];
        if (cumulative >= (total + 1) / 2 && mid1 == 0) {
            mid1 = i;
        }
        if (cumulative >= (total + 2) / 2) {
            mid2 = i;
            break;
        }
    }

    return (mid1 + mid2) / 2;
}

// Return the arithmetic mean
double Histogram::mean() const {
    size_t total = size();
    if (total == 0) {
        return 0.0; 
    }

    double sum = 0.0;
    for (size_t i = 0; i <= MAX; ++i) {
        sum += i * counts[i];
    }

    return sum / total;
}

// Return the variance
double Histogram::variance() const {
    double avg = mean();
    size_t total = size();
    if (total == 0) {
        return 0.0; 
    }

    double sumSquaredDiff = 0.0;
    for (size_t i = 0; i <= MAX; ++i) {
        sumSquaredDiff += counts[i] * (i - avg) * (i - avg);
    }

    return sumSquaredDiff / total;
}

// Add another histogram's counts to this one
void Histogram::operator +=(const Histogram& rhs) {
    for (size_t i = 0; i <= MAX; ++i) {
        counts[i] += rhs.counts[i];
    }
}

// Return the count of a specific value
size_t Histogram::operator [](size_t val) const {
    if (val <= MAX) {
        return counts[val];
    }
    return 0; 
}

// Display histogram contents to an output stream
ostream& operator <<(ostream& out, const Histogram& h) {
    for (size_t i = 0; i <= Histogram::MAX; ++i) {
        if (h[i] > 0) {
            out << i << ": " << h[i] << endl;
        }
    }
    return out;
}