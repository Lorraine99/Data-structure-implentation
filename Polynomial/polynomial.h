struct node {
    double coeff;
    node *next;
};

class Polynomial {
    private:
    node *front, *back;

    public:
    Polynomial();
    ~Polynomial();

    void init(const int size);

    //define first polynomial
    Polynomial& coeff(const double currPoly[]);

    //compare currPoly and expPoly
    bool compare(Polynomial& expPoly);

    //evaluate a polynomial
    bool eval(const double x, const double expValue);

    //add two polynomials
    Polynomial add(Polynomial& secPoly);

    //multiply two polynomials
    Polynomial mult(Polynomial& secPoly);
    
    //get the size of a linked list
    int getSize();

    //insert a linked list
    void insert(double x);
};