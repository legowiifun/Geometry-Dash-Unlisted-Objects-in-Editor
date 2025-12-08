/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/loader/Loader.hpp>
#include "./main.hpp"

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