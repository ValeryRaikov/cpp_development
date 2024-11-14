#include <iostream>
#include <vector>

#include "item.cpp"
#include "media_types.cpp"

using namespace std;

class Music: public Item {
private:
    vector<string> musicArtists;
    mediaTypes mediaType;
public:
    Music(string title, double price, int mediaNumber, string mediaFormat, string purchaseDate, vector<string> musicArtists, mediaTypes mediaType)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate) {
            this->musicArtists = musicArtists;
            this->mediaType = mediaType;
        }

    vector<string> getMusicArtists() {
        return musicArtists;
    }

    mediaTypes getMediaType() {
        return mediaType;
    }

    void getItemInformation() {
        cout << "Music:\n";

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

        cout << getMediaFormat() << ", with title: " << getTitle() << ", bought for: " << getPrice() << " on date: " << getPurchaseDate() << endl;

        if (getMusicArtists().empty()) {
            cout << "No artists added!\n";
            return;
        }

        cout << "Artists:\n";
        for (string artist: getMusicArtists()) {
            cout << artist << endl;
        }
    }
};