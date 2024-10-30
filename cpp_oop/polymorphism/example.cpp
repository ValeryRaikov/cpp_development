#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
    string channelName;
    int subscribersCount;
    list<string> publishedVideos;
protected:
    string ownerName;
    int contentQuality;
public:
    YouTubeChannel(string channelName, string ownerName) {
        this->channelName = channelName;
        this->ownerName = ownerName;
        this->subscribersCount = 0;
        this->contentQuality = 0;
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

    int getContentQuality() {
        return contentQuality;
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

    void checkAnalytics() {
        cout << "Content Quality: " << getContentQuality() << endl;

        if (getContentQuality() < 5) {
            cout << getChannelName() << " has bad quality content!" << endl;
        } else {
            cout << getChannelName() << " has good quality content!" << endl;
        }
    }
};

class CookingYouTubeChannel: public YouTubeChannel {
public:
    CookingYouTubeChannel(string channelName, string ownerName): YouTubeChannel(channelName, ownerName) {}

    void practice() {
        cout << getOwnerName() << " is still practicing cooking!" << endl;
        contentQuality++;
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

    void practice() {
        cout << getOwnerName() << " is sharing a " << getFavouriteSport() << " training session!" << endl;
        contentQuality++;
    }
};

int main() {
    /* 
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

    ytc1.getInformation();
    ytc2.getInformation();
    */

    CookingYouTubeChannel cytc1("Cooking channel 1", "Cooking Owner 1");

    cytc1.setOwnerName("Valery Raikov");
    cytc1.setSubscribersCount(100);
    list<string> publishedVideos = {"New Video 1", "New Video2"};
    cytc1.setPublishedVideos(publishedVideos);

    cytc1.subscribe();
    cytc1.publishVideo("Simple Apple-Pie Recipe");

    cytc1.practice();
    cytc1.getInformation();

    SportYouTubeChannel sytc1("FitLife", "Alex Trainer", "Basketball");
    sytc1.subscribe();
    sytc1.publishVideo("Basketball Dribbling Basics");
    sytc1.publishVideo("Top 10 Basketball Drills");

    sytc1.practice();
    sytc1.practice();
    sytc1.practice();
    sytc1.practice();
    sytc1.practice();
    sytc1.practice();
    sytc1.getInformation();

    YouTubeChannel* yt1 = &cytc1;           
    YouTubeChannel* yt2 = &sytc1;

    yt1->checkAnalytics();
    yt2->checkAnalytics();

    return 0;
}