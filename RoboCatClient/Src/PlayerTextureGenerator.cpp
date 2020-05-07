#include <RoboCatClientPCH.h>

std::unique_ptr<PlayerTextureGenerator> PlayerTextureGenerator::sInstance;

PlayerTextureGenerator::PlayerTextureGenerator()
{
	m_playerTextureIDs = {
		"GreenLMG", 
		"RedLMG",
		"BlueLMG",
		"GreenHMG",
		"RedHMG",
		"BlueHMG"
	};
}

SFTexturePtr PlayerTextureGenerator::GetPlayerTexure(uint32_t p_id)
{
	
	return SFTextureManager::sInstance->GetTexture(ResolveID(p_id));
}

std::string PlayerTextureGenerator::ResolveID(uint32_t p_id)
{
	return m_playerTextureIDs[p_id % m_playerTextureIDs.size()];
}

bool PlayerTextureGenerator::StaticInit()
{
	sInstance.reset(new PlayerTextureGenerator());
	return true;
}
