import std;
using namespace std;

struct Customer
{
    string name;
    vector<string> addresses;
    // ...
};
Customer some_fct()
{
    Customer fred{"Fred", {"17 Oak St.", "232 Rock Ave ."}};
    // ... use fred ...
    return fred; // fred is destroyed here, and its destructor is called
}

int main()
{
    print("{}\n", some_fct().name);
}