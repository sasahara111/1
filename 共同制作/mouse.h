#pragma once
#include<DxLib.h>

//�L�[���͏��ɕK�v�ȃf�[�^���܂Ƃ߂��\����
typedef struct {
	unsigned int m_nowKey;  //���݂̃{�^�����
	unsigned int m_PrevKey; //1�t���[���O�̃{�^�����
	int MouseX;
	int MouseY;
	VECTOR m_v;



}INPUT_DATA;




//�e�L�[�̊��蓖��
#define KEY_MOUSE     (0b1)     //��ړ�


//�L�[���͂̏�����
void InitInputMouse();
//�L�[���͏��X�V
void UpdateInputMouse();
//�L�[���͔���i�ʏ픻��j
bool IsInputRepMouse(unsigned int key);
//�L�[���͔���i�g���K�[����j
bool IsInputTrpMouse(unsigned int key);