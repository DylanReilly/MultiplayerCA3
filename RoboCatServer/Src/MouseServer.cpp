#include <RoboCatServerPCH.h>


MouseServer::MouseServer()
{
}

void MouseServer::HandleDying()
{
	NetworkManagerServer::sInstance->UnregisterGameObject( this );
}


bool MouseServer::HandleCollisionWithCat( RoboCat* inCat ) //Jason - When player hits pickup it generates a random effect.
{
	if (!picked)
	{
		srand((unsigned)time(0));
		int result = 1 + (rand() % 100);

		if (result >= 1 && result <= 25) { //Jason - Restores health
			if (inCat->GetHealth() <= 15)
				inCat->GetHealth()++;
		}
		else if (result >= 26 && result <= 50) { //Jason - Sets tank to heavy
			inCat->SetTankType(1);
		}
		else if (result >= 51 && result <= 75) { //Jason - Sets tank to gatling
			inCat->SetTankType(2);
		}
		else { //Jason - Sets tank to tesla 
			inCat->SetTankType(3);
		}

		/*if (inCat->GetHealth() <= 15)
			inCat->GetHealth()++;*/

		picked = true;

		// Hacked in here.d
		int ECRS_Health = 1 << 3;
		NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_Health); //Sends new health value

		int ECRS_TankType = 1 << 4;
		NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_TankType); //Jason - Sends new tank type
	}
	//kill yourself!
	SetDoesWantToDie( true );
	return false;
}


