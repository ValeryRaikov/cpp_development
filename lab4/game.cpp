#include <iostream>

#include "item.cpp"
#include "media_types.cpp"

using namespace std;

class Game: public Item {
private:
    int gameDifficulty;
    mediaTypes mediaType;
public:
    Game(string title, double price, int mediaNumber, string mediaFormat, string purchaseDate, int gameDifficulty, mediaTypes mediaType)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate) {
            this->gameDifficulty = gameDifficulty;
            this->mediaType = mediaType;
        }

    int getGameDifficulty() { 
        return gameDifficulty; 
    }

    void setGameDifficulty(int value) {
        if (value < 0 || value > 10) {
            cout << "Invalid input!\n";
            return;
        }

        gameDifficulty = value;
    }

    mediaTypes getMediaType() {
        return mediaType;
    }

    void getItemInformation() {
        cout << "Game:\n";

        cout << "Media Type: ";
        switch (mediaType) {
            case DVD:
                cout << "DVD";
                break;
            case VIDEO:
                cout << "VIDEO";
                break;
            case CD:
                cout << "CD";
                break;
            default:
                cout << "Unknown";
        }

        cout << getMediaFormat() << ", with title: " << getTitle() << ", bought for: " << getPrice() << " on date: " << getPurchaseDate() << " has game difficulty level: " << getGameDifficulty() << endl;
    }
};