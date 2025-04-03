#pragma once
#include <Windows.h>
#include <iostream>
#include <vector>

#ifndef OFFSETS_H
extern struct memeory_base {
	DWORD addrPos_x;
	DWORD addrPos_y;
	DWORD addrPos_z
		;
	DWORD addr_viewangle_x;
	DWORD addr_viewangle_y;
	 
	DWORD addr_hp;
	DWORD addr_ammor;
	DWORD addr_xrot;
	DWORD addr_yrot;
	DWORD addr_namespace;
}; memeory_base MBLP;

extern struct pVar {
	DWORD pid;
	DWORD localPlayer_arr = 0x57e0a8;
	DWORD entityArray = 0x58AC04;
	DWORD playerNumber = 0x591fd4;
	DWORD Entity_void = 0x04;
};  pVar VAR;

extern struct Local_Player {
	std::vector<DWORD> offsets = { 0x4 , 0x8  , 0xc  , 0x34 , 0x38 , 0x138 , 0x205 , 0xEC , 0x34 , 0x38 }; // 5 -> ammor 6 -> namespace 7-> hp 8 -> xrot 9-> yrot;
	DWORD pos_x = offsets[0];
	DWORD pos_y = offsets[1]; 
	DWORD pos_z = offsets[2];

	DWORD viewangle_x = offsets[3]; 
	DWORD viewangle_y = offsets[4];
}; Local_Player LPP;

extern struct practice_bot {
	std::vector<DWORD> enitity_bot = { 0x04 }; // offsets;
	std::vector<DWORD> entity_offsets_devine = { 0x4  , 0x8, 0xc, 0xEC, 0x205}; // 엔티티 어레이 + this.offsets ==> 0x58AC04 + entity_offsts_devine[n];
	// 0 posx 
	// 1 posy
	// 2 posz
	// 3 hp
	// 4 name
}; practice_bot PLPP;

#define OFFSETS_H
 
#endif // 오프셋 및 기초 논리 정의