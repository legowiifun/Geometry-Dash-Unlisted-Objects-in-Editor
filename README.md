# UnlistedObjectsinEditor

If, for some reason, you want to enable unstable objects, paste this at the bottom of mod.json: 
		, "removeUnstable":{
			"name": "Remove unstable blocks",
			"description": "Removes blocks that are likely to cause the game to crash. I do not reccomended turning this off",
			"type": "bool",
			"default": true
		}
, enable the commented lines of code 42, and 52-54 in main.cpp, and comment out or remove line 43. This is nearly guarenteed to cause the game to crash when entering the level editor. 