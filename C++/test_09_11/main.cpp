#include <iostream>
#include <fstream>

using namespace std;

//void ReadFile()
//{
//	ifstream ifs("main.cpp");
//	char ch;
//	while (ifs)
//	{
//		cout << (char)ifs.get();
//	}
//}
//
//void WriteFile()
//{
//	ofstream ofs("write.txt");
//	ofs.put('x');
//	ofs.write("hello world", 10);
//}
//
//int main()
//{
//	ReadFile();
//	WriteFile();
//
//	return 0;
//}

struct ServerInfo
{
	char _ip[20];
	int _port;
};

struct ConfigManger
{
public:
	ConfigManger(const char* filename)
		:_filename(filename)
	{}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_filename);
		ifs.read((char*)&info, sizeof(info));
	}
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs.write((char*)&info, sizeof(info));
	}
private:
	string _filename;
};

int main()
{
	ServerInfo winfo = {"192.0.0.1", 80};
	ConfigManger cfbin("config.bin");
	// 读写 二进制
	cfbin.WriteBin(winfo);

	// 读写 文本
}
