
class Account {
public:
    void calculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; }

    static void rate(double);
    //静态成员作为默认参数
    void staticParam(int = period);

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate;
    static constexpr int period = 30;
    double daily_tbl[period];
};