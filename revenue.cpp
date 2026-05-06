#include <iostream>
#include <cmath> 

using namespace std;


int calculateN(double b, double cp, double rp)
{
    double N = b / (rp - cp);

    return static_cast<int>(std::ceil(N));
}

int main() {
    double cp1;  
    double b1;   
    double rp1;  
      

    cout << "Enter the cost of production: ";
    cin >> cp1;

    cout << "Enter the base cost: ";
    cin >> b1;

    cout << "Enter the revenue from production: ";
    cin >> rp1;

    cout << "The number of devices needed to break even is: " << calculateN(b1, cp1, rp1) << endl;

}
