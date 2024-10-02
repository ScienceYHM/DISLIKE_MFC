#pragma once
#include "afxdialogex.h"


// 关于 对话框

class 关于 : public CDialogEx
{
	DECLARE_DYNAMIC(关于)

public:
	关于(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~关于();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
