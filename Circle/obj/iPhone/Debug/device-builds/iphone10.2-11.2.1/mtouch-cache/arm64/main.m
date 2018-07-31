#include "xamarin/xamarin.h"

extern void *mono_aot_module_Circle_info;
extern void *mono_aot_module_mscorlib_info;
extern void *mono_aot_module_Xamarin_iOS_info;
extern void *mono_aot_module_System_info;
extern void *mono_aot_module_System_Core_info;
extern void *mono_aot_module_Firebase_CloudMessaging_info;
extern void *mono_aot_module_Firebase_InstanceID_info;
extern void *mono_aot_module_Firebase_Core_info;
extern void *mono_aot_module_Firebase_Analytics_info;
extern void *mono_aot_module_Firebase_Database_info;
extern void *mono_aot_module_Firebase_Auth_info;
extern void *mono_aot_module_MonoTouch_Dialog_1_info;
extern void *mono_aot_module_System_Json_info;
extern void *mono_aot_module_Plugin_Geolocator_info;
extern void *mono_aot_module_Plugin_Permissions_info;
extern void *mono_aot_module_FloatLabeledEntry_iOS_info;
extern void *mono_aot_module_Facebook_info;

void xamarin_register_modules_impl ()
{
	mono_aot_register_module (mono_aot_module_Circle_info);
	mono_aot_register_module (mono_aot_module_mscorlib_info);
	mono_aot_register_module (mono_aot_module_Xamarin_iOS_info);
	mono_aot_register_module (mono_aot_module_System_info);
	mono_aot_register_module (mono_aot_module_System_Core_info);
	mono_aot_register_module (mono_aot_module_Firebase_CloudMessaging_info);
	mono_aot_register_module (mono_aot_module_Firebase_InstanceID_info);
	mono_aot_register_module (mono_aot_module_Firebase_Core_info);
	mono_aot_register_module (mono_aot_module_Firebase_Analytics_info);
	mono_aot_register_module (mono_aot_module_Firebase_Database_info);
	mono_aot_register_module (mono_aot_module_Firebase_Auth_info);
	mono_aot_register_module (mono_aot_module_MonoTouch_Dialog_1_info);
	mono_aot_register_module (mono_aot_module_System_Json_info);
	mono_aot_register_module (mono_aot_module_Plugin_Geolocator_info);
	mono_aot_register_module (mono_aot_module_Plugin_Permissions_info);
	mono_aot_register_module (mono_aot_module_FloatLabeledEntry_iOS_info);
	mono_aot_register_module (mono_aot_module_Facebook_info);

}

void xamarin_register_assemblies_impl ()
{
	guint32 exception_gchandle = 0;
	xamarin_open_and_register ("Firebase.CloudMessaging.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Firebase.InstanceID.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Firebase.Core.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Firebase.Analytics.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Firebase.Database.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Firebase.Auth.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Plugin.Geolocator.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("FloatLabeledEntry.iOS.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);
	xamarin_open_and_register ("Facebook.dll", &exception_gchandle);
	xamarin_process_managed_exception_gchandle (exception_gchandle);

}

extern "C" void xamarin_create_classes();
void xamarin_setup_impl ()
{
	xamarin_create_classes();
	xamarin_gc_pump = FALSE;
	xamarin_init_mono_debug = TRUE;
	xamarin_executable_name = "Circle.exe";
	mono_use_llvm = FALSE;
	xamarin_log_level = 0;
	xamarin_arch_name = "arm64";
	xamarin_marshal_objectivec_exception_mode = MarshalObjectiveCExceptionModeDisable;
	xamarin_debug_mode = TRUE;
	setenv ("MONO_GC_PARAMS", "nursery-size=512k,major=marksweep", 1);
	xamarin_supports_dynamic_registration = FALSE;
}

int main (int argc, char **argv)
{
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	int rv = xamarin_main (argc, argv, XamarinLaunchModeApp);
	[pool drain];
	return rv;
}
void xamarin_initialize_callbacks () __attribute__ ((constructor));
void xamarin_initialize_callbacks ()
{
	xamarin_setup = xamarin_setup_impl;
	xamarin_register_assemblies = xamarin_register_assemblies_impl;
	xamarin_register_modules = xamarin_register_modules_impl;
}
