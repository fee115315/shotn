#pragma once

#include "Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle) { m_handle = handle; }

    void setMain(SceneMain * pMain) { m_pMain = pMain; }

	// �v���C���[�̏�����
	void init();

	// ����
	void update();
	// �`��
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	//�����蔻��̕��A�������擾
	float getColWidth();
	float getColHeight();

	//���݂��邩
	bool isExist()const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

private:
	
	int m_handle;
	
	SceneMain* m_pMain;
	//���݃t���O
	bool m_isExist;
	//shot�̔����Ԋu
	int m_shotInteval;
	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
};