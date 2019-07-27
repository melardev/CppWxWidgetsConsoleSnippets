#pragma once
#include <wx/wx.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/thread.h>

namespace InteractiveShellWithTimer
{
	wxEvtHandler* handler;
	wxProcess* process;
	volatile bool running = false;
	int ID_PROC = wxNewId();

	void writeIntoProcess(const wxString& command)
	{
		wxOutputStream* processOutputStream = process->GetOutputStream();
		if (processOutputStream)
		{
			wxTextOutputStream textOutputStream(*processOutputStream);
			// I always prefere to use TextOutputStream.WriteString() but you can also use the low level wxOutputStream.WriteAll
			if (command.EndsWith(wxT('\n')))
				processOutputStream->WriteAll(command.c_str(), command.size());
			else
			{
				textOutputStream.WriteString(command + wxT('\n'));
				textOutputStream.Flush();
			}
		}
	}

	void readFromProcess()
	{
		char buffer[4096];
		size_t bytesRead = 0;
		if (process && process->IsErrorAvailable())
		{
			wxInputStream* in = process->GetErrorStream();

			while (in->CanRead() && (bytesRead = in->Read(&buffer, sizeof(buffer)).LastRead()) > 0)
			{
				wxPrintf("%s", wxString(buffer, 0, bytesRead));
				// std::cout << std::string(buffer, 0, bytesRead);
			};
		}
		bytesRead = 0;
		if (process && process->IsInputAvailable())
		{
			wxInputStream* in = process->GetInputStream();
			while (in->CanRead() && (bytesRead = in->Read(&buffer, sizeof(buffer)).LastRead()) > 0)
			{
				wxPrintf("%s", wxString(buffer, 0, bytesRead));
				// std::cout << std::string(buffer, 0, bytesRead);
			}
		}
	}

	class ProcessEvtHandler : public wxEvtHandler
	{
	public:
		ProcessEvtHandler(): wxEvtHandler()
		{
			m_Timer = new wxTimer(this, ID_PROC);
			m_Timer->Start(100, false /* oneShot? No*/);
		}

		void OnTimer(wxTimerEvent& event)
		{
			if (process)
				readFromProcess();
		}

		void OnProcessTerminated(wxProcessEvent& e)
		{
			running = false;
			if (process)
				readFromProcess();

			m_Timer->Stop();
			delete m_Timer;
			delete process;
		}

	private:
		wxTimer* m_Timer;

	DECLARE_EVENT_TABLE()
	};


	BEGIN_EVENT_TABLE(ProcessEvtHandler, wxEvtHandler)
			EVT_TIMER(ID_PROC, ProcessEvtHandler::OnTimer)
			EVT_END_PROCESS(wxID_ANY, ProcessEvtHandler::OnProcessTerminated)
			END_EVENT_TABLE()

	class ConsoleReaderThread : public wxThread
	{
	public:
		ConsoleReaderThread(): wxThread(wxTHREAD_JOINABLE)
		{
		}

	protected:
		virtual void* Entry() override
		{
			char buffer[1024];
			while (running)
			{
				std::cin.getline(buffer, sizeof(buffer));
				wxString command(buffer);
				if (!running)
					break;

				writeIntoProcess(command);

				if (command.Strip(wxString::both).CmpNoCase("exit") == 0)
				{
					running = false;
					wxTheApp->ExitMainLoop();
					break;
				}
			}

			return 0;
		}
	};

	static void main()
	{
		int argc = 0;
		char** argv = nullptr;

		wxApp::SetInstance(new wxAppConsole);
		wxEntryStart(argc, argv);
		running = true;

		wxEvtHandler* handler = new ProcessEvtHandler;
		// The handler will receive EVT_END_PROCESS, by default the Event id is wxID_ANY
		// if I want to change that I have to add the second argument to our custom Id, and also
		// change it in EVT_END_PROCESS first argument
		process = new wxProcess(handler);

#if defined(_WIN32) || defined(_WIN64)
		const wxString cmd = "cmd";
#else
		const wxString cmd = "/bin/bash";
#endif
		process->Redirect();

		// wxEXEC_SHOW_CONSOLE targets MSW only
		const long pid = wxExecute(cmd, wxEXEC_ASYNC | wxEXEC_SHOW_CONSOLE, process);

		wxThread* consoleReaderThread = new ConsoleReaderThread();
		consoleReaderThread->Create();
		consoleReaderThread->Run();

		wxTheApp->OnInit();
		wxTheApp->OnRun();

		consoleReaderThread->Wait();
		delete consoleReaderThread;

		// Exit the app
		wxTheApp->OnExit();
		// Cleanup the wxWidgets framework
		wxEntryCleanup();
	}
}
