# UnlistedObjectsinEditor
If, for some reason, you want to enable unstable objects, paste this after line 26 of mod.json:

		, "removeUnstable":{
			"name": "Remove unstable blocks",
			"description": "Removes blocks that are likely to cause the game to crash. I do not recommend turning this off",
			"type": "bool",
			"default": true,
			"enable-if": "activate"
		},

Then enable the commented lines of code 74 and 514 in main.cpp. This is nearly guaranteed to cause the game to crash when entering the level editor.