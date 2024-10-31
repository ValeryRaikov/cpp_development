#include <iostream>
#include <list>

using namespace std;

struct YouTubeChannel {
    string name;
    int subscribersCount;

    YouTubeChannel(string name, int subscribersCount) {
        this->name = name;
        this->subscribersCount = subscribersCount;
    }

    bool operator==(const YouTubeChannel& ytChannel) const {
        return this->name == ytChannel.name;
    }
};

ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
    COUT << "Name: " << ytChannel.name << endl;
    COUT << "Subscribers: " << ytChannel.subscribersCount << endl;

    return COUT;
}

struct MyCollection {
    list<YouTubeChannel> myChannels;

    void operator+=(YouTubeChannel& ytChannel) {
        this->myChannels.push_back(ytChannel);
    }

    void operator-=(YouTubeChannel& ytChannel) {
        this->myChannels.remove(ytChannel);
    }
};

ostream& operator<<(ostream& COUT, MyCollection& myCollection) {
    for (YouTubeChannel ytChannel: myCollection.myChannels) {
        COUT << ytChannel << endl;
    }

    return COUT;
}

int main() {
    YouTubeChannel yt1 = YouTubeChannel("CodeBro", 100000);
    YouTubeChannel yt2 = YouTubeChannel("Second Channel", 20000);

    cout << yt1 << yt2; // first
    operator<<(cout, yt1); // second

    MyCollection mc1;
    mc1 += yt1;
    mc1 += yt2;
    cout << mc1;
    
    mc1 -= yt2;
    cout << mc1;

    return 0;
}