#include "mmdcAssetManager.h"

// Init static variables
std::vector<assetinfo_t> mmdcAssetManager::info = std::vector<assetinfo_t>();
std::vector<std::shared_ptr<sf::Texture>> mmdcAssetManager::textures = std::vector<std::shared_ptr<sf::Texture>>();
std::vector<std::shared_ptr<sf::SoundBuffer>> mmdcAssetManager::sounds = std::vector<std::shared_ptr<sf::SoundBuffer>>();
std::vector<std::shared_ptr<sf::Font>> mmdcAssetManager::fonts = std::vector<std::shared_ptr<sf::Font>>();


mmdcAssetManager::mmdcAssetManager()
{
}


int mmdcAssetManager::CheckForExisting(std::string filename) const
{
	for (unsigned int i = 0; i < info.size(); i++)
	{
		if (info[i].filename == filename)
			return (int)info[i].index;
	}

	return -1;
}


void mmdcAssetManager::StoreInfo(std::string filename, unsigned int index)
{
	// Build asset info
	assetinfo_t tempInfo;
	tempInfo.filename = filename;
	tempInfo.index = index;
	// Add to vector
	info.push_back(tempInfo);
}


std::shared_ptr<sf::SoundBuffer> mmdcAssetManager::LoadSound(std::string filename)
{
	// Check for exist ing
	int existing = CheckForExisting(filename);
	if (existing > -1)
	{
		// Return existing one
		return sounds[existing];
	}
	// Store new asset
	else
	{
		sounds.push_back(std::shared_ptr<sf::SoundBuffer>(new sf::SoundBuffer()));
		if (!sounds.back()->loadFromFile(ASSETS_FOLDER + filename))
		{
			std::cout << "Could not load sound file " << filename << std::endl;
			return NULL;
		}
		else
		{
			std::cout << "Loaded sound file " << filename << std::endl;
		}
		// Store information
		StoreInfo(filename, sounds.size() - 1);

		return sounds.back();
	}
}

std::shared_ptr<sf::Texture> mmdcAssetManager::LoadTexture(std::string filename)
{
	// Check for exist ing
	int existing = CheckForExisting(filename);
	if (existing > -1)
	{
		// Return existing one
		return textures[existing];
	}
	// Store new asset
	else
	{
		textures.push_back(std::shared_ptr<sf::Texture>(new sf::Texture()));
		if (!textures.back()->loadFromFile(ASSETS_FOLDER + filename))
		{
			std::cout << "Could not load texture " << filename << std::endl;
			return NULL;
		}
		else
		{
			std::cout << "Loaded texture " << filename << std::endl;
		}
		// Store information
		StoreInfo(filename, textures.size() - 1);

		return textures.back();
	}
}

std::shared_ptr<sf::Font> mmdcAssetManager::LoadFont(std::string filename)
{
	// Check for exist ing
	int existing = CheckForExisting(filename);
	if (existing > -1)
	{
		// Return existing one
		return fonts[existing];
	}
	// Store new asset
	else
	{
		fonts.push_back(std::shared_ptr<sf::Font>(new sf::Font()));
		if (!fonts.back()->loadFromFile(ASSETS_FOLDER + filename))
		{
			std::cout << "Could not load font " << filename << std::endl;
			return NULL;
		}
		else
		{
			std::cout << "Loaded font " << filename << std::endl;
		}
		// Store information
		StoreInfo(filename, fonts.size() - 1);

		return fonts.back();
	}
}

void mmdcAssetManager::Unload()
{
	textures.clear();
	sounds.clear();
	fonts.clear();
}