#pragma once

class PlayerTextureGenerator
{

public:

	static bool StaticInit();
	static std::unique_ptr<PlayerTextureGenerator>	sInstance;
	PlayerTextureGenerator();
	SFTexturePtr GetPlayerTexure(uint32_t p_id, int tankType, int tankVersion);

private:
	std::string ResolveID(uint32_t p_id);
	std::vector<std::string> m_greenPlayerTextureIDs;
	std::vector<std::string> m_redPlayerTextureIDs;
};