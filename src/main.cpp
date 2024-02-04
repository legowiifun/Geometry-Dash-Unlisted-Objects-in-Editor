/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/EditButtonBar.hpp>
#include <Geode/modify/EditorUI.hpp>
/**
 * Brings cocos2d and all Geode namespaces 
 * to the current scope.
 */
using namespace geode::prelude;

// enum for object tabs
enum tabs {
	blocks, 
	outlines, 
	slopes, 
	hazards, 
	ThreeDL, 
	GameplayModifiers, 
	AnimatedObjs, 
	Pixels, 
	Collectables, 
	SpriteDeco, 
	OtherDeco, 
	RotatePulseObjs, 
	Triggers
};
// enum for types of unlisted objs
enum types {
	nonReplicable,
	stable,
	unstable
};

EditorUI* editorUI=nullptr;
cocos2d::CCArray* objArr;
auto active = Mod::get()->getSettingValue<bool>("activate");
auto unecessary = Mod::get()->getSettingValue<bool>("doNotInclude");
// auto noUnstable = Mod::get()->getSettingValue<bool>("removeUnstable");
auto noUnstable=true;

$execute{
	listenForSettingChanges("activate", +[](bool value) {
		active=value;
	});
	listenForSettingChanges("doNotInclude", +[](bool value) {
		unecessary=value;
	});
//		listenForSettingChanges("removeUnstable", +[](bool value) {
//		noUnstable=value;
//	});
}

// gets a reference to the editor UI
class $modify(EditorUI) {
	bool init(LevelEditorLayer* layer) {
		editorUI=this;
		return EditorUI::init(layer);
	}
};

// adds an object to an editor tab
void addObj(int objId, enum types necessary) {
	// if all objects are to be shown, 
	// or if it is unecessary and !unecessary, 
	// or if it is nonReplicable
	if(!noUnstable||
		(necessary==stable&&!unecessary)||
		necessary==nonReplicable) {
		//first argument is obj id, 2nd is always 4
		auto obj=editorUI->getCreateBtn(objId,4);
		objArr->addObject(obj);
	}
}

// modify the EditButtonBar
class $modify(EditButtonBar) {
	bool init(cocos2d::CCArray* objects, 
		cocos2d::CCPoint p1, int id, bool buildTab, int p4, int p5) {
		if(!active) {
			return EditButtonBar::init(objects,p1, id,buildTab,p4,p5);
		}
		objArr=objects;
		// id==tab to put in
		switch(id) {
			case tabs::AnimatedObjs:
				break;
			case tabs::blocks:
				if(buildTab) {
				// old half-slab, replaced with colorable one
				addObj(40,types::nonReplicable);
				addObj(369,types::stable);
				addObj(370,types::stable);
				// old quarter-blocks, replaced with colorable one
				addObj(195,types::nonReplicable);
				addObj(196,types::nonReplicable);
				// old grey stripes going in,
				// replaced with version without outlines
				addObj(160,types::stable);
				addObj(161,types::stable);
				addObj(162,types::stable);
				addObj(163,types::stable);
				addObj(164,types::stable);
				addObj(165,types::stable);
				addObj(166,types::stable);
				addObj(167,types::stable);
				addObj(168,types::stable);
				addObj(169,types::stable);
				addObj(193,types::stable);
				addObj(737,types::stable);
				// old colored grid blocks, unknown why replaced
				addObj(247,types::stable);
				addObj(248,types::stable);
				addObj(249,types::stable);
				addObj(250,types::stable);
				addObj(251,types::stable);
				addObj(252,types::stable);
				addObj(253,types::stable);
				addObj(254,types::stable);
				// solid startPos
				addObj(34,types::nonReplicable);
				}
				break;
			case tabs::Collectables:
				addObj(142,types::stable);
				break;
			case tabs::GameplayModifiers:
				break;
			case tabs::hazards:
				// old ground spike, replaced with colorable one
				addObj(9,types::stable);
				// old curve spikes, replaced with colorable one
				addObj(61,types::stable);
				addObj(243,types::stable);
				addObj(244,types::stable);
				addObj(366,types::stable);
				addObj(367,types::stable);
				addObj(368,types::stable);
				// old fake spikes, unknown why replaced
				addObj(191,types::stable);
				addObj(198,types::stable);
				addObj(199,types::stable);
				addObj(393, types::stable);
				// old spiky spikes, replaced with colorable one
				addObj(363,types::stable);
				addObj(364,types::stable);
				addObj(365,types::stable);
				// old bigger-curve spikes, replaced with colorable one
				addObj(446,types::stable);
				addObj(447,types::stable);
				// old block-on-top spikes, replaced with colorable one
				addObj(667,types::stable);
				addObj(989,types::stable);
				addObj(991,types::stable);
				addObj(720,types::stable);
				// old spike-on-top spikes, replaced with colorable ones
				addObj(421,types::stable);
				addObj(422,types::stable);
				addObj(768,types::stable);
				break;
			case tabs::OtherDeco:
				// old version of circle, unknown why replaced
				addObj(725,types::stable);
				// old bush versions, unknown why replaced
				addObj(461,types::stable);
				addObj(462,types::stable);
				addObj(463,types::stable);
				addObj(464,types::stable);
				addObj(465,types::stable);
				addObj(466,types::stable);
				break;
			case tabs::outlines:
				// alternate basic slope outlines
				// fit with blocks better
				addObj(665,types::nonReplicable);
				addObj(666,types::nonReplicable);
				break;
			case tabs::Pixels:
				/*
					1964-2011 are random pixels
					there are so many of these 
					the exact same as one of the ones
					in the pixel blocks tab
					this is much easier to write for adding them to the editor
				*/
				for(int i=1964;i<=2011;i++) {
					addObj(i,types::unstable);
				}
				break;
			case tabs::RotatePulseObjs:
				// old sawblades, replaced with colorable ones
				addObj(88,types::stable);
				addObj(89,types::stable);
				addObj(98,types::stable);
				addObj(397,types::stable);
				addObj(398,types::stable);
				addObj(399,types::stable);
				break;
			case tabs::slopes:
				// old grey grid slopes, unknown why replaced
				addObj(289,types::stable);
				addObj(291,types::stable);
				// other variants of slopes with outlines
				addObj(710,types::stable);
				addObj(711,types::stable);
				addObj(712,types::stable);
				addObj(726,types::stable);
				addObj(727,types::stable);
				addObj(728,types::stable);
				addObj(729,types::stable);
				addObj(321,types::stable);
				addObj(323,types::stable);
				addObj(331,types::stable);
				addObj(333,types::stable);
				addObj(343,types::stable);
				addObj(345,types::stable);
				addObj(353,types::stable);
				addObj(355,types::stable);
				addObj(349,types::stable);
				addObj(351,types::stable);
				addObj(337,types::stable);
				addObj(339,types::stable);
				addObj(483,types::stable);
				addObj(484,types::stable);
				addObj(492,types::stable);
				addObj(493,types::stable);
				addObj(651,types::stable);
				addObj(652,types::stable);
				addObj(886,types::stable);
				addObj(887,types::stable);
				break;
			case tabs::SpriteDeco:
				break;
			case tabs::ThreeDL:
				// 3D lines with hitboxes
				addObj(1561,types::nonReplicable);
				addObj(1562,types::nonReplicable);
				addObj(1563,types::nonReplicable);
				addObj(1564,types::nonReplicable);
				addObj(1565,types::nonReplicable);
				addObj(1566,types::nonReplicable);
				addObj(1567,types::nonReplicable);
				addObj(1568,types::nonReplicable);
				addObj(1569,types::nonReplicable);
				break;
			case tabs::Triggers:
				// old color Triggers (do not work as fas as I know)
				// replaced with general all-colors trigger in 2.0
				addObj(29,types::unstable);
				addObj(30,types::unstable);
				addObj(104,types::unstable);
				addObj(105,types::unstable);
				addObj(744,types::unstable);
				addObj(915,types::unstable);
				break;
		}
		return EditButtonBar::init(objects,p1,id,buildTab,p4,p5);
	}
};

