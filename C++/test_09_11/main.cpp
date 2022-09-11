#include <iostream>
#include <fstream>
#include <sstream>
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
	// 构造函数
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
//		ofstream ofs(_filename);
//		ofs.write(info._ip, strlen(info._ip));
//		ofs.put('\n');
//		string portstr = to_string(info._port);
//		ofs.write(portstr.c_str(), portstr.size());
		ofstream ofs(_filename);
		ofs << info._ip << "\n" << info._port;
	}

	void ReadTxt(ServerInfo& info)
	{
//		ifstream ifs(_filename);
//		ifs.getline(info._ip, 20);
//
//		char portbuff[20];
//		ifs.getline(portbuff, 20);
//		info._port = stoi(portbuff);
		ifstream ifs(_filename);
		ifs >> info._ip >> info._port;
	}


private:
	string _filename;
};

//int main()
//{
//	ServerInfo rinfo;
//	ServerInfo winfo = {"192.0.0.1", 80};
//	// 读写 二进制
//	//ConfigManger cfbin("config.bin");
//	//cfbin.WriteBin(winfo);
//
//	// 将文件中的数据读到rinfo中
//	//cfbin.ReadBin(rinfo);
//
//	// 读写 文本
////	ConfigManger cfbin("config.txt");
////	cfbin.WriteTxt(winfo);
//
//	ConfigManger cftxt("config.txt");
//	cftxt.ReadTxt(rinfo);
//
//}

int main()
{
	ServerInfo info = {"192.0.0.1", 8000};
	char buff[128];
	// 序列化
	sprintf(buff, "%s %d", info._ip, info._port);

	// 反序列化
	ServerInfo rinfo;
	sscanf(buff, "%s%d", rinfo._ip, &rinfo._port);

	return 0;
}
