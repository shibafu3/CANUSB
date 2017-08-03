#ifndef CANUSB_HPP
#define CANUSB_HPP

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include <stdlib.h>
#include <windows.h>

#include "lawicel_can.h"
#include "readdbc.hpp"

#include <vector>


// char��float�̋��p��
union ByteToFloat{
	float f[2];
	unsigned char c[8];
};


class CanUsb{
	// �n���h��
	CANHANDLE canhandle;
	// ��M���b�Z�[�W�i�[�z��
	CANMsg msgs[2048];
	// �\���p�̃��b�Z�[�W���i�[����x�N�^�[
	std::vector<CANMsg> temp_msgs;
	// ��M����ID�̃t���O
	double flag[2048] = {};


	// CANUSB�̏�����
	CANHANDLE InitCanUsb(){
		canhandle = -1;
		//CANUSB�I�[�v���̎��s��
		int open_try_num = 300;

		for (int i = 0; i < open_try_num; ++i){
			if ((canhandle = canusb_Open(NULL, "500", CANUSB_ACCEPTANCE_CODE_ALL, CANUSB_ACCEPTANCE_MASK_ALL, CANUSB_FLAG_TIMESTAMP)) > 0){
				std::cout << "CAN Adapter ID : " << canhandle << std::endl;
				Sleep(2000);
				break;
			}
			if (i == open_try_num - 1){
				std::cout << "CANUSB�̏������Ɏ��s���܂����B�ڑ����m�F���āA�A�v���P�[�V�������ċN�����Ă��������B" << std::endl;
				system("pause");
				exit(-1);
			}
			Sleep(10);
		}

		return canhandle;
	}
	int CloseCanUsb(){
		int status = canusb_Close(canhandle);
		std::cout << "Close Status : " << status << std::endl;
		Sleep(1000);
		return status;
	}
	int PrintMessage(CANMsg &msg){
		printf("[%08d] [0x%03x] [%02x %02x %02x %02x %02x %02x %02x %02x] [%f %f] [%d][%d]\n",
			msg.timestamp, msg.id,
			msg.data[0], msg.data[1], msg.data[2], msg.data[3], msg.data[4], msg.data[5], msg.data[6], msg.data[7],
			*((float *)(&msg.data[0])), *((float *)(&msg.data[4])),
			msg.flags, msg.len);

		Sleep(200);
		return 0;
	}

public:
	CanUsb(){
		InitCanUsb();
	}
	~CanUsb(){
		CloseCanUsb();
	}
	std::vector<CANMsg> ReadCan(){
		CANMsg msg;
		int status;

		// �SID�𑖍� ��M�ł���ID�Ƃ��̃��b�Z�[�W���i�[
		for (int i = 0; i < 2048; ++i){
			if ((status = canusb_Read(canhandle, &msg)) > 0){
				msgs[msg.id] = msg;
				flag[msg.id] = 1;
			}
		}

		// �\���p�x�N�^�[���N���A
		temp_msgs.clear();
		// �i�[���ꂽID�ƃ��b�Z�[�W�𑖍��A�t���O��0���傫���ꍇ�͕\���p�x�N�^�[�Ɋi�[���āA�t���O��-0.1����B
		for (int i = 0; i < 2048; ++i){
			if (flag[i] > 0){
				temp_msgs.push_back(msgs[i]);
				flag[i] -= 0.01;
			}
		}

		//�R���\�[�����N���A���ĕ\��
		system("cls");
		printf("Reading\n");
		for (auto &m : temp_msgs){
			PrintMessage(m);
		}

		return temp_msgs;

	}
	int WriteCan(int id, ByteToFloat &b2f){
		CANMsg msg;
		msg.len = 8;
		int status = 0;

		msg.id = id;
		// �o�b�t�@�Ƀ��b�Z�[�W���i�[
		for (int i = 0; i < 8; ++i){
			msg.data[i] = b2f.c[i];
		}

		// ���b�Z�[�W�𑗐M
		while (status <= 0){
			status = canusb_Write(canhandle, &msg);
		}

		system("cls");
		printf("Writing\n");
		PrintMessage(msg);

		return 0;
	}

};



#endif