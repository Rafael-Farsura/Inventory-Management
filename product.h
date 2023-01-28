#pragma once

#include <iostream>
#include <vector>
#include <string>

class Product
{
private:
    int cod {};
    int qtt{};
    std::string item{};
    std::string date{};
    std::string status{};
    std::string recipient{};

public:

    Product(int cod = 0, int qtt = 0, std::string item ="Null", std::string date ="dd/mm/yy", std::string status ="Null", std::string recipient="Null");

//// Get method
    int getCod();
    int getQtt();

    std::string getItem() const;
    std::string getDate();
    std::string getStatus();
    std::string getRecipient();

/// Set Method
    void setCod(int);
    void setQtt(int);

    void setItem(std::string);
    void setDate(std::string);
    void setStatus(std::string);
    void setRecipient(std::string);

};

void displayInventory(const std::vector<Product> &inventory);
void CreatingItem(std::vector<Product>&inventory);

