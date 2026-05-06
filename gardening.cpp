#include <iostream>
#include <cmath>
using namespace std;

double calculateM1(double n1, double p1, double k1, double n2, double p2, double k2, double n3, double p3, double k3)
{
    double M1 = (k3 - n3 + (n3 - n2 + k2 - k3) * ((p3 - n3) / (n2 - n3 + p3 - p2))) / (k3 - n3 + n1 - k1 + (n3 - n2 + k2 - k3) * ((n1 - n3 + p3 - p1) / (n2 - n3 + p3 - p2)));

    return M1;
}

double calculateM2(double p3, double n3, double M1, double n1, double p1, double n2, double p2)
{
    double M2 = (p3 - n3 - (M1 * (n1 - n3 + p3 - p1))) / (n2 - n3 + p3 - p2);
    return M2;
}

double calculateM3(double M1, double M2)
{
    double M3 = 1 - M1 - M2;
    return M3;
}

double calculateN(double M1, double M2, double M3, double n1, double n2, double n3)
{
    double N = (M1 * n1) + (M2 * n2) + (M3 * n3);
    return N;
}

double calculateP(double M1, double M2, double M3, double p1, double p2, double p3)
{
    double P = (M1 * p1) + (M2 * p2) + (M3 * p3);
    return P;
}

double calculateK(double M1, double M2, double M3, double k1, double k2, double k3)
{
    double N = (M1 * k1) + (M2 * k2) + (M3 * k3);
    return N;
}

int main()
{
    
    double na, pa, ka;
    double nb, pb, kb;
    double nc, pc, kc;
    double M1, M2, M3;
    double N, P, K;

    cout << "Enter proportion of nitrogen in ingredient 1: ";
    cin >> na;
    cout << "Enter proportion of phosphorus in ingredient 1: ";
    cin >> pa;
    cout << "Enter proportion of potassium in ingredient 1: ";
    cin >> ka;

    cout << "Enter proportion of nitrogen in ingredient 2: ";
    cin >> nb;
    cout << "Enter proportion of phosphorus in ingredient 2: ";
    cin >> pb;
    cout << "Enter proportion of potassium in ingredient 2: ";
    cin >> kb;

    cout << "Enter proportion of nitrogen in ingredient 3: ";
    cin >> nc;
    cout << "Enter proportion of phosphorus in ingredient 3: ";
    cin >> pc;
    cout << "Enter proportion of potassium in ingredient 3: ";
    cin >> kc;

    M1 = calculateM1(na, pa, ka, nb, pb, kb, nc, pc, kc);
    M2 = calculateM2(pc, nc, M1, na, pa, nb, pb);
    M3 = calculateM3(M1, M2);

    N = calculateN(M1, M2, M3, na, nb, nc);
    P = calculateP(M1, M2, M3, pa, pb, pc);
    K = calculateK(M1, M2, M3, ka, kb, kc);

    cout << "M1 is equal to: " << M1 << endl;
    cout << "M2 is equal to: " << M2 << endl;
    cout << "M3 is equal to: " << M3 << endl;

    cout << "The total proportion of nitrogen is: " << N << endl;
    cout << "The total proportion of phosphorus is: " << P << endl;
    cout << "The total proportion of potassium is: " << K << endl;
 }
