#ifndef WXGETAPP_USAGE_H
#define WXGETAPP_USAGE_H
#include <wx/wx.h>
#include <wx/app.h>

/// This snippet shows how to use wxGetApp() which is a function generated by
/// IMPLEMENT_APP_NO_MAIN macro and IMPLEMENT_APP macros, here we are using the earlier
namespace GetAppFuncUsage
{
	// Snippet on how to use IMPLEMENT_APP_NO_MAIN

	class MyWxApp : public wxApp
	{
	public:
		bool OnInit() override
		{
			// Create frame
			wxFrame* frame = new wxFrame(NULL, wxID_ANY, "wxGetApp() usage");
			frame->Show(true);
			return true;
		}
	};

	// This is the macro that generates the wxGetApp, try commenting this line, you will notice
	// compilation errors will appear
	IMPLEMENT_APP_NO_MAIN(MyWxApp);
	// The above line is the same as(in my system, in yours it will be slightly different):
	/*
	MyWxApp& wxGetApp() { return *static_cast<MyWxApp*>(wxApp::GetInstance()); }

	wxAppConsole* wxCreateApp()
	{
		wxAppConsole::CheckBuildOptions(
			"3" "." "1" "." "2" " (" "wchar_t" ",Visual C++ " "1900" ",STL containers" ",compatible with 3.0" ")",
			"your program");
		return new MyWxApp;
	}
	wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction)wxCreateApp);;
	*/
	IMPLEMENT_WX_THEME_SUPPORT;

	int main(int argc, char** argv)
	{
		// MyWxApp derives from wxApp
		// This is not needed because we used IMPLEMENT_APP_NO_MAIN which
		// already takes care of creating the wxApp
		// wxApp::SetInstance(new MyWxApp());

		// Initialize wxWidgets framework
		wxEntryStart(argc, argv);

		// Init Your wxApp instance
		if (wxGetApp().OnInit())
		{
			// Enter Ui Loop if Initialization was successful
			wxGetApp().OnRun();
		}
		// Exit the app
		wxGetApp().OnExit();

		// Cleanup the wxWidgets framework
		wxEntryCleanup();

		return true;
	}
}
#endif
