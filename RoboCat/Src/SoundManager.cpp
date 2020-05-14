#include "RoboCatPCH.h"

std::unique_ptr< SoundManager >	SoundManager::sInstance;

void SoundManager::StaticInit()
{
	sInstance.reset(new SoundManager());
}

SoundManager::SoundManager()
{
	LoadSoundFromFile(pickup, pickupB, "../Assets/TankVTank_Media/Sound/CollectPickup.wav");
	LoadSoundFromFile(shoot, shootB, "../Assets/TankVTank_Media/Sound/TankLMG.wav");
	LoadSoundFromFile(heavyS, shootH, "../Assets/TankVTank_Media/Sound/TankCannon1.wav");
	LoadSoundFromFile(teslaS, shootT, "../Assets/TankVTank_Media/Sound/TeslaShot.wav");
	LoadSoundFromFile(death, deathB, "../Assets/audio/death.wav");
	LoadSoundFromFile(join, joinB, "../Assets/audio/join.wav");
	LoadMusicFromFile(bgMusic, "../Assets/TankVTank_Media/Music/MenuTheme.ogg");
}

void SoundManager::LoadSoundFromFile(sf::Sound &p_sound, sf::SoundBuffer &p_buffer, string p_file)
{
	if (p_buffer.loadFromFile(p_file))
	{
		p_sound.setBuffer(p_buffer);
		p_sound.setVolume(5);
	}
}

void SoundManager::LoadMusicFromFile(sf::Music &p_music, string p_file)
{
	p_music.openFromFile(p_file);
	p_music.setLoop(true);
	p_music.setVolume(5);
}

void SoundManager::PlayMusic()
{
	bgMusic.play();
}

void SoundManager::PlaySound(SoundToPlay p_sound)
{
	switch (p_sound)
	{
	case SoundManager::STP_Pickup:
		pickup.setRelativeToListener(true);
		pickup.play();
		break;
	case SoundManager::STP_Shoot:
		shoot.play();
		break;
	case SoundManager::STP_Death:
		death.setRelativeToListener(true);
		death.play();
		break;
	case SoundManager::STP_Join:
		join.setRelativeToListener(true);
		join.play();
		break;
	case SoundManager::STP_HvyS:
		heavyS.play();
		break;
	case SoundManager::STP_TesS:
		teslaS.play();
		break;
	}

}

void SoundManager::PlaySoundAtLocation(SoundToPlay p_sound, sf::Vector3f p_location)
{
	switch (p_sound)
	{
	case SoundManager::STP_Shoot:
		shoot.setAttenuation(0.15);
		shoot.setPosition(p_location);
		shoot.play();
		break;
	case SoundManager::STP_HvyS:
		heavyS.setAttenuation(0.15);
		heavyS.setPosition(p_location);
		heavyS.play();
		break;
	case SoundManager::STP_TesS:
		teslaS.setAttenuation(0.15);
		teslaS.setPosition(p_location);
		teslaS.play();
		break;
	}
}