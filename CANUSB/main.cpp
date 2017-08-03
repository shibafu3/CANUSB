#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\canusbdrv.lib")
#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\borland_canusb.lib")

#include "canusb.hpp"






int main(){
	CanUsb cu;

	ByteToFloat b2f;
	//b2f.f[0] += 1.23;
	//b2f.f[1] = 3;
	b2f.c[0] = 0x00;
	b2f.c[1] = 0x10;
	b2f.c[2] = 0x00;
	b2f.c[3] = 0x0F;
	b2f.c[4] = 0x00;
	b2f.c[5] = 0x00;
	b2f.c[6] = 0x00;
	b2f.c[7] = 0x00;
	
	cu.WriteCan(0x5a2, b2f);
	system("pause");

	for (int i = 0; i < 3; ++i){
		cu.ReadCan();
	}
	system("pause");
	
	return 0;
}


//#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\canusbdrv.lib")
//#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\borland_canusb.lib")
//
//#include <iostream>
//#include <stdlib.h>
//#include <windows.h>
//#include <vector>
//#include <list>
//
//#include <fstream>
//#include <sstream>
//
//#include "lawicel_can.h"
//
//using namespace std;
//
//union ByteToFloat{
//	float f[2];
//	unsigned char c[8];
//};
//
//
//
//
//int main(){
//	CANHANDLE canhandle = -1;
//	int open_try_num = 300;
//	for (int i = 0; i < open_try_num; ++i){
//		if ((canhandle = canusb_Open(NULL, "500", CANUSB_ACCEPTANCE_CODE_ALL, CANUSB_ACCEPTANCE_MASK_ALL, CANUSB_FLAG_TIMESTAMP)) > 0){
//			cout << "CAN Adapter ID : " << canhandle << endl;
//			Sleep(2000);
//			break;
//		}
//		if (i == open_try_num - 1){
//			cout << "CANUSBの初期化に失敗しました。接続を確認したのち、再起動してください。" << endl;
//			system("pause");
//			return -1;
//		}
//		Sleep(10);
//	}
//
//
//	list<CANMsg> msgs;
//	CANMsg msg;
//	int status;
//	ByteToFloat b2f;
//	while (!GetAsyncKeyState(VK_RETURN)){
//		//		status = canusb_ReadFirst(canhandle, 0x101, 0, &msg);
//		if ((status = canusb_Read(canhandle, &msg)) > 0){
//			for (int i = 0; i < 8; ++i){ b2f.c[i] = msg.data[i]; }
//
//			if (msgs.empty()){
//				msgs.push_back(msg);
//			}
//			else{
//				for (auto itr = msgs.begin(); itr != msgs.end(); ++itr){
//					if (itr->id == msg.id){
//						*itr = msg;
//						break;
//					}
//					else if (itr->id > msg.id){
//						msgs.insert(itr, msg);
//						break;
//					}
//				}
//			}
//
//
//
//			if (1){
//				//Sleep(10);
//				system("cls");
//				printf("Reading\n");
//				for (auto &m : msgs){
//					printf("[%08d] [0x%03x] [%02x %02x %02x %02x %02x %02x %02x %02x] [%f %f] [%d][%d][%d]\n",
//						m.timestamp, m.id,
//						m.data[0], m.data[1], m.data[2], m.data[3], m.data[4], m.data[5], m.data[6], m.data[7],
//						*((float *)(&m.data[0])), *((float *)(&m.data[1])),
//						status, m.flags, m.len);
//				}
//			}
//		}
//	}
//
//	msg.id = 0x264;
//	b2f.f[0] = 4;
//	b2f.f[1] = 1;
//	Sleep(1000);
//	while (!GetAsyncKeyState(VK_RETURN)){
//		if (status = canusb_Write(canhandle, &msg)){
//			for (int i = 0; i < 8; ++i){
//				msg.data[i] = b2f.c[i];
//			}
//			Sleep(200);
//			system("cls");
//			printf("Writing\n");
//			printf("[%08d] [0x%03x] [%02x %02x %02x %02x %02x %02x %02x %02x] [%f %f] [%d][%d][%d]\n",
//				msg.timestamp, msg.id,
//				msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7],
//				b2f.f[0], b2f.f[1],
//				status, msg.flags, msg.len);
//		}
//	}
//	status = canusb_Close(canhandle);
//	cout << "Close Status : " << status << endl;
//	Sleep(1000);
//	return 0;
//}

//#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\canusbdrv.lib")
//#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\borland_canusb.lib")
//
//#include <iostream>
//#include <stdlib.h>
//#include <windows.h>
//#include <vector>
//
//#include <fstream>
//#include <sstream>
//
//#include "lawicel_can.h"
//
//using namespace std;
//
//union ByteToFloat{
//	float f[2];
//	unsigned char c[8];
//};
//
//
//
//
//int main(){
//	CANHANDLE canhandle = -1;
//	int open_try_num = 300;
//	for (int i = 0; i < open_try_num; ++i){
//		if ((canhandle = canusb_Open(NULL, "500", CANUSB_ACCEPTANCE_CODE_ALL, CANUSB_ACCEPTANCE_MASK_ALL, CANUSB_FLAG_TIMESTAMP)) > 0){
//			cout << "CAN Adapter ID : " << canhandle << endl;
//			Sleep(2000);
//			break;
//		}
//		if (i == open_try_num - 1){ 
//			cout << "Faild initializing can adapter." << endl;
//			system("pause");
//			return -1;
//		}
//		Sleep(10);
//	}
//
//
//
//	CANMsg msg;
//	int status;
//	ByteToFloat b2f;
//	_u32 prev_id = 0;
//	while (!GetAsyncKeyState(VK_RETURN)){
////		status = canusb_ReadFirst(canhandle, 0x101, 0, &msg);
//		if ((status = canusb_Read(canhandle, &msg)) > 0){
//			for (int i = 0; i < 8; ++i){
//				b2f.c[i] = msg.data[i];
//			}
//			if (prev_id >= msg.id){
//				Sleep(200);
//				system("cls");
//				printf("Reading\n");
//			}
//			printf("[%08d] [0x%03x] [%02x %02x %02x %02x %02x %02x %02x %02x] [%f %f] [%d][%d][%d]\n", 
//				msg.timestamp, msg.id, 
//				msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7], 
//				b2f.f[0], b2f.f[1], 
//				status, msg.flags, msg.len);
//			prev_id = msg.id;
//		}
//	}
//
//	msg.id = 0x264;
//	b2f.f[0] = 4;
//	b2f.f[1] = 1;
//	Sleep(1000);
//	while (!GetAsyncKeyState(VK_RETURN)){
//		if (status = canusb_Write(canhandle, &msg)){
//			for (int i = 0; i < 8; ++i){
//				msg.data[i] = b2f.c[i];
//			}
//			Sleep(200);
//			system("cls");
//			printf("Writing\n");
//			printf("[%08d] [0x%03x] [%02x %02x %02x %02x %02x %02x %02x %02x] [%f %f] [%d][%d][%d]\n",
//				msg.timestamp, msg.id,
//				msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7],
//				b2f.f[0], b2f.f[1],
//				status, msg.flags, msg.len);
//		}
//	}
//	status = canusb_Close(canhandle);
//	cout << "Close Status : " << status << endl;
//	Sleep(1000);
//	return 0;
//}