#pragma once

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/loader/Loader.hpp>

#include "../main.hpp"
#include "./UnlistedObjectUI.hpp"

 /**
  * Brings cocos2d and all Geode namespaces
  * to the current scope.
  */
using namespace geode::prelude;
// modify the EditButtonBar
class $modify(EditButtonBarUnlistedObjs, EditButtonBar) {
	void loadFromItems(CCArray * items, int r, int c, bool unkBool);
};