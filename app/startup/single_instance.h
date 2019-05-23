#pragma once
#include <wx/wx.h>
#include <wx/snglinst.h>

/// To test this snippet, enable this snippet by commenting all other snippets in main.cpp except
/// this one, then compile the application, and start it either from your file explorer, or
/// in your IDE, in VS click on Start Without Debugging many times

namespace SingleInstance
{
	class MyWxApp : public wxApp
	{
	public:
		wxSingleInstanceChecker* singleInstanceChecker;

		bool OnInit() override
		{
			singleInstanceChecker = new wxSingleInstanceChecker();
			if (singleInstanceChecker->IsAnotherRunning())
			{
				delete singleInstanceChecker;
				return false;
			}

			wxFrame* frame = new wxFrame(NULL, wxID_ANY, "wxSingleInstanceChecker usage",
			                             wxDefaultPosition, wxDefaultSize);
			SetTopWindow(frame);
			frame->Show(true);
			return true;
		}
	};

	IMPLEMENT_APP_NO_MAIN(MyWxApp)

	int main(int argc, char** argv)
	{
		// What is wxGetApp() see wxgetapp_usage.h snippet
		wxEntryStart(argc, argv);
		if (wxGetApp().OnInit())
			wxGetApp().OnRun();
		wxGetApp().OnExit();
		wxEntryCleanup();
		return 0;
	}
}
