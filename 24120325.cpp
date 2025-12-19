#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<set>
using namespace std;
struct CPlayer;

void Trim
class IPlayerState {
    public:
    virtual void ApplyStats(CPlayer* player)=0;
    virtual string GetStateName()=0;
    virtual ~IPlayerState() {}
};
class CPlayer {
    private: 
    string m_ID;
    string m_Name;
    int m_Health;

    int m_BaseSpike, m_BaseMovement, m_BaseSet;

    int m_Spike, m_Movement, m_Set;

    vector<string> m_Positions;
    IPlayerState* m_pState;
    public:
CPlayer(): m_State(nullptr){}
~CPlayer();
    void setHealth(int h) { m_Health = h; }
    int getHealth() { return m_Health; }
    int getTotalStats() { return m_Spike + m_Movement + m_Set; }
    vector<string> getPositions() { return m_Positions; }
    string getName() { return m_Name; }
    string getID() { return m_ID; }

    void setEffectiveStats(int spike, int movement, int set) {
        m_Spike = spike;
        m_Movement = movement;
        m_Set = set;
    }
    int getBaseSpike() { return m_BaseSpike; }
    int getBaseMovement() { return m_BaseMovement; }
    int getBaseSet() { return m_BaseSet; }


    void Input (istream& in);
    void UpdateState();
    void UpdatePlayerStatsBasedOnHealth();
    void CanPlayPosition(string position);
    void PrintInfo(ostream& out);

};

class roCStngState: public IPlayerState{
    public: 
    void ApplyStats(CPlayer* player) override {
        player->setEffectiveStats(
            player->getBaseSpike()+10,
            player->getBaseMovement()+10,
            player->getBaseSet()+10 
        );
    }
    string GetStateName() override {
        return "Strong";
    }
};

class CNormalState: public IPlayerState{
    public: 
    void ApplyStats(CPlayer* player) override {
        player->setEffectiveStats(
            player->getBaseSpike()-10,
            player->getBaseMovement()-10,
            player->getBaseSet() -10
        );
    }
    string GetStateName() override {
        return "Tired";
    }
};

CPlayer::~CPlayer() {
    if (m_pState!= nullptr) {
        delete m_pState;
        m_pState = nullptr;
    }
}

void CPlayer::UpdateState() {
    if (m_pState != nullptr) {
        delete m_pState;
        m_pState = nullptr;
    }
    if (m_Health >= 90) {
        m_pState = new roCStngState();
    } else if (m_Health > 50) {
        m_State = new CNormalState();
    } else {
        m_State = new CTiredState();
    }
}

void CPlayer::UpdatePlayerStatsBasedOnHealth() {
    UpdateState();
    if (m_pState != nullptr) {
        m_pState->ApplyStats(this);
    }
}

void CPlayer:: Input(istream&in){
    // đầu vào : 001 Kerri Walsh Jennings 90 85 80 95 OH S
    // 1. Đọc ID.
    // 2. Đọc Name: Vì Name có khoảng trắng, cần đọc từng từ cho đến khi gặp số (là Health).
    // 3. Đọc Health, Spike, Movement, Set.
    // 4. Đọc các chuỗi còn lại của dòng -> đó là Positions.
    in >> m_ID;
    string namePart, fullName;
    while (in >> namePart) {
        if (isdigit(namePart[0])) {
            // Đây là phần Health.
            m_Health = stoi(namePart);
            break;
        }
        if (!fullName.empty()) {
            fullName += " ";
        }
        fullName += namePart;
    }
    m_Name = fullName;
    in >> m_BaseSpike >> m_BaseMovement >> m_BaseSet;
    string position;
    while (in >> position) {
        m_Positions.push_back(position);
    }
    // Cập nhật trạng thái và stats ban đầu.
    UpdatePlayerStatsBasedOnHealth();
}
class CVollayballTeam{
    private:
    vector <CPlayer> m_Players;
    public:
    void InputList(string filename);
    void RemovePlayerByPosition(string position);
    

}
