#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\canusbdrv.lib")
#pragma comment(lib,"C:\\Users\\0133752\\Documents\\Visual Studio 2013\\Projects\\CANUSB\\CANUSB\\borland_canusb.lib")

#include "canusb.hpp"


//500 0x1f4 ノーマルモードかどうか 0 1
//float -1～1

int main(){
	CanUsb cu;

	ByteToFloat b2f;

	while (1){
		std::cout << *((float *)(&cu.ReadCan(0x100).data[4])) << std::endl;
		Sleep(10);
	}

	return 0;

	// for moter seigyo team
	//	CanUsb cu;
	//
	//	ByteToFloat b2f;
	//	//b2f.f[0] += 1.23;
	//	//b2f.f[1] = 3;
	//	b2f.c[0] = 0x00;
	//	b2f.c[1] = 0x10;
	//	b2f.c[2] = 0x00;
	//	b2f.c[3] = 0x0F;
	//	b2f.c[4] = 0x00;
	//	b2f.c[5] = 0x00;
	//	b2f.c[6] = 0x00;
	//	b2f.c[7] = 0x00;
	//	
	//	cu.WriteCan(0x5a2, b2f);
	//	system("pause");
	//
	//	for (int i = 0; i < 3; ++i){
	//		cu.ReadCan();
	//	}
	//	system("pause");
	//	
	//	return 0;
}