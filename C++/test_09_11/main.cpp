#include <iostream>
#include <fstream>
#include <cstring>

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
	// ���캯��
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

	void WriteTxt(const ServerInfo& info)
	{
		ofstream ofs(_filename);
		ofs.write(info._ip, strlen(info._ip));
		ofs.put('\n');
		string portstr = to_string(info._port);
		ofs.write(portstr.c_str(), portstr.size());
	}



private:
	string _filename;
};

int main()
{
	ServerInfo rinfo;
	ServerInfo winfo = {"192.0.0.1", 80};
	// ��д ������
	//ConfigManger cfbin("config.bin");
	//cfbin.WriteBin(winfo);

	// ���ļ��е����ݶ���rinfo��
	//cfbin.ReadBin(rinfo);

	// ��д �ı�
	ConfigManger cfbin("config.txt");
	cfbin.WriteTxt(winfo);

}
