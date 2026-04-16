# UnlistedObjectsinEditor
![Mod Version](https://api.geode-sdk.org/v1/mods/legowiifun.unlisted_objects_in_editor/status_badge?stat=version)
![Downloads](https://api.geode-sdk.org/v1/mods/legowiifun.unlisted_objects_in_editor/status_badge?stat=downloads)
![GD Version](https://api.geode-sdk.org/v1/mods/legowiifun.unlisted_objects_in_editor/status_badge?stat=gd_version)
![Geode Version](https://api.geode-sdk.org/v1/mods/legowiifun.unlisted_objects_in_editor/status_badge?stat=geode_version)

If, for some reason, you want to enable unstable objects, replace line 26 of mod.json with this:

	"one-of": [ "only nonreplicable objects", "all stable objects", "no secret coin", "unstable objects" ],

This is nearly guaranteed to cause the game to crash when entering the level editor.