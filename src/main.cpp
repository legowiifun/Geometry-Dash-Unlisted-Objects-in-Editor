#pragma once

/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/loader/Loader.hpp>

// define a macro for adding an object
#define ADD_OBJ(id, type) addObj(static_cast<EditorUI*>(ui), id, ObjTypes::type, items)

/**
 * Brings cocos2d and all Geode namespaces 
 * to the current scope.
 */
using namespace geode::prelude;

// enum for types of unlisted objs
enum class ObjTypes {
	NON_REPLICABLE,
	STABLE,
	UNSTABLE,
	COIN
};

// adds an object to an editor tab
void addObj(EditorUI* ui, int objId, enum ObjTypes necessary, cocos2d::CCArray* oArr) {
	// check settings
	std::string mode = Mod::get()->template getSettingValue<std::string>("activeObjs");
	// if only in nonreplicable
	bool unecessary = mode == "only nonreplicable objects";
	bool active = Mod::get()->template getSettingValue<bool>("activate");
	// if unstable is allowed
	bool noUnstable = mode != "unstable objects";
	// if the coin is allowed
	bool coinAllowed = (mode == "all stable objects" || mode == "unstable objects");

	// if all objects are to be shown, 
	// or if it is unecessary and !unecessary, 
	// or if it is nonReplicable
	// or if it is coin and coinAllowed

	if (!noUnstable ||
		(necessary == ObjTypes::STABLE && !unecessary) ||
		necessary == ObjTypes::NON_REPLICABLE ||
		(coinAllowed && necessary == ObjTypes::COIN)) {
		//first argument is obj id, 2nd is always 4
		auto obj = ui->getCreateBtn(objId, 4);

		if (obj && oArr->indexOfObject(obj) == UINT_MAX) {
			oArr->addObject(obj);
		}
	}
}