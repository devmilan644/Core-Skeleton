#pragma once
using namespace winrt;
using namespace winrt::Windows;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Popups;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;
using namespace Windows::Graphics::Display;

struct App :implements<App, IFrameworkViewSource, IFrameworkView> {
private:
	bool windowClosed;
public:
	IFrameworkView CreateView();
public:
	void Initialize(CoreApplicationView const& appView);
	void SetWindow(CoreWindow const& window);
	void Load(hstring const& enrtyPoint);
	void Run();
	void Uninitialize();
private:
	void OnActivated(CoreApplicationView const& coreAppView, IActivatedEventArgs const& args);
	winrt::fire_and_forget Suspending(IInspectable const& sender, SuspendingEventArgs const& args);
	void Resuming(IInspectable const& sender, IInspectable const& args);
private:
	void Closed(CoreWindow const& sender, CoreWindowEventArgs const& args);
	void PointerPressed(CoreWindow const& window, PointerEventArgs const& args);
	void PointerReleased(CoreWindow const& window, PointerEventArgs const& args);
	void PointerWheelChanged(CoreWindow const& window, PointerEventArgs const& args);
	void PointerMoved(CoreWindow const& window, PointerEventArgs const& args);
	void KeyDown(CoreWindow const& window, KeyEventArgs const& args);
	void KeyUp(CoreWindow const& window, KeyEventArgs const& args);
	void CharacterReceived(CoreWindow const& window, CharacterReceivedEventArgs const& args);
};
