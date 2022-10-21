#pragma once

#include "Vec2.h"

class SceneMain;

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();

	// グラフィックデータ設定
	void setHandle(int handle) { m_handle = handle; }

    void setMain(SceneMain * pMain) { m_pMain = pMain; }

	// プレイヤーの初期化
	void init();

	// 処理
	void update();
	// 描画
	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	//当たり判定の幅、高さを取得
	float getColWidth();
	float getColHeight();

	//存在するか
	bool isExist()const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

private:
	
	int m_handle;
	
	SceneMain* m_pMain;
	//存在フラグ
	bool m_isExist;
	//shotの発生間隔
	int m_shotInteval;
	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;
};