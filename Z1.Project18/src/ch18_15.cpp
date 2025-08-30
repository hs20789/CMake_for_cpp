#include <exception>
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <utility>

class BankAccount final
{
  public:
    BankAccount(int accounNumber, std::string name)
        : m_accountNumber{accounNumber}, m_clientName{std::move(name)}
    {}
    void setAccountNumber(int accountNumber)
    {
        m_accountNumber = accountNumber;
    }
    int getAccountNumber() const { return m_accountNumber; }

    void setClientName(std::string name) { m_clientName = std::move(name); }
    std::string const &getClientName() const { return m_clientName; }

  private:
    int m_accountNumber{};
    std::string m_clientName;
};

class BankDB final
{
  public:
    bool addAccount(BankAccount const &account);
    void deleteAccount(int accountNumber);
    BankAccount &findAccount(int accountNumber);
    BankAccount &findAccount(std::string_view name);

    void mergeDatabase(BankDB &db);

  private:
    std::map<int, BankAccount> m_accounts;
};

int main()
{
    BankDB db;
    db.addAccount(BankAccount{100, "Nicholas Solter"});
    db.addAccount(BankAccount{200, "Scott Kleper"});
    db.addAccount(BankAccount{1, "HeonSu Jeong"});

    try {
        auto &account{db.findAccount(100)};
        std::cout << "Found Account 100 \n";
        account.setClientName("Nicholas A Solter");

        auto &vip(db.findAccount(1));
        std::cout << "Fount VIP, " << vip.getClientName() << std::endl;
        auto &account2{db.findAccount(1000)};
        std::cout << "Found Account 1000\n";
    } catch (std::out_of_range const &e) {
        std::cout << "Unable to find account: " << e.what() << std::endl;
    }
}

bool BankDB::addAccount(BankAccount const &account)
{
    auto [it, success]{m_accounts.emplace(account.getAccountNumber(), account)};
    return success;
}

void BankDB::deleteAccount(int accountNubmer)
{
    m_accounts.erase(accountNubmer);
}

BankAccount &BankDB::findAccount(int accountNumber)
{
    auto it{m_accounts.find(accountNumber)};
    if (it == std::cend(m_accounts)) {
        throw std::out_of_range{"No account with that number."};
    }
    return it->second;
}

BankAccount &BankDB::findAccount(std::string_view name)
{
    for (auto &[accountNumber, account] : m_accounts) {
        if (account.getClientName() == name) {
            return account;
        }
    }
    throw std::out_of_range{"No account with that name."};
}

void BankDB::mergeDatabase(BankDB &db)
{
    m_accounts.merge(db.m_accounts);

    db.m_accounts.clear();
}