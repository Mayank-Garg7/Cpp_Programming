#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Structure to represent a product
struct Product {
    string name;
    double price;
    int quantity;

    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

// Function to display the product list
void displayProducts(const vector<Product>& products) {
    cout << "========================================" << endl;
    cout << setw(20) << left << "Product Name" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
    cout << "========================================" << endl;

    for (const Product& product : products) {
        cout << setw(20) << left << product.name << setw(10) << product.price << setw(10) << product.quantity << endl;
    }
    cout << "========================================" << endl;
}

// Function to calculate the total bill
double calculateTotalBill(const vector<Product>& products) {
    double total = 0.0;
    for (const Product& product : products) {
        total += product.price * product.quantity;
    }
    return total;
}

int main() {
    vector<Product> products;
    char choice;

    do {
        cout << "Billing System Menu" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Calculate Total Bill" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string name;
                double price;
                int quantity;

                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter price: ";
                cin >> price;

                cout << "Enter quantity: ";
                cin >> quantity;

                Product product(name, price, quantity);
                products.push_back(product);

                cout << "Product added successfully!" << endl;
                break;
            }

            case '2':
                displayProducts(products);
                break;

            case '3':
                cout << "Total Bill: $" << fixed << setprecision(2) << calculateTotalBill(products) << endl;
                break;

            case '4':
                cout << "Exiting the billing system." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');

    return 0;
}
