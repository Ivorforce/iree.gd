#include "resource_format_loader_iree_module.h"

#include "iree_module.h"

using namespace godot;

Variant ResourceFormatLoaderIREEModule::_load(const String &p_path,
		const String &original_path,
		bool use_sub_threads,
		int32_t cache_mode) const {
	Ref<IREEModule> iree_model = memnew(IREEModule);
	iree_model = iree_model->load(p_path);
	if (iree_model.is_null()) {
		ERR_PRINT("Cannot load " + p_path);
		return Ref<Resource>();
	}
	return iree_model;
}

PackedStringArray
ResourceFormatLoaderIREEModule::_get_recognized_extensions() const {
	PackedStringArray array;
	array.push_back("vmfb");
	return array;
}
bool ResourceFormatLoaderIREEModule::_handles_type(
		const StringName &type) const {
	return ClassDB::is_parent_class(type, "IREEModule");
}

String
ResourceFormatLoaderIREEModule::_get_resource_type(const String &p_path) const {
	String el = p_path.get_extension().to_lower();
	if (el == "vmfb") {
		return "IREEModule";
	}
	return "";
}
