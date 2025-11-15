#include<iostream>
using namespace std;

int main() {
    // Define constant weights
    const double WM = 1.0; // math weight
    const double WP = 1.5; // physics weight
    const double WC = 2.5; // chemistry weight
    const double WE = 3.3; // english weight
    // We will change scores here (0 ~ 100)
    int math = 70;
    int physics = 80;
    int chemistry = 90;
    int english = 100;

    // Compute weighted scores

    // Display
    cout << "Math: " << math << endl;
    cout << "Physics: " << physics << endl;
    cout << "Chemistry: " << chemistry << endl;
    cout << "English: " << english << endl;
    cout << "Weighted Score: " << (math * WM + physics * WP + chemistry * WC + english * WE) / (WM+WP+WC+WE) << endl;
    return 0;
}