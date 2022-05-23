struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression(){};
};

struct Number : Expression
{
    Number(double value):value(value){};
    double evaluate() const override{return value;};
private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right){
        this->left = left;
        this->right=right;
        this->op = op;
    };
    double evaluate() const override{
        switch(this->op)
        {
        case '+':
            return this->left->evaluate()+this->right->evaluate();
            break;
        case'-':
            return this->left->evaluate()-this->right->evaluate();
            break;
        case '*':
            return this->left->evaluate()*this->right->evaluate();
            break;
        case '/':
            return this->left->evaluate()/this->right->evaluate();
            break;
        default:
            return 0;
            break;
        }
    };
    ~BinaryOperation(){
        delete left;
        delete right;
    };
private:
    Expression const* left;
    Expression const* right;
    char op;
};

bool check(Expression const* f, Expression const* i)
{
    return (bool)(((char*)(f))[0]==((char*)i)[0]);
}
