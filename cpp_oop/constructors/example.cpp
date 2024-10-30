#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
public:
    string channelName;
    string ownerName;
    int subscribersCount;
    list<string> publishedVideos;

    YouTubeChannel(string channelName, string ownerName) {
        this->channelName = channelName;
        this->ownerName = ownerName;
        this->subscribersCount = 0;
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
    ytc1.publishedVideos.push_back("C++ for beginners");
    ytc1.publishedVideos.push_back("SQL zero to hero");

    YouTubeChannel ytc2("Channel 2", "Owner 2");
    ytc2.publishedVideos.push_back("Python basics");
    ytc2.publishedVideos.push_back("C# intermidiate");

    ytc1.getInformation();
    ytc2.getInformation();

    return 0;
}