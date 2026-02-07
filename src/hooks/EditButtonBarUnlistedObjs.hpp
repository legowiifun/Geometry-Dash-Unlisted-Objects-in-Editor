#pragma once

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/loader/Loader.hpp>

#include "../main.hpp"
#include "./UnlistedObjectUI.hpp"

// define a macro for adding an object
#define ADD_OBJ(id, type) addObj(static_cast<EditorUI*>(ui), id, ObjTypes::type, items)

 /**
  * Brings cocos2d and all Geode namespaces
  * to the current scope.
  */
using namespace geode::prelude;
// modify the EditButtonBar
class $modify(EditButtonBarUnlistedObjs, EditButtonBar) {
	void loadFromItems(CCArray * items, int r, int c, bool unkBool);
};