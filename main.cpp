// Application
#include "app/startup/impl_app_nomain.h"
#include "app/startup/wxapp_setinstance.h"
#include "app/startup/wxgetapp_usage.h"
#include "app/startup/single_instance.h"


// Concurrency
#include "concurrent/thread_class_demo.h"
#include "macros/try_catch.h"
#include "io/message_output_debug.h"
#include "macros/unused_var.h"
#include "macros/wxunused_demo.h"


// IO
#include "io/read_write_file.h"
#include "io/compress.h"


// FileSystem
#include "fs/filename_usage.h"
#include "fs/add_slash_if_need.h"
#include "fs/dirs_snippet.h"
#include "fs/special_dirs.h"
#include "fs/remove_file.h"
#include "fs/get_all_files.h"
#include "fs/trasverse_dir.h"
#include "fs/get_file_size.h"
#include "fs/rename_file.h"


// Data Structures
#include "data_structures/array_str.h"


// Process
#include "proccess/exec_cmd.h"
#include "proccess/dump_process_env.h"
#include "proccess/get_set_env.h"
#include "proccess/killproc.h"
#include "proccess/execute_process_streams.h"
#include "proccess/timer_interactive_shell.h"
#include "proccess/thread_interactive_shell.h"


// Text Processing
#include "text/string_tokenizer_usage.h"
#include "text/upper_lower.h"
#include "text/wxt_usage.h"
#include "text/wxstring_conv.h"
#include "text/wxsnprintf_demo.h"
#include "text/string_usage.h"
#include "text/string_format.h"
#include "text/fgets.h"


// System
#include "system/get_basic_info.h"
#include "misc/launch_browser.h"
#include "text/strip_str.h"
#include "text/substr.h"


#define ImplementAppSnippet false

// As stated in my tweet https://twitter.com/melardev/status/1119344453913907205
// These two may really give you headaches if they are missing, many link errors(LNK)
// are due to these statements missing
#if defined(_WIN32) || defined(_WIN64)
#pragma comment(lib, "comctl32.lib")
#pragma comment(lib, "Rpcrt4.lib")
#endif


// If you wanna see the IMPLEMENT_APP macro usage then set the ImplementAppSnippet macro to true
#if ImplementAppSnippet == true

class HelloApp : public wxApp
{
public:
	bool OnInit() override
	{
		wxFrame* frame = new wxFrame(NULL, -1, "Hello World");
		wxButton* btn = new wxButton(frame, -1, "Click");
		btn->Bind(wxEVT_BUTTON, &HelloApp::OnButtonClicked, this);
		frame->Show();
		return true;
	}

	void OnButtonClicked(wxCommandEvent& evt)
	{
		wxMessageBox("Button Clicked!");
	}
};


wxIMPLEMENT_APP(HelloApp);
#endif


#if ImplementAppSnippet == false
int main(int argc, char** argv)
{
	// App initialization
	// ImplAppNoMain::main(argc, argv);
	// SetAppInstance::main(argc, argv);
	// GetAppFuncUsage::main(argc, argv);
	// SingleInstance::main(argc, argv);


	// Concurrency
	// wxThreadUsage::main(argc, argv);


	// Macros
	// WxUnusedUsage::main(argc, argv);
	// WxUnusedMacroUsage::main(argc, argv);
	// WxUnusedMacroUsage::main(argc, argv);
	// TryCatchSnippet::main();


	// Filesystem
	// wxFileNameUsage::main();
	// AddSlashIfNeeded::main();
	// FsDirectories::main();
	// SpecialDirectories::main();
	// RemoveFileSnippet::main();
	// GetAllFiles::main();
	// TraverseDirectory::main();
	// GetFileSizeSnippet::main();
	// RenameFileSnippet::main();


	// IO
	// ReadWriteFile::main();
	// MessageOutputDebug::main(argc, argv);
	// ZipCompression::main();


	// Data structures
	// ArrayStringUsage::main();
	// ArrayStringUsage::main();


	// Process
	// ExecCommand::main();
	// DumpProcessEnv::main();
	// GetSetEnvVariables::main();
	// KillProcess::main();
	// ExecuteProcess::main();
	// InteractiveShellWithTimer::main();
	// InteractiveShellWithThreads::main();


	// Text
	// StringTokenizerUsage::main();
	// ToUpperToLower::main();
	// wxTUsage::main();
	// WxStringConv::main();
	// wxSprintfUsage::main();
	// StringUsage::main();
	// StringFormatUsage::main();
	// FGetsUsage::main();
	// StripString::main();
	// SubString::main();


	// System
	// GetBasicInfo::main();


	// Misc
	// LaunchBrowser::main();


	wxPuts("Press any key to exit");
	wxGetc(stdin);
	return 0;
}

#endif
