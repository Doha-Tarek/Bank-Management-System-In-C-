#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
    public:
        Account();
        virtual ~Account();
        void create_account();
        void show_account();
        void deposit(int deposit_amount);
        void withdraw(long withdraw_amount);
        int return_account_num();

    protected:

    private:
        int account_num;
        char name[50];
        long balance;
};

#endif // ACCOUNT_H
