#pragma once

class SFTextureManager
{
public:
	static void StaticInit();

	static std::unique_ptr<SFTextureManager> sInstance;

	SFTexturePtr GetTexture(const string& inTextureName, int tankType);
	SFTexturePtr GetTexture(const string& inTextureName);

private:
	SFTextureManager();

	bool CacheTexture(string inName, const char* inFileName);
	std::string pickTexture(const string& inTextureName,int tankType);

	unordered_map< string, SFTexturePtr >	mNameToTextureMap;
};