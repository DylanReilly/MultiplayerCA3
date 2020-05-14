#include <RoboCatClientPCH.h>

std::unique_ptr<SFTextureManager> SFTextureManager::sInstance;

void SFTextureManager::StaticInit()
{
	sInstance.reset(new SFTextureManager());
}

SFTextureManager::SFTextureManager()
{
	CacheTexture("cat", "../Assets/cat.png");
	CacheTexture("pickup", "../Assets/random.png");
	CacheTexture("bullet", "../Assets/TankBullet.png");
	CacheTexture("heavy_bullet", "../Assets/HeavyBullet.png");
	CacheTexture("tesla_bullet", "../Assets/TeslaBullet.png");
	CacheTexture("tile", "../Assets/tile.png");
	CacheTexture("wood", "../Assets/wood.png");
	CacheTexture("stone", "../Assets/stone.png");
	CacheTexture("grass_org", "../Assets/grass.png");
	CacheTexture("start_screen", "../Assets/start_screen.png");
	CacheTexture("died_screen", "../Assets/died_screen.png");
	CacheTexture("winner_screen", "../Assets/winner_screen.png");

	//TankVTank Textures
	CacheTexture("bricks", "../Assets/TankVTank_Media/Textures/Arena/Decor_Tiles/Decor_Tile_B_04.png");
	CacheTexture("dirt", "../Assets/TankVTank_Media/Textures/Arena/Tiles/Ground_Tile_01_A.png");
	CacheTexture("grass", "../Assets/TankVTank_Media/Textures/Arena/Tiles/Ground_Tile_01_B.png");


	// Player textures.
	CacheTexture("hitman", "../Assets/hitman.png");
	CacheTexture("hatman", "../Assets/hatman.png");
	CacheTexture("man_blue", "../Assets/man_blue.png");
	CacheTexture("man_brown", "../Assets/man_brown.png");
	CacheTexture("man_old", "../Assets/man_old.png");
	CacheTexture("robot", "../Assets/robot.png");
	CacheTexture("soldier", "../Assets/soldier.png");
	CacheTexture("woman", "../Assets/woman.png");
	CacheTexture("zombie", "../Assets/zombie.png");

	//Green Tank Start Varient
	CacheTexture("GreenLMG1", "../Assets/TankVTank_Media/Textures/Tanks/tank-1.png");
	CacheTexture("GreenLMG2", "../Assets/TankVTank_Media/Textures/Tanks/tank-2.png");
	CacheTexture("GreenLMG3", "../Assets/TankVTank_Media/Textures/Tanks/tank-3.png");

	//Green Tank Heavy Variant
	CacheTexture("GreenHvy1", "../Assets/TankVTank_Media/Textures/Tanks/tank-4.png");
	CacheTexture("GreenHvy2", "../Assets/TankVTank_Media/Textures/Tanks/tank-5.png");
	CacheTexture("GreenHvy3", "../Assets/TankVTank_Media/Textures/Tanks/tank-6.png");

	//Green Tank Gatling Varient
	CacheTexture("GreenGat1", "../Assets/TankVTank_Media/Textures/Tanks/tank-7.png");
	CacheTexture("GreenGat2", "../Assets/TankVTank_Media/Textures/Tanks/tank-8.png");
	CacheTexture("GreenGat3", "../Assets/TankVTank_Media/Textures/Tanks/tank-9.png");

	//Green Tank Tesla Varient
	CacheTexture("GreenTes1", "../Assets/TankVTank_Media/Textures/Tanks/tank-10.png");
	CacheTexture("GreenTes2", "../Assets/TankVTank_Media/Textures/Tanks/tank-11.png");
	CacheTexture("GreenTes3", "../Assets/TankVTank_Media/Textures/Tanks/tank-12.png");





	//Red Tank Start Varient
	CacheTexture("RedLMG1", "../Assets/TankVTank_Media/Textures/Tanks/tank-13.png");
	CacheTexture("RedLMG2", "../Assets/TankVTank_Media/Textures/Tanks/tank-14.png");
	CacheTexture("RedLMG3", "../Assets/TankVTank_Media/Textures/Tanks/tank-15.png");

	//Red Tank Heavy Varient
	CacheTexture("RedHvy1", "../Assets/TankVTank_Media/Textures/Tanks/tank-16.png");
	CacheTexture("RedHvy2", "../Assets/TankVTank_Media/Textures/Tanks/tank-17.png");
	CacheTexture("RedHvy3", "../Assets/TankVTank_Media/Textures/Tanks/tank-18.png");

	//Red Tank Gatling Varient
	CacheTexture("RedGat1", "../Assets/TankVTank_Media/Textures/Tanks/tank-19.png");
	CacheTexture("RedGat2", "../Assets/TankVTank_Media/Textures/Tanks/tank-20.png");
	CacheTexture("RedGat3", "../Assets/TankVTank_Media/Textures/Tanks/tank-21.png");

	//Red Tank Tesla Varient
	CacheTexture("RedTes1", "../Assets/TankVTank_Media/Textures/Tanks/tank-22.png");
	CacheTexture("RedTes2", "../Assets/TankVTank_Media/Textures/Tanks/tank-23.png");
	CacheTexture("RedTes3", "../Assets/TankVTank_Media/Textures/Tanks/tank-24.png");





	//Blue Tank Start Varient
	CacheTexture("BlueLMG1", "../Assets/TankVTank_Media/Textures/Tanks/tank-25.png");
	CacheTexture("BlueLMG2", "../Assets/TankVTank_Media/Textures/Tanks/tank-26.png");
	CacheTexture("BlueLMG3", "../Assets/TankVTank_Media/Textures/Tanks/tank-27.png");

	//Blue Tank Heavy Varient
	CacheTexture("BlueHvy1", "../Assets/TankVTank_Media/Textures/Tanks/tank-28.png");
	CacheTexture("BlueHvy2", "../Assets/TankVTank_Media/Textures/Tanks/tank-29.png");
	CacheTexture("BlueHvy3", "../Assets/TankVTank_Media/Textures/Tanks/tank-30.png");

	//Blue Tank Gatling Varient
	CacheTexture("BlueGat1", "../Assets/TankVTank_Media/Textures/Tanks/tank-31.png");
	CacheTexture("BlueGat2", "../Assets/TankVTank_Media/Textures/Tanks/tank-32.png");
	CacheTexture("BlueGat3", "../Assets/TankVTank_Media/Textures/Tanks/tank-33.png");

	//Blue Tank Tesla Varient
	CacheTexture("BlueTes1", "../Assets/TankVTank_Media/Textures/Tanks/tank-34.png");
	CacheTexture("BlueTes2", "../Assets/TankVTank_Media/Textures/Tanks/tank-35.png");
	CacheTexture("BlueTes3", "../Assets/TankVTank_Media/Textures/Tanks/tank-36.png");





	// Healthbar frames.
	CacheTexture("health10", "../Assets/healthbar/health10.png");
	CacheTexture("health9", "../Assets/healthbar/health9.png");
	CacheTexture("health8", "../Assets/healthbar/health8.png");
	CacheTexture("health7", "../Assets/healthbar/health7.png");
	CacheTexture("health6", "../Assets/healthbar/health6.png");
	CacheTexture("health5", "../Assets/healthbar/health5.png");
	CacheTexture("health4", "../Assets/healthbar/health4.png");
	CacheTexture("health3", "../Assets/healthbar/health3.png");
	CacheTexture("health2", "../Assets/healthbar/health2.png");
	CacheTexture("health1", "../Assets/healthbar/health1.png");
	CacheTexture("health0", "../Assets/healthbar/health0.png");
	CacheTexture("armor10", "../Assets/healthbar/armor10.png");
	CacheTexture("armor9", "../Assets/healthbar/armor9.png");
	CacheTexture("armor8", "../Assets/healthbar/armor8.png");
	CacheTexture("armor7", "../Assets/healthbar/armor7.png");
	CacheTexture("armor6", "../Assets/healthbar/armor6.png");
	CacheTexture("armor5", "../Assets/healthbar/armor5.png");
	CacheTexture("armor4", "../Assets/healthbar/armor4.png");
	CacheTexture("armor3", "../Assets/healthbar/armor3.png");
	CacheTexture("armor2", "../Assets/healthbar/armor2.png");
	CacheTexture("armor1", "../Assets/healthbar/armor1.png");

}

SFTexturePtr SFTextureManager::GetTexture(const string& inTextureName, int tankType) //Jason- Overload of base GetTexture for tank textures
{
	//return mNameToTextureMap[inTextureName];

	std::string tex = pickTexture(inTextureName, tankType);
	return mNameToTextureMap[tex];
}

SFTexturePtr SFTextureManager::GetTexture(const string& inTextureName)
{
	return mNameToTextureMap[inTextureName];
}

std::string SFTextureManager::pickTexture(const string& inTextureName, int tankType) { //Jason - Gets texture based on value from tank type. Also checks which colour you are
	srand((unsigned)time(0));
	int result = 1 + (rand() % 3);

	//Dylan - Checks player score before spawning tank
	std::ifstream inputFile;
	int fileScore;
	inputFile.open("../Assets/Saved/Scores.txt");
	inputFile >> fileScore;
	inputFile.close();

	if (tankType == 0) {

		if (fileScore >= 5)
		{
			if (inTextureName == "green")
			{
				return "GreenLMG3";
			}
			else
			{
				return "RedLMG3";
			}
		}
		else if (fileScore >= 3)
		{
			if (inTextureName == "green")
			{
				return "GreenLMG2";
			}
			else
			{
				return "RedLMG2";
			}
		}
		else if (fileScore < 3)
		{
			if (inTextureName == "green")
			{
				return "GreenLMG1";
			}
			else
			{
				return "RedLMG1";
			}
		}
		else //Default just in case
		{
			if (inTextureName == "green")
			{
				return "GreenLMG1";
			}
			else
			{
				return "RedLMG1";
			}
		}
	}
	else if (tankType == 1)
	{

		if (fileScore >= 5)
		{
			if (inTextureName == "green")
			{
				return "GreenHvy3";
			}
			else
			{
				return "RedHvy3";
			}
		}
		else if (fileScore >= 3)
		{
			if (inTextureName == "green")
			{
				return "GreenHvy2";
			}
			else
			{
				return "RedHvy2";
			}
		}
		else if (fileScore < 3)
		{
			if (inTextureName == "green")
			{
				return "GreenHvy1";
			}
			else
			{
				return "RedHvy1";
			}
		}
		else //Default just in case
		{
			if (inTextureName == "green")
			{
				return "GreenHvy1";
			}
			else
			{
				return "RedHvy1";
			}
		}
	}
	else if (tankType == 2)
	{

		if (fileScore >= 5)
		{
			if (inTextureName == "green")
			{
				return "GreenGat3";
			}
			else
			{
				return "RedGat3";
			}
		}
		else if (fileScore >= 3)
		{
			if (inTextureName == "green")
			{
				return "GreenGat2";
			}
			else
			{
				return "RedGat2";
			}
		}
		else if (fileScore < 3)
		{
			if (inTextureName == "green")
			{
				return "GreenGat1";
			}
			else
			{
				return "RedGat1";
			}
		}
		else //Default just in case
		{
			if (inTextureName == "green")
			{
				return "GreenGat1";
			}
			else
			{
				return "RedGat1";
			}
		}
	}
	else if (tankType == 3)
	{

		if (fileScore >= 5)
		{
			if (inTextureName == "green")
			{
				return "GreenTes3";
			}
			else
			{
				return "RedTes3";
			}
		}
		else if (fileScore >= 3)
		{
			if (inTextureName == "green")
			{
				return "GreenTes2";
			}
			else
			{
				return "RedTes2";
			}
		}
		else if (fileScore < 3)
		{
			if (inTextureName == "green")
			{
				return "GreenTes1";
			}
			else
			{
				return "RedTes1";
			}
		}
		else //Default just in case
		{
			if (inTextureName == "green")
			{
				return "GreenTes1";
			}
			else
			{
				return "RedTes1";
			}
		}
	}

}

bool SFTextureManager::CacheTexture(string inName, const char* inFileName)
{
	SFTexturePtr newTex(new sf::Texture());
	if (!newTex->loadFromFile(inFileName))
		return false;

	mNameToTextureMap[inName] = newTex;
	return true;
}
