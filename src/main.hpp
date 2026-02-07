#pragma once

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
void addObj(EditorUI* ui, int objId, enum ObjTypes necessary, cocos2d::CCArray* oArr);
std::vector<Ref<CCNode>> addObj(EditorUI* ui, int objId, enum ObjTypes necessary, std::vector<Ref<CCNode>> oArr);