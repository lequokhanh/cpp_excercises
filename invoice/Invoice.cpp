#include "Customer.cpp"

using namespace std;

class Invoice{
private:
    int id;
    Customer customer;
    double amount;
public:
    Invoice(int id, Customer customer, double amount): id(id), customer(customer), amount(amount) {}
    int getId(){ 
        return id;
    }
    void setCustomer(Customer customer){ 
        this->customer = customer;
    }
    Customer getCustomer(){ 
        return customer;
    }
    void setAmount(double amount){ 
        this->amount = amount;
    }
    double getAmount(){ 
        return amount;
    }
    string getCustomerName(){ 
        return customer.getName();
    }
    double getAmountAfterDiscount(){ 
        return amount* double(1 - (double)customer.getDiscount() / 100);
    }
};