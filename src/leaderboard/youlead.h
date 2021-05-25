//
// Created by cpasjuste on 21/05/2021.
//

#ifndef SILLYTOWER_YOULEAD_H
#define SILLYTOWER_YOULEAD_H

#include <string>
#include <vector>
#include <curl/curl.h>
#include "score.h"
#include "user.h"

class YouLead {

public:
    YouLead();

    ~YouLead();

    User getLocalUser() const;

    Score getScore(const std::string &id, const std::string &username, int order = 0) const;

    std::vector<Score> getScores(const std::string &id, int order = 0, int limit1 = 0, int limit2 = 0) const;

    Score addScore(const std::string &id, const std::string &username, const std::string &password,
                   long score, int order = 0, bool overwrite = false) const;

private:
    CURL *m_curl = nullptr;
    std::string m_key = __YOULEAD_KEY__;
    //std::string m_url = "http://mydedibox.fr/sillytower/leaderboard/Unity.php?";
    std::string m_url = "http://127.0.0.1/Unity.php?";
    std::string m_id = "top";
    User m_user;
    bool m_available = true;
};

#endif //SILLYTOWER_YOULEAD_H
