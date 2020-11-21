#include "Main.h"

EXPORT uint32_t GetSDKVersion()
{
	return alt::ICore::SDK_VERSION;
}

EXPORT alt::IScriptRuntime* CreateJSScriptRuntime(alt::ICore* _core)
{
	_core->LogInfo("[WASM] Wasm module loaded.");

	return nullptr;
}