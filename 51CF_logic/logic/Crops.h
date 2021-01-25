#pragma once

#ifndef CROPS_H
#define CROPS_H

#include "definition.h"
#include "data.h"
#include "cell.h"
#include "player.h"

class Crops
{
private:
	//新增兵团属性
	static TCorpsID		ID;
	TCorpsID			m_myID;//兵团ID
	corpsType			m_type;//兵团属性
	battleCorpsType		m_BattleType;//战斗兵用
	constructCorpsType	m_BuildType;//建造兵用

	TPlayerID				m_PlayerID;//所属阵营

	TMovePoint				m_MovePoint;//行动力
	THealthPoint			m_HealthPoint;//生命值 归0即死亡
	int						m_level;//等级 从0开始
	TBuildPoint				m_BuildPoint;//劳动力

	TPoint		m_position;//位置

	int			m_PeaceNum;//多少个回合没有受到攻击
	//
public:
	Crops(void);
	~Crops(void);
	Crops(corpsType type, battleCorpsType battletype, constructCorpsType buildtype, TPlayerID ID, TPoint pos);
	//作战兵团移动 有待地图接口判断地形

	//作战兵团攻击 返回是否成功攻击 并减去生命值 如果死亡则在兵团数组中删除
	bool AttackCrops(TCorpsID enemyID);
	//是否存活
	bool bAlive();
	//获取战斗力
	TBattlePoint getCE();
	//返回位置
	TPoint getPos();
	//
	TPlayerID getPlayerID();
	//回复HP 每回合调用所有兵团该函数回复生命力
	void Recover();
	//整编兵团 返回是否整编成功
	bool MergeCrops(TCorpsID cropsID);
	//该兵团灭亡，将该兵团从兵团集合中删除
	void Delete();
	//新回合开始，重置行动力
	void ResetMP();
protected:
	//作战兵团受到攻击 返回是否存活 如果死亡，会自动在兵团数组中删除
	bool BeAttacked(int attack, Crops* enemy);
};

#endif