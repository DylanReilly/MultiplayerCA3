#include <RoboCatClientPCH.h>

std::unique_ptr<PlayerTextureGenerator> PlayerTextureGenerator::sInstance;

PlayerTextureGenerator::PlayerTextureGenerator()
{
	m_greenPlayerTextureIDs = {
		"GreenLMG1",
		"GreenLMG2",
		"GreenLMG3",
	};

	m_redPlayerTextureIDs = {
		"RedLMG1",
		"RedLMG2",
		"RedLMG3",
	};
}

SFTexturePtr PlayerTextureGenerator::GetPlayerTexure(uint32_t p_id)
{
	
	return SFTextureManager::sInstance->GetTexture(ResolveID(p_id));
}

std::string PlayerTextureGenerator::ResolveID(uint32_t p_id)
{
	if (p_id % 2 == 1)
	{
		return m_greenPlayerTextureIDs[p_id % m_greenPlayerTextureIDs.size()];
	}
	else
	{
		return m_redPlayerTextureIDs[p_id % m_redPlayerTextureIDs.size()];
	}
}

bool PlayerTextureGenerator::StaticInit()
{
	sInstance.reset(new PlayerTextureGenerator());
	return true;
}
