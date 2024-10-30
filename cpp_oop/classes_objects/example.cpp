#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel {
public:
    string channelName;
    string ownerName;
    int subscribersCount;
    list<string> publishedVideos;
};

int main() {
    YouTubeChannel ytc1;
    ytc1.channelName = "Channel 1";
    ytc1.ownerName = "Owner 1";
    ytc1.subscribersCount = 10000;
    ytc1.publishedVideos = {"C++ tutorial", "HTML & CSS tutorial", "React.js introduction"};

    cout << "Name: " << ytc1.channelName << endl;
    cout << "Owner name: " << ytc1.ownerName << endl;
    cout << "Subscribers: " << ytc1.subscribersCount << endl;

    for (string video: ytc1.publishedVideos) {
        cout << "Video: " << video << endl;
    }

    return 0;
}