import std;
using namespace std;

void sizes(char ch, int i, int *p)
{
    cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
    cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
    cout << "the size of int * is " << sizeof(int *) << ' ' << sizeof(p) << '\n';
    vector<int> v(1000); // vector with 1000 elements of type int
    cout << "the size of vector<int>(1000) is " << sizeof(v) << '\n';
}

int main()
{
    sizes('a', 1, nullptr); // nullpointer is a pointer that points to nothing. It is used to indicate that a pointer does not point to any valid memory location.
}

// TRY THIS
// Execute the example above and see what you get. Then extend the example to determine
// the size of bool, double, and some other type.
