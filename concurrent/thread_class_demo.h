#pragma once
#include <wx/wx.h>
#include <wx/thread.h> // We would need this header


/// Snippet showing the very minimum needed to spawn threads using wxWidgets
/// But this minimum may not be enough in some situations, for example
/// with this setup, we can not queue wxThreadEvent because there is no queue at all
namespace wxThreadUsage
{
	unsigned long mainThreadId;

	/// To use wxThreads we must extend them
	/// There are Joinable threads and detached threads
	/// Joinable threads must be clean up manually, the detached threads
	/// they take care of cleaning themselves
	class WorkerThread : public wxThread
	{
	public:
		WorkerThread()
			: wxThread(wxTHREAD_JOINABLE)
		{
		}

	private:
		WorkerThread(const WorkerThread& copy);

	public:
		void* Entry(void)
		{
			// wxThreadIdType is just a typedef to unsigned long
			wxThreadIdType currentId = wxThread::GetCurrentId();
			wxPrintf("WorkerThread::Entry() Is this the main thread? %s\n",
			         currentId == mainThreadId ? "true" : "false");
			// Sleep for 3 seconds, simulate some work
			wxSleep(3);

			return 0;
		}
	};

	void main(int argc, char** argv)
	{
		wxEntryStart(argc, argv);

		mainThreadId = wxThread::GetMainId();

		// Threads have to be created on the heap
		auto workerThread = new WorkerThread();

		//Start thread
		workerThread->Create();
		workerThread->Run();
		workerThread->Wait();

		// Joinable(like ours) threads must be deleted using delete operator
		// Detached threads(not used here) delete themselves
		delete workerThread;

		// Exit the app
		wxTheApp->OnExit();
		// Cleanup the wxWidgets framework
		wxEntryCleanup();
	}
}
