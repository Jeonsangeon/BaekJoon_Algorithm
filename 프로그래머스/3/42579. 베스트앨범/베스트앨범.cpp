#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> ret;

struct Item {
    int id;
    int play;
};

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {return a.second > b.second;}
bool compare(const Item& a, const Item& b) {
    if (a.play == b.play) 
        return a.id < b.id;
    return a.play > b.play; 
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<Item>> items;
    map<string, int> total_play;
    for(int i = 0; i < genres.size(); ++i) {
        items[genres[i]].push_back({i, plays[i]});
        total_play[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> priority_genres(total_play.begin(), total_play.end());
    sort(priority_genres.begin(), priority_genres.end(), cmp);
    
    for (auto& genre : priority_genres) {
        string cur_genre = genre.first;
        auto& song_list = items[cur_genre];

        sort(song_list.begin(), song_list.end(), compare);
        ret.push_back(song_list[0].id);
        if (song_list.size() > 1)
            ret.push_back(song_list[1].id);
    }

    
    return ret;
}