#include <iostream>

#include "item.cpp"
#include "media_types.cpp"

using namespace std;

class Movie: public Item {
private:
    float movieRating;
    mediaTypes mediaType;
public:
    Movie(string title, double price, int mediaNumber, string mediaFormat, string purchaseDate, float movieRating, mediaTypes mediaType)
        : Item(title, price, mediaNumber, mediaFormat, purchaseDate) {
            this->movieRating = movieRating;
            this->mediaType = mediaType;
        }

    float getMovieRating() {
        return movieRating;
    }

    void setMovieRating(float value) {
        if (value < 0 || value > 10) {
            cout << "Invalid input!\n";
            return;
        }

        movieRating = value;
    }

    mediaTypes getMediaType() {
        return mediaType;
    }

    void getItemInformation() {
        cout << "Movie:\n";

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

        cout << getMediaFormat() << ", with title: " << getTitle() << ", bought for: " << getPrice() << " on date: " << getPurchaseDate() << " has rating: " << getMovieRating() << endl;
    }
};