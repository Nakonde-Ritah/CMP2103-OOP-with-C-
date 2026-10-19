struct Link
{

    Link(const string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}
    string value;
    Link *prev;
    Link *succ;
};

int main()
{
    Link* norse_gods = new Link{"Thor", nullptr, nullptr};
    norse_gods = new Link{"Odin", nullptr, norse_gods};
    norse_gods->succ->prev = norse_gods;
    norse_gods = new Link{"Freja", nullptr, norse_gods};
    norse_gods->succ->prev = norse_gods;
}