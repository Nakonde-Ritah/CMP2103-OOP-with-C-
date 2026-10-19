import std;
using namespace std;

int main()
{
    int x = 17;
    int *pi = &x; // pointer to int
    double e = 2.71828;
    double *pd = &e; // pointer to double

    cout << "pi == " << pi << "; contents of pi == " << *pi << "\n";
    cout << "pd == " << pd << "; contents of pd == " << *pd << "\n";
}
