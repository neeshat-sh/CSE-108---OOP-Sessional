#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Product
{
private:
    double price;
    char *name;

public:
    Product()
    {
        price = 0;
        name = nullptr;
    }
    Product(const char *name, double price)
    {
        this->price = price;
        this->name = (char *)malloc(strlen(name) + 1);
        if (this->name != nullptr)
        {
            strcpy(this->name, name);
        }
    }
    ~Product()
    {
        if (name != nullptr)
        {
            free(name);
        }
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setName(const char *name)
    {
        if (this->name != nullptr)
        {
            free(this->name);
        }
        this->name = (char *)malloc(strlen(name) + 1);
        strcpy(this->name, name);
    }
    double getPrice()
    {
        return price;
    }
    const char *getName()
    {
        return name ? name : "";
    }
    void display()
    {
        cout << "Product: " << name << " - " << " Price: $" << price << endl;
    }
};
class OnlineStore
{
private:
    int productCount;
    Product products[100];

public:
    OnlineStore()
    {
        productCount = 0;
    }
    ~OnlineStore()
    {
        
    }
    void addProduct(Product &p)
    {
        if (productCount < 100)
        {
            products[productCount].setPrice(p.getPrice());
            products[productCount].setName(p.getName());
            productCount += 1;
        }
        else
        {
            cout << "No more Products can be added\n";
        }
    }
    void displayProducts()
    {
        cout << "Available Products in the Store: \n";
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
        }
        cout << endl;
    }
};
class ShoppingCart
{
private:
    int productCount;
    Product products[100];
    double totalCost;

public:
    ShoppingCart()
    {
        productCount = 0;
        totalCost = 0;
    }
    ~ShoppingCart()
    {
        
    }
    void addProduct(Product &p)
    {
        if (productCount < 100)
        {
            products[productCount].setPrice(p.getPrice());
            products[productCount].setName(p.getName());
            totalCost += products[productCount].getPrice();
            productCount += 1;
        }
        else
        {
            cout << "No more Products can be added\n";
        }
    }
    double getCost()
    {
        return totalCost;
    }
    void displayCart()
    {
        cout << "Shopping Cart: \n";
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
        }
        cout << "Total Cost: $" << getCost() << endl << endl;
    }
    void removeProduct(const char *name)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (strcmp(products[i].getName(), name) == 0)
            {
                totalCost -= products[i].getPrice();

                for (int j = i; j < (productCount - 1); j++)
                {
                    products[j].setPrice(products[j + 1].getPrice());
                    products[j].setName(products[j + 1].getName());
                }
                productCount -= 1;
                return;
            }
        }
    }
};
int main()
{
    OnlineStore store;

    // Add products to the online store
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 699.99);
    Product product3("Headphones", 99.99);

    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);

    // Display available products
    store.displayProducts();

    // Create a new shopping cart
    ShoppingCart cart;

    // Add products to the shopping cart
    cart.addProduct(product1);
    cart.addProduct(product2);

    // Display the shopping cart
    cart.displayCart();

    // Add another product to the cart
    cart.addProduct(product3);

    // Display the updated shopping cart
    cart.displayCart();

    // Remove a product from the cart
    cart.removeProduct("Laptop");

    // Display the updated shopping cart
    cart.displayCart();

    return 0;
}