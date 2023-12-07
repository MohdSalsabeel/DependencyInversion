class IDatabase {
public:
	virtual void insertData(string d)=0;
	virtual ~IDatabase(){}
};

class Database: public IDatabase {
public:
	void insertData(string data) {
		cout << "Inserting " << data << " into database" << endl;
	}
};

class DataProcessor {
public:
	void processData(vector<string> data, IDatabase& base) {
		for (auto i : data) {
			base.insertData(i);
		}
	}
};

int main() {
	vector<string> v{ "data1","data2","data3" };
	DataProcessor process;
	Database base;
	process.processData(v, base);
}
