#include<iostream>
#include<string>

class Employee{
private:
    std::string name;
    int number;
    std::string date;
public:
    class InvalidEmployeeNumber
    {
    private:
        int value;
    public:
        InvalidEmployeeNumber(int val)
        { value = val; }
        int getValue() const
        { return value; }
    };

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {

        Employee::name = name;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        std::cout<<"try setting number as: "<< number<<std::endl;
        if (number >= 0&&number<=9999)
            Employee::number = number;
        else
            throw InvalidEmployeeNumber(number);
    }

    const std::string &getDate() const {
        return date;
    }

    void setDate(const std::string &date) {
        Employee::date = date;
    }

    Employee(std::string s, int x, std::string s1) {

        if(x<0||x>9990){
            throw InvalidEmployeeNumber(x);
        }
        else {
            name = s;
            number = x;
            date = s1;
        }
    }

};

class ProductionWorker: public Employee{
private:
    int shift;
    double payRate;

public:
    ProductionWorker(int c, double m): Employee("Bob",1000,"10/23 2000")
                                 {
        bool build =true;
        if(c!=1&&c!=2){
            build = false;
            throw InvalidShift(c);
        }
        if(payRate<0){
            build = false;
            throw InvalidPayRate(payRate);
        }
        if(build ==true){
            shift= c;
            payRate = m;
        }

        std::cout<<"ProductionWorker constructed"<<std::endl;
    }

    class InvalidShift
    {
    private:
        int value;
    public:
        InvalidShift(int val)
        { value = val; }
        int getValue() const
        { return value; }
    };

    class InvalidPayRate
    {
    private:
        int value;
    public:
        InvalidPayRate(int val)
        { value = val; }
        int getValue() const
        { return value; }
    };

    int getShift() const {
        return shift;
    }

    void setShift(int shift) {
        std::cout<<"try setting shift as: "<< shift<<std::endl;
        if(shift!=1&&shift!=2){
            throw InvalidShift(shift);
        }
        else {
            ProductionWorker::shift = shift;
        }
    }

    double getPayRate() const {
        return payRate;
    }

    void setPayRate(double payRate) {
        std::cout<<"try setting pay rate as: "<< payRate<<std::endl;
        if(payRate<0){
            throw InvalidPayRate(payRate);
        }
    else {
            ProductionWorker::payRate = payRate;
        }
    }

};

int main(){

    try {
        ProductionWorker p(1, 2.3); //it work for constructor as well
        p.setNumber(99999);
        p.setDate("11/12 1997");
    }
    catch (Employee::InvalidEmployeeNumber){
        std::cout<<"Invalid Employee Number"<<std::endl;
    }
    catch (ProductionWorker::InvalidShift){
        std::cout<<"Invalid Shift"<<std::endl;
    }
    catch(ProductionWorker::InvalidPayRate){
        std::cout<<"Invalid Pay Rate"<<std::endl;
    }

}
