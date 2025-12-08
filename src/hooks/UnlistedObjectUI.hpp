#pragma once

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>
#include <Geode/loader/Loader.hpp>

#include <alphalaneous.editortab_api/include/EditorTabs.hpp>
#include "../main.hpp"

 /**
  * Brings cocos2d and all Geode namespaces
  * to the current scope.
  */
using namespace geode::prelude;

 // gets a reference to the editor UI
class $modify(UnlistedObjectsUI, EditorUI) {
	struct Fields {
		// a series of booleans to prevent a bug where objects are duplicated
		// when they populate in the preexisting EditButtonBars
		// They are set to false when the EditorUI is loaded, and set to true 
		// when the tab is loaded for the first time
		bool block;
		bool outline;
		bool slope;
		bool hazard;
		bool threeD;
		bool portal;
		bool monster;
		bool pixel;
		bool collectable;
		bool icon;
		bool deco;
		bool sawblade;
		bool trigger;

		std::vector<CreateMenuItem*> buttonFix;
	};
    bool init(LevelEditorLayer * layer);
};