#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;

class CSoldier {
protected:
	string m_Code; // ma so binh si
	double m_Attack; // chi so tan cong
	double m_Defend; // chi so phong thu
	string m_Equipment; // trang bi tra ve yes la co trang bi, no la khong co trang bi
	int m_Strength; // chi so suc manh
public:
	CSoldier(string code, double attack, double m_Defend, string equipment, int strength)
		: m_Code(code), m_Attack(attack), m_Defend(m_Defend), m_Equipment(equipment), m_Strength(strength) {}
	virtual double CalculatePower() const {
		double equipmentBonus = (m_Equipment == "yes") ? 10.0 : 0.0;
		return m_Attack * 2 + m_Defend * 1.5 + m_Strength + equipmentBonus;
	}
	virtual void DisplayInfo() const {
		cout << "Code: " << m_Code << ", Attack: " << m_Attack << ", m_Defend: " << m_Defend
			<< ", Equipment: " << m_Equipment << ", Strength: " << m_Strength
			<< ", Power: " << CalculatePower() << endl;
	}
	virtual ~CSoldier() {}

	 // getter and setter
	string getCode() const { return m_Code; }
	double getAttack() const { return m_Attack; }
	double getm_Defend() const { return m_Defend; }
	string getEquipment() const { return m_Equipment; }
	int getStrength() const { return m_Strength; }
	void setCode(const string& code) { m_Code = code; }
	void setAttack(double attack) { m_Attack = attack; }
	void setm_Defend(double m_Defend) { m_Defend = m_Defend; }
	void setEquipment(const string& equipment) { m_Equipment = equipment; }
	void setStrength(int strength) { m_Strength = strength; }
	 // phuong thuc ao de tinh chi so thuc te
	virtual double getRealDefend() const {
		return m_Defend;
	}
	virtual double getRealAttack() const {
		return m_Attack;
	}
	// hàm cập nhật chỉ số sau khi thắng trận
	void weakenAfterVicorty() {
		m_Attack -= 20;
		m_Defend -= 20;
		if (m_Attack < 0) m_Attack = 0;
		if (m_Defend < 0) m_Defend = 0;

	}
	// hàm áp dụng chỉ số của tướng lên lính 
	void ApplyGeneralBonus(double multiplier) {
		m_Attack *= multiplier;
		m_Defend *= multiplier;
		
	}
};

class CValiant : public CSoldier {
public:
	CValiant(string code, double attack, double m_Defend, string equipment, int strength)
		: CSoldier(code, attack, m_Defend, equipment, strength) {}
	double getRealDefend() const override {
		if(m_Equipment == "YES")
			return m_Defend * 2;
		return m_Defend;
	}
	double getRealAttack() const override {
		return m_Attack;
	}
};
class CArcher : public CSoldier {
public:
	CArcher(string code, double attack, double m_Defend, string equipment, int strength)
		: CSoldier(code, attack, m_Defend, equipment, strength) {
	}
	double getRealAttack() const override {
		if(m_Equipment == "YES")
			return m_Attack * 1.5;
		return m_Attack;
	}
	double getRealDefend() const override {
		return m_Defend;
	}
};

class CKnight : public CSoldier {
	public:
	CKnight(string code, double attack, double m_Defend, string equipment, int strength)
		: CSoldier(code, attack, m_Defend, equipment, strength) {
	}
	double getRealAttack() const override {
		if (m_Equipment == "YES") {
			return m_Attack * 3;
			return m_Attack;
		}
	
	}
	double getRealDefend() const override {
		if(m_Equipment == "YES")
			return m_Defend * 3;
		return m_Defend;
	}
};
class CGeneral : public CSoldier {
private:
	double m_Experience; // chi so kinh nghiem
public:
	CGeneral(string code, double attack, double m_Defend, string equipment, int strength, double experience)
		: CSoldier(code, attack, m_Defend, equipment, strength), m_Experience(experience) {}
	double CalculatePower() const override {
		double basePower = CSoldier::CalculatePower();
		return basePower + m_Experience * 5;
	}
	void DisplayInfo() const override {
		cout << "Code: " << m_Code << ", Attack: " << m_Attack << ", m_Defend: " << m_Defend
			<< ", Equipment: " << m_Equipment << ", Strength: " << m_Strength
			<< ", Experience: " << m_Experience
			<< ", Power: " << CalculatePower() << endl;
	}

	// hàm trả về chỉ số ảnh hưởng lên toàn quân 
	double getArmyBonusMultiplier() const {
		if (m_Experience == 0)return 0.5;
		if (m_Experience < 2.0)return (1.0 / 1.2);
		if (m_Experience < 5.0)return 1.5;
		if (m_Experience >= 5.0)return 2.0;
	}
};

class CArmy {
private:
		string m_ArmyName;
		vector<CSoldier*> m_Soldiers;
		CGeneral* m_General;
public:
	CArmy() : m_General(nullptr) {}
	~CArmy() {
		for (auto soldier : m_Soldiers) {
			delete soldier;
		}
		m_Soldiers.clear();
		delete m_General;
	}
	string getName() const {
		return m_ArmyName;
	}

	// hàm nhâp quân đội từ file với kiểu đầu vào là: 
	// 
	
	/*
	Team A 4
	AG AG1 70 70 YES 30 3.5
		V V001 20 10 YES 15
		A A001 10 5 NO 14
		K K001 30 35 YES 20*/
	void inputArmy(ifstream&);
	void applyGeneralBonus();
	// ham kiem tra linh con khong 
	bool hasSoldiers() const;
	// ham tra ve linhs dau tien
	CSoldier* getFirstSoldier() const;
	// hàm xóa lính đầu tiên sau khi thua trận
	void removeFirstSoldier();

	 // hàm kiểm tra quân đội thua hoàn toàn chưa
	bool isDefeated() const;

	void printResult(ofstream&);

	
};
void CArmy::inputArmy(ifstream& inFile) {
	inFile >> m_ArmyName;
	int soldierCount;
	inFile >> soldierCount;
	for (int i = 0; i < soldierCount; ++i) {
		string type;
		inFile >> type;
		if (type == "AG") {
			string code, equipment;
			double attack, defend, experience;
			int strength;
			inFile >> code >> attack >> defend >> equipment >> strength >> experience;
			m_General = new CGeneral(code, attack, defend, equipment, strength, experience);
		}
		else if (type == "V") {
			string code, equipment;
			double attack, defend;
			int strength;
			inFile >> code >> attack >> defend >> equipment >> strength;
			m_Soldiers.push_back(new CValiant(code, attack, defend, equipment, strength));
		}
		else if (type == "A") {
			string code, equipment;
			double attack, defend;
			int strength;
			inFile >> code >> attack >> defend >> equipment >> strength;
			m_Soldiers.push_back(new CArcher(code, attack, defend, equipment, strength));
		}
		else if (type == "K") {
			string code, equipment;
			double attack, defend;
			int strength;
			inFile >> code >> attack >> defend >> equipment >> strength;
			m_Soldiers.push_back(new CKnight(code, attack, defend, equipment, strength));
		}
	}
	
}

void CArmy::applyGeneralBonus() {
	if (m_General) {
		double multiplier = m_General->getArmyBonusMultiplier();
		for (auto soldier : m_Soldiers) {
			soldier->ApplyGeneralBonus(multiplier);
		}
	}
}

bool CArmy::hasSoldiers() const {
	return !m_Soldiers.empty();
}
CSoldier * CArmy::getFirstSoldier() const {
	if (!m_Soldiers.empty()) {
		return m_Soldiers.front();
	}
	return nullptr;
}
void CArmy::removeFirstSoldier() {
	if (!m_Soldiers.empty()) {
		delete m_Soldiers.front();
		m_Soldiers.erase(m_Soldiers.begin());
	}
	else if (m_General != nullptr) {
		delete m_General;
		m_General = nullptr;
	}
}
bool CArmy::isDefeated() const {
	return m_Soldiers.empty() && (m_General == nullptr);
}
void CArmy::printResult(ofstream& out) {
	out << m_ArmyName << " has " << m_Soldiers.size() << " soldiers remaining." << endl;
	if (m_General) {
		out << "General: ";
		m_General->DisplayInfo();
	}
	else {
		out << "No General remaining." << endl;
	}
}


void battle(CArmy& army1, CArmy& army2) {
	while (!army1.isDefeated() && !army2.isDefeated()) {
		CSoldier* soldier1 = army1.getFirstSoldier();
		CSoldier* soldier2 = army2.getFirstSoldier();
		double power1 = soldier1->CalculatePower();
		double power2 = soldier2->CalculatePower();
		if (power1 > power2) {
			soldier1->weakenAfterVicorty();
			army2.removeFirstSoldier();
		}
		else if (power1 < power2) {
			soldier2->weakenAfterVicorty();
			army1.removeFirstSoldier();
		}
		else {
			army1.removeFirstSoldier();
			army2.removeFirstSoldier();
		}
	}
} 
int main() {
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	CArmy army1, army2;
	army1.inputArmy(inFile);
	army2.inputArmy(inFile);
	army1.applyGeneralBonus();
	army2.applyGeneralBonus();
	battle(army1, army2);
	outFile << "Battle Result:" << endl;
	army1.printResult(outFile);
	army2.printResult(outFile);
	inFile.close();
	outFile.close();
	return 0;
}


