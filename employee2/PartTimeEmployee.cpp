#include "Employee.cpp"

class PartTimeEmployee: public Employee {
private:
    int workingHours;
public:
    PartTimeEmployee(string name, int paymentPerHour, int workingHours) : Employee(name, paymentPerHour), workingHours(workingHours) {}
    int calculateSalary(){
        return workingHours * Employee::getPaymentPerHour();
    }
};