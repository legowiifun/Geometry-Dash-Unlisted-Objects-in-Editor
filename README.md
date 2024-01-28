# UnlistedObjectsinEditor

If you find a way to fix the bug where objects on tab 0 (blocks tab) also show up in the edit menu,
please share it, and set the boolean bugFixed to true. 

If, for some reason, you want to enable unstable objects, paste this at the bottom of mod.json: 
		, "removeUnstable":{
			"name": "Remove unstable blocks",
			"description": "Removes blocks that are likely to cause the game to crash. I do not reccomended turning this off",
			"type": "bool",
			"default": true
		}
, enable the commented lines of code 42, and 54-56 in main.cpp, and comment out or remove line 43. This is nearly guarenteed to cause the game to crash when entering the level editor. 