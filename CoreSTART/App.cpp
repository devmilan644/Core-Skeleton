#include "Precompiled.h"
#include "App.h"

IFrameworkView App::CreateView()
{
	return *this;
}

void App::Initialize(CoreApplicationView const& appView)
{
	appView.Activated({ this, &App::OnActivated });
	CoreApplication::Suspending({ this, &App::Suspending });
	CoreApplication::Resuming({ this, &App::Resuming });

	windowClosed = false;
}

void App::SetWindow(CoreWindow const& window)
{
	window.Closed({ this, &App::Closed });
	window.PointerPressed({ this, &App::PointerPressed });
	window.PointerReleased({ this, &App::PointerReleased });
	window.PointerWheelChanged({ this, &App::PointerWheelChanged });
	window.PointerMoved({ this, &App::PointerMoved });
	window.KeyDown({ this, &App::KeyDown });
	window.KeyUp({ this, &App::KeyUp });
	window.CharacterReceived({ this, &App::CharacterReceived });
}

void App::Load(hstring const& enrtyPoint)
{

}

void App::Run()
{
	CoreWindow window = CoreWindow::GetForCurrentThread();
	CoreDispatcher dispatcher = window.Dispatcher();
	dispatcher.ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);

	while (!windowClosed) {
		window.Dispatcher().ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
	}
}

void App::Uninitialize()
{

}

#pragma region Impl_Initialize
/*
	for more information : https://docs.microsoft.com/ko-kr/windows/uwp/launch-resume/suspend-an-app
*/
void App::OnActivated(CoreApplicationView const& coreAppView, IActivatedEventArgs const& args)
{
	// æ€ ªÁ¿¸Ω««‡
	CoreWindow window = CoreWindow::GetForCurrentThread();
	window.Activate();
}

winrt::fire_and_forget App::Suspending(IInspectable const& sender, SuspendingEventArgs const& args)
{
	// æ€ ¿œΩ√¡ﬂ¥‹
	auto lifetime = get_strong();

	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral deferral = args.SuspendingOperation().GetDeferral();

	co_await winrt::resume_background();

	deferral.Complete();
}

void App::Resuming(IInspectable const& sender, IInspectable const& args)
{
	// æ€ ¥ŸΩ√Ω√¿€
}
#pragma endregion

#pragma region Impl_SetWindow
void App::Closed(CoreWindow const& sender, CoreWindowEventArgs const& args)
{
	windowClosed = true;
}
void App::PointerPressed(CoreWindow const& window, PointerEventArgs const& args)
{
}
void App::PointerReleased(CoreWindow const& window, PointerEventArgs const& args)
{
}
void App::PointerWheelChanged(CoreWindow const& window, PointerEventArgs const& args)
{
}
void App::PointerMoved(CoreWindow const& window, PointerEventArgs const& args)
{
}
void App::KeyDown(CoreWindow const& window, KeyEventArgs const& args)
{
}
void App::KeyUp(CoreWindow const& window, KeyEventArgs const& args)
{
}
void App::CharacterReceived(CoreWindow const& window, CharacterReceivedEventArgs const& args)
{
}
#pragma endregion
