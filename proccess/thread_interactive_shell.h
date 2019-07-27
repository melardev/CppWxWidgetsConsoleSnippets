#pragma once
#include <wx/wx.h>
#include <wx/process.h>
#include <wx/txtstrm.h>
#include <wx/thread.h>

namespace InteractiveShellWithThreads
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

	class ProcessEvtHandler : public wxEvtHandler
	{
	public:
		ProcessEvtHandler() : wxEvtHandler()
		{
		}

		void OnProcessTerminated(wxProcessEvent& e)
		{
			running = false;
			wxTheApp->ExitMainLoop();
			process->CloseOutput();
		}

	DECLARE_EVENT_TABLE()
	};


	BEGIN_EVENT_TABLE(ProcessEvtHandler, wxEvtHandler)
			EVT_END_PROCESS(wxID_ANY, ProcessEvtHandler::OnProcessTerminated)
			END_EVENT_TABLE()

	class RunnableThread : public wxThread
	{
	public:

		RunnableThread(std::function<void*()> func) : wxThread(wxTHREAD_JOINABLE), m_Runnable(func)
		{
			m_Runnable = func;
		}

	protected:
		virtual void* Entry() override
		{
			return m_Runnable();
		}

	private:
		std::function<void*()> m_Runnable;
	};

	static void main()
	{
#if  defined(_WIN32) || defined(_WIN64)
		const wxString cmd = "cmd";

#else
		wxString cmd;
		if (wxFileExists("/bin/bash"))
			cmd.Append("/bin/bash");
		else if (wxFileExists("/bin/sh"))
			cmd.Append("/bin/sh");
		else
		{
			wxPuts("Shell could not be located on this system");
			// wxExit();
			exit(2);
		}

#endif

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

		process->Redirect();

		// wxEXEC_SHOW_CONSOLE targets MSW only
		const long pid = wxExecute(cmd, wxEXEC_ASYNC | wxEXEC_SHOW_CONSOLE, process);


		// Console Input Stream
		wxThread* consoleInputThread = new RunnableThread([&]() -> void*
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
					process->CloseOutput();
					break;
				}
			}

			return nullptr;
		});
		consoleInputThread->Create();
		consoleInputThread->Run();


		// Process Output Stream
		wxThread* outputProcessReaderThread = new RunnableThread([&]() -> void*
		{
			char buffer[4096];
			size_t bytesRead = 0;

			wxInputStream* in = process->GetInputStream();

			while ((bytesRead = in->Read(&buffer, sizeof(buffer)).LastRead()) > 0)
			{
				buffer[bytesRead] = '\0';
				wxPrintf("%s", wxString(buffer, 0, bytesRead));
				// std::cout << std::string(buffer, 0, bytesRead);
			};
			return nullptr;
		});
		outputProcessReaderThread->Create();
		outputProcessReaderThread->Run();


		// Process Error Stream
		wxThread* errorProcessReaderThread = new RunnableThread([&]() -> void*
		{
			char buffer[4096];
			size_t bytesRead = 0;
			wxInputStream* in = process->GetErrorStream();
			while ((bytesRead = in->Read(&buffer, sizeof(buffer)).LastRead()) > 0)
			{
				buffer[bytesRead] = '\0';
				wxPrintf("%s", wxString(buffer, 0, bytesRead));
				// std::cout << std::string(buffer, 0, bytesRead);
			}

			return nullptr;
		});

		errorProcessReaderThread->Create();
		errorProcessReaderThread->Run();

		wxTheApp->OnInit();
		wxTheApp->OnRun();

		outputProcessReaderThread->Wait();
		errorProcessReaderThread->Wait();
		consoleInputThread->Wait();

		delete outputProcessReaderThread;
		delete errorProcessReaderThread;
		delete consoleInputThread;

		// Exit the app
		wxTheApp->OnExit();
		// Cleanup the wxWidgets framework
		wxEntryCleanup();
	}
}
