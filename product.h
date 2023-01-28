#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include <QCoreApplication>
#include <QTextStream>
#include <QIODevice>
#include <QString>
#include <QFile>

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
