import std;
using namespace std;

// User defined type
// Understant the concept of operator overloading


// Defining a user-defined type Month
// enum class Month maps the months of the year to integer values starting from 1 for January to 12 for December.
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

// convert Month to int
int to_int(Month m)
{
    return static_cast<int>(m);
}

// Override the increment operator for Month    
Month operator++(Month &m)
{
    m = (m == Month::dec)
            ? Month::jan
            : Month{to_int(m) + 1};

    return m;
}

// Override the addition operator for Month
Month operator+(Month &m, int n)
{
    int month = to_int(m);

    month = (month - 1 + n) % 12 + 1;

    return Month{month};
}

int main()
{
    // Create a month object m and initialize it to November
    Month m = Month::nov;

    ++m; // Increment the month by 1, which should wrap around to December

    std::cout << to_int(m) << '\n'; // 12

    ++m; // Increment the month by 1, which should wrap around to January
    m = m + 1; // Add 1 to the month, which should wrap around to February
    cout << to_int(m) << '\n'; // 2
}