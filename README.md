# UnlistedObjectsinEditor

If, for some reason, you want to enable unstable objects, paste this after line 21 of mod.json: 
		, "removeUnstable":{
			"name": "Remove unstable blocks",
			"description": "Removes blocks that are likely to cause the game to crash. I do not reccomended turning this off",
			"type": "bool",
			"default": true
		},
, enable the commented lines of code 28, and 41-43 in main.cpp, and comment out or remove line 29. This is nearly guarenteed to cause the game to crash when entering the level editor. 