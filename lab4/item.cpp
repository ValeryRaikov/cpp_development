#include <iostream>

using namespace std;

class Item {
private:
    string title;
    double price;
    int mediaNumber;
    string mediaFormat;
    string purchaseDate;
public:
    Item() {}
    Item(string title, double price, int mediaNumber, string mediaFormat, string purchaseDate) {
        this->title = title;
        this->price = price;
        this->mediaNumber = mediaNumber;
        this->mediaFormat = mediaFormat;
        this->purchaseDate = purchaseDate;
    }

    static Item createItem() {
        string title, mediaFormat, purchaseDate;
        double price;
        int mediaNumber;

        cout << "Create your own item:\n";

        cout << "Enter title: ";
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter media number: ";
        cin >> mediaNumber;

        cin.ignore();
        cout << "Enter media format: ";
        getline(cin, mediaFormat);

        cout << "Enter purchase date: ";
        getline(cin, purchaseDate);

        if (!title.empty() && price > 0 && mediaNumber > 0 && !mediaFormat.empty() && !purchaseDate.empty()) {
            return Item(title, price, mediaNumber, mediaFormat, purchaseDate);
        } else {
            cout << "Invalid input provided. Returning default item.\n";
            return Item();
        }
    }

    string getTitle() {
        return title;
    }

    void setTitle(string value) {
        if (value.length() < 2 || value.length() > 100) {
            cout << "Invalid input!\n";
            return;
        }

        title = value;
    }

    double getPrice() {
        return price;
    }

    void setPrice(double value) {
        if (value < 0 || value > 10000) {
            cout << "Invalid input!\n";
            return;
        }

        price = value;
    }

    int getMediaNumber() {
        return mediaNumber;
    }

    void setMediaNumber(int value) {
        mediaNumber = value;
    }

    string getMediaFormat() {
        return mediaFormat;
    }

    void setMediaFormat(string value) {
        mediaFormat = value;
    }

    string getPurchaseDate() {
        return purchaseDate;
    }

    void setPurchaseDate(string value) {
        purchaseDate = value;
    }

    void getItemInformation() {
        cout << "Item:\n";
        cout << getMediaFormat() << ", with title: " << getTitle() << ", bought for: " << getPrice() << " on date: " << getPurchaseDate() << endl;
    }
};