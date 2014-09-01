/* ============================================================
	Assets Manager
	Loads/unloads assets as they're needed by the various subsystems
	Does not handle actual displaying/playback
	===========================================================*/
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "mmdcDataTypes.h"

class mmdcAssetManager
{
private:
	// Asset information vector
	static std::vector<assetinfo_t>							info;
	// Actual assets
	static std::vector<std::shared_ptr<sf::Texture>>		textures;
	static std::vector<std::shared_ptr<sf::SoundBuffer>>	sounds;
	static std::vector<std::shared_ptr<sf::Font>>			fonts;

public:
	mmdcAssetManager();

	// Check for already existing asset, based on filename
	// Returns index of existing asset if found, or -1 if not found
	int CheckForExisting(std::string filename) const;

	// Store information
	void StoreInfo(std::string filename, unsigned int index);

	// Load a sound
	// Returns pointer to sound loaded
	// Returns null on error
	std::shared_ptr<sf::SoundBuffer> LoadSound(std::string filename);

	// Load a texture
	// Returns pointer to texture loaded
	// Returns null on error
	std::shared_ptr<sf::Texture> LoadTexture(std::string filename);

	// Load a font
	// Returns pointer to font loaded
	// Returns null on error
	std::shared_ptr<sf::Font> LoadFont(std::string filename);

	// Unload all assets
	// Mostly used when changing gamestate
	void Unload();
};

