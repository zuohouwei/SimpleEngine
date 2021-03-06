#pragma once


#include "pos.h"
#include "tsv.h"
#include "logger.h"
#include "../animation/frame_animation.h"
#include "../State.h"
#include "../message.h"
class Player;

class BasePlayerCombatState :  public State<Player> 
{
public:
	virtual void Enter(Player* ) ;
    virtual void Execute(Player* player);
 	virtual void Exit(Player* ) ;
	virtual bool OnMessage(Player*, const Telegram&) ;
};


class PlayerIdleState : public BasePlayerCombatState, public Singleton<PlayerIdleState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	bool OnMessage(Player* , const Telegram& ) override;
};

class PlayerMoveState : public BasePlayerCombatState, public Singleton<PlayerMoveState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	bool OnMessage(Player* , const Telegram& ) override;
};

class PlayerCombatIdleState : public BasePlayerCombatState, public Singleton<PlayerCombatIdleState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
};

class PlayerCombatMoveState : public BasePlayerCombatState, public Singleton<PlayerCombatMoveState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	bool OnMessage(Player* , const Telegram& ) override;
private:
	bool m_bSent;
};
class PlayerCombatAttackState : public BasePlayerCombatState, public Singleton<PlayerCombatAttackState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
};

class PlayerCombatCastAttackState : public BasePlayerCombatState, public Singleton<PlayerCombatCastAttackState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	void Exit(Player* player) override;
};


class PlayerCombatBackState : public BasePlayerCombatState, public Singleton<PlayerCombatBackState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	void Exit(Player* ) override;
};


class PlayerCombatBeAttackedState : public BasePlayerCombatState, public Singleton<PlayerCombatBeAttackedState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;

};

class PlayerCombatBeCastAttackedState : public BasePlayerCombatState, public Singleton<PlayerCombatBeCastAttackedState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;

};

class PlayerCombatClpsState : public BasePlayerCombatState, public Singleton<PlayerCombatClpsState>
{
public:
	void Execute(Player* player) override;
	void Enter(Player* player) override;
	void Exit(Player*) override;
};

class PlayerCombatGlobalState : public BasePlayerCombatState, public Singleton<PlayerCombatGlobalState>
{
public:	
    void Execute(Player* player) override;
	void Enter(Player* player) override;
	bool OnMessage(Player* , const Telegram& ) override;
};