#ifndef IMPL_APP_NO_MAIN_H
#define IMPL_APP_NO_MAIN_H
#include <wx/wx.h>
#include <wx/app.h>


namespace ImplAppNoMain
{
	// Snippet on how to use IMPLEMENT_APP_NO_MAIN

	class MyWxApp : public wxApp
	{
		bool OnInit() override
		{
			// Create frame
			wxFrame* frame = new wxFrame(NULL, wxID_ANY, "");
			frame->Show(true);
			return true;
		}
	};


	IMPLEMENT_APP_NO_MAIN(MyWxApp);
	IMPLEMENT_WX_THEME_SUPPORT;

	int main(int argc, char** argv)
	{
		// MyWxApp derives from wxApp
		// This line is optional, the app instance is already set by IMPLEMENT_APP_NO_MAIN
		// go look the wxapp_setinstance snippet
		// wxApp::SetInstance(new MyWxApp());

		// Initialize wxWidgets framework
		wxEntryStart(argc, argv);

		// Init Your wxApp instance
		if (wxTheApp->OnInit())
		{
			// Enter Ui Loop if initialization successful
			wxTheApp->OnRun();
		}

		// Exit the app
		wxTheApp->OnExit();

		// Cleanup the wxWidgets framework
		wxEntryCleanup();

		return true;
	}
}
#endif
