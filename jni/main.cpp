#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <item/BackpackItem.h>
#include <language/I18n.h>
#include <Substrate.h>

#define LOG_TAG "backpackmod"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*Item_initItems_real)();

static void Item_initItems_hook() {
	Item_initItems_real();
	BackpackItem* b = new BackpackItem();
};

static void (*Item_initCreativeItems_real)();

static void Item_initCreativeItems_hook() {
Item_initCreativeItems_real();
Item::addCreativeItem(356, 0);
};

static std::string (*I18n_get_real)(std::string const&,std::vector<std::string,std::allocator<std::string>> const&);

static std::string I18n_get_hook(std::string const& key,std::vector<std::string,std::allocator<std::string>> const& a) {
if(key == "item.Backpack.name") {
return "Backpack";
} else {
return I18n_get_real(key, a);
}
};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

MSHookFunction((void*)&Item::initItems, (void*)&Item_initItems_hook, (void**)&Item_initItems_real);

MSHookFunction((void*)&Item::initCreativeItems, (void*)&Item_initCreativeItems_hook, (void**)&Item_initCreativeItems_real);

MSHookFunction((void*)&I18n::get, (void*)&I18n_get_hook, (void**)&I18n_get_real);

	return JNI_VERSION_1_2;
}
