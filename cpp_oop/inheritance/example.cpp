#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
    string channelName;
    string ownerName;
    int subscribersCount;
    list<string> publishedVideos;
public:
    YouTubeChannel(string channelName, string ownerName) {
        this->channelName = channelName;
        this->ownerName = ownerName;
        this->subscribersCount = 0;
    }

    string getChannelName() {
        return channelName;
    }

    void setChannelName(string channelName) {
        this->channelName = channelName;
    }

    string getOwnerName() {
        return ownerName;
    }

    void setOwnerName(string ownerName) {
        this->ownerName = ownerName;
    }  

    int getSubscribersCount() {
        return subscribersCount;
    }

    void setSubscribersCount(int subscribersCount) {
        this->subscribersCount = subscribersCount;
    }

    list<string> getPublishedVideos() {
        return publishedVideos;
    }

    void setPublishedVideos(list<string> publishedVideos) {
        this->publishedVideos = publishedVideos;
    }

    void subscribe() {
        subscribersCount++;
    }

    void unsubscribe() {
        if (subscribersCount > 0) {
            subscribersCount--;
        }
    }

    void publishVideo(string videoName) {
        publishedVideos.push_back(videoName);
    }

    void getInformation() {
        cout << "Name: " << getChannelName() << endl;
        cout << "Owner name: " << getOwnerName() << endl;
        cout << "Subscribers: " << getSubscribersCount() << endl;

        for (string video: getPublishedVideos()) {
            cout << "Video: " << video << endl;
        }

        cout << endl;
    }
};

class CookingYouTubeChannel: public YouTubeChannel {
public:
    CookingYouTubeChannel(string channelName, string ownerName): YouTubeChannel(channelName, ownerName) {}

    void practice() {
        cout << getOwnerName() << " is still practicing cooking!" << endl;
    }
};

class SportYouTubeChannel: public YouTubeChannel {
private:
    string favouriteSport;
public:
    SportYouTubeChannel(string channelName, string ownerName, string favouriteSport):
    YouTubeChannel(channelName, ownerName), favouriteSport(favouriteSport) {}

    string getFavouriteSport() {
        return favouriteSport;
    }

    void setFavouriteSport(string favouriteSport) {
        this->favouriteSport = favouriteSport;
    }

    void showTraining() {
        cout << getOwnerName() << " is sharing a " << getFavouriteSport() << " training session!" << endl;
    }
};

int main() {
    YouTubeChannel ytc1("Channel 1", "Owner 1");
    ytc1.subscribe();
    ytc1.subscribe();
    ytc1.publishVideo("C++ for beginners");
    ytc1.publishVideo("SQL zero to hero");

    YouTubeChannel ytc2("Channel 2", "Owner 2");
    ytc2.subscribe();
    ytc2.subscribe();
    ytc2.unsubscribe();
    ytc2.publishVideo("Python basics");
    ytc2.publishVideo("C# intermidiate");

    // ytc1.getInformation();
    // ytc2.getInformation();

    CookingYouTubeChannel cytc1("Cooking channel 1", "Cooking Owner 1");

    cytc1.setOwnerName("Valery Raikov");
    cytc1.setSubscribersCount(100);
    list<string> publishedVideos = {"New Video 1", "New Video2"};
    cytc1.setPublishedVideos(publishedVideos);

    cytc1.subscribe();
    cytc1.publishVideo("Simple Apple-Pie Recipe");

    cytc1.practice();
    cytc1.getInformation();

    SportYouTubeChannel sportChannel("FitLife", "Alex Trainer", "Basketball");
    sportChannel.subscribe();
    sportChannel.publishVideo("Basketball Dribbling Basics");
    sportChannel.publishVideo("Top 10 Basketball Drills");

    sportChannel.showTraining();
    sportChannel.getInformation();

    return 0;
}