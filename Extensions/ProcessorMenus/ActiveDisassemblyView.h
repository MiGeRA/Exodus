#ifndef __ACTIVEDISASSEMBLYVIEW_H__
#define __ACTIVEDISASSEMBLYVIEW_H__
#include "WindowsSupport/WindowsSupport.pkg"
#include "DeviceInterface/DeviceInterface.pkg"
#include "ActiveDisassemblyViewPresenter.h"
#include "Processor/Processor.pkg"

class ActiveDisassemblyView :public ViewBase
{
public:
	// Constructors
	ActiveDisassemblyView(IUIManager& uiManager, ActiveDisassemblyViewPresenter& presenter, IProcessor& model);

protected:
	// Member window procedure
	virtual INT_PTR WndProcDialog(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

private:
	// Event handlers
	INT_PTR msgWM_INITDIALOG(HWND hwnd, WPARAM wParam, LPARAM lParam);
	INT_PTR msgWM_DESTROY(HWND hwnd, WPARAM wParam, LPARAM lParam);
	INT_PTR msgWM_TIMER(HWND hwnd, WPARAM wParam, LPARAM lParam);
	INT_PTR msgWM_COMMAND(HWND hwnd, WPARAM wParam, LPARAM lParam);

	void OutputActiveDisassemblyToTextFile(const std::wstring& filePath);
	void OutputActiveDisassemblyToIDCFile(const std::wstring& filePath);

private:
	ActiveDisassemblyViewPresenter& _presenter;
	IProcessor& _model;
	bool _initializedDialog;
	std::wstring _previousText;
	unsigned int _currentControlFocus;
};

#endif
