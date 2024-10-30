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
        cout << "Name: " << channelName << endl;
        cout << "Owner name: " << ownerName << endl;
        cout << "Subscribers: " << subscribersCount << endl;

        for (string video: publishedVideos) {
            cout << "Video: " << video << endl;
        }

        cout << endl;
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

    cout << ytc1.getChannelName() << endl;
    cout << ytc1.getOwnerName() << endl;
    
    cout << ytc2.getChannelName() << endl;
    cout << ytc2.getOwnerName() << endl;

    ytc1.getInformation();
    ytc2.getInformation();

    return 0;
}